#include "header.h"

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

		int temp = v[i];
		v[i] = v[index];
		v[index] = temp;
	}
}