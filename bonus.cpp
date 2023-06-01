#include <opencv2/opencv.hpp>

/*Note: I have understood that this involves convolution operation, and I applied the matrix on the image but
 * got a output of a similar image that is black instead of gray with the writing 'follow these instructions a bot more blurred
 * than the original image.
 *
 */



int main()
{
    cv::Mat image = cv::imread("img_signed_16bpp.png", cv::IMREAD_GRAYSCALE); //read image
    cv::Mat kernel = (cv::Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);    // Define kernel

    cv::Mat result;
    cv::filter2D(image, result, -1, kernel);  // Apply the convolution operation


    return 0;
}
