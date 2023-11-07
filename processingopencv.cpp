#include "processingopencv.h"

//конвертируем QImage в cv::mat
cv::Mat qImageToCvMat(const QImage &image)
{
    return cv::Mat(image.height(), image.width(), CV_8UC4,
                   const_cast<uchar*>(image.bits()), image.bytesPerLine());
}

//конвертируем cv::mat в QImage
QImage cvMatToQImage(const cv::Mat &mat)
{
    return QImage(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
}

processingOpenCV::processingOpenCV()
{}

//конструктор с одним параметром
processingOpenCV::processingOpenCV(const QImage &image)
{
    currentImage = qImageToCvMat(image);
    cannyImage.create(currentImage.size(), currentImage.type() );
}

//метод позволяющий загрузить QImage в объект
void processingOpenCV::setCurrentImage(const QImage &image)
{
    currentImage = qImageToCvMat(image);
}

//размытие по гауссу
QImage processingOpenCV::gaussianBlur(double sigmaX)
{
    cv::Size kernelSize(5,5);
    cv::GaussianBlur(currentImage, gaussianBlurImage, kernelSize, sigmaX);
    QImage outputImage = cvMatToQImage(gaussianBlurImage);
    return outputImage;
}

QImage processingOpenCV::cannyAlgorithm(int lowThreshold)
{
    cv::Mat detected_edges;
    const int ratio = 3;
    const int kernel_size = 3;

    cv::cvtColor(gaussianBlurImage, detected_edges, cv::COLOR_BGR2GRAY);
    cv::Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    cannyImage = cv::Scalar::all(0);
    currentImage.copyTo(cannyImage, detected_edges);
    QImage outputImage = cvMatToQImage(cannyImage);

    return outputImage;
}
