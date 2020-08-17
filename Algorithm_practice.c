// 백준 2775
/*
#include<stdio.h>

int main() {

	int t, k, n, i, j, l;
	int arr[15][15] = { 0, };
	for (i = 0; i < 15; i++)
		arr[0][i] = i;
	for (i = 1; i < 15; i++) {
		for (j = 1; j < 15; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", arr[k][n]);
	}


	return 0;
}
*/


// 백준 2798
/*
#include<stdio.h>

int arr[101];

int main() {

	int N, M, i, j, k;
	int num1 = 0;
	int p = 0;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N-2; i++) {
		for (j = i+1; j < N-1; j++) {
			for (k = j+1; k < N; k++) {
				if(i != k && i != j && j!=k)
					p = arr[i] + arr[j] + arr[k];
				if (num1 < p && p <= M) {
					num1 = p;
				}
			}
		}
	}
	printf("%d", num1);

	return 0;
}
*/

// 백준 2231
/*
#include<stdio.h>
int main() {
	int num, i;
	int result = 0;
	int tmp = 0;
	scanf("%d", &num);

	if (num < 10) {
		result = num;
	}
	else if (10 <= num && num < 100) {
		for (i = 10; i < num; i++) {
			tmp = (i / 10) + (i % 10);
			if (tmp == num) {
				result = i;
				break;
			}
			else
				result = 0;
		}
	}
	else if (100 <= num && num < 1000) {
		for (i = 100; i < num; i++) {
			tmp =i + (i / 100) + ((i - (i / 100) * 100) / 10) +(i % 10);
			if (tmp == num) {
				result = i;
				break;
			}
			else
				result = 0;
		}
	}
	else if (1000 <= num && num < 10000) {
		for (i = 1000; i < num; i++) {
			tmp =i + (i / 1000) + ((i-(i/1000)*1000) / 100)
				 + ((i - (i / 100) * 100) / 10) + (i % 10);  //2459 = 2459 + 4 + 5 + 9
			if (tmp == num) {
				result = i;
				break;
			}
			else
				result = 0;
		}
	}
	else if (10000 <= num && num <= 100000) {
		for (i = 10000; i < num; i++) {
			tmp = i + (i / 10000) + ((i - (i / 10000) * 10000) / 1000) + ((i - (i / 1000) * 1000) / 100)
				+ ((i - (i / 100) * 100) / 10) + (i % 10);  //245910 = 2459 + 4 + 5 + 9 + 1
			if (tmp == num) {
				result = i;
				break;
			}
			else
				result = 0;
		}
	}
	else if (100000 <= num && num <= 1000000) {
		for (i = 100000; i < num; i++) {
			tmp = i + (i / 100000) + ((i - (i / 100000) * 100000) / 10000)
				+ ((i - (i / 10000) * 10000) / 1000) + ((i - (i / 1000) * 1000) / 100)
				+ ((i - (i / 100) * 100) / 10) + (i % 10);  
			if (tmp == num) {
				result = i;
				break;
			}
			else
				result = 0;
		}
	}

	printf("%d\n", result);

	return 0;
}


------------------간편한 방법-------------------------------

int share(int n, int sum) {
	sum += n % 10;
	n = n / 10;

	if (n > 0)
		return share(n, sum);
	else
		return sum;
}

int main() {
	int check = 0;
	int num, i;
	int result = 0;
	int tmp = 0;
	scanf("%d", &num);

	for (i = 10; i <= num; i++) {
		tmp = i;
		tmp = share(i, tmp);

		if (tmp == num) {
			printf("%d\n", i);
			check = 1;
			break;
		}
	}
	if (check == 0)
		printf("%d\n", 0);

	return 0;
}
*/


//백준 1252
#include<stdio.h>

int main() {

	int bill;
	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	int i;
	int num = 0;
	int balance;

	scanf("%d", &bill);
	
	balance = 1000 - bill;

	for (i = 0; i < 6; i++) {
		if (balance / coin[i] != 0) {
			num += balance / coin[i];
		}
		balance = balance % coin[i];
	}

	printf("%d", num);

	return 0;
}