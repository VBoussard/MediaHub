#ifndef ENGINE_H
#define ENGINE_H

#include "stream.h"
#include <vector>


class Engine
{
private:
    //Attributs :
    int m_nbStream;
    std::vector<Stream*> m_streamArray;
    static bool instanceFlag;


public:
    Engine();
    Engine* getInstance();
    int createStream();

    void setSrc(int _IDStream, const char* _pathSrc = NULL);
    void setDest(int _IDStream, const char* _pathDest = NULL, int _winID = 0);

    void play(int _IDStream, int _speed = 1);
    void pause(int _IDStream);


    // anciens noms à remplacer
    std::vector<Stream*> tableauFlux;
    int m_positionFlux;
    int m_numFlux;

    ~Engine();
};

#endif // ENGINE_H
