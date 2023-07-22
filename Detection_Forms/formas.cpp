#include "formas.hpp"

//construtor
Formas::Formas() {
  path = "./teste.jpeg";
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
  
  lados = contornos;
  retangulo.resize( contornos.size());

  for(size_t i = 0; i < contornos.size(); ++i)
    {
    int area = cv::contourArea(contornos[i]);
    perimetro = cv::arcLength( contornos[i], true ); 
    cv::approxPolyDP(contornos[i], lados[i], 0.03*perimetro, true);
    cv::drawContours( img, lados, i, cv::Scalar(0,20,0), 2 );
    retangulo[i] = cv::boundingRect( lados[i] );
    cv::rectangle (img, retangulo[i].tl(), retangulo[i].br(), cv::Scalar(0,140,255), 4 );

    /*
    if( area != 0 )
      {
      cv::drawContours( img, contornos, i, cv::Scalar( 147, 20, 255 ), 2 ); //BGR
      }
    */

    if( lados[i].size() == 3 )
      {
      nome_da_forma = "Triangulo";
      }     
    else if( lados[i].size() == 4 )
      {
      if( retangulo[i].width == retangulo[i].height )
        {
        nome_da_forma = "Quadrado";	    
        }
      else
        {
        nome_da_forma = "Retangulo";	    
        }
      }
    else if( lados[i].size() > 4 )
      {
      nome_da_forma = "Circulo";
      }
    
    putText( img, nome_da_forma, cv::Point( retangulo[i].x, retangulo[i].y ), cv::QT_FONT_NORMAL, 1, cv::Scalar(255, 255, 255), 2 );
     

    std::cout << "Area: " << area << " " << " | Qtd. de lados " << lados[i].size() << '\n';

    }
  cv::imshow( "Original", img );
//  cv::imshow("Canny", img_canny);
//  cv::imshow("Dilatada", img_dilatada);
}

