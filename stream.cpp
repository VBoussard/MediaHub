#include "stream.h"
#include <iostream>
#include <QWidget>

using namespace std;

Stream::Stream()
{
    m_profile = 0;
    m_producer = 0;
    m_consumer = 0;
}

Stream::Stream(const Stream &_copy)
{
    m_profile = _copy.m_profile;
    m_producer = _copy.m_producer;
    m_consumer = _copy.m_consumer;
}

Stream::~Stream()
{

}

void Stream::initMLT()
{
    Mlt::Factory::init();
}

void Stream::setID(int _IDStream)
{

}

void Stream::setSrc(const char* _src)
{
    m_profile = new Mlt::Profile();
    m_producer = new Mlt::Producer(*m_profile, _src);
}

void Stream::setDest(const char* _dest, int _winID)
{
    m_consumer = new Mlt::Consumer(*m_profile, "sdl_preview");
    m_consumer->set("window_id", _winID);
    m_consumer->connect(*m_producer);
    m_consumer->start();
}

void Stream::play(int _speed)
{
    if(m_producer)
        m_producer->set_speed(1);
    if(m_consumer)
        m_consumer->set("refresh", 1);
}

void Stream::pause()
{
    if(m_producer)
        m_producer.pause();
}

void Stream::close()
{
    if(m_consumer)
        m_consumer->stop();
    delete m_consumer;
    m_consumer = 0;
    delete m_producer;
    m_producer = 0;
    delete m_profile;
    m_profile = 0;
}
