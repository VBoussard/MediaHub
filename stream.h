#ifndef STREAM_H
#define STREAM_H


class Stream
{
private:
    //Attribut :
    int m_IDStream;
    Mlt::profile* m_profile;
    Mlt::producer* m_producer;
    Mlt::consumer* m_consumer;

public:
    Stream();
    Stream(const Stream _copy);
    ~Stream();

    void setID(int _IDStream);
    void setSrc(const char* _src);
    void setDest(const char* _dest, int _winID = NULL);
    void play(int _speed = 1);
    void pause();
    void close();
};

#endif // STREAM_H
