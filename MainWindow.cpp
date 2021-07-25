#include "MainWindow.h"
#include "draw.h"

#include <QVBoxLayout>
#include <QSlider>

battery::battery(QWidget *parent)
    : QMainWindow(parent)
{
    int minvalue = 0;             //电池最小电量
    int maxvalue = 100;           //电池最大电量
    int step = 1;                 //电池移动步长

    QWidget *window = new QWidget(this);
    QSlider *slider = new QSlider(Qt::Horizontal);
    QVBoxLayout *layout = new QVBoxLayout;
    draw *DrawBattery = new draw;

    slider->setMinimum(minvalue);
    slider->setMaximum(maxvalue);
    slider->setSingleStep(step);
    slider->setValue(DrawBattery->getValue());

    connect(slider, &QSlider::valueChanged, DrawBattery, &draw::setValue);

    layout->addWidget(DrawBattery);
    layout->addWidget(slider);
    window->setLayout(layout);
    setCentralWidget(window);
}

battery::~battery()
{
}

int draw::getValue() const {
    return value;
}

void draw::setValue(int value) {
    this->value = value;
    update();
}
