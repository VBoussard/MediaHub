#ifndef STREAM_H
#define STREAM_H

#include <Mlt.h>


class Stream
{
private:
    //Attribut :
    int m_IDStream;
    Mlt::Profile* m_profile;
    Mlt::Producer* m_producer;
    Mlt::Consumer* m_consumer;

public:
    Stream();
    Stream(const Stream &_copy);
    ~Stream();

    void setID(int _IDStream);
    void setSrc(const char* _src);
    void setDest(const char* _dest, int _winID);
    void play(int _speed = 1);
    void pause();
    void close();
};

#endif // STREAM_H
