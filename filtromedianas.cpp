#include "filtromedianas.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>

FiltroMedianas::FiltroMedianas(){

}

Mat FiltroMedianas::aplicarFiltroMediana(Mat image_src, int filterRows, int filterCols){
    image = image_src.clone(); //Imagen original
    imagenFiltrada = image.clone(); //Imagen para aplicar filtro
    int ventanitaRows = filterRows, ventanitaCols = filterCols; //Dimensión para el filtro 3x3
    for(int i=floor(ventanitaRows/2.0); i<image.rows-floor(ventanitaRows/2.0); i++){
        for(int j=floor(ventanitaCols/2.0); j<image.cols-floor(ventanitaCols/2.0); j++){
           Mat ventanita = ventana(image, ventanitaRows, ventanitaCols, i,j);
           vector <int> vect = matToVector(ventanita);
           sort(vect.begin(), vect.end());
           int pos = floor(ventanitaRows*ventanitaCols/2);
           int mediana = vect[pos];
           imagenFiltrada.at<uchar>(i, j) = mediana;
        }
    }
    return imagenFiltrada;
}

vector<int> FiltroMedianas::matToVector(Mat ventana){
    vector <int> vec;
    int pos = -1;
    for(int i=0; i<ventana.rows; i++){
        for(int j=0; j<ventana.cols; j++){
            pos ++;
            vec.push_back((int)ventana.at<uchar>(i,j));
        }
    }
    return vec;
}

Mat FiltroMedianas::ventana(Mat image, int ventanitaRows, int ventanitaCols, int posX, int posY){
    Mat ventanita(ventanitaRows, ventanitaCols,CV_8U);
    for(int i=0; i<ventanita.rows; i++){
        for(int j=0; j<ventanita.cols; j++){
            ventanita.at<uchar>(i,j)  = image.at<uchar>(posX-1+i, posY-1+j);
        }
    }
    return ventanita;
}
