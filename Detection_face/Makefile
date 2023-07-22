TARGET=a.out
CXX=g++
LD=g++
OPENCV=-I/usr/include/opencv4 -g
CXXFLAGS=`pkg-config --cflags --libs opencv4`
all:
	$(CXX) $(OPENCV) main.cpp $(CXXFLAGS)
	@./$(TARGET)
