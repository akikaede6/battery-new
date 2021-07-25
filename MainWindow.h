#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class battery : public QMainWindow
{
    Q_OBJECT

public:
    battery(QWidget *parent = nullptr);
    ~battery();

};
#endif // MAINWINDOW_H
