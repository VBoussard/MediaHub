#ifndef ADDSTREAM_H
#define ADDSTREAM_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

class AddStream : public QWidget
{
    Q_OBJECT

public:
    explicit AddStream(QWidget *parent = 0);

private:
    QLabel *m_labelIO;
    QPushButton *m_boutonIN, *m_boutonOUT, *m_boutonQuit;

private slots:
    void Annuler();
    void Entree();
    void Sortie();
};

#endif // ADDSTREAM_H
