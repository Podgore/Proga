#include <math.h>
#include "TPrism3.h"

using namespace std;

TPrism3::TPrism3(double Height, double TriagleSide) {
	this->Height = Height;
	this->TriagleSide = TriagleSide;
}


double TPrism3::Volume()  {
	double SquareTriagle = ((TriagleSide * TriagleSide) * sqrt(3)) / 4;
	return (SquareTriagle * Height);
}


double TPrism3::Surface()  {
	double SquareTriagle = ((TriagleSide * TriagleSide) * sqrt(3)) / 4;
	double PerimeterTriagle = 3* TriagleSide;
	double SurfaceLateral = PerimeterTriagle * Height;
	return ((2 * SquareTriagle) +  SurfaceLateral);
}


