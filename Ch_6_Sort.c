
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

	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
*/

//practice 6-2(6-1 ����)
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
		if (exchg == 0) break;				// ������ �� �Ǿ����� ����
	}
}

int main() {
	int i, nx;
	int* x;

	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}
*/

//practice 6-3(6-2 ����)
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

	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
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

	puts("�ܼ� ���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	selection(x, nx);

	puts("������������ �����߽��ϴ�.");
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

	puts("�ܼ� ���� ����");

	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx);

	puts("������������ �����߽��ϴ�.");
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
	printf("%dȸ ��ȯ�߽��ϴ�.\n", cnt);
}

int main() {
	int i, nx;
	int* x;
	puts("�� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shell(x, nx);
	puts("������������ �����߽��ϴ�.");
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

	puts("�� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	shell(x, nx);

	puts("������������ �����߽��ϴ�.");
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

// practice 6-8 �ǹ��������� ������
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
	printf("�ǹ��� ���� %d�Դϴ�.\n", x);
	printf("�ǹ� ������ �׷�\n");
	for (i = 0; i <= pl - 1; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
	if (pl > pr + 1) {
		printf("�ǹ��� ��ġ�ϴ� �׷�\n");
		for (i = pr + 1; i <= pl - 1; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	printf("�ǹ� �̻��� �׷�\n");
	for (i = pr + 1; i < n; i++)
		printf("%d ", a[i]);
	putchar('\n');
}


int main() {

	int i, nx;

	int* x;
	puts("�迭�� �����ϴ�.");
	printf("��� ���� : ");
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
/*�� ���� �Լ�*/
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
	puts("�� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	quick(x, 0, nx - 1);
	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}
*/

//practice 6-12
/*qsort�Լ� ����ϱ�*/

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

	puts("���� ��");
	print_person(x, nx);


	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))npcmp);
	puts("\n�̸� ������������ ���� ��");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))hpcmp);
	puts("\nŰ ������������ ���� ��");
	print_person(x, nx);

	qsort(x, nx, sizeof(Person), (int(*)(const void*, const void*))wpcmp);
	puts("\n������ ������������ ���� ��");
	print_person(x, nx);

	return 0;
}