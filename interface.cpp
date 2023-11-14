#include "interface.h"
#include "ui_interface.h"

bool cannyProcOn = false;

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    ui->slider_gaussBlur->hide();
    ui->label_gaussBlurValue->hide();
    ui->slider_canny->hide();
}

Interface::~Interface()
{
    delete ui;
}


void Interface::on_btn_openFileDialog_clicked()
{
    //Переменная для пути к файлу
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Open Document", "", "*.png || *.jpg || *.jpeg");

    //Загружаем изображение по указанному пути
    m_image.load(filename);

    //Устанавливаем изображение в label_image
    ui->label_image->setPixmap(QPixmap::fromImage(m_image));
    ui->label_image->setScaledContents(true);

    //Рассчитываем новые размеры для label_image на основе
    //переданного изображения и текущей ширина label_image
    int pixWidth = m_image.width();
    int pixHeight = m_image.height();
    int label_pictureWindowWidth = ui->label_image->width();
    double factor = double(label_pictureWindowWidth)/pixWidth;

    //Устанавливаем новые размеры label_image
    ui->label_image->setFixedWidth(factor * pixWidth);
    ui->label_image->setFixedHeight(factor * pixHeight);
    m_object.setCurrentImage(m_image);
}


void Interface::on_btn_execute_clicked()
{
    //comboBox установлен на GaussianBlur
    if(ui->comboBox->currentIndex() == 0)
    {
        //ui->label_image->setPixmap(QPixmap::fromImage(m_object.gaussianBlur(0)));
        ui->slider_canny->hide();
        cannyProcOn = false;
        ui->slider_gaussBlur->show();
        ui->label_gaussBlurValue->show();
        ui->label_gaussBlurValue->setText(QString::number(0));
    }

    //comboBox установлен на Canny
    if(ui->comboBox->currentIndex() == 1)
    {
        ui->slider_canny->show();
        cannyProcOn = true;
    }

}


void Interface::on_slider_gaussBlur_valueChanged(int value)
{

    double sigmaX = ((double)value)/20;
    if(!cannyProcOn) {
        ui->label_image->setPixmap(QPixmap::fromImage(m_object.gaussianBlur(sigmaX)));
    } else if(cannyProcOn) {
        m_object.gaussianBlur(sigmaX);
        ui->label_image->setPixmap((QPixmap::fromImage(m_object.cannyAlgorithm(ui->slider_canny->sliderPosition()))));
    }
    ui->label_gaussBlurValue->setText(QString::number(sigmaX));
}


void Interface::on_slider_canny_valueChanged(int value)
{
    ui->label_image->setPixmap((QPixmap::fromImage(m_object.cannyAlgorithm(value))));
}

