#ifndef FENETRESERVEUR2_H
#define FENETRESERVEUR2_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>

class FenetreServeur2 : public QWidget
{
    Q_OBJECT

public:
    explicit FenetreServeur2(QWidget *parent = 0);


private:

    QPushButton *m_boutonAdd;
    QTabWidget *m_tabServeur;
public slots:
    void ajouterFlux();
};

#endif // FENETRESERVEUR2_H
