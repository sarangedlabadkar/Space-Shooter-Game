#include "Media.h"
#include <iostream>

namespace sfe
{
Media::Media() :
myFormatCtx     (NULL),
myAudioStream   (-1),
mySamples       (NULL),
myData          (NULL),
myDataSize      (0),
myDataSizeMax   (0)
{
    av_register_all();
}

Media::~Media()
{
    Stop();

    if (myFormatCtx)
    {
        for (unsigned int i=0; i<myFormatCtx->nb_streams; i++)
        {
            if (myFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO)
            {
                if (myData)
                    av_free(myData);

                if (mySamples)
                {
                    delete [] mySamples;
                    mySamples = NULL;
                }

                avcodec_close(myFormatCtx->streams[i]->codec);
            }
        }

        avformat_free_context(myFormatCtx);
    }
}

bool Media::OpenFromFile(const std::string& filename)
{
    if (avformat_open_input(&myFormatCtx, filename.c_str(), NULL, NULL) != 0)
    {
        std::cerr << "Unexisting file!" << std::endl;
        return false;
    }

    if (avformat_find_stream_info(myFormatCtx, NULL) < 0)
    {
        std::cerr << "Couldn't find stream information!" << std::endl;
        return false;
    }

    for (unsigned int i=0; i<myFormatCtx->nb_streams; i++)
    {
        if (myFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_AUDIO && myAudioStream < 0)
        {
            AVCodec* codec = avcodec_find_decoder(myFormatCtx->streams[i]->codec->codec_id);
            if (!codec)
                std::cerr << "Unsupported codec!" << std::endl;
            else if (avcodec_open2(myFormatCtx->streams[i]->codec, codec, NULL) < 0)
                std::cerr << "Couldn't open audio codec context!" << std::endl;
            else
            {
                mySamples = new char[19200];
                if (!mySamples)
                    std::cerr << "Out of memory allocating temp buffer!" << std::endl;
                else
                    myAudioStream = i;

                Initialize(myFormatCtx->streams[i]->codec->channels, myFormatCtx->streams[i]->codec->sample_rate);
            }
        }
    }
    if (myAudioStream == -1)
        return false;

    return true;
}

int Media::GetAVAudioData(void* data, int length)
{
    static size_t decodedDataSize = 0;
    static char decodedData[AVCODEC_MAX_AUDIO_FRAME_SIZE];
    int dec = 0;

    while(dec < length)
    {
        if (decodedDataSize > 0)
        {
            size_t rem = length - dec;
            if (rem > decodedDataSize)
                rem = decodedDataSize;

            memcpy(data, decodedData, rem);
            data = (char*)data + rem;
            dec += rem;

            if (rem < decodedDataSize)
                memmove(decodedData, &decodedData[rem], decodedDataSize - rem);
            decodedDataSize -= rem;
        }

        if (decodedDataSize == 0)
        {
            size_t insize = myDataSize;
            if (insize == 0)
            {
                GetNextPacket();
                if (insize == myDataSize)
                    break;
                insize = myDataSize;
                memset(&myData[insize], 0, FF_INPUT_BUFFER_PADDING_SIZE);
            }

            int size = AVCODEC_MAX_AUDIO_FRAME_SIZE;
            int len;
            AVPacket pkt;
            av_init_packet(&pkt);
            pkt.data = (unsigned char*)myData;
            pkt.size = insize;
            while((len = avcodec_decode_audio3(myFormatCtx->streams[myAudioStream]->codec, (int16_t*)decodedData,
&size, &pkt)) == 0)
            {
                if (size > 0)
                    break;
                GetNextPacket();
                if (insize == myDataSize)
                    break;
                insize = myDataSize;
                memset(&myData[insize], 0, FF_INPUT_BUFFER_PADDING_SIZE);
            }

            if (len < 0)
                break;

            if (len > 0)
            {
                size_t rem = insize - len;
                if (rem)
                    memmove(myData, &myData[len], rem);
                myDataSize = rem;
            }
            decodedDataSize = size;
        }
    }

    return dec;
}

void Media::GetNextPacket()
{
    AVPacket packet;
    while(av_read_frame(myFormatCtx, &packet) >= 0)
    {
        for (unsigned int i=0; i<myFormatCtx->nb_streams; i++)
        {
            if (myAudioStream == packet.stream_index)
            {
                size_t idx = myDataSize;
                if (idx + packet.size > myDataSizeMax)
                {
                    void *temp = av_realloc(myData, idx+packet.size + FF_INPUT_BUFFER_PADDING_SIZE);
                    if (!temp)
                        return;
                    myData = (char*)temp;
                    myDataSizeMax = idx+packet.size;
                }

                memcpy(&myData[idx], packet.data, packet.size);
                myDataSize += packet.size;

                return;
            }
            else
                av_free_packet(&packet);
        }
    }
}

bool Media::OnGetData(Chunk &data)
{
    if (myAudioStream >= 0)
    {
        int done = GetAVAudioData(mySamples, 19200);

        data.Samples   = (sf::Int16*)mySamples;
        data.SampleCount = done/sizeof(sf::Int16);

        return (data.SampleCount > 0);
    }
    else
        return false;
}

void Media::OnSeek(float timeOffset)
{

}

} // namespace sfe
