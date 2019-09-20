#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]){
    int zoom = 1;
    Mat img = imread("lena.png", CV_LOAD_IMAGE_COLOR);
    Mat img2 = Mat::zeros(img.size()*zoom, CV_8UC3);
    int wid = img.size().width;
    int hei = img.size().height;
    int wid2 = img2.size().width;
    int hei2 = img2.size().height;
    for(int i = 0;i < wid;i++){
        for(int j = 0;j < hei;j++){
            double k,l;
            k = i*zoom;
            l = j*zoom;
            int amp = 2; //Fator de ampliação
            img2.at<Vec3b>(k, l) = img.at<Vec3b>(i, j);
            img2.at<Vec3b>(k+amp, l) = img.at<Vec3b>(i, j);
            img2.at<Vec3b>(k, l+amp) = img.at<Vec3b>(i, j);
            img2.at<Vec3b>(k+amp, l+amp) = img.at<Vec3b>(i, j);
        }
    }

    namedWindow("Zoom", CV_WINDOW_AUTOSIZE);
    imshow("Zoom", img2);
    waitKey(0);
    return 0;
}