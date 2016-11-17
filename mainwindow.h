#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "engine.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QApplication>


class MainWindow : public QWidget
{
    Q_OBJECT

private:
    Engine* m_engine;
    QPushButton *m_pbAdmin, *m_pbVision, *m_pbServer, *m_pbScript;

public:
    explicit MainWindow(Engine* _engine);

public slots :
    void slotServer();
    void slotAdmin();
    void slotVision();
    void slotScript();

};

#endif // MAINWINDOW_H

