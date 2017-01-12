#include "thumbnail.h"

#include <QFrame>
#include <QGridLayout>

Thumbnail::Thumbnail() : QWidget()
{
    m_pbPlay = new QPushButton("Play");
    m_pbPause = new QPushButton("Pause");
    m_videoWidget = new QWidget();

    QFrame *frame_thumb = new QFrame(this);
    frame_thumb->setFrameStyle(QFrame::Panel | QFrame::Raised);
    frame_thumb->setFixedHeight(180);
    QGridLayout *gl_thumb = new QGridLayout(frame_thumb);
    gl_thumb->addWidget(m_videoWidget, 0,0, 1,2);
    gl_thumb->addWidget(m_pbPlay,1,0);
    gl_thumb->addWidget(m_pbPause,1,1);

}

Thumbnail::~Thumbnail()
{

}

void Thumbnail::slotPlay()
{

}

void Thumbnail::slotPause()
{

}

int Thumbnail::getWinID()
{
    return ((int) m_videoWidget->winId());
}
