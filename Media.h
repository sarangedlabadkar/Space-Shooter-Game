#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED

#include <SFML/Audio.hpp>
extern "C"
{
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
}

namespace sfe
{
class Media : public sf::SoundStream
{
public :
    Media();
    ~Media();

    bool OpenFromFile(const std::string& filename);

private :
    int GetAVAudioData(void* data, int length);
    void GetNextPacket();
    bool OnGetData(Chunk& data);
    void OnSeek(sf::Time timeOffset);

    AVFormatContext*    myFormatCtx;
    int                 myAudioStream;
    char*               mySamples;
    char*               myData;
    size_t              myDataSize;
    size_t              myDataSizeMax;
};

} // namespace sfe

#endif // MEDIA_H_INCLUDED
