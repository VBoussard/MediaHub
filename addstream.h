#ifndef ADDSTREAM_H
#define ADDSTREAM_H

#include <QWidget>
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>

#include "engine.h"

class AddStream : public QDialog
{
    Q_OBJECT

public:
    explicit AddStream(Engine *moteur, int _idWinView[]);
    ~AddStream();

     const char *getSource();

protected:
    //Config IN
    QRadioButton *radioEntreePhy, *radioEntreeStr;

    QComboBox *comboNumCarteIN, *comboProfilIN;
    QLineEdit *lineNomIN, *lineAdressIN;
    QPushButton *boutonAdressIN, *boutonParamVidIN, *boutonParamAudIN;


    //Config OUT
    QRadioButton *radioSortiePhy, *radioSortieStr;

    QComboBox *comboNumCarteOUT, *comboProfilOUT;
    QLineEdit *lineNomOUT, *lineAdressOUT;
    QPushButton *boutonAdressOUT, *boutonParamVidOUT, *boutonParamAudOUT;

    const char* nomSource;



private:
    Engine *m_moteur;
    QPushButton *m_pbValid, *m_pbCancel;
    int m_idWinView[8];

    //Config IN
    QString choixCarte, profil;

    //const char* C_choixCarte, C_profil, C_nomSource;

    //const char* S_choixCarte, S_profil, S_nomSource;

    int m_numFlux;


private slots:
    void Annuler();
    void Valider();
    void slotAdressIN();
    void slotAdressOUT();

};

#endif // ADDSTREAM_H
