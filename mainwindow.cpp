#include "mainwindow.h"
#include "fenetreserveur2.h"


MainWindow::MainWindow() : QWidget()
{

    QWidget *fenMain = new QWidget(this);
    QGridLayout *glMain = new QGridLayout;
    glMain->setSpacing(5);
    fenMain->setLayout(glMain);

    fenMain->setFixedSize(800, 600);
    fenMain->setWindowTitle("MediaHub");

    // Construction du bouton ADMIN
    m_boutonAdmin = new QPushButton("ADMINISTRATION", this);
    m_boutonAdmin->setMinimumHeight(100);
    m_boutonAdmin->setMaximumHeight(100);
    m_boutonAdmin->setMinimumWidth(300);
    m_boutonAdmin->setMaximumWidth(300);
    m_boutonAdmin->setFont(QFont("Arial", 16));
    m_boutonAdmin->setCursor(Qt::PointingHandCursor);
    //m_boutonAdmin->move(100, 200);
    glMain->addWidget(m_boutonAdmin,0,0);

    // Construction du bouton VISION
    m_boutonVision = new QPushButton("VISION", this);
    m_boutonVision->setMinimumHeight(100);
    m_boutonVision->setMaximumHeight(100);
    m_boutonVision->setMinimumWidth(300);
    m_boutonVision->setMaximumWidth(300);
    m_boutonVision->setFont(QFont("Arial", 16));
    m_boutonVision->setCursor(Qt::PointingHandCursor);
    //m_boutonVision->move(100, 300);
    glMain->addWidget(m_boutonVision,1,0);

    // Construction du bouton SERVEUR
    m_boutonServeur = new QPushButton("OP SERVEUR", this);
    m_boutonServeur->setMinimumHeight(100);
    m_boutonServeur->setMaximumHeight(100);
    m_boutonServeur->setMinimumWidth(300);
    m_boutonServeur->setMaximumWidth(300);
    m_boutonServeur->setFont(QFont("Arial", 16));
    m_boutonServeur->setCursor(Qt::PointingHandCursor);
    //m_boutonServeur->move(400, 200);
    glMain->addWidget(m_boutonServeur,0,1);

    // Construction du bouton SCRIPTE
    m_boutonScripte = new QPushButton("SCRIPTE", this);
    m_boutonScripte->setMinimumHeight(100);
    m_boutonScripte->setMaximumHeight(100);
    m_boutonScripte->setMinimumWidth(300);
    m_boutonScripte->setMaximumWidth(300);
    m_boutonScripte->setFont(QFont("Arial", 16));
    m_boutonScripte->setCursor(Qt::PointingHandCursor);
    //m_boutonScripte->move(400, 300);
    glMain->addWidget(m_boutonScripte,1,1);

    connect(m_boutonAdmin, SIGNAL(clicked()), this, SLOT(opServeur()));

}

void MainWindow::opServeur()
{
    FenetreServeur2 *Fenetre = new FenetreServeur2;
    Fenetre->show();
}
