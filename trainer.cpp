#include "trainer.hpp"

trainer::trainer(matrix input_data_set,matrix target_data_set)
{
	this->input_data_set = input_data_set;
	this->target_data_set = target_data_set;
	this->alpha = 1;
	this->tol = 0.001;
}

trainer::trainer(matrix input_data_set,matrix target_data_set,double alpha)
{
	this->input_data_set = input_data_set;
	this->target_data_set = target_data_set;
	this->alpha = alpha;
	this->tol = 0.001;
}

trainer::trainer(matrix input_data_set,matrix target_data_set,double alpha,double tol)
{
	this->input_data_set = input_data_set;
	this->target_data_set = target_data_set;
	this->alpha = alpha;
	this->tol = tol;
}

void trainer::train_once(artificialnn &ann)
{
	matrix l[ann.NUM_LAYERS];
	matrix l_delta[ann.NUM_LAYERS];
	l[0] = ann.layers[0].calculate_output(input_data_set);
	for(int i = 0;i<ann.NUM_LAYERS-1;i++)
		l[i+1] = ann.layers[i+1].calculate_output(l[i]);
	l_delta[ann.NUM_LAYERS - 1] = (target_data_set - l[ann.NUM_LAYERS - 1]).prod(l[ann.NUM_LAYERS - 1].prod(1 - l[ann.NUM_LAYERS - 1]));
	for(int i = ann.NUM_LAYERS - 1;i>0;i--)
		l_delta[i-1] = (ann.layers[i].W.transpose()*l_delta[i]).prod(l[i-1].prod(1 - l[i-1]));
	ann.layers[0].W = ann.layers[0].W + alpha*l_delta[0]*input_data_set.transpose();	
	for(int i = 0;i<ann.NUM_LAYERS-1;i++)
		ann.layers[i+1].W = ann.layers[i+1].W + alpha*l_delta[i+1]*l[i].transpose();	
}

void trainer::train_until_tol(artificialnn &ann)
{
	for(int i = 0;i<800;i++)
		train_once(ann);
}

void trainer::train_once(artificialnn &ann,matrix input_data_set,matrix target_data_set)
{
	matrix l[ann.NUM_LAYERS];
	matrix l_delta[ann.NUM_LAYERS];
	l[0] = ann.layers[0].calculate_output(input_data_set);
	for(int i = 0;i<ann.NUM_LAYERS-1;i++)
		l[i+1] = ann.layers[i+1].calculate_output(l[i]);
	l_delta[ann.NUM_LAYERS - 1] = (target_data_set - l[ann.NUM_LAYERS - 1]).prod(l[ann.NUM_LAYERS - 1].prod(1 - l[ann.NUM_LAYERS - 1]));
	for(int i = ann.NUM_LAYERS - 1;i>0;i--)
		l_delta[i-1] = (ann.layers[i].W.transpose()*l_delta[i]).prod(l[i-1].prod(1 - l[i-1]));
	ann.layers[0].W = ann.layers[0].W + l_delta[0]*input_data_set.transpose();	
	for(int i = 0;i<ann.NUM_LAYERS-1;i++)
	{
		ann.layers[i+1].W = ann.layers[i+1].W + l_delta[i+1]*l[i].transpose();
	}
}

void trainer::train_until_tol(artificialnn &ann,matrix input_data_set,matrix target_data_set,double tol)
{
	for(int i = 0;i<800;i++)
		train_once(ann,input_data_set,target_data_set);
}