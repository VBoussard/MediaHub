#include "thumbnail.h"

#include <QFrame>
#include <QGridLayout>

Thumbnail::Thumbnail(Engine *_engine) : QWidget()
{
    m_engine = _engine;
    m_pbPlay = new QPushButton("Play");
    connect(m_pbPlay, SIGNAL(clicked()), this, SLOT(slotPlay()));
    m_pbPause = new QPushButton("Pause");
    connect(m_pbPause, SIGNAL(clicked()), this, SLOT(slotPause()));
    m_videoWidget = new QWidget();

    m_struct = new structStream;

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
    m_struct->S_stream->play();
}

void Thumbnail::slotPause()
{
    m_struct->S_stream->pause();
}

int Thumbnail::getWinID()
{
    return ((int) m_videoWidget->winId());
}

void Thumbnail::linkToStream(structStream *_struct)
{
    m_struct = _struct;
}
