#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int
main()
  {
  
  float w = 300, h = 500;
  std::string path = "./placa_oficial.jpg";
  cv::Mat img = cv::imread( path ), warp, img_cut;

// v1= 62,12
// v3= 63,328
// v2= 2,51
// v4= 251,312

  cv::Point2f src[4] = {{64,7}, {245, 48}, {63,339}, {253,315}};
  cv::Point2f des[4] = {{0,0},{w,0},{0,h},{w,h}};
  
  
  cv::warpPerspective(img, warp, cv::getPerspectiveTransform( src, des ), cv::Size( w, h ) );

  for(int i = 0; i < 4; i++)
    {
    cv::circle( img, cv::Point(src[i]), 10, cv::Scalar(0,0,0), 3); 
    } 

  cv::Rect cut ( 0, 2, w,h - 2 );

  img_cut = warp( cut ); 
  
  
  cv::imshow("Original", img);
  cv::imshow("Imagem Transformada", warp);
  cv::imshow("Imagem cortada", img_cut);
  cv::waitKey(0);
  return(0);
  }

