#ifndef MYMAT_H
#define MYMAT_H

#include "opencv2/opencv.hpp"
#include <QImage>

class MyMat : public cv::Mat
{
public:
    MyMat();
    MyMat(const QImage &image);
    ~MyMat();
    void setQImage(const QImage &image);
    cv::Mat gaussianBlur(double sigmaX);
    cv::Mat cannyAlgorithm(int lowThreshold, double sigmaX);
    static cv::Mat* qImageToCvMat(const QImage &image)
    {
        return new cv::Mat(image.height(), image.width(),
                           CV_8UC4,
                           const_cast<uchar*>(image.bits()),
                           image.bytesPerLine()
                           );
    }
    static QImage cvMatToQImage(const cv::Mat &mat)
    {
        return QImage(mat.data, mat.cols,
                      mat.rows, mat.step,
                      QImage::Format_ARGB32
                      );
    }

private:
    cv::Mat *m_mat;
};

#endif // MYMAT_H
