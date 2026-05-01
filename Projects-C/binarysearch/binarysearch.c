#include <stdio.h>
#include "binarysearch.h"

int binary_search(int *arr, int size, int key){
	int low = 0;
	int high = size - 1;

	while (low <= high){
		int mid = low + (high - low) / 2;
		if (arr[mid] == key)
			return mid;
		if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
