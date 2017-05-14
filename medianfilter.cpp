#include "medianfilter.h"
#include "ui_medianfilter.h"
#include "filtromedianas.h"
using namespace std;

MedianFilter::MedianFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MedianFilter)
{
    ui->setupUi(this);
}

MedianFilter::~MedianFilter()
{
    delete ui;
}

void MedianFilter::DisplayImageFiltrada(Mat image){
    Mat imageForFMediana = image.clone();
    FiltroMedianas *filtromedianas = new FiltroMedianas();
    Mat imagenFiltrada = filtromedianas->aplicarFiltroMediana(imageForFMediana, 3, 3);
    QImage imdisplay_ori((uchar*)image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
    QImage imdisplay_fil((uchar*)imagenFiltrada.data, imagenFiltrada.cols, imagenFiltrada.rows, imagenFiltrada.step, QImage::Format_Indexed8);

    ui->display_image_ori->setPixmap(QPixmap::fromImage(imdisplay_ori));
    ui->display_image_fil->setPixmap(QPixmap::fromImage(imdisplay_fil));
}
