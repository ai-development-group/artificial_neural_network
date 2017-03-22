#include "trainer.hpp"
#include <iostream>

using namespace std;

int main()
{
	char cad[100]= "3,4;4,1";
	matrix layers_info(cad,2,2);
	char cad1[100] = "1,1,0,0;1,0,1,0;1,1,1,1";
	matrix input_data_set(cad1,3,4);
	char cad2[100] = "1,0,0,1";
	matrix target_data_set(cad2,1,4);
	artificialnn ann;
	ann = artificialnn(layers_info);
	trainer t(input_data_set,target_data_set);
	t.train_until_tol(ann);
	cout << ann.calculate_output(input_data_set);	
	//cout << matrix::AXIS_Y;
}
