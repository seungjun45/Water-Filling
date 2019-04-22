#include <cv.h>
#include <highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include "dirent.h"
#include <string>
using namespace cv;

Mat RGB2YCbCr(Mat img);
Mat YCbCr2RGB(Mat img);
Mat water_filling(Mat input);
Mat incre_filling(Mat input, Mat Original);