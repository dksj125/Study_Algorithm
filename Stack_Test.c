#include<stdio.h>
#include "Ch4_IntStack.h"

int main() {
	IntStack s;
	if (Initialize(&s, 64) == -1) {
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸쉬 (2)팝 (3)피크 (4)출력 (5)용량보기 (6)비워? (7)꽉차? (8)찾기 (9)비우기 (0)종료 : ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu) {

		case 1:
			printf("데이터 : ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류: 푸쉬에 실패하였습니다.");
			break;

		case 2:
			if (Pop(&s, &x) == -1)
				puts("\a오류: 팝에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;

		case 3:
			if (Peek(&s, &x) == -1)
				puts("\a오류: 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 4:
			Print(&s);
			break;
		
		case 5:
			printf("스택의 총 용량은 %d 입니다.\n", Capacity(&s));
			break;

		case 6:
			if (IsEmpty(&s) != 0)
				printf("스택이 비어있군요!\n");
			else
				printf("스택이 비어있지 않습니다!.\n");
			break;

		case 7:
			if (IsFull(&s) != 0)
				printf("스택이 꽉차있네요!\n");
			else
				printf("스택이 꽉차 있지 않습니다!\n");
			break;

		case 8:
			printf("찾을 숫자: ");
			scanf("%d", &x);
			if (Search(&s, x) == -1)
				printf("찾으시는 %d가(이) 스택내에 존재하지 않습니다.\n", x);
			else
				printf("찾으시는 %d가(이) 스택내 %d번째에 존재하네요.\n", x, Search(&s, x));
			break;

		case 9:
			Clear(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}