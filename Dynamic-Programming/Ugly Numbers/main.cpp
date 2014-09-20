#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define ugly_150 5

int min(int a, int b) {
	return (a<b) ? a:b;
}

int min(int a, int b, int c) {
	return min(min(a,b),c);
}

void main() {
	int *a = (int*) malloc(ugly_150 * sizeof(int));
	int i = 0;
	
	// init 
	a[i] = 1;
	int i2 = a[i];
	int i3 = a[i];
	int i5 = a[i];

	while (i < ugly_150) {
		
		int min_no = min(i2*2,i3*3,i5*5);
		a[++i] = min_no;

		if (min_no == i2*2) {
			i2++;
		} else if (min_no == i3*3) {
			i3++;
		}else if (min_no == i5*5) {
			i5++;
		}
	}

	printf ("%d\n",a[ugly_150]);

}