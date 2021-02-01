#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int a[100], i;
	int n,left = 0 ,right;

	void QuickSort(int *a, int left, int right);

	setbuf(stdout, NULL);

	printf("Enter number of elements : \n");
	scanf("%d",&n);

	right = n;

	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}

	QuickSort(a, left, right);

	for(i = 0; i < n; i ++){
		printf("%d\t",a[i]);
	}

	return EXIT_SUCCESS;
}

void QuickSort(int *a, int left, int right){
	int newPivotIndex;
	int partitionArray(int *a, int left, int right, int pivot);

	if(left < right){

		newPivotIndex = partitionArray(a, left, right, (left + right)/2);

		QuickSort(a, left, newPivotIndex - 1);

		QuickSort(a, newPivotIndex + 1, right);

	}

}

int partitionArray(int *a, int left, int right, int pivot){

		int lIndex;
		int i,temp;

		int pivotValue = a[pivot];

		temp = a[pivot];
		a[pivot] = a[right];
		a[right] = temp;

		lIndex = left;

		for(i = left; i < right; i++){
			if(a[i] < pivotValue){
				temp = a[i];
				a[i] = a[lIndex];
				a[lIndex] = temp;
				lIndex++;
			}
		}

		temp = a[lIndex];
		a[lIndex] = a[right];
		a[right] = temp;

		return lIndex;
}