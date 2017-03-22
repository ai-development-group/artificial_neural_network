#include "layer.hpp"

class artificialnn
{
public:
	layer* layers;
	int NUM_LAYERS;
public:
	artificialnn();
	artificialnn(int num_layers);
	artificialnn(matrix layers_info);
	~artificialnn();
	matrix calculate_output(matrix input);
};

ostream& operator<<(ostream& os,artificialnn ann);