#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QMainWindow>

#include "cameradevice.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void graphOscill_AddPath(QPainterPath *path);
    void graphImage_AddImage(QImage *im);

protected:
    void changeEvent(QEvent *e);

private slots:
    void buttonStartStop();

private:
    Ui::MainWindow *ui;
    CameraDevice *camDevice;
};

#endif // MAINWINDOW_H
