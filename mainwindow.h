#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QApplication>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow();

public slots :
    void opServeur();

private:
    QPushButton *m_boutonAdmin, *m_boutonVision, *m_boutonServeur, *m_boutonScripte;
};

#endif // MAINWINDOW_H

