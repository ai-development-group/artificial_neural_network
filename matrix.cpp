#include "matrix.hpp"

matrix::matrix()
{

}

matrix::matrix(int cols)
{
	this->rows = 1;
	this->cols = cols;
	this->data = (double **)malloc(sizeof(double*));
	*this->data = (double*) malloc(sizeof(double)*this->cols);

}

matrix::matrix(int rows,int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->data = (double **)malloc(sizeof(double*)*rows);
	for(int i = 0;i<rows;i++)
		this->data[i] = (double*) malloc(sizeof(double)*this->cols);
}

matrix::matrix(char* data_cad,int rows,int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->data = (double **)malloc(sizeof(double*)*rows);
	for(int i = 0;i<rows;i++)
		this->data[i] = (double*) malloc(sizeof(double)*this->cols);
	list<char*> aux;
	char* tk;
	tk = strtok(data_cad,";");
	int j;
	while(tk!=NULL)
	{
		aux.add(tk);
		tk = strtok(NULL,";");
		j++;
	}
	for(int i = 0;i<aux.size();i++)
	{
		j = 0;
		tk = strtok(aux.get(i),", ");
		while(tk!=NULL)
		{
			this->data[i][j] = atof(tk);
			tk = strtok(NULL,", ");
			j++;
		}
	}
}

matrix::~matrix()
{

}

void matrix::zeros()
{
	for(int i = 0;i<this->rows;i++)
		for(int j = 0;j<this->cols;j++)
			this->data[i][j] = 0;
}

void matrix::ones()
{
	for(int i = 0;i<this->rows;i++)
		for(int j = 0;j<this->cols;j++)
			this->data[i][j] = 1;
}

void matrix::eye()
{
	for(int i = 0;i<this->rows;i++)
	{
		for(int j = 0;j<this->cols;j++)
		{
			if(i==j)
				this->data[i][i] = 1;
			else
				this->data[i][j] = 0;
		}
	}
}

void matrix::clone(matrix &M)
{
	this->rows = M.rows;
	this->cols = M.cols;
	this->data = M.data;
}

void matrix::random()
{
	srand(time(NULL));
	for(int i = 0;i<this->rows;i++)
		for(int j=0;j<this->cols;j++)
			this->data[i][j] = rand()%100 / 100.0;
}	

matrix matrix::transpose()
{
	matrix out(this->cols,this->rows);
	for(int i = 0;i<this->cols;i++)
		for(int j = 0;j<this->rows;j++)
			out.data[i][j] = this->data[j][i];
	return out;
}

matrix matrix::size()
{
	matrix out(1,2);
	out.data[0][0] = this->rows;
	out.data[0][1] = this->cols;
	return out;
}

matrix matrix::prod(matrix M)
{
	matrix out(this->rows,this->cols);
	for(int i = 0;i<this->rows;i++)
		for(int j = 0;j<this->cols;j++)
			out.data[i][j] = this->data[i][j]*M.data[i][j];
	return out;
}

matrix matrix::operator+(matrix M)
{
	matrix out(this->rows,this->cols);
	for(int i = 0;i<this->rows;i++)
		for(int j =0;j<this->cols;j++)
			out.data[i][j] = this->data[i][j] + M.data[i][j];
	return out;
}

matrix matrix::operator+(double num)
{
	matrix out(this->rows,this->cols);
	for(int i = 0;i<this->rows;i++)
		for(int j =0;j<this->cols;j++)
			out.data[i][j] = this->data[i][j] + num;
	return out;
}

matrix matrix::operator-(matrix M)
{
	matrix out(this->rows,this->cols);
	for(int i = 0;i<this->rows;i++)
		for(int j =0;j<this->cols;j++)
			out.data[i][j] = this->data[i][j] - M.data[i][j];
	return out;
}

matrix matrix::operator-(double num)
{
	matrix out(this->rows,this->cols);
	for(int i = 0;i<this->rows;i++)
		for(int j =0;j<this->cols;j++)
			out.data[i][j] = this->data[i][j] - num;
	return out;
}

matrix matrix::operator*(matrix M)
{
	matrix out(this->rows,M.cols);
	double s = 0;
	for(int i = 0;i<this->rows;i++)
	{
		for(int j =0;j<M.cols;j++)
		{
			s = 0;
			for(int k = 0;k<this->cols;k++)
				s = s + this->data[i][k]*M.data[k][j];
			out.data[i][j] = s;
		}
	}
	return out;
}

matrix matrix::operator*(double num)
{
	matrix out(this->rows,this->cols);
	for(int i = 0;i<this->rows;i++)
		for(int j =0;j<this->cols;j++)
			out.data[i][j] = this->data[i][j] * num;
	return out;
}

double matrix::norm()
{
	double s = 0;
	for(int i = 0;i<this->rows;i++)
		for(int j = 0;j<this->cols;j++)
			s = s + this->data[i][j]*this->data[i][j];
	return sqrt(s);
}

matrix matrix::sum(int axis)
{
	matrix out;
	double s;
	if(axis == AXIS_X)
	{
		out = matrix(this->rows,1);
		s = 0;
		for(int i = 0;i<this->rows;i++)
		{
			s = 0;
			for(int j = 0;j<this->cols;j++)
				s = s + this->data[i][j];
			out.data[i][0] = s;
		}
	}
	else if(axis == AXIS_Y)
	{
		out = matrix(1,this->cols);
		for(int i = 0;i<this->cols;i++)
		{
			s = 0;
			for(int j = 0;j<this->rows;j++)
				s = s + this->data[j][i];
			out.data[0][i] = s;
		}
	}
	else
	{

	}
	return out;

}

matrix operator*(double num,matrix M)
{
	matrix out(M.rows,M.cols);
	for(int i = 0;i<M.rows;i++)
		for(int j =0;j<M.cols;j++)
			out.data[i][j] = M.data[i][j] * num;
	return out;
}

matrix operator+(double num,matrix M)
{
	matrix out(M.rows,M.cols);
	for(int i = 0;i<M.rows;i++)
		for(int j =0;j<M.cols;j++)
			out.data[i][j] = M.data[i][j] + num;
	return out;
}

matrix operator-(double num,matrix M)
{
	matrix out(M.rows,M.cols);
	for(int i = 0;i<M.rows;i++)
		for(int j =0;j<M.cols;j++)
			out.data[i][j] = num - M.data[i][j];
	return out;
}

ostream &operator<<(ostream& stream, matrix mat)
{
	stream << "[" << endl;
	for(int i = 0;i<mat.rows;i++)
	{
		stream << "[ ";
		for(int j = 0;j<mat.cols;j++)
			stream << mat.data[i][j] << " ";
		stream << "]";
		stream << endl;
	}
	stream << "]"<<endl;
	return stream;
}

