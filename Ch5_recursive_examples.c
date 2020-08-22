//실습 5-1 factorial
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
	printf("정수를 입력하세요 : ");
	scanf("%d", &x);
	printf("%d의 순차곱셈 값은 %d입니다.\n", x, factorial(x));


	return 0;
}
*/

//실습 5-2 Euclidean method of mutual division
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
	puts("두 정수의 최대공약수를 구합니다.");
	printf("정수를 입력하세요 : ");
	scanf("%d", &x);
	printf("정수를 입력하세요 : ");
	scanf("%d", &y);
	printf("최대공약수는 %d입니다.\n", gcd(x, y));


	return 0;
}
*/