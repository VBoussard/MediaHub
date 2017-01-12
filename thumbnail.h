#ifndef THUMBNAIL_H
#define THUMBNAIL_H

#include <QWidget>
#include <QPushButton>

class Thumbnail : public QWidget
{
    Q_OBJECT

private:
    QPushButton *m_pbPlay, *m_pbPause;
    QWidget *m_videoWidget;

public:
    Thumbnail();
    ~Thumbnail();

private slots:
    void slotPlay();
    void slotPause();
};

#endif // THUMBNAIL_H
