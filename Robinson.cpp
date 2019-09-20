#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;




int xgradiente(Mat imagem, int x, int y){

int xgrade = 0;

xgrade = imagem.at<uchar>(y-1,x-1) * 1;
xgrade = xgrade +  imagem.at<uchar>(y,x-1) * 2;
xgrade = xgrade +  imagem.at<uchar>(y+1,x-1) * 1;
xgrade = xgrade +  imagem.at<uchar>(y-1,x) * 0;
xgrade = xgrade +  imagem.at<uchar>(y,x) * 0;
xgrade = xgrade +  imagem.at<uchar>(y+1,x) * 0;
xgrade = xgrade +  imagem.at<uchar>(y-1,x+1) * (-1);
xgrade = xgrade +  imagem.at<uchar>(y,x+1) * (-2);
xgrade = xgrade +  imagem.at<uchar>(y+1,x+1) * (-1);

xgrade = xgrade + imagem.at<uchar>(y-1,x-1) * 2;
xgrade = xgrade +  imagem.at<uchar>(y,x-1) * 1;
xgrade = xgrade +  imagem.at<uchar>(y+1,x-1) * 0;
xgrade = xgrade +  imagem.at<uchar>(y-1,x) * 1;
xgrade = xgrade +  imagem.at<uchar>(y,x) * 0;
xgrade = xgrade +  imagem.at<uchar>(y+1,x) * (-1);
xgrade = xgrade +  imagem.at<uchar>(y-1,x+1) * 0;
xgrade = xgrade +  imagem.at<uchar>(y,x+1) * (-1);
xgrade = xgrade +  imagem.at<uchar>(y+1,x+1) * 2;


xgrade = xgrade + imagem.at<uchar>(y-1,x-1) * 1;
xgrade = xgrade +  imagem.at<uchar>(y,x-1) * 0;
xgrade = xgrade +  imagem.at<uchar>(y+1,x-1) * (-1);
xgrade = xgrade +  imagem.at<uchar>(y-1,x) * 2;
xgrade = xgrade +  imagem.at<uchar>(y,x) * 0;
xgrade = xgrade +  imagem.at<uchar>(y+1,x) * (-2);
xgrade = xgrade +  imagem.at<uchar>(y-1,x+1) * 1;
xgrade = xgrade +  imagem.at<uchar>(y,x+1) * 0;
xgrade = xgrade +  imagem.at<uchar>(y+1,x+1) * (-1);



xgrade = xgrade +  imagem.at<uchar>(y-1,x-1) * 0;
xgrade = xgrade +  imagem.at<uchar>(y,x-1) * (-1);
xgrade = xgrade +  imagem.at<uchar>(y+1,x-1) * (-2);
xgrade = xgrade +  imagem.at<uchar>(y-1,x) * 1;
xgrade = xgrade +  imagem.at<uchar>(y,x) * 0;
xgrade = xgrade +  imagem.at<uchar>(y+1,x) * (-1);
xgrade = xgrade +  imagem.at<uchar>(y-1,x+1) * 2;
xgrade = xgrade +  imagem.at<uchar>(y,x+1) * 1;
xgrade = xgrade +  imagem.at<uchar>(y+1,x+1) * 0;


             
return xgrade;
             
}


int ygradiente(Mat imagem, int x, int y){
int ygrade =0;
ygrade = imagem.at<uchar>(y-1,x-1) * 2;
ygrade = ygrade +  imagem.at<uchar>(y,x-1) * 1;
ygrade = ygrade +  imagem.at<uchar>(y+1,x-1) * 0;
ygrade = ygrade +  imagem.at<uchar>(y-1,x) * 1;
ygrade = ygrade +  imagem.at<uchar>(y,x) * 0;
ygrade = ygrade +  imagem.at<uchar>(y+1,x) * (-1);
ygrade = ygrade +  imagem.at<uchar>(y-1,x+1) * 0;
ygrade = ygrade +  imagem.at<uchar>(y,x+1) * (-1);
ygrade = ygrade +  imagem.at<uchar>(y+1,x+1) * 2;


ygrade = ygrade +  imagem.at<uchar>(y-1,x-1) * 0;
ygrade = ygrade +  imagem.at<uchar>(y,x-1) * (-1);
ygrade = ygrade +  imagem.at<uchar>(y+1,x-1) * (-2);
ygrade = ygrade +  imagem.at<uchar>(y-1,x) * 1;
ygrade = ygrade +  imagem.at<uchar>(y,x) * 0;
ygrade = ygrade +  imagem.at<uchar>(y+1,x) * (-1);
ygrade = ygrade +  imagem.at<uchar>(y-1,x+1) * 2;
ygrade = ygrade +  imagem.at<uchar>(y,x+1) * 1;
ygrade = ygrade +  imagem.at<uchar>(y+1,x+1) * 0;

return ygrade;
             
}


int main(){
Mat src, img;
    int gx, gy, sum;
    src = imread("lena.png", CV_LOAD_IMAGE_GRAYSCALE);
    img = src.clone();


 for(int y = 1; y < src.rows - 1; y++){
            for(int x = 1; x < src.cols - 1; x++){
                gx = xgradiente(src, x, y);
                //gy = ygradiente(src, x, y);
                sum = sqrt(pow(abs(gx),2));
                if(sum >255){
                    sum = 255;
                }

                if(sum <0){
                    sum = 0;
                }
                img.at<uchar>(y,x) = sum;
            }
        }

 

    imshow("Robinson",img);

    imshow("imagem original",src);

    waitKey();

    return 0;
}