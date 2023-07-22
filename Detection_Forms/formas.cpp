#include "formas.hpp"

//construtor
Formas::Formas() {
  path = "./formas.jpg";
  img = cv::imread( path );

  cv::Canny( img, img_canny, 0, 200 );
  nucleo = cv::getStructuringElement( 0, cv::Size( 3,3 ) );
  cv::dilate( img_canny, img_dilatada, nucleo );
}
 
Formas::~Formas(){
  cv::waitKey(0);
}

void
Formas::desenhar_nas_formas(){
  
  cv::findContours( img_dilatada, contornos, hierarquia, 0, 2 );
//  cv::drawContours( img, contornos, -1, cv::Scalar(147,20,255), 2 ); //BGR e nao RGB
  
  for(size_t i = 0; i < contornos.size(); i++)
    {
    int area = cv::contourArea(contornos[i]);
    
    if( area != 0 )
      {
      cv::drawContours( img, contornos, i, cv::Scalar( 147, 20, 255 ), 2 ); //BGR 
      }
    std::cout << "Area: " << area << '\n';
    }
  cv::imshow( "Original", img );
//  cv::imshow("Canny", img_canny);
//  cv::imshow("Dilatada", img_dilatada);
}

