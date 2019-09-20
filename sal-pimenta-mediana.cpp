#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;


//FUNCAO PARA PEGAR O CENTRO DO VETOR DA MEDIANA
void centro(int mascara[])
{
int auxi=0;

for(int i=1;i<9;i++){
    for(int j=0;j<8;j++){
        if(mascara[j]>mascara[j+1]){
        auxi = mascara[j];
        mascara[j] = mascara[j+1];
        mascara[j+1] = auxi;
        }    
    } 
}
}

int main(int argc, char *argv[]){
    int n = 30000;
    int v;
    Mat img = imread("lena.png", CV_LOAD_IMAGE_GRAYSCALE);
    //image = cv::imread("cam.png" , CV_LOAD_IMAGE_GRAYSCALE);
    
    //RUIDO SAL E PIMENTA
   for(int i = 0;i<n;i++)
    {
        int a =rand()%img.cols;
        int b =rand()%img.rows;

        //int c =rand()%img.cols;
        //int d =rand()%img.rows;
        
        if(img.channels() == 1)
        {
            v = rand()%2;
            if(v == 0){
                img.at<uchar>(b,a) = 0;
            }

            else{
                img.at<uchar>(b,a) = 255;
            }

        }
        else if(img.channels() == 3)
        {
             v = rand()%2;
            if(v==0){
                img.at<Vec3b>(b,a)[0] = 0;
                img.at<Vec3b>(b,a)[1] = 0;
                img.at<Vec3b>(b,a)[2] = 0;

            }
            else{
                img.at<Vec3b>(b,a)[0] = 255;
                img.at<Vec3b>(b,a)[1] = 255;
                img.at<Vec3b>(b,a)[2] = 255;
            } 
        }
    }

// MEDINA


Mat img2 = img.clone();

//criar vetor de 9 posições
      int vetor[9];
 
        //for(int y = 0; y < img.rows; y++){
            //for(int x = 0; x < img.cols; x++){
                //img2.at<uchar>(y,x) = 0.0;
            //}
        //}
 
        for(int y = 1; y < img.rows - 1; y++){
            for(int x = 1; x < img.cols - 1; x++){
 
                
 
                vetor[0] = img.at<uchar>(y - 1 ,x - 1);
                vetor[1] = img.at<uchar>(y, x - 1);
                vetor[2] = img.at<uchar>(y + 1, x - 1);
                vetor[3] = img.at<uchar>(y - 1, x);
                vetor[4] = img.at<uchar>(y, x);
                vetor[5] = img.at<uchar>(y + 1, x);
                vetor[6] = img.at<uchar>(y - 1, x + 1);
                vetor[7] = img.at<uchar>(y, x + 1);
                vetor[8] = img.at<uchar>(y + 1, x + 1);
 
                // ordenar vetor
                 centro(vetor);
 
                // pegar o centro
                  img2.at<uchar>(y,x) = vetor[4];
            }
        }

// MEDIA

    Mat img3 = img.clone();

        int vetor2[9];

        for(int y = 1; y < img.rows - 1; y++){
            for(int x = 1; x < img.cols - 1; x++){
 
               
 
                vetor2[0] = img.at<uchar>(y - 1 ,x - 1);
                vetor2[1] = img.at<uchar>(y, x - 1);
                vetor2[2] = img.at<uchar>(y + 1, x - 1);
                vetor2[3] = img.at<uchar>(y - 1, x);
                vetor2[4] = img.at<uchar>(y, x);
                vetor2[5] = img.at<uchar>(y + 1, x);
                vetor2[6] = img.at<uchar>(y - 1, x + 1);
                vetor2[7] = img.at<uchar>(y, x + 1);
                vetor2[8] = img.at<uchar>(y + 1, x + 1);
 
                
 
                
                  int media = (vetor2[0] + vetor2[1] + vetor2[2] +
                               vetor2[3] + vetor2[4] + vetor2[5] +
                               vetor2[6] + vetor2[7] + vetor2[8])/9;
                                         
                img3.at<uchar>(y,x) = media; 
            }
        }
//PLOT DAS IMAGENS 
    //namedWindow("Sal e Pimenta",CV_WINDOW_KEEPRATIO);
    imshow("Sal e Pimenta",img);

    //namedWindow("Medina",CV_WINDOW_KEEPRATIO);
    imshow("Mediana",img2);

    //namedWindow("Media",CV_WINDOW_KEEPRATIO);
    imshow("Media",img3);

    waitKey();
    //destroyAllWindows();


    cout << "teste" << endl;
    return 0;
}