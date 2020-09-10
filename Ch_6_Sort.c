
/*Bubble Sort*/
//practice 6-1
/*
#include<stdio.h>
#include<stdlib.h>
#define swap(type, x, y) do{type t = x ; x = y; y = t;} while(0)

void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(int, a[j - 1], a[j]);
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

//practice 6-2(6-1 개선)
/*
#include<stdio.h>
#include<stdlib.h>
#define swap(type, x, y) do{type t = x ; x = y; y = t;} while(0)

void bubble(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int exchg = 0;
		for (j = n - 1; j > i; j--)
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				exchg++;
			}
		if (exchg == 0) break;				// 정렬이 다 되었으면 종료
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

//practice 6-3(6-2 개선)
/*
#include<stdio.h>
#include<stdlib.h>
#define swap(type, x, y) do{type t = x ; x = y; y = t;} while(0)

void bubble(int a[], int n) {
	int k = 0;
	while (k < n - 1) {
		int j;
		int last = n - 1;
		for (j = n - 1; j > k; j--) {
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}
		k = last;
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


/*Straight Selection Sort*/
// practice 6-4
/*
#include<stdio.h>
#include<stdlib.h>
#define swap(type, x, y) do{type t = x ; x = y; y = t;} while(0)

void selection(int a[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(int, a[i], a[min]);
	}
}

int main() {
	int i, nx;
	int* x;

	puts("단순 선택 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	selection(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);


	return 0;
}
*/

/*Straight Insertion Sort*/
// practice 6-5
/*
#include<stdio.h>
#include<stdlib.h>

void insertion(int a[], int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		int tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void) {

	int i, nx;

	int* x;

	puts("단순 삽입 정렬");

	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
*/

/*Shell Sort*/
// practice 6-6
/*
#include<stdio.h>
#include<stdlib.h>

void shell(int a[], int n) {
	int i, j, h;
	int cnt = 0;
	for(h = n / 2 ; h > 0 ; h /= 2)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				cnt++;
			}
			a[j + h] = tmp;
		}
	printf("%d회 교환했습니다.\n", cnt);
}

int main() {
	int i, nx;
	int* x;
	puts("셸 정렬");
	printf("요소 갯수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shell(x, nx);
	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;

}
*/

//practice 6-7
/*
#include<stdio.h>
#include<stdlib.h>

void shell(int a[], int n) {
	int i, j, h;
	int cnt = 0;
	for (h = 1; h < n / 9; h = h * 3 + 1)
		;
	for(; h > 0 ; h /= 3)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				cnt++;
			}
			a[j + h] = tmp;
		}
}


int main() {

	int i, nx;
	int* x;

	puts("셀 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shell(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++) {
		printf("x[%d] = %d\n", i, x[i]);
	}
	free(x);

	return 0;
}
*/

// Example Shell Algorithm

#include<stdio.h>
void shell(int a[], int n) {
	int i, j, h;

	for (h = n / 2; h > 0; h /= 2)
		for (i = h; i < n; i++) {
			int tmp = a[i];
			for (j = i - h; j >= 0 && a[j] > tmp; j -= h)
				a[j + h] = a[j];
			a[j + h] = tmp;
		}
}

int main() {

	int a[] = { 10,8,6,20,4,3,22,1,0,15,16 };

	shell(a, sizeof(a)/sizeof(int));

	for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}