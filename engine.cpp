#include <iostream>
#include "stream.h"
#include "engine.h"
#include "vector"

bool Engine::instanceFlag = false;
//engine* engine::MediaHub = NULL;


Engine::Engine()
{
    //m_numFlux = 0;
    m_nbStreams = 0;
    //tableauFlux.push_back(NULL);
    Stream::initMLT();

    for(int i=0; i<8; i++)
    {
       streamTab[i] = new structStream;
       streamTab[i]->S_stream = new Stream;
       streamTab[i]->S_pathInType = new int;
       streamTab[i]->S_pathOutType = new int;
       streamTab[i]->S_numStream = new int(i);
    }
}

Engine* Engine::getInstance()
{
    return this;
}

int Engine::createStream()
{
    Stream* newFlux = new Stream();
    tableauFlux.push_back(newFlux);

    m_positionFlux = tableauFlux.size()-1;

    std::cout << "creation du flux, position dans le tableau : "<< m_positionFlux << std::endl;

    /// retourne l'indice du flux dans le tableau == le numero du flux
    return m_positionFlux;
}

void Engine::setSrc(int _IDStream, const char* _pathSrc)
{
    std::cout << "appel de setSource " << std::endl;
    std::cout << "path dans engine " << _pathSrc << std::endl;
    std::cout << "ID stream " << _IDStream << std::endl;
    //tableauFlux[_IDStream]->setSrc(_pathSrc);
    streamTab[_IDStream]->S_stream->setSrc(_pathSrc);

}

void Engine::setDest(int _IDStream, const char* _pathDest, int _winID)
{
    //tableauFlux[_IDStream]->setDest(_pathDest, _winID);
    streamTab[_IDStream]->S_stream->setDest(_pathDest, _winID);

    std::cout<<"s_numstream sans engine : "<<*(streamTab[_IDStream]->S_numStream)<< std::endl;
    std::cout<<"Appel de setDest dans engine" << std::endl;
    std::cout<<"IDWin player in engine: "<< _winID <<std::endl;
    std::cout<<"IDStream in engine: "<< _IDStream <<std::endl;
}

void Engine::play(int _IDStream, int _speed)
{
    //tableauFlux[_IDStream]->play();
    streamTab[_IDStream]->S_stream->play();
}

void Engine::pause(int _IDStream)
{
     streamTab[_IDStream]->S_stream->pause();
}

structStream* Engine::getStream(int _numStream)
{
    return streamTab[_numStream];
}

int Engine::getNbStreams()
{
    return m_nbStreams;
}

void Engine::NbStreamsPlus()
{
    ++m_nbStreams;
}
