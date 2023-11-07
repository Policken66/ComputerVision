#ifndef PROCESSINGOPENCV_H
#define PROCESSINGOPENCV_H

#include <QImage>
#include <QDebug>

#include "opencv2/opencv.hpp"


class processingOpenCV
{
public:
    processingOpenCV();
    processingOpenCV(const QImage &image);
    void setCurrentImage(const QImage &image);
    QImage gaussianBlur(double sigmaX);
    QImage cannyAlgorithm(int lowThashold);
private:
    cv::Mat currentImage;
    cv::Mat gaussianBlurImage;
    cv::Mat cannyImage;


};

#endif // PROCESSINGOPENCV_H
