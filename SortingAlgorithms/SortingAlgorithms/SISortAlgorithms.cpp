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

// # MergeSort
// not using recursion
pair<int, int> MergeProcess(vector<int>& v, pair<int, int> leftArray, pair<int,int> rightArray)
{
	vector<int> mergeV; // merged array.

	int left_left = leftArray.first;
	int left_right = leftArray.second;
	int right_left = rightArray.first;
	int right_right = rightArray.second;

	int result_left = left_left;
	int result_right = right_right;

	while (true)
	{
		int inputData = 0;

		if (v[left_left] > v[right_left])
		{
			inputData = v[right_left];
			right_left++;
		}
		else
		{
			inputData = v[left_left];
			left_left++;
		}

		mergeV.push_back(inputData);

		if (left_left > left_right)
		{
			for (int i = right_left; i <= right_right; i++)
				mergeV.push_back(v[i]);
			break;
		}
		else if (right_left > right_right)
		{
			for (int i = left_left; i <= left_right; i++)
				mergeV.push_back(v[i]);
			break;
		}
	}

	int index = 0;
	for (int i = result_left; i <= result_right; i++)
	{
		v[i] = mergeV[index];
		index++;
	}

	// return pair of the left index of the merged array and the right index of the merged array.
	return make_pair(result_left, result_right);
}

void SI_Sort::MergeSort(vector<int>& v)
{
	queue<pair<int,int>> q;
	bool oddFlag;				// Flag for whether array' count is odd or not.

	if (v.size() % 2 == 0)
		oddFlag = false;
	else
		oddFlag = true;

	// Divide to smallest array and push the left index and right index of the array to queue.
	for (int i = 0; i < v.size(); i++)
	{
		q.push(make_pair(i,i));
	}

	// If queue is empty, return.
	if (q.empty())
		return;

	// The variable is for checking whether the number of smallest array in queue is one or not.
	int count = 0;

	while (q.size() != 1)
	{
		// Merge two arrays and push the merged array to the queue again.
		pair<int, int> leftArray = q.front();
		q.pop();
		pair<int, int> rightArray = q.front();
		q.pop();

		pair<int, int> resultArray = MergeProcess(v, leftArray, rightArray);

		if (oddFlag == true && count == (v.size() / 2 - 1))
		{
			rightArray = q.front();
			q.pop();
			leftArray = resultArray;

			resultArray = MergeProcess(v, leftArray, rightArray);
		}

		q.push(resultArray);

		count++;
	}
}
// =================================================

// # QuickSort
void SI_Sort::QuickSort(vector<int>& v)
{

}
// ==================================================

// # HeapSort
void SI_Sort::HeapSort(vector<int>& v)
{

}
// ==================================================