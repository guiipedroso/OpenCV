#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>

int
main(int argc, char ** argv)
  {
  cv::VideoCapture cap ( 0 );

  cv::Mat img;

  cv::CascadeClassifier placas_cascade;
  placas_cascade.load("./haarcascade_russian_plate_number.xml");
  
  if( placas_cascade.empty() )
    {
    std::cerr << "Nao foi possivel abrir o video";	  
    return 1;
    }

  std::vector<cv::Rect> placas;


  while ( true )
    {
    cap.read(img);	    
    placas_cascade.detectMultiScale( img, placas );
    
    
  for (int i = 0; i < placas.size(); ++i)
    {
    cv::rectangle(img, placas[i].tl(), placas[i].br(), cv::Scalar(0,0,255), 4);
    cv::Mat imagem_cortada = img( placas[i] );
    // imshow(std::to_string(i), imagem_cortada);
    cv::imwrite("./" + std::to_string(i) + " placa-detectada.png", imagem_cortada);
    }
    
    cv::imshow("Detectar placas", img);
    cv::waitKey(1);	  
    }

  return(0);
  }

