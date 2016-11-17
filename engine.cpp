#include <iostream>
#include "flux.h"
#include "engine.h"
#include "vector"

bool engine::instanceFlag = false;
//engine* engine::MediaHub = NULL;

Engine::Engine()
{
    m_numFlux = 0;
    //tableauFlux.push_back(NULL);
    std::cout << &tableauFlux << "titi" << std::endl;
    flux::initMLT();
}
Engine* Engine::getInstance()
{
    return this;
}

int Engine::createStream()
{
    flux* newFlux = new flux();
    //std::cout << &newFlux << std::endl;

    tableauFlux.push_back(newFlux);


    //std::cout << "titi" << std::endl;
    m_positionFlux = tableauFlux.size()-1;

    /// retourne l'indice du flux dans le tableau == le numero du flux
    return m_positionFlux;
}

bool Engine::setSrc(int _IDStream, const char* _pathSrc)
{
    cout << "path dans engine " << _pathSrc << endl;
    tableauFlux[_IDStream]->setSrc(_pathSrc);

}

bool Engine::setDest(int _IDStream, const char* _pathDest, int _winID)
{
    tableauFlux[_IDStream]->setDest(_winID, _pathDest);
}

void Engine::play(int _IDStream, int _speed)
{
    tableauFlux[_IDStream]->play();
}

void Engine::pause(int _IDStream)
{
    tableauFlux[_IDStream]->pause();
}
