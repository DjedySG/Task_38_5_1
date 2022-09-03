#pragma once

#include <QtWidgets>
#include <QMediaPlayer>
//#include <QMediaContent>
#include <QTimer>

class Button : public QPushButton
{
    Q_OBJECT

public:
    Button(QWidget *parent);
    void paintEvent(QPaintEvent* e) override;
    void keyPressEvent(QKeyEvent* e) override;

public slots:
    void setDown();

private:
    QPixmap currentPixmap;
    QPixmap upPixmap;
    QPixmap downPixmap;
    QMediaPlayer* player = new QMediaPlayer(this);

};
