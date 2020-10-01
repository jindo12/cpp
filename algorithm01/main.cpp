#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void q_sort(int ary[], int left, int right) {

	if (left < right) {

		int somewhere = (left + right) / 2;
		int pivot = ary[somewhere];	// pivotは真ん中

		ary[somewhere] = ary[left];
		int p = left;

		for (int i = left + 1; i <= right; i++) {
			if (ary[i] < pivot) {
				p = p + 1;
				swap(ary[p], ary[i]);
			}
		}

		ary[left] = ary[p];
		ary[p] = pivot;

		// pivotより小さいグループにsort
		q_sort(ary, left, p - 1);
		// pivotより大きいグループにsort
		q_sort(ary, p + 1, right);
	}
}

int main(int argc, char const* argv[])
{

	/** QuickSort **/
	int ary1[] = { 3,4,5,2,1 };

	// q_sprt(配列、左端添字、右端添字)
	q_sort(ary1, 0, sizeof(ary1) / sizeof(ary1[0]) - 1);

	for (int i = 0; i < sizeof(ary1) / sizeof(ary1[0]); i++) {
		cout << ary1[i] << " ";
	}


	/** BubbleSort **/
	int array[] = { 3,4,5,2,1 };
	// ascending order
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		for (int j = i + 1; j < sizeof(array) / sizeof(array[0]); j++) {
			if (array[i] > array[j]) {
				swap(array[i], array[j]);
			}
		}
	}

	// descending order
	for (int i = sizeof(array) / sizeof(array[0]) - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (array[j] < array[i]) {
				swap(array[i], array[j]);
			}
		}
	}


	return 0;
}

