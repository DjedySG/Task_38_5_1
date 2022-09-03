#include "button.h"
#include <QMediaPlayer>

Button::Button(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    upPixmap = QPixmap("button_up.png");
    downPixmap = QPixmap("button_down.png");
    currentPixmap = upPixmap;
    setGeometry(currentPixmap.rect());

    connect(this, &QPushButton::clicked, this, &Button::setDown);

    player->setSource(QUrl::fromLocalFile("clicked.mp3"));



}
void Button::paintEvent(QPaintEvent* e) {
    QPainter paint(this);
    paint.drawPixmap(e->rect(), currentPixmap);

}
void Button::keyPressEvent(QKeyEvent* event) {
    setDown();

}
void Button::setDown() {
    currentPixmap = downPixmap;
    update();
    player->play();
    QTimer::singleShot(150, [this]() {
    currentPixmap = upPixmap;
    update();
    });

}
