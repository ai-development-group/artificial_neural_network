#include "matrix.hpp"
#include <iostream>
#include <math.h>

using namespace std;

class layer
{
public:
	matrix W;
	int INPUTS;
	int OUTPUTS;

public:
	layer();
	layer(int INPTUS,int OUTPUTS);
	~layer();
	matrix calculate_output(matrix input);
};

ostream& operator<<(ostream &os,layer l);
double sigmoid(double x);
matrix sigmoid(matrix mat);
double heaviside(double x);
matrix heaviside(matrix mat);