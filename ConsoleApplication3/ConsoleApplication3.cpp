#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;

int main(int argc, char** argv) {
	using namespace cv;
	Mat image = imread("F:/Project/deepFace/DeepFaceLab_NVIDIA_up_to_RTX2080Ti/workspace/data_dst/aligned/08916.jpg");
	if (!image.data) {
		printf("could not load image...\n");
		return -1;
	}

	Ptr<FaceDetectorYN> faceDetector = FaceDetectorYN::create("F:/Users/Admin/Downloads/yunet.onnx", "", image.size());
	Mat faces;
	faceDetector->detect(image, faces);

	int thickness = 2;
	for (int i = 0; i < faces.rows; i++)
	{
		//rectangle(image, Rect2i(int(faces.at< float>(i, 0)), int(faces.at< float>(i, 1)), int(faces.at< float>(i, 2)), int(faces.at< float>(i, 3))), Scalar(0, 255, 0), thickness);
		circle(image, Point2i(int(faces.at<float>(i, 4)), int(faces.at<float>(i, 5))), 2, Scalar(255, 0, 0), thickness);

		circle(image, Point2i(int(faces.at<float>(i, 6)), int(faces.at<float>(i, 7))), 2, Scalar(0, 0, 255), thickness);

		circle(image, Point2i(int(faces.at<float>(i, 8)), int(faces.at<float>(i, 9))), 2, Scalar(0, 255, 0), thickness);

		circle(image, Point2i(int(faces.at<float>(i, 10)), int(faces.at<float>(i, 11))), 2, Scalar(255, 0, 255), thickness);

		circle(image, Point2i(int(faces.at<float>(i, 12)), int(faces.at<float>(i, 13))), 2, Scalar(0, 255, 255), thickness);
	}

	imshow("人脸检测", image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
