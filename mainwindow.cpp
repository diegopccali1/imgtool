#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QFileDialog>
using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   // Re

    ui->setupUi(this);
    ui->completa->setVisible(false);

    cv::Mat inputImage = cv::imread("marilin.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    if(! inputImage.data )                              // Check for invalid input
        {
            cout <<  "Could not open or find the image" << std::endl ;

        }else {

        namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
        imshow( "Display window", inputImage );
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pathimg_textChanged()
{

}

void MainWindow::on_OpenImg_clicked(){


}

void MainWindow::printMat(Mat mat){

    namedWindow( "Imprimiendo imagen", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", mat);

}

void MainWindow::on_addfile_clicked()
{
    QString imgpath=QFileDialog::getOpenFileName();
    ui->imgpath->setText(imgpath);

    if (imgpath==""){

        cout<<"emptyfile"<<endl;

    }else {
         cv::Mat inputImage = cv::imread(imgpath.toStdString(),CV_LOAD_IMAGE_GRAYSCALE);
         this->image=inputImage;

        // inputImage.convertTo(inputImage, CV_32F, 1.0/255);
         //SVD svdimagencita(inputImage);

         cv::Size size(300,300);//the dst image size,e.g.100x100
        cv::Mat temp;
         cv::resize(inputImage,temp,size);//resize image

          //el resto de la prueba


           // Qt image
           QImage img= QImage((const unsigned char*)(temp.data),
             temp.cols,temp.rows,QImage::Format_Indexed8);


           // display on label
           ui->img_2->setPixmap(QPixmap::fromImage(img));
           // resize the label to fit the image
           ui->img_2->resize(ui->img_2->pixmap()->size());
           ui->completa->setVisible(true);

           img.save("mico");
           imwrite( "micoopensv.jpg", image );
    }



}

void MainWindow::on_img_2_linkActivated(const QString &link)
{

}

void MainWindow::on_completa_clicked()
{
    printMat(this->image);
}
