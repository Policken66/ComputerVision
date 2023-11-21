#ifndef INTERFACE_H
#define INTERFACE_H

//#include "processingopencv.h"
#include "mymat.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_btn_openFileDialog_clicked();

    void on_btn_execute_clicked();

    void on_slider_gaussBlur_valueChanged(int value);

    void on_slider_canny_valueChanged(int value);

private:
    Ui::Interface *ui;
    QImage *m_image;
    MyMat *m_mat;
};
#endif // INTERFACE_H
