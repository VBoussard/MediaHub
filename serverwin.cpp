#include "ajoutflux.h"
#include "serverwin.h"

ServerWin::ServerWin(QWidget *parent) : QWidget(parent)
{

    QWidget *fenServeur = new QWidget(this);
    QGridLayout *glServeur = new QGridLayout;
    fenServeur->setFixedSize(800, 600);
    fenServeur->setWindowTitle("Administration");
    glServeur->setSpacing(4);
    fenServeur->setLayout(glServeur);

    m_pbAdd = new QPushButton("Add",this);
    m_pbAdd->setMinimumHeight(70);
    m_pbAdd->setMaximumHeight(100);
    m_pbAdd->setMinimumWidth(70);
    m_pbAdd->setMaximumWidth(100);
    glServeur->addWidget(m_pbAdd,0,0);

    m_tabServeur = new QTabWidget;
    QWidget *tab1 = new QWidget();
    QWidget *tab2 = new QWidget();
    m_tabServeur->addTab(tab1,"Carte 1");
    m_tabServeur->addTab(tab2,"Carte 2");
    glServeur->addWidget(m_tabServeur,1,0);

    connect(m_pbAdd,SIGNAL(clicked()), this, SLOT(ajouterFlux()));
}

int ServerWin::getPosition()
{

}

void ServerWin::setPosition(int _position)
{

}

void ServerWin::slotpbAdd()
{
    AjoutFlux *FenetreAjout = new AjoutFlux;
    FenetreAjout->show();
}
