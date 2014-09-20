#include <conio.h>
#include <stdio.h>

#define arr_length 8

/*
Kadane’s Algorithm:
Does not work with all Positive
*/

int KadaneAlgorithm(int *arr_1, int arr_length_1) {
	int max_so_far = 0;
	int max_ending_here = 0;

	for (int i = 0; i < arr_length_1; i++) {
		max_ending_here = max_ending_here + arr_1[i];
		if (max_ending_here < 0) max_ending_here = 0;
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;
	}
	return max_so_far;
}

void main() {
	int arr[arr_length]  = {-2,-3,4,-1,-2,1,5,-3};

	int max_KadaneAlgorithm = KadaneAlgorithm(arr,arr_length);

	printf("%d\n", max_KadaneAlgorithm);
}