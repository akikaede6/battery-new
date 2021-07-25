#ifndef DRAW_H
#define DRAW_H
#include <QWidget>

class draw : public QWidget
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *);

private:
    int value{50};    //拖动电量
    int alarmvalue{30};  //红色电量值

    int board_angle{20};       //边框矩形圆角角度
    int back_angle{20};        //背景矩形圆角角度
    int head_angle{5};        //电池头部圆角角度

public slots:
    int getValue() const;
    void setValue(int value);
};

#endif // DRAW_H
