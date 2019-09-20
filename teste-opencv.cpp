#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
 
int main( int argc, char** argv ) {
  
  cv::Mat image;
  image = cv::imread("cam.png" , CV_LOAD_IMAGE_COLOR);
  //image = cv::imread("cam.png" , CV_LOAD_IMAGE_GRAYSCALE);
  
  if(! image.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }

    for(int i=0; i < image.rows;i++){
      for (int j = 0; j < image.cols; j++){
        cout << j <<endl;
      }
      cout << i <<endl;

    }
for(int i=0;i<image.rows;i++)
 {
  for(int j=0;j<image.cols;j++)
  {
   if(image.at<cv::Vec3b>(i,j)[0] == 0 || image.at<cv::Vec3b>(i,j)[1] == 0 || image.at<cv::Vec3b>(i,j)[2] == 0 )
    {
     //originalImage.at<Vec3b>(i,j) = 255;
     image.at<cv::Vec3b>(i,j)[0]=255; // change it to white
     image.at<cv::Vec3b>(i,j)[1]=255;
     image.at<cv::Vec3b>(i,j)[2]=255;
        //   cout << i<<" " <<j<< endl; 
     }
   }
 }

  cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Display window", image );
  
  cv::waitKey(0);

  return 0;
}