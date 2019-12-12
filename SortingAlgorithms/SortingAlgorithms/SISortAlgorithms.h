#pragma once
#ifndef __SI_SORT_HEADER_
#define __SI_SORT_HEADER_

#include <iostream>
#include <vector>
#include <list>

using namespace std;

namespace SI_Sort
{
	void SwapData(int& a, int& b);

	void SelectionSort(vector<int>& v);
	void BubbleSort(vector<int>& v);
	void InsertionSort(vector<int>& v);

}

#endif