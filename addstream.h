#ifndef ADDSTREAM_H
#define ADDSTREAM_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include "engine.h"

class AddStream : public QWidget
{
    Q_OBJECT

public:
    explicit AddStream(QWidget *parent = 0, Engine *moteur = NULL);
    ~AddStream();

private:
    QLabel *m_labelIO;
    QPushButton *m_boutonIN, *m_boutonOUT, *m_boutonQuit;
    Engine *m_moteur;

private slots:
    void Annuler();
    void Entree();
    void Sortie();
};

#endif // ADDSTREAM_H
