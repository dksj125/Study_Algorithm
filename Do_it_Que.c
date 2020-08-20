#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int max; //ť�� �뷮
	int num; //���� ������ ��
	int* q;  //ť�� ù ��ҿ� ���� ������
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
		printf("(1) ��ť, (2) ��ť, (3) ���, (4) ���� : ");
		scanf("%d", &menu);
		if (menu == 1) {
			printf("������ : ");
			scanf("%d", &x);
			if (InQeue(&qu, x) == -1)
				puts("\a����: ��ť�� �����Ͽ����ϴ�.");
		}
		else if (menu == 2) {
			if (DeQeue(&qu, &x) == -1)
				puts("\a����: ��ť�� �����Ͽ����ϴ�.");
			else
				printf("��ť �����ʹ� %d�Դϴ�.\n", x);
		}
		else if (menu == 3) {
			Print(&qu);
		}
		else if (menu == 4) {
			puts("���α׷��� �����մϴ�.");
			break;
		}
	}
	
	return 0;
}