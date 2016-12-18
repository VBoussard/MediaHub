#include "addstream.h"
#include "serverwin.h"

ServerWin::ServerWin(Engine *_engine) : QWidget()
{

    m_engine = _engine;

    QWidget *fenServer = new QWidget(this);
    QGridLayout *glServer = new QGridLayout;
    fenServer->setFixedSize(800, 600);
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
    AddStream *FenetreAjout = new AddStream(m_engine);
    FenetreAjout->show();
}
