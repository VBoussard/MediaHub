#include "mainwindow.h"
#include "serverwin.h"


MainWindow::MainWindow() : QWidget()
{

    QWidget *fenMain = new QWidget(this);
    QGridLayout *glMain = new QGridLayout;
    glMain->setSpacing(5);
    fenMain->setLayout(glMain);

    fenMain->setFixedSize(800, 600);
    fenMain->setWindowTitle("MediaHub");

    // Construction du bouton ADMIN
    m_pbAdmin = new QPushButton("ADMINISTRATION", this);
    m_pbAdmin->setMinimumHeight(100);
    m_pbAdmin->setMaximumHeight(100);
    m_pbAdmin->setMinimumWidth(300);
    m_pbAdmin->setMaximumWidth(300);
    m_pbAdmin->setFont(QFont("Arial", 16));
    m_pbAdmin->setCursor(Qt::PointingHandCursor);
    //m_pbAdmin->move(100, 200);
    glMain->addWidget(m_pbAdmin,0,0);

    // Construction du bouton VISION
    m_pbVision = new QPushButton("VISION", this);
    m_pbVision->setMinimumHeight(100);
    m_pbVision->setMaximumHeight(100);
    m_pbVision->setMinimumWidth(300);
    m_pbVision->setMaximumWidth(300);
    m_pbVision->setFont(QFont("Arial", 16));
    m_pbVision->setCursor(Qt::PointingHandCursor);
    //m_pbVision->move(100, 300);
    glMain->addWidget(m_pbVision,1,0);

    // Construction du bouton SERVEUR
    m_pbServer = new QPushButton("OP SERVEUR", this);
    m_pbServer->setMinimumHeight(100);
    m_pbServer->setMaximumHeight(100);
    m_pbServer->setMinimumWidth(300);
    m_pbServer->setMaximumWidth(300);
    m_pbServer->setFont(QFont("Arial", 16));
    m_pbServer->setCursor(Qt::PointingHandCursor);
    //m_pbServer->move(400, 200);
    glMain->addWidget(m_pbServer,0,1);

    // Construction du bouton SCRIPTE
    m_pbScripte = new QPushButton("SCRIPTE", this);
    m_pbScripte->setMinimumHeight(100);
    m_pbScripte->setMaximumHeight(100);
    m_pbScripte->setMinimumWidth(300);
    m_pbScripte->setMaximumWidth(300);
    m_pbScripte->setFont(QFont("Arial", 16));
    m_pbScripte->setCursor(Qt::PointingHandCursor);
    //m_pbScripte->move(400, 300);
    glMain->addWidget(m_pbScripte,1,1);

    connect(m_pbAdmin, SIGNAL(clicked()), this, SLOT(opServeur()));

}

void MainWindow::opServeur()
{
    FenetreServeur2 *Fenetre = new FenetreServeur2;
    Fenetre->show();
}
