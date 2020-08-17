#include<stdio.h>
#include "Ch4_IntStack.h"

int main() {
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�뷮���� (6)���? (7)����? (8)ã�� (9)���� (0)���� : ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu) {

		case 1:
			printf("������ : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a����: Ǫ���� �����Ͽ����ϴ�.");
			break;

		case 2:
			if (Pop(&s, &x) == -1)
				puts("\a����: �˿� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:
			if (Peek(&s, &x) == -1)
				puts("\a����: ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4:
			Print(&s);
			break;
		
		case 5:
			printf("������ �� �뷮�� %d �Դϴ�.\n", Capacity(&s));
			break;

		case 6:
			if (IsEmpty(&s) != 0)
				printf("������ ����ֱ���!\n");
			else
				printf("������ ������� �ʽ��ϴ�!.\n");
			break;

		case 7:
			if (IsFull(&s) != 0)
				printf("������ �����ֳ׿�!\n");
			else
				printf("������ ���� ���� �ʽ��ϴ�!\n");
			break;

		case 8:
			printf("ã�� ����: ");
			scanf("%d", &x);
			if (Search(&s, x) == -1)
				printf("ã���ô� %d��(��) ���ó��� �������� �ʽ��ϴ�.\n", x);
			else
				printf("ã���ô� %d��(��) ���ó� %d��°�� �����ϳ׿�.\n", x, Search(&s, x));
			break;

		case 9:
			Clear(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}