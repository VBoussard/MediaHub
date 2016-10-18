#include "ajoutflux.h"
#include "fenetreserveur2.h"

FenetreServeur2::FenetreServeur2(QWidget *parent) : QWidget(parent)
{

    QWidget *fenServeur = new QWidget(this);
    QGridLayout *glServeur = new QGridLayout;
    fenServeur->setFixedSize(800, 600);
    fenServeur->setWindowTitle("Administration");
    glServeur->setSpacing(4);
    fenServeur->setLayout(glServeur);

    m_boutonAdd = new QPushButton("Add",this);
    m_boutonAdd->setMinimumHeight(70);
    m_boutonAdd->setMaximumHeight(100);
    m_boutonAdd->setMinimumWidth(70);
    m_boutonAdd->setMaximumWidth(100);
    glServeur->addWidget(m_boutonAdd,0,0);

    m_tabServeur = new QTabWidget;
    QWidget *tab1 = new QWidget();
    QWidget *tab2 = new QWidget();
    m_tabServeur->addTab(tab1,"Carte 1");
    m_tabServeur->addTab(tab2,"Carte 2");
    glServeur->addWidget(m_tabServeur,1,0);

    connect(m_boutonAdd,SIGNAL(clicked()), this, SLOT(ajouterFlux()));
}

void FenetreServeur2::ajouterFlux()
{
    AjoutFlux *FenetreAjout = new AjoutFlux;
    FenetreAjout->show();
}
