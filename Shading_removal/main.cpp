#include "main.h"
#include <ctime>

using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
	DIR *dir;
	struct dirent *ent;

	if ((dir = opendir("./testimage/")) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir(dir)) != NULL) {
			char addr[100] = "./testimage/";
			char addr3[100] = "./results/";
			strcat(addr, ent->d_name);
			printf("%s\n", ent->d_name);
			strcat(addr3, ent->d_name);

			//processing images one-by-one(in a specified folder)
			try{
				Mat img = imread(addr, CV_LOAD_IMAGE_UNCHANGED);
				if (!img.empty()) //check whether the image is loaded or not
				{

					clock_t start;
					double duration;
					start = clock();

					Mat img_YCbCr = RGB2YCbCr(img);
					//vector<int> compression_params; //vector that stores the compression parameters of the image
					Mat chan[3];
					split(img_YCbCr, chan);
					//compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique
					//compression_params.push_back(0); //specify the compression quality

					Mat G_ = water_filling(chan[2]);
					G_ = incre_filling(G_, chan[2]);

					vector<Mat> channels_(3);
					channels_[0] = chan[0];
					channels_[1] = chan[1];
					channels_[2] = G_;
					Mat img_YCbCr_rec;
					merge(channels_, img_YCbCr_rec);
					Mat rec_img = YCbCr2RGB(img_YCbCr_rec);

					duration = (clock() - start) / (double)CLOCKS_PER_SEC;
					cout << "Total Time: " << duration << " sec" << endl << endl << endl;


					//imwrite("../G_test.bmp", G_);
					//imwrite("../rec_YCbCr.bmp", img_YCbCr);
					imwrite(addr3, rec_img);
					printf("%s\n", addr3);
				}
				else
					continue;

			}
			catch(Exception e){

			}
		}
		closedir(dir);
	}
	else {
		/* could not open directory */
		perror("");
		return EXIT_FAILURE;
	}
}