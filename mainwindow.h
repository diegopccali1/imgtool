#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    cv::Mat image;
private slots:
    void on_addfile_clicked();

    void on_pathimg_textChanged();

    void on_OpenImg_clicked();

    void printMat(cv::Mat);

    void on_img_2_linkActivated(const QString &link);

    void on_completa_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
