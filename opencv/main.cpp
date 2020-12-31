#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using namespace cv;

int main(){
    std::string path = "test.jpg";
    Mat img = imread(path);
    imshow("Image", img);
    waitKey(0);
    return 0;
}