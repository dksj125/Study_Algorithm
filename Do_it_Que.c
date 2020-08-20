#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int max; //큐의 용량
	int num; //현재 데이터 수
	int* q;  //큐의 첫 요소에 대한 포인터
} ArrayIntQeue;

int Initialize(ArrayIntQeue* qu, int max) {
	qu->num = 0;
	if ((qu->q = calloc(max, sizeof(int))) == NULL) {
		qu->max = 0;
		return -1;
	}
	qu->max = max;
	return 0;
}

int InQeue(ArrayIntQeue* qu, int x) {
	if (qu->num >= qu->max)
		return -1;
	qu->q[qu->num++] = x;
	return 0;
}

int DeQeue(ArrayIntQeue* qu, int* x) {
	int i;
	if (qu->num <= 0)
		return -1;
	*x = qu->q[0];
	for (i = 0; i < (qu->num)-1; i++) {
		qu->q[i] = qu->q[i + 1];
	}
	qu->q[qu->num] = 0;
	qu->num--;
}

void Print(const ArrayIntQeue* qu) {
	int i;
	for (i = 0; i < qu->num; i++) {
		printf("%d ", qu->q[i]);
	}
	putchar('\n');
}

int main() {
	ArrayIntQeue qu;
	int x, menu;
	Initialize(&qu, 8);
	while (1) {
		printf("(1) 인큐, (2) 디큐, (3) 출력, (4) 종료 : ");
		scanf("%d", &menu);
		if (menu == 1) {
			printf("데이터 : ");
			scanf("%d", &x);
			if (InQeue(&qu, x) == -1)
				puts("\a오류: 인큐에 실패하였습니다.");
		}
		else if (menu == 2) {
			if (DeQeue(&qu, &x) == -1)
				puts("\a오류: 디큐에 실패하였습니다.");
			else
				printf("디큐 데이터는 %d입니다.\n", x);
		}
		else if (menu == 3) {
			Print(&qu);
		}
		else if (menu == 4) {
			puts("프로그램을 종료합니다.");
			break;
		}
	}
	
	return 0;
}