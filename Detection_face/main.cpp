#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int
main(int argc, char ** argv)
  {
  std::string path = "./teste0.jpeg";
  cv::Mat img = cv::imread( path );

  cv::CascadeClassifier face_cascade;
  face_cascade.load("./haarcascade_frontalface_default.xml");
  
  if( face_cascade.empty() )
    {
    std::cerr << "Nao foi possivel ler o XML";	  
    return 1;
    }

  std::vector<cv::Rect> faces;
  face_cascade.detectMultiScale( img, faces );

  for (int i = 0; i < faces.size(); ++i)
    {
    cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(255,0,0), 4);
    }

  cv::imshow("Detectar Rosto", img);
  cv::waitKey(0);
  return(0);
  }

