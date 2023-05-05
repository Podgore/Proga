#pragma once
#include "TPrism.h"

using namespace std;

class TPrism3 : public TPrism
{
private:
	double Height;
	double TriagleSide;
public:
	TPrism3() {};

	TPrism3(double Height, double TriagleSide);




	double Volume() override;
	double Surface() override;
};

