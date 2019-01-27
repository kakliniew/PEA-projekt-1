#pragma once
#include "Matrix.h"
class BruteForce :
	public Matrix
{
	int cost; // najmniejsza waga cyklu
	int nowCost; // aktualny koszt
	bool *visited;
	int *tempRoute;
	int *route;
	int control;
	int start;
	int once;
public:
	BruteForce();
	~BruteForce();
	void displayRoute();
	void TSP(int);
	int getCost();
};

