#include <iostream>
#include <fstream>
#include "configin.h"
#include "configout.h"
#include "ui_configin.h"
#include "paraminvid.h"
#include "paramoutaudio.h"
#include "paramstream.h"
#include "engine.h"
#include "player.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QGridLayout>
#include <QComboBox>
#include <QLineEdit>

configIN::configIN(QWidget *parent, Engine *moteur)
    : QMainWindow(parent), m_moteur(moteur)
{
    QFrame *framePrincipal = new QFrame();
    setCentralWidget(framePrincipal);

    //---------------------------------------- Frame 1 : Choix type source ----------------------------------------//
    QFrame *frameChoixSource = new QFrame();
    QLabel *labelChoixSource = new QLabel("Type de la source :");
    radioEntreePhy = new QRadioButton("Entrée physique");
    radioEntreeStr = new QRadioButton("Fichier/Stream");
    QGridLayout *layoutGrid1 = new QGridLayout(frameChoixSource);
    layoutGrid1->addWidget(labelChoixSource,0,0);
    layoutGrid1->addWidget(radioEntreePhy,0,1);
    layoutGrid1->addWidget(radioEntreeStr,1,1);

    //---------------------------------------- Frame 2 : Entrée Physique ----------------------------------------//
    QFrame *framePhy = new QFrame();
    framePhy->setDisabled(true);
    QLabel *labelPhy = new QLabel("Entrée physique");
    labelPhy->setStyleSheet("font-weight: bold");
    QLabel *labelNumCarte = new QLabel("Numéro de la carte :");
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

    //---------------------------------------- Frame 3 : Entrée flux/fichier ----------------------------------------//
    QFrame *frameStr = new QFrame();
    frameStr->setDisabled(true);
    QLabel *labelStr = new QLabel("Fichier/Stream");
    labelStr->setStyleSheet("font-weight: bold");
    QLabel *labelAdress = new QLabel("Adresse :");
    lineAdress = new QLineEdit();
    boutonAdress = new QPushButton("...");
    boutonAdress->setFixedSize(25,25);
    boutonParamVid = new QPushButton("Paramètres vidéo");
    boutonParamAud = new QPushButton("Paramètres audio");
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


    //---------------------------------------- Frame 4 : Prec, suiv, annuler ----------------------------------------//
    QFrame *frameNavig = new QFrame();
    boutonAnnul = new QPushButton("Annuler");
    boutonPrec = new QPushButton("Précédent");
    boutonTerm = new QPushButton("Terminer");
    QHBoxLayout *layoutNavig = new QHBoxLayout(frameNavig);
    layoutNavig->addWidget(boutonAnnul,0);
    layoutNavig->addWidget(boutonPrec,1);
    layoutNavig->addWidget(boutonTerm,2);

    //---------------------------------------- Mise en page ----------------------------------------//
    QLabel *ligne1 = new QLabel();
    ligne1->setFrameStyle(QFrame::HLine | QFrame::Raised);
    QLabel *ligne2 = new QLabel();
    ligne2->setFrameStyle(QFrame::HLine | QFrame::Raised);
    QLabel *ligne3 = new QLabel();
    ligne3->setFrameStyle(QFrame::HLine | QFrame::Raised);


    //---------------------------------------- Layout vertical GLOBAL ----------------------------------------//
    QVBoxLayout *layoutVPrincipal = new QVBoxLayout(framePrincipal);
    layoutVPrincipal->addWidget(frameChoixSource,0,0);
    layoutVPrincipal->addWidget(ligne1,1,0);
    layoutVPrincipal->addWidget(framePhy,2,0);
    layoutVPrincipal->addWidget(ligne2,3,0);
    layoutVPrincipal->addWidget(frameStr,4,0);
    layoutVPrincipal->addWidget(ligne3,4,0);
    layoutVPrincipal->addWidget(frameNavig,5,0);

    //---------------------------------------- Connects radioButtons ----------------------------------------//
    connect(radioEntreePhy, SIGNAL(toggled(bool)), framePhy, SLOT(setEnabled(bool)));
    connect(radioEntreeStr, SIGNAL(toggled(bool)), frameStr, SLOT(setEnabled(bool)));
}

configIN::~configIN()
{

}


void configIN::Annuler()
{
    this->close();
}

void configIN::ParamVideo()
{
    paramStream *fenParamVid = new paramStream;
    fenParamVid->show();
}

void configIN::ParamAudio()
{
    paramInVid *fenParamAud = new paramInVid;
    fenParamAud->show();
}

void configIN::Next()
{
    /*
    //Cas 1 : Entrée physique
    if (radioEntreePhy->isChecked())
    {
        //Initialisation de typeEntree à 1 (entrée physique)
        int typeEntree(1);
        //Récupération des paramètres entrés par l'utilisateur :
        choixCarte = ui->choixCarte->currentText();
        profil = ui->choixProfil->currentText();
        nomSource = ui->nomSource->text();

        //Conversion des QString -> const char* en vue de l'utilisation par le moteur
        C_choixCarte = choixCarte.toAscii().data();
        C_profil = profil.toAscii().data();
        C_nomSource = nomSource.toAscii().data();




    }
    //Cas 2 : Entrée stream/fichier
    else */
    if (radioEntreeStr->isChecked())
    {
        //Initialisation de typeEntree à 2 (entrée stream/fichier)
        int typeEntree(2);
        //Récupération des paramètres entrés par l'utilisateur :
        QString adresse = lineAdress->text();



        //Conversion des QString -> string en vue de l'utilisation par le moteur
        S_nomSource = adresse.toUtf8().constData();


    }

//////////////////disparition inquietante de S_nomSource////////////////
    //m_moteur->getInstance();

    cout << "path dans configin 1 "<< S_nomSource << endl;

    m_numFlux = m_moteur->createFlux();

    cout << "path dans configin 2 "<< S_nomSource << endl;

    cout << m_numFlux << endl;


    m_moteur->setPathIn(m_numFlux, S_nomSource);

    this->hide();

    //home/vif/Bureau/thierry.mp4

    player *fenetreLecture = new player(NULL, m_moteur);
    int id_fenetreLecture = (int) fenetreLecture->winId();
    QWidget *tutu = new QWidget();
    int ID_tutu = (int) tutu->winId();


    //player *fenetreLecture2 = new player(NULL, m_moteur);
    //int id_fenetreLecture2 = (int) fenetreLecture->winId();

    m_moteur->setPathOut(id_fenetreLecture, m_numFlux, "");
    //m_moteur->setPathOut(id_fenetreLecture2, m_numFlux, "");
    fenetreLecture->show();
    //fenetreLecture2->show();
}
