#include "layer.hpp"

layer::layer()
{
	this->W = matrix(1,1);
	this->INPUTS = 0;
	this->OUTPUTS = 0;
}

layer::layer(int INPUTS,int OUTPUTS)
{
	this->W = matrix(OUTPUTS,INPUTS);
	this->W.random();
	this->OUTPUTS = OUTPUTS;
	this->INPUTS = INPUTS;
}

layer::~layer()
{

}

matrix layer::calculate_output(matrix input)
{
	matrix output;
	output = this->W*input;
	output = sigmoid(output);
	return output;
}

ostream& operator<<(ostream &os,layer l)
{
	os << "Weights:" << endl;
	os << l.W << endl;
	os << "INPUTS: "<< l.INPUTS << "\t" << "OUTPUTS: "<< l.OUTPUTS << endl;
	return os;
}

double sigmoid(double x)
{
	return 1.0/(1 + exp(-x));
}

matrix sigmoid(matrix mat)
{
	matrix out(mat.rows,mat.cols);
	for(int i = 0;i < mat.rows;i++)
		for(int j = 0;j<mat.cols;j++)
			out.data[i][j] = sigmoid(mat.data[i][j]);
	return out;
}

double heaviside(double x)
{
	if(x>0)
		return 1;
	return 0;
}

matrix heaviside(matrix mat)
{
	matrix out(mat.rows,mat.cols);
	for(int i = 0;i<mat.rows;i++)
		for(int j = 0;j<mat.cols;j++)
			out.data[i][j] = heaviside(mat.data[i][j]);
	return out;
}