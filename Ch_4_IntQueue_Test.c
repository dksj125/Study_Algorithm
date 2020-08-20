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

		printf("���� ������ ��: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (0)���� : ");
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
		}
	}
	Terminate(&que);

	return 0;
}