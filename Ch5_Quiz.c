//Q1 make factorial function without using recursive
/*
#include<stdio.h>

int factorial(int x) {
	int fac = 1;
	for (; x >= 1; x--) {
		fac *= x;
	}
	return fac;
}

int main() {
	int n;
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &n);
	printf("%d�� ���� ������ %d�Դϴ�.", n, factorial(n));
	return 0;

}
*/



/*Q2 make gcd function wihout using recursive*/
/*
#include<stdio.h>

int gcd(int x, int y) {
	int tmp;
	while (1) {
		tmp = x;
		x = y;
		y = tmp % y;
		if (y == 0) {
			break;
		}
	}

	return x;
}

int main() {
	int x, y;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &y);
	printf("%d�� %d�� �ִ� ������� %d�Դϴ�.\n", x, y, gcd(x,y));

	return 0;
}
*/



//Q3 find gcd in array of elements

#include<stdio.h>
#include<stdlib.h>

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int gcd_array(const int a[], int n) {
	int i;
	int gc;
	gc = gcd(a[0], a[1]);
	printf("%d\n", gc);
	for (i = 2; i < n; i++) {
		gc = gcd(gc, a[i]);
		printf("%d\n", gc);
	}
	return gc;
}


int main() {
	int N, i;
	int *arr;
	scanf("%d", &N);
	arr = calloc(N, sizeof(int));

	for (i = 0; i < N; i++) {
		printf("arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}

	printf("arr���� ���ڵ��� �ּ� ������� %d�Դϴ�.\n",gcd_array(arr, N));

	free(arr);

	return 0;
}