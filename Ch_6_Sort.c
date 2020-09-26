
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
/*
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
*/


/*Quick Sort*/

// practice 6-8 피벗기준으로 나누기
/*
#include<stdio.h>
#include<stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void partition(int a[], int n) {
	int i;
	int pl = 0;
	int pr = n - 1;
	int x = a[n / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	printf("피벗의 값은 %d입니다.\n", x);
	printf("피벗 이하의 그룹\n");
	for (i = 0; i <= pl - 1; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
	if (pl > pr + 1) {
		printf("피벗과 일치하는 그룹\n");
		for (i = pr + 1; i <= pl - 1; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	printf("피벗 이상의 그룹\n");
	for (i = pr + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}


int main() {

	int i, nx;

	int* x;
	puts("배열을 나눕니다.");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	partition(x, nx);
	free(x);

	return 0;
}
*/


//practice 6-9
/*퀵 정렬 함수*/
/*
#include<stdio.h>
#include<stdlib.h>
#define swap(type, x, y) do{type t = x ; x= y; y = t;} while(0)



void quick(int a[], int left, int right) {
	int pl = left;
	int pr = right;
	int x = a[(pl + pr) / 2];
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	if (left < pr) quick(a, left, pr);
	if (pl < right) quick(a, pl, right);
}

int main() {
	int i, nx;
	int* x;
	puts("퀵 정렬");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	quick(x, 0, nx - 1);
	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}
*/

//practice 6-12
/*qsort함수 사용하기*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[10];
	int height;
	int weight;
}Person;


int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name, y->name);
}

int hpcmp(const Person* x, const Person* y) {
	return x->height < y->height ? -1 :
		x->height > y->height ? 1:0;
}

int wpcmp(const Person* x, const Person* y) {
	return x->weight < y->weight ? 1 :
		x->weight > y->weight ? -1 : 0;
}

void print_person(const Person x[], int no) {
	int i;
	for (i = 0; i < no; i++) {
		printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
	}
}

int main() {
	Person x[] = {
		{"sunmi", 170, 52},
		{"yoobun", 180, 70},
		{"soohee", 172, 63},
		{"jina", 165, 50},
	};

	int nx = sizeof(x) / sizeof(x[0]);

	puts("정렬 전");
	print_person(x, nx);


	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))npcmp);
	puts("\n이름 오름차순으로 정렬 후");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))hpcmp);
	puts("\n키 오름차순으로 정렬 후");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))wpcmp);
	puts("\n몸무게 오름차순으로 정렬 후");
	print_person(x, nx);

	return 0;
}
*/


//practice 6-14
/*병합 정렬*/
/*
#include<stdio.h>

void merge(const int a[],int na,const int b[], int nb, int c[]) {
	int pa = 0;
	int pb = 0;
	int pc = 0;
	while (pa < na && pb < nb)
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];
	while (pa < na)
		c[pc++] = a[pa++];
	while (pb < na)
		c[pc++] = b[pb++];
}

int main() {

	int i, na, nb;
	int* a, * b, * c;
	printf("a의 요소 개수 : "); scanf("%d", &na);
	printf("b의 요소 개수 : "); scanf("%d", &nb);
	a = calloc(na, sizeof(int));
	b = calloc(nb, sizeof(int));
	c = calloc(na + nb, sizeof(int));

	printf("a[0]: ");
	scanf("%d", &a[0]);
	for (i = 1; i < na; i++) {
		do {
			printf("a[%d] : ", i);
			scanf("%d", &a[i]);
		} while (a[i] < a[i - 1]);
	}
	printf("b[0] : "); scanf("%d", &b[0]);

	for (i = 1; i < nb; i++) {
		do {
			printf("b[%d] : ", i);
			scanf("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}

	merge(a, na,b, nb, c);
	puts("배열 a와 b를 병합하여 배열 c에 저장했습니다.");
	for (i = 0; i < na + nb; i++) {
		printf("c[%d] = %d\n", i, c[i]);
	}

	free(a);
	free(b);
	free(c);

	return 0;
}
*/

//practice 6-15

#include<stdio.h>
#include<stdlib.h>

static int* buff;

static void __mergesort(int a[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;
		__mergesort(a, left, center);
		__mergesort(a, center + 1, right);
		for (i = left; i <= center; i++)
			buff[p++] = a[i];
		while (i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while (j < p)
			a[k++] = buff[j++];
	}
}

int mergesort(int a[], int n) {
	if ((buff = calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);
	free(buff);
	return 0;
}

int main() {
	int i, nx;
	int* x;
	puts("병합 정렬");
	printf("요소 개수 : "); scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}
	mergesort(x, nx);

	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}