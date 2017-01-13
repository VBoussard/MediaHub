#include "addstream.h"
#include "serverwin.h"

#include <iostream>

ServerWin::ServerWin(Engine *_engine) : QWidget(),
    nb_streams(0)
{

    m_engine = _engine;

    QWidget *fenServer = new QWidget(this);
    QGridLayout *glServer = new QGridLayout;
    fenServer->setFixedSize(800, 600);
    this->move(0,0);
    fenServer->setWindowTitle("Administration");
    glServer->setSpacing(4);
    fenServer->setLayout(glServer);

    m_pbAdd = new QPushButton("Add",this);
    m_pbAdd->setMinimumHeight(70);
    m_pbAdd->setMaximumHeight(100);
    m_pbAdd->setMinimumWidth(70);
    m_pbAdd->setMaximumWidth(100);
    glServer->addWidget(m_pbAdd,0,0);

    m_tabServer = new QTabWidget;
    QWidget *tab1 = new QWidget();

    QWidget *tab2 = new QWidget();
    m_tabServer->addTab(tab1,"Carte 1");
    m_tabServer->addTab(tab2,"Carte 2");
    glServer->addWidget(m_tabServer,1,0);

    gl_thumbnails = new QGridLayout(tab1);
    //gl_thumbnails->setAlignment(Qt::AlignTop);

/*
    for (int i=0; i<8; i++)
    {
        WinView[i] = new Thumbnail();
        WinViewID[i] = WinView[i]->getWinID();

    }
        //gl_thumbnails->setAlignment(Qt::AlignTop);
        gl_thumbnails->addWidget(WinView[0],0,0);
        gl_thumbnails->addWidget(WinView[1],0,1);
        gl_thumbnails->addWidget(WinView[2],0,2);
        gl_thumbnails->addWidget(WinView[3],0,3);
        gl_thumbnails->addWidget(WinView[4],1,0);
        gl_thumbnails->addWidget(WinView[5],1,1);
        gl_thumbnails->addWidget(WinView[6],1,2);
        gl_thumbnails->addWidget(WinView[7],1,3);

    */
    connect(m_pbAdd,SIGNAL(clicked()), this, SLOT(slotpbAdd()));
}

ServerWin::~ServerWin()
{
    //delete m_engine;
}

int ServerWin::getPosition()
{
    return 0;
}

void ServerWin::setPosition(int _position)
{

}

void ServerWin::slotpbAdd()
{
    AddStream *FenetreAjout = new AddStream(m_engine,WinViewID);
    FenetreAjout->exec();
    if(FenetreAjout->result() == QDialog::Accepted)
    {
        nb_streams++;
        WinView[nb_streams] = new Thumbnail;
        WinViewID[nb_streams] = WinView[nb_streams]->getWinID();

        gl_thumbnails->addWidget(WinView[nb_streams],(nb_streams/5),((nb_streams-1)%4));

        m_numFlux = m_engine->createStream();
        m_engine->setSrc(m_numFlux, FenetreAjout->getSource());
        m_engine->setDest(m_numFlux, "m_numFlux", WinViewID[nb_streams]);
        m_engine->play(m_numFlux, 1);
    }

}
