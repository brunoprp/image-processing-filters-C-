#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


int main(int argc, char *argv[]){
    int n = 30000;
    int v;
    /*
    int kernel[5][5]={ 
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };
*/
    int kernel[5][5]={ 
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };




    Mat img = imread("j.png", CV_LOAD_IMAGE_GRAYSCALE);
    
int vert = 2;
int hori = 2;

    Mat img2 = img.clone();
    Mat img3 = img.clone();

 for(int y = 0; y < img.rows ; y++){
            for(int x = 0; x < img.cols ; x++){
                    if(img.at<uchar>(y,x)>0){
                        img.at<uchar>(y,x) = 1;
                    }
                    else{
                        img.at<uchar>(y,x) = 0;
                    }
            
            }
        }


        for(int y = 0; y < img.rows ; y++){
            for(int x = 0; x < img.cols ; x++){

                int soma = 0;
                for(int i = 0; i<5;i++){
                for(int j = 0; j<5;j++){
                soma += img.at<uchar>(i+y,x+j) * kernel[i][j];
                }
                
                }
                  if(soma >=1){
                      soma = 255;
                  }
                            
                  img2.at<uchar>(y,x) = soma;

            }
        }


    imshow("Sal e Pimenta",img3);

    imshow("Mediana",img2);

    waitKey();
//g++ main.cpp -o output `pkg-config --cflags --libs opencv`

    cout << "teste" << endl;
    return 0;
}