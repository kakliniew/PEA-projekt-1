#include "pch.h"
#include "BranchAndBound.h"
#include <iostream>
using namespace std;

BranchAndBound::BranchAndBound()
{
	cost = INT32_MAX;
}


BranchAndBound::~BranchAndBound()
{
}

int BranchAndBound::firstMin(int i)
{
	int min = INT32_MAX;
	for (int k = 0; k < getSize(); k++)
	{
		if (table[i][k] < min && i != k)
			min = table[i][k];
	}
	return min;
}

int BranchAndBound::secondMin(int i)
{
	int first = INT32_MAX;
	int second = INT32_MAX;
	for (int j = 0; j < getSize(); j++)
	{
		if (i == j)continue;
		if (table[i][j] <= first)
		{
			second = first;
			first = table[i][j];
		}
		else if (table[i][j] <= second && table[i][j] != first)
		{
			second = table[i][j];
		}

	}
	return second;
}

void BranchAndBound::TSPp1(int nowBound, int nowWeight , int level, int nowPath[])
{
	cout << level<<" ";
	if (level == getSize())
	{
		cout << table[nowPath[level - 1]][nowPath[0]];
		if (table[nowPath[level - 1]][nowPath[0]] != 0)
		{
			int nowCost = nowWeight + table[nowPath[level - 1]][nowPath[0]];
			
			
			if (nowCost < cost)
			{
				for (int i = 0; i < getSize(); i++)
				{
					finalPath[i] = nowPath[i];
					

				}
				finalPath[getSize()] = nowPath[0];
				cost = nowCost;
			}


		}
		return;

	}

	for (int i = 0; i < getSize(); i++)
	{	
		if (table[nowPath[level - 1]][i] != 0 && visited[i] == false)
		{
			int temp = nowBound;
			nowWeight += table[nowPath[level - 1]][i];
			if (level == 1)
			{
				nowBound -= ((firstMin(nowPath[level - 1]) + firstMin(i)) / 2);
			}
			else
			{
				nowBound -= ((secondMin(nowPath[level - 1]) + firstMin(i)) / 2);
			}

			if (nowBound + nowWeight < cost)
			{
				nowPath[level] = i;
				visited[i] = true;
				cout << level <<" level "<< endl;
				TSPp1(nowBound, nowWeight, level + 1, nowPath);
			}
			nowWeight -= table[nowPath[level - 1]][i];
			nowBound = temp;
			memset(visited, false, sizeof(visited));
			for (int j = 0; j < level - 1; j++)
				visited[nowPath[j]] = true;


		}
	}
}

void BranchAndBound::TSPp2()
{
	int *nowPath;
	nowPath = new int[getSize() + 1];
	finalPath = new int[getSize() + 1];
	visited = new bool[getSize()];


	int nowBound = 0;
	memset(nowPath, -1, sizeof(nowPath));
	memset(visited, 0, sizeof(nowPath));
	for (int i = 0; i < getSize(); i++)
		nowBound += (firstMin(i)) + secondMin(i);

	nowBound = (nowBound & 1) ? nowBound / 2 + 1 : nowBound / 2;

	visited[0] = true;
	nowPath[0] = 0;
	TSPp1(nowBound, 0, 1, nowPath);

}

void BranchAndBound::showResult()
{
	cout << "Koszt " << cost << endl;
	cout << " Droga ";
	for (int i = 0; i <= getSize(); i++)
	{
		cout << finalPath[i] << " ";
	}
	cout << endl;
}
