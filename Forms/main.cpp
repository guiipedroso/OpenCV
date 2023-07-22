#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int
main()
  {
  cv::Mat img(720, 1280, CV_8UC3, cv::Scalar( 147, 0, 255 ));
  cv::circle(img, cv::Point( 250, 250 ), 200, cv::Scalar(0, 0, 255), cv::FILLED); //negativo preenche o circle 

  cv::rectangle( img, cv::Point( 100, 100 ), cv::Point(400, 400), cv::Scalar(0, 0, 0) ); // retangulo

  cv::line( img, cv::Point( 0, 0 ), cv::Point( 400, 400 ), cv::Scalar(36,90,63), 5 ); // colocando linha

  cv::line( img, cv::Point(200, 0), cv::Point( 400, 400 ), cv::Scalar(36,90,63), 5 ); //colocando linha
 
  cv::putText( img, "Follow me Try Hack Me", cv::Point (500, 500), cv::QT_FONT_NORMAL, 2, cv::Scalar(255, 255, 255), 5); 

  std::cout << "Numero = " << cv::FILLED << '\n';
  cv::imshow("Fundo", img);
  cv::waitKey(0);
  return(0);
  }

