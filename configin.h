#ifndef CONFIGIN_H
#define CONFIGIN_H

#include <QMainWindow>

#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

class configIN : public QMainWindow
{
    Q_OBJECT

public:
    configIN(QWidget *parent = 0);
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
    QPushButton *boutonSuiv;
};

#endif // CONFIGIN_H
