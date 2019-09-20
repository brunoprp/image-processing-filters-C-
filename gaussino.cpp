#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(){
const double PI = 4.0*atan(1.0) ;
 double sigma=  1.0;
 const int linhas=5;
 const int colunas=5;
 Mat img1 = imread("gaussiano.jpg", CV_LOAD_IMAGE_GRAYSCALE);
 Mat img2 = img1.clone();
  Mat img3 = img1.clone();
double total = 0;
double kernel2 [25];
int cont2 = 0;
double vetorKernel[5][5];

// Criar kerall fomula gausssina

for(int row=0; row < linhas; row++){
    for(int col = 0; col < colunas; col++){
        double valor = (1/(2*PI*pow(sigma,2)))*exp(-(pow(row-linhas/2,2)+pow(col-colunas/2,2))/(2*pow(sigma,2)));
        vetorKernel[row][col] = valor;
        total +=valor;

    }
}

// Normalizar vetor
for(int i =0; i < 5;i++){
    for(int j = 0; j < 5; j++){ 
    vetorKernel[i][j]= vetorKernel[i][j]/total;
    kernel2[cont2]= vetorKernel[i][j];
    cont2 +=1;
    
    }
}

// passar filtro na imagem]

int vert = 2;
int hori = 2;
int teste =0;
for(int y = 0; y < img1.rows; y++){
            for(int x = 0; x < img1.cols; x++){
                
                double pixel = 0.0;
                for (int i =0; i<5; i++){
                        
                        for(int j = 0; j < 5; j++)
                        {
                           double soma = img1.at<uchar>(i+y-vert,j+x-hori) * vetorKernel[i][j];
                           pixel += soma;

                        }          
                }
                
                img2.at<uchar>(y,x)= cvRound(pixel);
            }
}


 for(int y = 1; y < img1.rows - 1; y++){
            double calc = 0.0;
            
            for(int x = 1; x < img1.cols - 1; x++){
 
                calc = img1.at<uchar>(y - 1 ,x - 1) * kernel2[0];
                calc = calc + img1.at<uchar>(y, x - 1) * kernel2[1];
                calc = calc + img1.at<uchar>(y+1, x - 1) * kernel2[2];
                calc = calc + img1.at<uchar>(y + 2, x - 1) * kernel2[3];
                calc = calc + img1.at<uchar>(y + 3, x - 1) * kernel2[4];
                

                calc = calc + img1.at<uchar>(y - 1 ,x) * kernel2[5];
                calc = calc + img1.at<uchar>(y, x) * kernel2[6];
                calc = calc + img1.at<uchar>(y+1, x) * kernel2[7];
                calc = calc + img1.at<uchar>(y + 2, x) * kernel2[8];
                calc = calc + img1.at<uchar>(y + 3, x) * kernel2[9];

                calc = calc + img1.at<uchar>(y - 1 ,x + 1) * kernel2[10];
                calc = calc + img1.at<uchar>(y, x + 1) * kernel2[11];
                calc = calc + img1.at<uchar>(y+1, x + 1) * kernel2[12];
                calc = calc + img1.at<uchar>(y + 2, x + 1) * kernel2[13];
                calc = calc + img1.at<uchar>(y + 3, x + 1) * kernel2[14];


                calc = calc + img1.at<uchar>(y - 1 ,x + 2) * kernel2[15];
                calc = calc + img1.at<uchar>(y, x + 2) * kernel2[16];
                calc = calc + img1.at<uchar>(y+1, x + 2) * kernel2[17];
                calc = calc + img1.at<uchar>(y + 2, x + 2) * kernel2[18];
                calc = calc + img1.at<uchar>(y + 3, x + 2) * kernel2[19];  

                calc = calc + img1.at<uchar>(y - 1 ,x + 3) * kernel2[20];
                calc = calc + img1.at<uchar>(y, x + 3) * kernel2[21];
                calc = calc + img1.at<uchar>(y+1, x + 3) * kernel2[22];
                calc = calc + img1.at<uchar>(y + 2, x + 3) * kernel2[23];
                calc = calc + img1.at<uchar>(y + 3, x + 3) * kernel2[24];

             
                img3.at<uchar>(y,x) = cvRound(calc);

                
             
            }
        }



//namedWindow("calcHist Demo", WINDOW_AUTOSIZE );
imshow("imagem com ruindo", img1 );
imshow("imagem com filtro 1", img2);
imshow("imagem com filtro 2", img3);
waitKey(0);

    return 0;
}