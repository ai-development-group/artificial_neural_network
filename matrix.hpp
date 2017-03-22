#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "list.hpp"

using namespace std;

class matrix
{
public:
	double** data;
	int rows;
	int cols;
	static const int AXIS_X = 0;
	static const int AXIS_Y = 1;

public:
	matrix();
	matrix(int cols);
	matrix(int rows,int cols);
	matrix(char* data_cad,int rows,int cols);
	~matrix();
	void zeros();
	void ones();
	void eye();
	void clone(matrix &M);
	void random();
	matrix transpose();
	matrix size();
	matrix prod(matrix M);
	matrix operator+(matrix M);
	matrix operator+(double num);
	matrix operator-(matrix M);
	matrix operator-(double num);
	matrix operator*(matrix M);
	matrix operator*(double num);
	double norm();
	matrix sum(int axis);
};

ostream &operator<<(ostream& stream, matrix mat);
matrix operator*(double num,matrix M);
matrix operator+(double num,matrix M);
matrix operator-(double num,matrix M);