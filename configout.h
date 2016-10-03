#ifndef CONFIGOUT_H
#define CONFIGOUT_H

#include <QMainWindow>

#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

class configOUT : public QMainWindow
{
    Q_OBJECT

public:
    configOUT(QWidget *parent = 0);
    ~configOUT();
protected:
    QRadioButton *radioSortiePhy;
    QRadioButton *radioSortieStr;

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

    //test push
    //Ajout de Lucas

};

#endif // CONFIGOUT_H
