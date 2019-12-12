#include "SISortAlgorithms.h"

// # SwapData
void SI_Sort::SwapData(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// # SelectionSort
void SI_Sort::SelectionSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		int min = v[i], index = i;

		for (int j = i + 1; j < v.size(); j++)
		{
			if (min > v[j])
			{
				min = v[j];
				index = j;
			}
		}

		SwapData(v[i], v[index]);
	}
}
// ===============================================

// # BubbleSort
void SI_Sort::BubbleSort(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size() - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
				SwapData(v[j], v[j + 1]);
		}
	}
}
// ================================================

// # InsertionSort
void SI_Sort::InsertionSort(vector<int>& v)
{	
	for (int i = 1; i < v.size(); i++)
	{
		int curNum = v[i];
		int j = i - 1;

		while ((j >= 0) && (v[j] > curNum))
		{
			v[j + 1] = v[j];
			j--;
		}

		v[j + 1] = curNum;
	}
}
// =================================================