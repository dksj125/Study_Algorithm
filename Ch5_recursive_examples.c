//�ǽ� 5-1 factorial
/*
#include<stdio.h>

int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main() {

	int x;
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);
	printf("%d�� �������� ���� %d�Դϴ�.\n", x, factorial(x));


	return 0;
}
*/

//�ǽ� 5-2 Euclidean method of mutual division
/*
#include<stdio.h>

int gcd(int x, int y) {

	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main() {
	int x, y;
	puts("�� ������ �ִ������� ���մϴ�.");
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &y);
	printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));


	return 0;
}
*/