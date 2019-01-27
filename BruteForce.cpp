#include "pch.h"
#include "BruteForce.h"
#include <iostream>

using namespace std;

BruteForce::BruteForce()
{
	cost = 32424242; 
	nowCost = 0;
	control = 0;
	start = 0;
	once = 1;
}


BruteForce::~BruteForce()
{
}

void BruteForce::displayRoute()
{
	for (int i = 0; i < getSize(); i++)
	{

		cout << route[i] << " ->";


	}
	cout << route[0];

}

void BruteForce::TSP(int top)
{	
	if (once > 0)
	{
		visited = new bool[getSize()];
		route = new int[getSize()];
		tempRoute = new int[getSize()];
		route[0] = 0;

		for (int i = 0; i < getSize(); i++)
			visited[i] = false;
	}
	once--;
	
	int u;
	tempRoute[control++] = top;
	if (control < getSize())
	{
		visited[top] = true;
		
		for (u = 0; u < getSize(); u++)
		{
			
			if (neighborhoodMatrix[top][u] != 0 && !visited[u])
			{
				nowCost += table[top][u];
				TSP(u);
				nowCost -= table[top][u];
				

			}


		}
		visited[top] = false;
	}
	else if (neighborhoodMatrix[start, top]!=0)
	{
		nowCost += table[top][start];

		if (nowCost < cost)
		{
			cost = nowCost;
			for (u = 0; u < control; u++)
			{

				route[u] = tempRoute[u];

			}


		}
		nowCost -= table[top][start];

	}
	control--;
	
}

int BruteForce::getCost()
{
	return cost;
}
