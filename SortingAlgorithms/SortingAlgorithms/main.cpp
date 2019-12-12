
#include "SISortAlgorithms.h"

using namespace SI_Sort;

int main()
{
	vector<int> v;

	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(2);
	v.push_back(5);

	cout << "Before :" << endl;

	for (int i : v)
		cout << i << " ";

	cout << endl << endl;

	//SelectionSort(v);
	//BubbleSort(v);
	InsertionSort(v);

	cout << "After :" << endl;

	for (int i : v)
		cout << i << " ";

	cout << endl << endl;

	return 0;
}