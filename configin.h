#ifndef CONFIGIN_H
#define CONFIGIN_H

#include <QMainWindow>

#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "engine.h"

class configIN : public QMainWindow
{
    Q_OBJECT

public:
    explicit configIN(QWidget *parent = 0, Engine *moteur);
    ~configIN();

protected:
    QRadioButton *radioEntreePhy;
    QRadioButton *radioEntreeStr;

    QComboBox *comboNumCarte;
    QComboBox *comboProfil;
    QLineEdit *lineNom;

    QLineEdit *lineAdress;
    QPushButton *boutonAdress;
    QPushButton *boutonParamVid;
    QPushButton *boutonParamAud;

    QPushButton *boutonAnnul;
    QPushButton *boutonPrec;
    QPushButton *boutonTerm;

private:
    QString choixCarte;
    QString profil;
    QString nomSource;
    Engine *m_moteur;

    const char* C_choixCarte;
    const char* C_profil;
    const char* C_nomSource;

    const char* S_choixCarte;
    const char* S_profil;
    const char* S_nomSource;

    int m_numFlux;

private slots:
    void Annuler();
    void ParamAudio();
    void ParamVideo();
    void Next();
};

#endif // CONFIGIN_H
