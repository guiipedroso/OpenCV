#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int
main( int argv, char **argc )
  {
  std::string path = "./minha_foto.jpeg";
  cv::Mat img = cv::imread( path );
  cv::Mat img_rainbow;
  cv::Mat img_bw, img_gaussian, img_canny, img_canny_dilate, img_erode, img_plasma;

//  cv::cvtColor ( img, img_rainbow, cv::COLORMAP_RAINBOW );
//  cv::cvtColor (img, img_rainbow, cv::COLORMAP_PLASMA ); //error
//  cv::cvtColor ( img, img_bw, 6 );
//  cv::GaussianBlur( img, img_gaussian, cv::Size(7, 7), 7 );
  cv::Canny(img, img_canny, 6, 93);
//  cv::dilate(img, img_canny_dilate, cv::getStructuringElement(2, cv::Size(4, 4) ) ); //dilatar

//  cv::erode( img_canny, img_erode, cv::getStructuringElement(1, cv::Size( 2,2) ) );

  cv::imshow("Original", img);
//  cv::imshow("Rainbow", img_rainbow);
//  cv::imshow("Aleatoria", img_bw);
//  cv::imshow("Gaussian Blur", img_gaussian);
//  cv::imshow("Canny", img_canny);
//  cv::imshow("Canny Dilate", img_canny_dilate); 
//  cv::imshow("Erode", img_erode); //erosao
  cv::waitKey(0);
  return(0);	
  }
