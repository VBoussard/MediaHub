#ifndef SERVERWIN_H
#define SERVERWIN_H

#include "engine.h"
#include "vector"
#include "thumbnail.h"
//#include "InfoStream.h"

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>

class ServerWin : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWin(Engine *_engine = NULL);
    ~ServerWin();
    int getPosition();
    void setPosition(int _position);


private:
    Engine* m_engine;
    //std::vector<InfoStream*> m_vectInfo;
    QGridLayout *m_gridInfo;
    QPushButton *m_pbAdd;
    QTabWidget *m_tabServer;

    int WinViewID[8];    //REMPLACER PAR VECTOR ??
    //====================//
    int nb_streams;
    QGridLayout *gl_thumbnails;
    Thumbnail *WinView[8];  //REMPLACER PAR VECTOR ?
    //====================//

public slots:
    void slotpbAdd();
};

#endif // SERVERWIN_H
