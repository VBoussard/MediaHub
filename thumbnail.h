#ifndef THUMBNAIL_H
#define THUMBNAIL_H

#include <QWidget>
#include <QPushButton>

#include <engine.h>

class Thumbnail : public QWidget
{
    Q_OBJECT

private:
    QPushButton *m_pbPlay, *m_pbPause;
    QWidget *m_videoWidget;
    Engine *m_engine;

public:
    Thumbnail(Engine *_engine);
    ~Thumbnail();

    int getWinID();

private slots:
    void slotPlay();
    void slotPause();
};

#endif // THUMBNAIL_H
