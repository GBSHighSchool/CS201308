#include <stdio.h>

int binary_search(int array[], int size, int value) {
	int left, mid, right;
	left = 0;
	right = size - 1;
	while ( left <= right) {
		mid = (left + right) / 2;
		if (array[mid] == value)
			return mid;
		if (array[mid] > value)
			right = mid - 1;
		if (array[mid] < value)
			left = mid + 1;
	}
	return -1;
}


int main() {

	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int value = 8;
	
	printf("%d\n", binary_search(a, 10, value));
	
	

	return 0;
	
}