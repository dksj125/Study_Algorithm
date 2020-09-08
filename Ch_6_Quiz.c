
//Q1
/*
#include<stdio.h>
#include<stdlib.h>
#define swap(type, x, y) do{type t = x ; x = y; y = t;} while(0)

void bubble(int a[], int n) {
	int i, j;
	for (i = 1; i < n - 1; i++) {
		for (j = i; j < n - 1; j++)
			if (a[j] > a[j + 1])
				swap(int, a[j], a[j + 1]);
	}
}

int main() {
	int i, nx;
	int* x;

	puts("버블 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
*/

//Q3
/*
#include<stdio.h>
#include<stdlib.h>

void bubble(int arr[], int nx) {
	int i, j;
	int tmp;
	for (i = 1; i < nx - 1; i++) {
		int ex = 0;
		for (j = 0; j < nx-i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				ex++;
			}
		}
		if (ex == 0) {
			break;
		}
	}
}

int is_sorted(const int a[], int n) {
	int i;
	int ex = 0;
	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			ex++;
		}
	}
	if (ex == 0) {
		return 1;
	}
	else
		return 0;
}

int main() {
	int* arr;
	int* arr_2;
	int nx;
	int i;
	printf("요수 개수 : ");
	scanf("%d", &nx);
	arr = calloc(nx, sizeof(int));
	arr_2 = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
		arr_2[i] = arr[i];
	}

	bubble(arr, nx);
	printf("arr = %d\n", is_sorted(arr, nx));
	printf("arr_2 = %d", is_sorted(arr_2, nx));
	free(arr);
	free(arr_2);

	return 0;
}
*/

//Q6
/*#include<stdio.h>

void shaker(int arr[], int n) {
	int first = 0;
	int last = n - 1;
	while (first <= last) {
		for (int i = first; i < last; i++) {
			if (arr[first] > arr[i]) {
				int temp = arr[i];
				arr[i] = arr[first];
				arr[first] = temp;
			}
			else if (arr[i] > arr[last]) {
				int temp = arr[i];
				arr[i] = arr[last];
				arr[last] = temp;
			}
		}
		first++;
		last--;
	}

}

int main() {
	int arr[] = { 9,1,3,4,5,6,7,8 };
	int size = sizeof(arr) / sizeof(int);
	shaker(arr, size);
	for (int i = 0; i < size; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}
*/

//Q9
/*
#include<stdio.h>
#include<stdlib.h>

void insertion(int a[], int n) {
	int i, j;
	for (i = 1; i < n+1; i++) {
		int tmp = a[0] = a[i];
		for (j = i; a[j - 1] > tmp; j--) {
			a[j] = a[j - 1];
		}
		printf("%d : a[0] = %d\n", i, a[0]);
		if (j) a[j] = tmp;
	}

}

int main() {

	int i, nx;
	int* x;
	puts("x[0]을 보초로 지정한 단순 삽입 정렬");

	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx+1, sizeof(int));

	for (i = 1; i < nx + 1; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);

	for (i = 1; i < nx+1; i++) {
		printf("x[%d] : %d\n", i, x[i]);
	}

	free(x);


	return 0;
}
*/

//Q10(이진삽입 정렬)
/*
#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[], int n, int in) {
	int first = 0;
	int middle;
	int end = n-1;
	int idx;
	int i;
	middle = (first + end) / 2;

	do {
		middle = (first + end) / 2;
		if (arr[middle] > in) {
			first = middle + 1;
			idx = middle;
		}
		else {
			end = middle - 1;
			idx = middle;
		}
	} while (middle >= first);
	printf("%d\n", middle);
	for (i = n-1; i > idx; i--) {
		arr[i]= arr[i-1];
	}
	arr[idx] = in;
}

int main() {
	int nx;
	int i;
	int insert_number;
	int* x;
	int idx;
	printf("요소 갯수: ");
	scanf("%d", &nx);
	x = calloc(nx+1, sizeof(int));
	puts("오름차순으로 입력해주세요.");

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
		if (i > 0 && x[i - 1] > x[i]) {
			printf("오름차순!!!!!!!!!!!!\n");
			i -= 1;
		}
	}
	printf("삽입할 수: ");
	scanf("%d", &insert_number);

	BinarySearch(x, nx+1, insert_number);

	for (i = 0; i < nx + 1; i++) {
		printf("%d ", x[i]);
	}

	free(x);

	return 0;
}
*/

//Q11(Memmove를 이용한 이진 삽입 정렬
/*
#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int arr[], int n, int in) {
	int first = 0;
	int middle;
	int end = n - 1;
	int idx;
	int i;
	middle = (first + end) / 2;

	do {
		middle = (first + end) / 2;
		if (arr[middle] > in) {
			first = middle + 1;
			idx = middle;
		}
		else {
			end = middle - 1;
			idx = middle;
		}
	} while (middle >= first);
	memmove(&arr[idx+1], &arr[idx], sizeof(int) * (n-idx));
	arr[idx] = in;
}

int main() {
	int nx;
	int i;
	int insert_number;
	int* x;
	int idx;
	printf("요소 갯수: ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
	puts("오름차순으로 입력해주세요.");

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
		if (i > 0 && x[i - 1] > x[i]) {
			printf("오름차순!!!!!!!!!!!!\n");
			i -= 1;
		}
	}
	printf("삽입할 수: ");
	scanf("%d", &insert_number);

	BinarySearch(x, nx+1, insert_number);

	for (i = 0; i < nx+1; i++) {
		printf("%d ", x[i]);
	}

	free(x);

	return 0;
}
*/