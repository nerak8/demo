#include <opencv2/opencv.hpp>

using namespace cv;


int main()
{
    VideoCapture cap(0);

    if(!cap.isOpened())
        return -1;

    namedWindow("webcam");

    for(;;)
    {
       Mat frame, val;
       cap >> frame;
       cv::Rect corte((frame.size().width/2) - (frame.size().width/4),  (frame.size().height/2) - (frame.size().height/4),
       (frame.size().width/2) + (frame.size().width/4),  (frame.size().height/2) + (frame.size().height/4));
       frame(corte).copyTo(val);
       rectangle(frame, Point( (frame.size().width/2) - (frame.size().width/4),  (frame.size().height/2) - (frame.size().height/4)),
       Point( (frame.size().width/2) + (frame.size().width/4),  (frame.size().height/2) + (frame.size().height/4)), Scalar( 0, 55, 255 ), +1, 4 );
       imshow("webcam", frame);
       imshow("recort", val);
       if(waitKey(50) >= 0) break;

    }

    return 0;
}
