#ifndef AJOUTFLUX_H
#define AJOUTFLUX_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class AjoutFlux : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutFlux(QWidget *parent = 0);

private:
    QLabel *m_labelIO;
    QPushButton *m_boutonIN, *m_boutonOUT, *m_boutonQuit;

private slots:
    void Annuler();
    void Entree();
    void Sortie();
};

#endif // AJOUTFLUX_H
