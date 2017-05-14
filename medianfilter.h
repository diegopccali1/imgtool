#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

#include <QDialog>
#include <QWidget>
#include <opencv2/opencv.hpp>
using namespace cv;

namespace Ui {
class MedianFilter;
}

class MedianFilter : public QDialog
{
    Q_OBJECT

public:
    explicit MedianFilter(QWidget *parent = 0);
    ~MedianFilter();
    void DisplayImageFiltrada(Mat image);

private:
    Ui::MedianFilter *ui;
};

#endif // MEDIANFILTER_H
