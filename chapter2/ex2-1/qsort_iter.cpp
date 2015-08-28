
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

template<class RandomAccessIterator>
static RandomAccessIterator qsort_partition(RandomAccessIterator first, RandomAccessIterator last);

/* Iterative implementation of QuickSort */
template <class RandomAccessIterator>
void qsort_iter(RandomAccessIterator first, RandomAccessIterator last) {

	if (first == last)
		return;

	typedef pair<RandomAccessIterator, RandomAccessIterator> elem_t;

	queue<elem_t> partitions;
	partitions.push(elem_t(first, last));

	while (!partitions.empty()) {

		elem_t next_partition = partitions.front();
		partitions.pop();

		RandomAccessIterator pivot;
		pivot = qsort_partition(next_partition.first, next_partition.second);

		if (pivot != next_partition.first)
			partitions.push(elem_t(next_partition.first, pivot));
		if (pivot+1 != next_partition.second)
			partitions.push(elem_t(pivot+1, next_partition.second));
	}
}

/* qsort_partition() is an auxiliary function that partitions the range [first, last[ around the
 * middle value, placing every element less than the middle before every element greater than or
 * equal to the middle.
 */
template<class RandomAccessIterator>
static RandomAccessIterator qsort_partition(RandomAccessIterator first, RandomAccessIterator last) {
	swap(*first, *(first+(last-first)/2));
	RandomAccessIterator end = first;

	for (RandomAccessIterator curr = first+1; curr != last; curr++)
		if (*curr < *first)
			swap(*++end, *curr);

	swap(*first, *end);

	return end;
}

static void print_arr(const vector<int> &arr) {
	cout << "{ ";
	if (arr.size() > 0)
		cout << arr[0];
	for (vector<int>::size_type i = 1; i < arr.size(); i++)
		cout << ", " << arr[i];
	cout << " }";
}

int main(void) {

	cout << "Enter the size of the array, followed by the elements." << endl;
	cout << "> ";

	vector<int>::size_type arr_sz;
	while (cin >> arr_sz) {
		vector<int> arr(arr_sz);

		for (vector<int>::size_type i = 0; i < arr_sz; i++)
			cin >> arr[i];

		cout << "Original: ";
		print_arr(arr);
		cout << endl;

		qsort_iter(arr.begin(), arr.end());

		cout << "Sorted: ";
		print_arr(arr);
		cout << endl;

		cout << "> ";		
	}

	return 0;
}
