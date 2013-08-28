#include <stdio.h>

int binary_search(int a[], int low, int high, int key) {
	
	int middle = (low + high) / 2;
	if (key == a[middle])
		return middle;
	else if (key < a[middle])
		binary_search(a, low, middle - 1, key);
	else if (key > a[middle])
		binary_search(a, middle + 1, high, key);
	else
		return -1;
	
}


int main() {

	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int value = 8;
	
	printf("%d\n", binary_search(a, 0, 9, value));
	
	

	return 0;
	
}