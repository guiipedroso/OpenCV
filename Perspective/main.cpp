#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int
main()
  {
  float w = 900, h = 200;

  std::string path = "./memory.jpg";
  cv::Mat img = cv::imread( path ), warp, img_cut;
  

//v1 = 63, 579
//v2 = 811, 248
//v3 = 204, 749
//v4 = 949, 367

  cv::Point2f src[4] = { {63, 579}, {811,248}, {204,749}, {949,367} };
  cv::Point2f des[4] = { {0,0}, {w, 0}, {0, h}, {w, h} };

/*  for(int i = 0; i < 4; i++)
    {
    cv::circle( img, cv::Point(src[i]), 10, cv::Scalar(0,0,0), 3);
    }
*/
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

