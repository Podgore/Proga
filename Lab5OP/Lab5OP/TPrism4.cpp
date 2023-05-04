#include <math.h>
#include "TPrism4.h"

using namespace std;

TPrism4::TPrism4(double Height, double RectSide) {
	this->Height = Height;
	this->RectSide = RectSide;
}


double TPrism4::Volume() {
	double SquareRect = RectSide * RectSide;
	return (SquareRect * Height);
}


double TPrism4::Surface() {
	double SquareRect = RectSide * RectSide;
	double PerimeterRect = 4 * RectSide;
	double SurfaceLateral = PerimeterRect * Height;
	return ((2 * SquareRect) + SurfaceLateral);
}