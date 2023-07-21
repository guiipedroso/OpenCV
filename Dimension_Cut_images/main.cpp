#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

int
main()
  {
  std::string path = "./minha_foto.jpeg";
  cv::Mat img = cv::imread( path ), img_resize, img_cut;

  std::cout << "Dimensoes da minha imagem: " << img.size() << '\n';
  std::cout << "Largura da minha imagem: " << img.size().width << '\n';
  std::cout << "Altura da minha imagem: " <<img.size().height << '\n';
  
  img_cut = img(cv::Rect(0, 0, img.size().width / 2, img.size().height / 2) );

  cv::resize( img, img_resize, cv::Size(img.size().width / 2, img.size().height / 2) );

  // cv::resize( img, img_resize, cv::Size(), 0.5, 0.5, cv::INTER_BITS );

  cv::imshow("Original", img);
  cv::imshow("Redimencionada", img_resize);
  cv::imshow("Cortada", img_cut);
  cv::waitKey(0);
  return(0);
  }

