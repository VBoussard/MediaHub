#ifndef ENGINE_H
#define ENGINE_H

#include "stream.h"
#include <vector>


typedef struct {
  int *S_numStream;
  Stream *S_stream;
  int *S_pathInType;
  int *S_pathOutType;
} structStream;

class Engine
{
private:
    //Attributs :
    //int m_nbStream;
    std::vector<Stream*> m_streamArray;
    static bool instanceFlag;

    int m_nbStreams;


public:
    Engine();
    Engine* getInstance();
    int createStream();

    void setSrc(int _IDStream, const char* _pathSrc = NULL);
    void setDest(int _IDStream, const char* _pathDest = NULL, int _winID = 0);

    void play(int _IDStream, int _speed = 1);
    void pause(int _IDStream);

    structStream* streamTab[8];

    structStream* getStream(int _numStream);

    int getNbStreams();
    void NbStreamsPlus();

    // anciens noms à remplacer
    std::vector<Stream*> tableauFlux;
    int m_positionFlux;
    int m_numFlux;

    ~Engine();
};

#endif // ENGINE_H
