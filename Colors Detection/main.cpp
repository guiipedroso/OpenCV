#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int
main( int argc, char ** argv )
  {

  int matiz_min = 18, matiz_max = 34, // 20 , 170
      saturacao_min = 190, saturacao_max = 255,
      brilho_min = 21, brilho_max = 255;

  std::string path = "./tux.jpg";

  cv::Mat img = cv::imread( path ), img_hsv, img_mask;

  cv::cvtColor( img, img_hsv, cv::COLOR_BGR2HSV );

  cv::namedWindow("Barra de seleção", cv::WINDOW_AUTOSIZE);

  cv::createTrackbar("Matiz mínima", "Barra de seleção", &matiz_min, 255);
  cv::createTrackbar("Matiz máxima", "Barra de seleção", &matiz_max, 255);

  cv::createTrackbar("Saturação mínima", "Barra de seleção", &saturacao_min, 255);
  cv::createTrackbar("Saturação máxima", "Barra de seleção", &saturacao_max, 255);

  cv::createTrackbar("Brilho mínimo", "Barra de seleção", &brilho_min, 255);
  cv::createTrackbar("Brilho máximo", "Barra de seleção", &brilho_max, 255);

  while( true )
    {
    cv::Scalar min( matiz_min, saturacao_min, brilho_min );
    cv::Scalar max( matiz_max, saturacao_max, brilho_max );

    cv::inRange( img_hsv, min, max, img_mask );

    cv::imshow("Imagem Original", img);
    //cv::imshow("Imagem HSV", img_hsv);
    cv::imshow("Imagem Binária", img_mask );

    cv::waitKey( 1 );
    }
  
  return 0;
  }

