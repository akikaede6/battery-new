#include "draw.h"
#include "MainWindow.h"

#include <QPainter>

void draw::paintEvent(QPaintEvent *) {
    QPainter *painter = new QPainter(this);
    painter->setRenderHint(QPainter::Antialiasing, true);
    QLinearGradient linearGradient_body(100, 100, 100, 200);
    QLinearGradient linearGradient_head(10,10,100,100);//设置垂直渐变

    painter->setPen(QPen(Qt::black, 4));//设置画笔形式
    painter->drawRoundedRect(QRect(30, 40, 310, 200), board_angle, board_angle);//画电池本体
    painter->setRenderHint(QPainter::Antialiasing, false);

    linearGradient_head.setColorAt(1.0,Qt::black);//设置电池头填充色
    painter->setBrush(QBrush(linearGradient_head)); //设置填充形式
    painter->drawRoundedRect(QRect(340, 115, 20, 50), head_angle, head_angle);//画电池头

    if (value < alarmvalue) {
        painter->setPen(QPen(Qt::white, 2));
        painter->setBrush(QBrush(linearGradient_body));//设置填充形式
        linearGradient_body.setColorAt(0.5, Qt::red);
        linearGradient_body.setColorAt(1, Qt::black);//设置电池颜色填充色
        painter->setBrush(QBrush(linearGradient_body));//设置填充形式
        painter->drawRoundedRect(QRect(35, 45, 3 * value, 190), back_angle, back_angle);//画电池填充色
    } else {
        painter->setPen(QPen(Qt::white, 2));
        linearGradient_body.setColorAt(0.5, Qt::green);
        linearGradient_body.setColorAt(1, Qt::black);//设置电池颜色填充色
        painter->setBrush(QBrush(linearGradient_body));//设置填充形式
        painter->drawRoundedRect(QRect(35, 45, 3 * value, 190), back_angle, back_angle);//画电池填充色
    }
    painter->end();
}
