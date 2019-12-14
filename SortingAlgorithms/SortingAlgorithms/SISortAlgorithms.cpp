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
	queue<int*> q;
	
	// index set's index value.
	int pivot = 0;
	int left = 1;
	int right = 2;

	int first[3]; // first array's index set.
	first[pivot] = 0, first[left] = 0, first[right] = v.size() - 1;
	
	q.push(first);
	
	while (q.empty() == false)
	{
		vector<int> leftArray, rightArray;

		int* indexes = q.front();
		q.pop();

		// Divide to left array and right array.
		for (int i = indexes[left]; i <= indexes[right]; i++)
		{
			if (v[indexes[pivot]] > v[i])
				leftArray.push_back(v[i]);
			else if (v[indexes[pivot]] < v[i])
				rightArray.push_back(v[i]);
		}

		// It is for using when changing datas from original array.
		int pivotData = v[indexes[pivot]];

		// Change datas from original array.
		for (int i = indexes[left]; i <= indexes[right]; i++)
		{
			if (i < indexes[left] + leftArray.size())
			{
				v[i] = leftArray[i - indexes[left]];
			}
			else if (i == indexes[left] + leftArray.size())
			{
				v[i] = pivotData;
			}
			else
			{
				v[i] = rightArray[i - indexes[left] - leftArray.size() - 1];
			}
		}

		// If each array size is less than 1, push array's index set to the queue.
		if (leftArray.size() > 1)
		{
			int leftIndex[3] = { indexes[left], indexes[left], indexes[left] + leftArray.size() - 1 };
			q.push(leftIndex);
		}
		if (rightArray.size() > 1)
		{
			int rightIndex[3] = { indexes[right] - rightArray.size() + 1, indexes[right] - rightArray.size() + 1, indexes[right] };
			q.push(rightIndex);
		}
	}
}
// ==================================================

// # HeapSort
void SI_Sort::HeapSort(vector<int>& v)
{

}
// ==================================================