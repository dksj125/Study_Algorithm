#include<stdio.h>
#include "Ch_4_IntQueue.h"

int main() {
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("ť�� ������ �����Ͽ����ϴ�.");
		return 1;
	}
	while (1) {
		int m, x;
		int idx;

		printf("���� ������ ��: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)�ε��� ã�� (6)ã�� (7)�뷮 (8)������ ���� (9)EMPTY? (10)FULL? (11)���� (0)���� : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1:
			printf("������ : "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			break;
		
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a���� : ��ť�� �����Ͽ�����.");
			else
				printf("��ť�� �����ʹ� %d�Դϴ�\n", x);
			break;

		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;
			
		case 4:
			Print(&que);
			break;
		case 5:
			printf("ã�� ������ : "); scanf("%d", &x);
			idx = Search2(&que, x);
			if (idx == -1)
				printf("ã���ô� �����Ͱ� �����ϴ�.\n");
			else
				printf("ã���ô� �����Ͱ� front�κ��� %d �ڿ� �ֽ��ϴ�.\n", idx);
			break;
		case 6:
			printf("ã�� ������ : "); scanf("%d", &x);
			idx = Search2(&que, x);
			if (idx == -1)
				printf("ã���ô� �����Ͱ� �����ϴ�.\n");
			else
				printf("ã���ô� �����Ͱ� %d�� �ֽ��ϴ�.\n", idx);
			break;
		case 7:
			printf("�� �뷮 : %d\n", Capacity(&que));
			break;
		case 8:
			printf("ť�� �����ϴ� ������ ���� : %d\n", Size(&que));
			break;
		case 9:
			if (IsEmpty(&que) != 0)
				printf("����ֽ��ϴ�.\n");
			else
				printf("������� �ʽ��ϴ�.\n");
			break;
		case 10:
			if (IsFull(&que) != 0)
				printf("�� �� �ֳ׿�.\n");
			else
				printf("�� �� �����ʾƿ�.\n");
			break;
		case 11:
			Clear(&que);
			printf("���� �Ϸ�\n");
			break;
		}
	}
	Terminate(&que);

	return 0;
}