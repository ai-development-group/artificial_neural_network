#include "artificialnn.hpp"

class trainer
{
public:
	matrix input_data_set;
	matrix target_data_set;
	double alpha;
	double tol;
public:
	trainer(matrix input_data_set,matrix target_data_set);
	trainer(matrix input_data_set,matrix target_data_set,double alpha);
	trainer(matrix input_data_set,matrix target_data_set,double alpha,double tol);
	void train_once(artificialnn &ann);
	void train_until_tol(artificialnn &ann);
	void train_once(artificialnn &ann,matrix input_data_set,matrix target_data_set);
	void train_until_tol(artificialnn &ann,matrix input_data_set,matrix target_data_set,double tol);
};