#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    // 動画ファイルを指定
    cv::VideoCapture cap("sample.avi");

    // 動画ファイルが開けなかったらエラーメッセージを出力して終了
    if (!cap.isOpened()) {
        std::cout << "Error opening video file" << std::endl;
        return -1;
    }

    while (1) {

        cv::Mat frame;

        // フレームを取得
        cap >> frame;

        // フレームが空、つまり動画の終端に達した場合ループを抜ける
        if (frame.empty())
            break;

        // 取得したフレームを表示
        cv::imshow("Frame", frame);

        // 'q'キーが押された場合、ループを抜ける
        if ((char)cv::waitKey(1) == 'q')
            break;
    }

    cap.release();

    cv::destroyAllWindows();

    return 0;
}
