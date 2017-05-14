#ifndef FILTROMEDIANAS_H
#define FILTROMEDIANAS_H
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

class FiltroMedianas
{
public:
    FiltroMedianas();
    Mat ventana(Mat image, int ventanitaRows, int ventanitaCols, int posX, int posY);
    vector<int> matToVector(Mat ventana);
    Mat aplicarFiltroMediana(Mat image, int filterRows, int filterCols);

private:
    Mat image;
    Mat imagenFiltrada;
};

#endif // FILTROMEDIANAS_H
