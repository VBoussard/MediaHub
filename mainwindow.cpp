#include "mainwindow.h"
#include "serverwin.h"

#include <QSpacerItem>

MainWindow::MainWindow(Engine *_engine) : QWidget()
{
    m_engine = _engine;

    QWidget *fenMain = new QWidget(this);
    QGridLayout *glMain = new QGridLayout;
    glMain->setSpacing(5);
    glMain->setAlignment(fenMain, Qt::AlignCenter);
    fenMain->setLayout(glMain);

    //QSpacerItem spacerTop, spacerBottom, spacerLeft, spacerRight;
    QSpacerItem *spacerTop = new QSpacerItem(100,100,QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem *spacerBottom = new QSpacerItem(100,100,QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem *spacerLeft = new QSpacerItem(100,100,QSizePolicy::Expanding, QSizePolicy::Expanding);
    QSpacerItem *spacerRight = new QSpacerItem(100,100,QSizePolicy::Expanding, QSizePolicy::Expanding);
    glMain->addItem(spacerTop,0,0,1,4);
    glMain->addItem(spacerRight, 0,1,1,2);
    glMain->addItem(spacerLeft,3,1,1,2);
    glMain->addItem(spacerBottom,0,3,1,4);

    //fenMain->setFixedSize(800, 600);
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
    glMain->addWidget(m_pbAdmin,1,1);

    // Construction du bouton VISION
    m_pbVision = new QPushButton("VISION", this);
    m_pbVision->setMinimumHeight(100);
    m_pbVision->setMaximumHeight(100);
    m_pbVision->setMinimumWidth(300);
    m_pbVision->setMaximumWidth(300);
    m_pbVision->setFont(QFont("Arial", 16));
    m_pbVision->setCursor(Qt::PointingHandCursor);
    //m_pbVision->move(100, 300);
    glMain->addWidget(m_pbVision,2,1);

    // Construction du bouton SERVEUR
    m_pbServer = new QPushButton("OP SERVEUR", this);
    m_pbServer->setMinimumHeight(100);
    m_pbServer->setMaximumHeight(100);
    m_pbServer->setMinimumWidth(300);
    m_pbServer->setMaximumWidth(300);
    m_pbServer->setFont(QFont("Arial", 16));
    m_pbServer->setCursor(Qt::PointingHandCursor);
    //m_pbServer->move(400, 200);
    glMain->addWidget(m_pbServer,1,2);

    // Construction du bouton SCRIPTE
    m_pbScript = new QPushButton("SCRIPTE", this);
    m_pbScript->setMinimumHeight(100);
    m_pbScript->setMaximumHeight(100);
    m_pbScript->setMinimumWidth(300);
    m_pbScript->setMaximumWidth(300);
    m_pbScript->setFont(QFont("Arial", 16));
    m_pbScript->setCursor(Qt::PointingHandCursor);
    //m_pbScript->move(400, 300);
    glMain->addWidget(m_pbScript,2,2);

    connect(m_pbAdmin, SIGNAL(clicked()), this, SLOT(slotServer()));

}

MainWindow::~MainWindow()
{
    //delete m_engine;
}

void MainWindow::slotServer()
{
    ServerWin *Fenetre = new ServerWin(m_engine);
    Fenetre->show();
}


void MainWindow::slotAdmin()
{

}

void MainWindow::slotVision()
{

}

void MainWindow::slotScript()
{

}
