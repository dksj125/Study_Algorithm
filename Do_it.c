
//�ǽ� 3C-1
/*
#include<stdio.h>

int sum(int x1, int x2) {
	return x1 + x2;
}

int mul(int x1, int x2) {
	return x1 * x2;
}

void kuku(int (*calc)(int, int)) {
	int i, j;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%3d", (*calc)(i, j));
		}
		putchar('\n');
	}
}

int main(void) {
	puts("����ǥ");
	kuku(sum);
	puts("\n ����ǥ");
	kuku(mul);

	return 0;
}
*/


//�ǽ� 3-7
/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
	char name[10];
	int height;
	int weight;
} Person;

int npcmp(const Person* x, const Person* y) {`
	return strcmp(x->name, y->name);
}

int main() {
	Person x[] = {
		{"�迵��", 179, 79},
		{"������", 172, 63},
		{"�̼���", 176, 52},
		{"������", 165, 51},
		{"������", 181, 73},
		{"ȫ����", 172, 84},
	};
	int nx = sizeof(x) / sizeof(x[0]); //�迭 x�� ��� ����
	int retry;
	puts("�̸����� �˻��մϴ�.");
	do {
		Person temp, *p;
		printf("�̸� : ");
		scanf("%s", temp.name);
		p = bsearch(&temp, x, nx, sizeof(Person),
			(int(*)(const void *, const void *)) npcmp);
		if (p == NULL)
			puts("�˻��� �����߽��ϴ�.");
		else {
			puts("�˻� ���� !! �Ʒ� ��Ҹ� ã�ҽ��ϴ�.");
			printf("x[%d] : %s %dcm %dkg\n", (int)(p - x), p->name ,p->height, p->weight);
		}
		printf("�ٽ� �˻��ұ��? (1) �� / (2) �ƴϿ�: ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;

}
*/

//Q3-6
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int int_cmp(const int*a, const int*b) {
	if (*a > *b) return -1;
	else if (*a < * b) return 1;
	else return 0;
}

int main() {

	long *arr;
	int n, i;
	int search;
	int *result;
	scanf("%d", &n);
	arr = calloc(n, sizeof(int));

	puts("������������ �Է��ϼ���!!");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (i > 0 && arr[i - 1] < arr[i]) {
			puts("�ٽ� �Է��ϼ���!");
			i--;
		}
	}

	printf("� ���� ã�� �;��? : ");
	scanf("%d", &search);

	result = bsearch(&search, arr, n, sizeof(int), (int(*)(const void *,const void*)) int_cmp);

	if (result == NULL)
		puts("�˻��� ������!!");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", search, (int)(result - arr));

	free(arr);

	return 0;
}
*/

//Q3-7
/*
#define _CRT_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void* seqsearch(const void* key, void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*)) {
	size_t i;
	char* x = (char*)base;

	for (i = 0; i < nmemb; i++)
		if (!compar((const void*)&x[i * size], key))
			return(&x[i * size]);
	return NULL;
}

int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > * b)
		return 1;
	else
		return 0;
}

int main() {
	int i, nx, ky;
	int* x;
	int* p;

	puts("seqsearch �Լ��� ����Ͽ� �˻�");
	printf("��ڼ� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("�˻� �� : ");
	scanf("%d", &ky);

	p = seqsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	if (p == NULL)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));

	free(x);

	return 0;
}
*/

//Q3-8
/*
#define _CRT_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void* binsearch(const void* key, 
				const void* base, 
				size_t nmemb, 
				size_t size, 
				int(*compar)(const void*, const void*))
{
	size_t start = 0;
	size_t end = nmemb - 1;
	size_t mid;
	char* x = (char*)base;
	printf("char* = %c\n", x);
	printf("int* = %d\n", (int*)x);

	if (nmemb > 0) {
		while (1) {
			int comp = compar((const void*) & x[(mid = (start + end) / 2) * size], key);
			if (comp == 0)
				return &x[mid * size];
			else if (start == end)
				break;
			else if (comp < 0)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	return NULL;
}

int int_cmp(const int* a, const int* b) {
	if (*a < *b)
		return -1;
	else if (*a > * b)
		return 1;
	else
		return 0;
}

int main() {

	int i, arr_n, ky;
	int* arr;
	int* p;
	printf("��ڼ�: ");
	scanf("%d", &arr_n);
	
	arr = calloc(arr_n, sizeof(int));

	for (i = 0; i < arr_n; i++) {
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	printf("ã�� ���� ���� : ");
	scanf("%d", &ky);

	p = binsearch(&ky, arr, arr_n, sizeof(int), (int(*)(const void*,const void*))int_cmp);

	if (p == NULL)
		printf("ã�����ϴ� ���� �����ϴ�!!\n");
	else
		printf("%d�� arr[%d]�� �ֳ׿�.\n", ky, (p-arr));
	printf("p-arr(%d - %d) = %d\n", p, arr,p-arr);

	free(arr);

	return 0;
}
*/

#define _CRT_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {

	int* x;
	int n, i;
	scanf("%d", &n);

	x = calloc(n, sizeof(x));

	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	for (i = 0; i < n; i++) {
		printf("%d\n", sizeof(x[i]));
	}
	printf("===========================\n");
	for (i = 0; i < n; i++) {
		printf("%d\n", sizeof((char *)x[i]));
	}


	return 0;
 }
