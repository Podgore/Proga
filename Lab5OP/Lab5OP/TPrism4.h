#pragma once
#include "TPrism.h"

class TPrism4 : public TPrism
{
private:
	double Height;
	double RectSide;
public:
	TPrism4() {};
	TPrism4(double Height, double RectSide);

	double Volume() override;
	double Surface() override;
};

