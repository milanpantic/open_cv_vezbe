/*
 *  tutorijal https://www.youtube.com/watch?v=2FYm3GOonhk
 */


#include "opencv4/opencv2/imgproc.hpp"
#include "opencv4/opencv2/highgui.hpp"

#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core/matx.hpp>

#include <iostream>
using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
	string pic_path = "audi.png";

	cv::Mat image = cv::imread(pic_path);
	cv::Mat chanels[3], zero_mat;


	cv::imshow("Originalna fotografija", image);
	cv::waitKey();
	cv::destroyAllWindows();



	std::cout << image.size << std::endl;
	std::cout << "Width : " << image.cols << " Height : " << image.rows << std::endl;



	cv::Mat gray_img;

	cv::cvtColor(image, gray_img, cv::COLOR_BGR2GRAY);
	cv::imshow("Crno-bela fotografija", gray_img);
	cv::waitKey();
	cv::destroyAllWindows();



	cv::Mat hsv_img;
	vector<cv::Mat> hsv_chanels;

	cv::cvtColor(image, hsv_img, cv::COLOR_BGR2HSV);
	cv::split(hsv_img, hsv_chanels);

	cv::imshow("HSV fotografija", hsv_img);
	cv::imshow("Hue channel", hsv_chanels[0]);
	cv::imshow("Saturation channel", hsv_chanels[1]);
	cv::imshow("Value channel", hsv_chanels[2]);

	cv::waitKey();
	cv::destroyAllWindows();



	vector<cv::Mat> rgb_chanels;
	cv::split(image, rgb_chanels);

	cv::imshow("blue", rgb_chanels[0]);
	cv::imshow("green", rgb_chanels[1]);
	cv::imshow("red", rgb_chanels[2]);

	cv::waitKey(0);
	cv::destroyAllWindows();




	cv::Mat merged;
	cv::merge(rgb_chanels, merged);
	cv::imshow("Merged", merged);




	cv::Mat merged_100;
	rgb_chanels[0] = rgb_chanels[0] + 100;
	cv::merge(rgb_chanels, merged_100);
	cv::imshow("Merged + with Blue Amplified", merged_100);

	cv::waitKey(0);
	cv::destroyAllWindows();



	zero_mat = cv::Mat::zeros(image.rows, image.cols, image.type());

	cv::imshow("zero_img", zero_mat);
	cv::waitKey(0);
	cv::destroyAllWindows();

	vector<cv::Mat> zero_chanels;
	cv::Mat merged_2;

	zero_chanels.push_back(zero_mat);
	zero_chanels.push_back(zero_mat);
	zero_chanels.push_back(rgb_chanels[1]);

	cv::merge(zero_chanels, merged_2);
	std::cout << "Width : " << merged_2.cols << " Height : " << merged_2.rows << std::endl;
	cv::imshow("zero_chanels", merged_2);
	cv::waitKey(0);
	cv::destroyAllWindows();




    return 0;
}
