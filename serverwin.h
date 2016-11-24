#ifndef SERVERWIN_H
#define SERVERWIN_H

#include "engine.h"
#include "vector"
//#include "InfoStream.h"

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>

class ServerWin : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWin(QWidget *parent = 0);
    int getPosition();
    void setPosition(int _position);


private:
    Engine* m_engine;
    //std::vector<InfoStream*> m_vectInfo;
    QGridLayout *m_gridInfo;
    QPushButton *m_pbAdd;
    QTabWidget *m_tabServer;

public slots:
    void slotpbAdd();
};

#endif // SERVERWIN_H
