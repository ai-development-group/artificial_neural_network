#include "artificialnn.hpp"

artificialnn::artificialnn()
{
	this->layers = (layer*) malloc(sizeof(layer));
	this->NUM_LAYERS = 0;
}

artificialnn::artificialnn(int num_layers)
{
	this->layers = (layer*) malloc(sizeof(layer)*num_layers);
	this->NUM_LAYERS = num_layers;
}

artificialnn::artificialnn(matrix layers_info)
{
	this->layers = (layer*) malloc(sizeof(layer)*layers_info.rows);
	for(int i = 0;i < layers_info.rows;i++)
		this->layers[i] = layer(layers_info.data[i][0],layers_info.data[i][1]);
	this->NUM_LAYERS = layers_info.rows;
}

artificialnn::~artificialnn()
{

}

matrix artificialnn::calculate_output(matrix input)
{
	matrix out;
	out = input;
	for(int i = 0;i<NUM_LAYERS;i++)
		out = layers[i].calculate_output(out);
	return out;
}

ostream& operator<<(ostream& os,artificialnn ann)
{
	for(int i = 0;i<ann.NUM_LAYERS;i++)
	{
		os << "Layer " << i+1 << ":" << endl;
		os << ann.layers[i] << endl;
	}
	return os;
}