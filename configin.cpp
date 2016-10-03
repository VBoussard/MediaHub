#include "configin.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>

configIN::configIN(QWidget *parent)
    : QMainWindow(parent)
{
    QFrame *framePrincipal = new QFrame();
    setCentralWidget(framePrincipal);

    //-------------------- Frame 1 : Choix type source --------------------//
    QFrame *frameChoixSource = new QFrame();
    QLabel *labelChoixSource = new QLabel("Type de la source :");
    radioEntreePhy = new QRadioButton("Entree physique");
    radioEntreeStr = new QRadioButton("Fichier/Stream");
    QGridLayout *layoutGrid1 = new QGridLayout(frameChoixSource);
    layoutGrid1->addWidget(labelChoixSource,0,0);
    layoutGrid1->addWidget(radioEntreePhy,0,1);
    layoutGrid1->addWidget(radioEntreeStr,1,1);

    //-------------------- Frame 2 : Entrée Physique --------------------//
    QFrame *framePhy = new QFrame();
    framePhy->setDisabled(true);
    QLabel *labelPhy = new QLabel("Entree physique");
    labelPhy->setStyleSheet("font-weight: bold");
    QLabel *labelNumCarte = new QLabel("Numero de la carte :");
    QLabel *labelProfil = new QLabel("Profil :");
    QLabel *labelNomSource = new QLabel("Nom de la source :");
    comboNumCarte = new QComboBox();
    int cartesLibres = 8;
    QString indiceCartes[8] = {"1","2","3","4","5","6","7","8"};
    for(int i = 0; i < cartesLibres; i++)
    {
        comboNumCarte->addItem(indiceCartes[i]);
    }

    comboProfil = new QComboBox();
    comboProfil->addItem("CRM");
    comboProfil->addItem("Profil 2");
    lineNom = new QLineEdit();
    QGridLayout *layoutGrid2 = new QGridLayout(framePhy);
    layoutGrid2->addWidget(labelPhy,0,0);
    layoutGrid2->addWidget(labelNumCarte,1,0);
    layoutGrid2->addWidget(comboNumCarte,1,1);
    layoutGrid2->addWidget(labelProfil,2,0);
    layoutGrid2->addWidget(comboProfil,2,1);
    layoutGrid2->addWidget(labelNomSource,3,0);
    layoutGrid2->addWidget(lineNom,3,1);

    //-------------------- Frame 3 : Entrée flux/fichier --------------------//
    QFrame *frameStr = new QFrame();
    frameStr->setDisabled(true);
    QLabel *labelStr = new QLabel("Fichier/Stream");
    labelStr->setStyleSheet("font-weight: bold");
    QLabel *labelAdress = new QLabel("Adress :");
    lineAdress = new QLineEdit();
    boutonAdress = new QPushButton("...");
    boutonAdress->setFixedSize(25,25);
    boutonParamVid = new QPushButton("Parametres video");
    boutonParamAud = new QPushButton("Parametres audio");
    QFrame *frameLayoutH1 = new QFrame();
    QHBoxLayout *layoutH1 = new QHBoxLayout(frameLayoutH1);
    layoutH1->addWidget(lineAdress,0);
    layoutH1->addWidget(boutonAdress,1);
    QFrame *frameLayoutH2 = new QFrame();
    QHBoxLayout *layoutH2 = new QHBoxLayout(frameLayoutH2);
    layoutH2->addWidget(boutonParamVid,0);
    layoutH2->addWidget(boutonParamAud,1);
    QVBoxLayout *layoutV = new QVBoxLayout(frameStr);
    layoutV->addWidget(labelStr,0,0);
    layoutV->addWidget(labelAdress,1,0);
    layoutV->addWidget(frameLayoutH1,2,0);
    layoutV->addWidget(frameLayoutH2,3,0);


    //-------------------- Frame 4 : Prec, suiv, annuler --------------------//
    QFrame *frameNavig = new QFrame();
    boutonAnnul = new QPushButton("Annuler");
    boutonPrec = new QPushButton("Précédent");
    boutonSuiv = new QPushButton("Suivant");
    QHBoxLayout *layoutNavig = new QHBoxLayout(frameNavig);
    layoutNavig->addWidget(boutonAnnul,0);
    layoutNavig->addWidget(boutonPrec,1);
    layoutNavig->addWidget(boutonSuiv,2);

    //-- Mise en page --//
    QLabel *ligne1 = new QLabel();
    ligne1->setFrameStyle(QFrame::HLine | QFrame::Raised);
    QLabel *ligne2 = new QLabel();
    ligne2->setFrameStyle(QFrame::HLine | QFrame::Raised);
    QLabel *ligne3 = new QLabel();
    ligne3->setFrameStyle(QFrame::HLine | QFrame::Raised);


    //-------------------- Layout vertical GLOBAL --------------------//
    QVBoxLayout *layoutVPrincipal = new QVBoxLayout(framePrincipal);
    layoutVPrincipal->addWidget(frameChoixSource,0,0);
    layoutVPrincipal->addWidget(ligne1,1,0);
    layoutVPrincipal->addWidget(framePhy,2,0);
    layoutVPrincipal->addWidget(ligne2,3,0);
    layoutVPrincipal->addWidget(frameStr,4,0);
    layoutVPrincipal->addWidget(ligne3,4,0);
    layoutVPrincipal->addWidget(frameNavig,5,0);


    connect(radioEntreePhy, SIGNAL(toggled(bool)), framePhy, SLOT(setEnabled(bool)));
    connect(radioEntreeStr, SIGNAL(toggled(bool)), frameStr, SLOT(setEnabled(bool)));
}

configIN::~configIN()
{

}
