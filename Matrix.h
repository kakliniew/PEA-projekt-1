#pragma once
#include <string>
class Matrix
{
	int size;
public:
	int **table;
	int **neighborhoodMatrix;

	Matrix();
	~Matrix();
	void loadMatrix(std::string);
	void displayMatrix();
	int getSize();
	void createNeighborhoodMatrix();
	void displayNeighborhoodMatrix();

};

