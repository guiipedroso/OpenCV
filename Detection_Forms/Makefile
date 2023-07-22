TARGET=a.out
CXX=g++
LD=g++
OPENCV=-I/usr/include/opencv4 -g
CXXFLAGS=-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -std=c++11
all:
	$(CXX) $(OPENCV) main.cpp formas.cpp $(CXXFLAGS)
	@./$(TARGET)
