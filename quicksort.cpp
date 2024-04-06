#include <iostream>

void print_array(int* array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << (array[i]) << std::endl;
	}
}

int partition(int array[], int start, int end) {
	int pivot = array[end];
	int i = start - 1;
	for (int j = start; j <= end - 1; j++)
	{
		if (array[j] < pivot) {
			i++;
			int temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	i++;
	int temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	return i;
}

void quickSort(int array[], int start, int end) {
	if (end <= start) return;
	int pivot = partition(array, start, end);
	quickSort(array, start, pivot - 1);
	quickSort(array, pivot + 1, end);
}

int main() {
	int array[] = { 9, 11, 0, 6, 3, 6 ,7, 4, 3, 2, 1 };
	int n = sizeof(array) / sizeof(array[0]);
	print_array(array, n);
	quickSort(array, 0, n -1);
	std::cout << "----------------" << std::endl;
	print_array(array, n);

}