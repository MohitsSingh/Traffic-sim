#pragma once
#include "Includes.h"

class Semi : public Vehicle
{
private:
	string model;
public:
	Semi();
	~Semi();
	Semi(double x, double y);
};

