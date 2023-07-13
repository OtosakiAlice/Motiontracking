#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    // ����t�@�C�����w��
    cv::VideoCapture cap("sample.avi");

    // ����t�@�C�����J���Ȃ�������G���[���b�Z�[�W���o�͂��ďI��
    if (!cap.isOpened()) {
        std::cout << "Error opening video file" << std::endl;
        return -1;
    }

    while (1) {

        cv::Mat frame;

        // �t���[�����擾
        cap >> frame;

        // �t���[������A�܂蓮��̏I�[�ɒB�����ꍇ���[�v�𔲂���
        if (frame.empty())
            break;

        // �擾�����t���[����\��
        cv::imshow("Frame", frame);

        // 'q'�L�[�������ꂽ�ꍇ�A���[�v�𔲂���
        if ((char)cv::waitKey(1) == 'q')
            break;
    }

    cap.release();

    cv::destroyAllWindows();

    return 0;
}
