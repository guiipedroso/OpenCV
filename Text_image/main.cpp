#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>
#include <tesseract/publictypes.h>

int
main(int argc, char ** argv)
  {
  
  if(argc <= 1)
    {
    std::cerr << "Informe uma imagem. Exemplo de uso: " << argv[0]  << " [nome-da-imagem] \n";
    return 1;
    } 

  std::string text, path = argv[1];
  cv::Mat img = cv::imread(path, cv::IMREAD_COLOR);

  tesseract::TessBaseAPI * ocr = new tesseract::TessBaseAPI();

  ocr->Init(NULL, "por", tesseract::OEM_LSTM_ONLY); //"eng" english - por "portuguese"
  ocr->SetPageSegMode(tesseract::PSM_AUTO);
  ocr->SetImage(img.data, img.cols, img.rows, 3, img.step);

  text = std::string( ocr->GetUTF8Text());

  std::cout << text;
  ocr->End();

  return(0);
  }
