#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "main.h"
using namespace cv;

float inv_relu(float input_){
	float output_;
	if (input_ > 0){
		output_=0;
	}
	else{
		output_ = input_;
	}
	return output_;
}

Mat water_filling(Mat input_){

	
	input_.convertTo(input_, CV_32F);
	Mat h_;
	Size size(0, 0);
	resize(input_, h_, size, 0.2, 0.2, INTER_LINEAR);
	
	int height = h_.rows;
	int width = h_.cols;
	Mat w_ = Mat(h_.rows, h_.cols, CV_32F, Scalar(0, 0, 0));
	Mat G_ = Mat(h_.rows, h_.cols, CV_32F, Scalar(0, 0, 0));
	
	
	double w_pre;
	double pouring;
	double neta = 0.2;
	double G_peak;
	double G_min;
	float* w_ptr = (float*)w_.data;
	float* G_ptr = (float*)G_.data;
	size_t elem_step = w_.step / sizeof(float);
	float temp;
	
	double del_w;

	for (int t = 0; t < 2500; t++){
		G_ = w_ + h_;
		minMaxLoc(G_, &G_min, &G_peak);
		for (int y = 1; y < (height-2); y++){

			for (int x = 1; x < (width-2); x++){
				
					w_pre = w_ptr[x+y*elem_step];
					pouring = exp(-t)*(G_peak - G_ptr[x+y*elem_step]);
					del_w = neta*(inv_relu(-G_ptr[x + y*elem_step] + G_ptr[x + (y + 1)*elem_step])
						+ inv_relu(-G_ptr[x + y*elem_step] + G_ptr[x + (y - 1)*elem_step])
						+ inv_relu(-G_ptr[x + y*elem_step] + G_ptr[(x + 1) + y*elem_step])
						+ inv_relu(-G_ptr[x + y*elem_step] + G_ptr[(x - 1) + y*elem_step]));
					temp = del_w + pouring + w_pre;
					if (temp < 0){
						w_ptr[x + y*elem_step] = 0;
					}
					else{
						w_ptr[x + y*elem_step] = temp;
					}
					//printf("w_pre is %f\n", w_pre);
					//printf("pouring is %f\n", pouring);
					//printf("del_w is %f\n", del_w);

				
			}
		}
		
	}
	Mat output_;
	Size outsize(input_.cols, input_.rows);
	resize(G_, output_, outsize, 0, 0, INTER_LINEAR);
	//output_ = input_ / output_*255;
	output_.convertTo(output_, CV_8UC1);
	return output_;
}

Mat incre_filling(Mat h_, Mat Original){


	h_.convertTo(h_, CV_32F);
	Original.convertTo(Original, CV_32F);

	int height = h_.rows;
	int width = h_.cols;
	Mat w_ = Mat(h_.rows, h_.cols, CV_32F, Scalar(0, 0, 0));
	Mat G_ = Mat(h_.rows, h_.cols, CV_32F, Scalar(0, 0, 0));


	double w_pre;
	double pouring;
	double neta = 0.2;
	double G_peak;
	double G_min;
	float* w_ptr = (float*)w_.data;
	float* G_ptr = (float*)G_.data;
	size_t elem_step = w_.step / sizeof(float);
	float temp;

	double del_w;

	for (int t = 0; t < 100; t++){
		G_ = w_ + h_;
		for (int y = 1; y < (height - 2); y++){

			for (int x = 1; x < (width - 2); x++){

				w_pre = w_ptr[x + y*elem_step];
				del_w = neta*(-G_ptr[x + y*elem_step] + G_ptr[x + (y + 1)*elem_step]
					+ -G_ptr[x + y*elem_step] + G_ptr[x + (y - 1)*elem_step]
					+ -G_ptr[x + y*elem_step] + G_ptr[(x + 1) + y*elem_step]
					+ -G_ptr[x + y*elem_step] + G_ptr[(x - 1) + y*elem_step]);
				temp = del_w + w_pre;
				if (temp < 0){
					w_ptr[x + y*elem_step] = 0;
				}
				else{
					w_ptr[x + y*elem_step] = temp;
				}
				//printf("w_pre is %f\n", w_pre);
				//printf("pouring is %f\n", pouring);
				//if (t == 99){
				//	printf("del_w is %f\n", del_w);
				//}


			}
		}

	}
	Mat output_;
	output_ = 0.85*Original / G_ * 255;
	output_.convertTo(output_, CV_8UC1);
	return output_;
}