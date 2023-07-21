#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>

int
main( int argc, char ** argv )
  {
  cv::VideoCapture cap(0);
  cv::Mat img;

  while( true )
  {
  cap.read( img );
  cv::imshow("Minha WebCam", img);
  cv::waitKey(1); //deixar no minimo 1 para nao ficar statico

  }

  return(0);
  } 

