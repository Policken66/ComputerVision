#include "mymat.h"

MyMat::MyMat()
{
    m_mat = new cv::Mat;
}

MyMat::MyMat(const QImage &image)
{
    m_mat = new cv::Mat;
    m_mat = qImageToCvMat(image);
}

MyMat::~MyMat()
{
    delete m_mat;
}

void MyMat::setQImage(const QImage &image)
{
    m_mat = qImageToCvMat(image);
}

cv::Mat MyMat::gaussianBlur(double sigmaX)
{
    cv::Mat gaussianBlurImage;
    cv::Size kernelSize(5,5);
    cv::GaussianBlur(*m_mat, gaussianBlurImage, kernelSize, sigmaX);
    return gaussianBlurImage;
}

cv::Mat MyMat::cannyAlgorithm(int lowThreshold, double sigmaX)
{
    cv::Mat detected_edges;
    cv::Mat gaussianBlurImage;
    cv::Mat cannyImage;
    cv::Mat currentImage;
    gaussianBlurImage = gaussianBlur(sigmaX);
    const int ratio = 3;
    const int kernel_size = 3;

    cv::cvtColor(gaussianBlurImage, detected_edges, cv::COLOR_BGR2GRAY);
    cv::Canny(detected_edges, detected_edges,
              lowThreshold, lowThreshold*ratio,
              kernel_size );
    cannyImage = cv::Scalar::all(0);
    m_mat->copyTo(cannyImage, detected_edges);

    return cannyImage;
}
