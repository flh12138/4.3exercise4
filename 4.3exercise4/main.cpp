#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("E:\\PIC\\lena.jpg", 1);

	if (srcMat.empty())return -1;

	const cv::Point2f pst1[] = {
									cv::Point2f(150,150),
									cv::Point2f(150,300),
									cv::Point2f(350,300),
									cv::Point2f(350,150)
	};
	const cv::Point2f pst2[] = {
								   cv::Point2f(200,150),
								   cv::Point2f(200,300),
								   cv::Point2f(340,270),
								   cv::Point2f(340,180)
	};

	const cv::Mat p_matrix = cv::getPerspectiveTransform(pst1, pst2);
	cv::warpPerspective(srcMat, dstMat, p_matrix, srcMat.size());

	imshow("src1", srcMat);
	imshow("src2", dstMat);
	waitKey(0);
}