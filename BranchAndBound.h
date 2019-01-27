#pragma once
#include "Matrix.h"
class BranchAndBound :
	public Matrix
{
	int *finalPath;
	bool *visited;
	int cost;


public:
	BranchAndBound();
	~BranchAndBound();
	int firstMin(int);
	int secondMin(int);
	void TSPp1(int,int,int, int[]);
	void TSPp2();
	void showResult();
};

