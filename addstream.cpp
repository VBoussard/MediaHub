#include "addstream.h"
#include <iostream>

#include <QButtonGroup>
#include <QFileDialog>


AddStream::AddStream(Engine *moteur) : QWidget(), m_moteur(moteur)
{
    QWidget *fenAjout = new QWidget(this);
    QGridLayout *glAjout = new QGridLayout;
    fenAjout->setFixedSize(700, 450);
    fenAjout->setWindowTitle("Assistant I/O");

    glAjout->setSpacing(4);
    fenAjout->setLayout(glAjout);

    //---------------| Confif IN |---------------//
    QGridLayout *glIN = new QGridLayout;

    //Choix type source :
    QLabel *labelChoixSource = new QLabel("Source :");
    radioEntreePhy = new QRadioButton("Entree physique");
    radioEntreeStr = new QRadioButton("Fichier/Stream");
    QButtonGroup *bgIN = new QButtonGroup;
    bgIN->addButton(radioEntreePhy);
    bgIN->addButton(radioEntreeStr);
    QGridLayout *glTypeIN = new QGridLayout;
    glTypeIN->addWidget(labelChoixSource, 0,0);
    glTypeIN->addWidget(radioEntreePhy, 0,1);
    glTypeIN->addWidget(radioEntreeStr, 1,1);

    //Entree Physique :
    QFrame *framePhyIN = new QFrame();
    framePhyIN->setDisabled(true);
    QLabel *labelPhyIN = new QLabel("Entree physique");
    labelPhyIN->setStyleSheet("font-weight: bold");
    QLabel *labelNumCarteIN = new QLabel("Numero de la carte :");
    QLabel *labelProfilIN = new QLabel("Profil :");
    QLabel *labelNomSourceIN = new QLabel("Nom de la source :");
    comboNumCarteIN = new QComboBox();
    int cartesLibresIN = 8;
    QString indiceCartesIN[8] = {"1","2","3","4","5","6","7","8"};
    for(int i = 0; i < cartesLibresIN; i++)
    {
        comboNumCarteIN->addItem(indiceCartesIN[i]);
    }

    comboProfilIN = new QComboBox();
    comboProfilIN->addItem("CRM");
    comboProfilIN->addItem("Profil 2");
    lineNomIN = new QLineEdit();
    QGridLayout *glPhyIN = new QGridLayout(framePhyIN);
    glPhyIN->addWidget(labelPhyIN,0,0);
    glPhyIN->addWidget(labelNumCarteIN,1,0);
    glPhyIN->addWidget(comboNumCarteIN,1,1);
    glPhyIN->addWidget(labelProfilIN,2,0);
    glPhyIN->addWidget(comboProfilIN,2,1);
    glPhyIN->addWidget(labelNomSourceIN,3,0);
    glPhyIN->addWidget(lineNomIN,3,1);

    //Entree fichier/stream :
    QFrame *frameStrIN = new QFrame();
    frameStrIN->setDisabled(true);
    QLabel *labelStrIN = new QLabel("Fichier/Stream");
    labelStrIN->setStyleSheet("font-weight: bold");
    QLabel *labelAdressIN = new QLabel("Adresse :");
    lineAdressIN = new QLineEdit();
    boutonAdressIN = new QPushButton("...");
    connect(boutonAdressIN, SIGNAL(clicked()), this, SLOT(slotAdressIN()));
    boutonAdressIN->setFixedSize(25,25);
    boutonParamVidIN = new QPushButton("Parametres video");
    boutonParamAudIN = new QPushButton("Parametres audio");
    QHBoxLayout *hlAdressIN = new QHBoxLayout;
    hlAdressIN->addWidget(lineAdressIN,0);
    hlAdressIN->addWidget(boutonAdressIN,1);
    QHBoxLayout *hlParamIN = new QHBoxLayout;
    hlParamIN->addWidget(boutonParamVidIN,0);
    hlParamIN->addWidget(boutonParamAudIN,1);
    QVBoxLayout *vblStrIN = new QVBoxLayout(frameStrIN);
    vblStrIN->addWidget(labelStrIN,0);
    vblStrIN->addWidget(labelAdressIN,1);
    vblStrIN->addLayout(hlAdressIN,2);
    vblStrIN->addLayout(hlParamIN,3);


    QLabel *ligne1IN = new QLabel();
    ligne1IN->setFrameStyle(QFrame::HLine | QFrame::Raised);
    QLabel *ligne2IN = new QLabel();
    ligne2IN->setFrameStyle(QFrame::HLine | QFrame::Raised);

    glIN->addLayout(glTypeIN, 0,0);
    glIN->addWidget(ligne1IN, 1,0);
    glIN->addWidget(framePhyIN, 2,0);
    glIN->addWidget(ligne2IN, 3,0);
    glIN->addWidget(frameStrIN, 4,0);

    //---------------| Config OUT |---------------//
    QGridLayout *glOUT = new QGridLayout;

    //Choix type destination :
    QLabel *labelChoixDest = new QLabel("Destination :");
    radioSortiePhy = new QRadioButton("Sortie physique");
    radioSortieStr = new QRadioButton("Fichier/Stream");
    QButtonGroup *bgOUT = new QButtonGroup;
    bgOUT->addButton(radioSortiePhy);
    bgOUT->addButton(radioSortieStr);
    QGridLayout *glTypeOUT = new QGridLayout;
    glTypeOUT->addWidget(labelChoixDest,0,0);
    glTypeOUT->addWidget(radioSortiePhy,0,1);
    glTypeOUT->addWidget(radioSortieStr,1,1);

    //Sortie physique :
    QFrame *framePhyOUT = new QFrame();
    framePhyOUT->setDisabled(true);
    QLabel *labelPhyOUT = new QLabel("Sortie physique");
    labelPhyOUT->setStyleSheet("font-weight: bold");
    QLabel *labelNumCarteOUT = new QLabel("Numero de la carte :");
    QLabel *labelProfilOUT = new QLabel("Profil :");
    QLabel *labelNomSourceOUT = new QLabel("Nom de la source :");
    comboNumCarteOUT = new QComboBox();
    int cartesLibresOUT = 8;
    QString indiceCartesOUT[8] = {"1","2","3","4","5","6","7","8"};
    for(int i = 0; i < cartesLibresOUT; i++)
    {
        comboNumCarteOUT->addItem(indiceCartesOUT[i]);
    }

    comboProfilOUT = new QComboBox();
    comboProfilOUT->addItem("CRM");
    comboProfilOUT->addItem("Profil 2");
    lineNomOUT = new QLineEdit();
    QGridLayout *glPhyOUT = new QGridLayout(framePhyOUT);
    glPhyOUT->addWidget(labelPhyOUT,0,0);
    glPhyOUT->addWidget(labelNumCarteOUT,1,0);
    glPhyOUT->addWidget(comboNumCarteOUT,1,1);
    glPhyOUT->addWidget(labelProfilOUT,2,0);
    glPhyOUT->addWidget(comboProfilOUT,2,1);
    glPhyOUT->addWidget(labelNomSourceOUT,3,0);
    glPhyOUT->addWidget(lineNomOUT,3,1);

    //Sortie fichier/stream :
    QFrame *frameStrOUT = new QFrame();
    frameStrOUT->setDisabled(true);
    QLabel *labelStrOUT = new QLabel("Fichier/Stream");
    labelStrOUT->setStyleSheet("font-weight: bold");
    QLabel *labelAdressOUT = new QLabel("Adresse :");
    lineAdressOUT = new QLineEdit();
    boutonAdressOUT = new QPushButton("...");
    connect(boutonAdressOUT, SIGNAL(clicked()), this, SLOT(slotAdressOUT()));
    boutonAdressOUT->setFixedSize(25,25);
    boutonParamVidOUT = new QPushButton("Parametres video");
    boutonParamAudOUT = new QPushButton("Parametres audio");
    QHBoxLayout *hlAdressOUT = new QHBoxLayout;
    hlAdressOUT->addWidget(lineAdressOUT,0);
    hlAdressOUT->addWidget(boutonAdressOUT,1);
    QHBoxLayout *hlParamOUT = new QHBoxLayout;
    hlParamOUT->addWidget(boutonParamVidOUT,0);
    hlParamOUT->addWidget(boutonParamAudOUT,1);
    QVBoxLayout *vblStrOUT = new QVBoxLayout(frameStrOUT);
    vblStrOUT->addWidget(labelStrOUT,0);
    vblStrOUT->addWidget(labelAdressOUT,1);
    vblStrOUT->addLayout(hlAdressOUT,2);
    vblStrOUT->addLayout(hlParamOUT,3);

    QLabel *ligne1OUT = new QLabel();
    ligne1OUT->setFrameStyle(QFrame::HLine | QFrame::Raised);
    QLabel *ligne2OUT = new QLabel();
    ligne2OUT->setFrameStyle(QFrame::HLine | QFrame::Raised);

    glOUT->addLayout(glTypeOUT, 0,0);
    glOUT->addWidget(ligne1OUT, 1,0);
    glOUT->addWidget(framePhyOUT, 2,0);
    glOUT->addWidget(ligne2OUT, 3,0);
    glOUT->addWidget(frameStrOUT, 4,0);

    //----------------------------------------/
    connect(radioEntreePhy, SIGNAL(toggled(bool)), framePhyIN, SLOT(setEnabled(bool)));
    connect(radioEntreeStr, SIGNAL(toggled(bool)), frameStrIN, SLOT(setEnabled(bool)));

    connect(radioSortiePhy, SIGNAL(toggled(bool)), framePhyOUT, SLOT(setEnabled(bool)));
    connect(radioSortieStr, SIGNAL(toggled(bool)), frameStrOUT, SLOT(setEnabled(bool)));

    m_pbCancel = new QPushButton("Annuler");
    connect(m_pbCancel, SIGNAL(clicked()), this, SLOT(Annuler()));
    m_pbValid = new QPushButton("Ok");
    connect(m_pbValid, SIGNAL(clicked()), this, SLOT(Valider()));

    QLabel *ligneVert = new QLabel();
    ligneVert->setFrameStyle(QFrame::VLine | QFrame::Raised);
    QLabel *ligneHor = new QLabel();
    ligneHor->setFrameStyle(QFrame::HLine | QFrame::Raised);

    glAjout->addLayout(glIN,0,0);
    glAjout->addWidget(ligneVert, 0,1);
    glAjout->addLayout(glOUT, 0,2);
    glAjout->addWidget(ligneHor, 1,0, 1,3);
    glAjout->addWidget(m_pbCancel, 2,0);
    glAjout->addWidget(m_pbValid,2,2);
}

AddStream::~AddStream()
{

}


void AddStream::Annuler()
{
    this->close();
}

void AddStream::Valider()
{
    QWidget winAff;
    winAff.show();
    std::cout << "titi"<< std::endl;


}

void AddStream::slotAdressIN()
{
    QString *adressIN = new QString(QFileDialog::getOpenFileName());
    lineAdressIN->setText(*adressIN);
}
void AddStream::slotAdressOUT()
{
    QString *adressOUT = new QString(QFileDialog::getSaveFileName());
    lineAdressOUT->setText(*adressOUT);
}
