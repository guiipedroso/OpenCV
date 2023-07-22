#ifndef FORMAS_H
#define FORMAS_H
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <iostream>

class Formas{
  public:
    Formas();
    ~Formas(); //destrutor

    cv::String path, nome_da_forma;
    cv::Mat img, img_dilatada, img_canny, nucleo;

    std::vector<std::vector<cv::Point>> contornos, lados;
    std::vector<cv::Vec4i> hierarquia;
    std::vector<cv::Rect> retangulo;

    void desenhar_nas_formas();
    float perimetro;
};




#endif 
