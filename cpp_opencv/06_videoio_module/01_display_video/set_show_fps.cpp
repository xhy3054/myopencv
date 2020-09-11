#include "opencv2/opencv.hpp"
#include <iostream>
#include <time.h> 
using namespace std;
using namespace cv;
 
int main(int argc, char** argv){
 
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  //VideoCapture cap("chaplin.mp4"); 
  if(argc!=4){
    cout<<"you should execute the program as follows:"<<endl;
    cout<<"./set_show_fps width height fps"<<endl;
    return -1;
  }
  VideoCapture cap(0);
  // Check if camera opened successfully
  int width = stoi(argv[1]);
  int height = stoi(argv[2]);
  int fps = stoi(argv[3]); 
  cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);
  cap.set(CV_CAP_PROP_FPS, fps);

  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }
      // Number of frames to capture
  int num_frames = 0;
  time_t start, end;     
  time(&start);
  cout<<"fps is:"<<cap.get(CV_CAP_PROP_FPS)<<endl;
  while(1){
    num_frames++;
    Mat frame;
    // Capture frame-by-frame
    cap >> frame;
  
    // If the frame is empty, break immediately
    if (frame.empty())
      break;
 
    // Display the resulting frame
    imshow( "Frame", frame );
 
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(1);
    if(c==27)
      break;
  }
    // End Time
    time(&end);
    
    // Time elapsed
    double seconds = difftime (end, start);
    cout << "Time taken : " << seconds << " seconds" << endl;
    
    // Calculate frames per second
    double fps1  = num_frames / seconds;
    cout << "Estimated frames per second : " << fps1 << endl;  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  destroyAllWindows();
     
  return 0;
}

