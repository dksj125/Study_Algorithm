#include<stdio.h>
#include "Ch_4_IntQueue.h"

int main() {
	IntQueue que;

	if (Initialize(&que, 64) == -1) {
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}
	while (1) {
		int m, x;
		int idx;

		printf("현재 데이터 수: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)인덱스 찾기 (6)찾기 (7)용량 (8)데이터 갯수 (9)EMPTY? (10)FULL? (11)비우기 (0)종료 : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1:
			printf("데이터 : "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;
		
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습다.");
			else
				printf("디큐한 데이터는 %d입니다\n", x);
			break;

		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;
			
		case 4:
			Print(&que);
			break;
		case 5:
			printf("찾을 데이터 : "); scanf("%d", &x);
			idx = Search2(&que, x);
			if (idx == -1)
				printf("찾으시는 데이터가 없습니다.\n");
			else
				printf("찾으시는 데이터가 front로부터 %d 뒤에 있습니다.\n", idx);
			break;
		case 6:
			printf("찾을 데이터 : "); scanf("%d", &x);
			idx = Search2(&que, x);
			if (idx == -1)
				printf("찾으시는 데이터가 없습니다.\n");
			else
				printf("찾으시는 데이터가 %d에 있습니다.\n", idx);
			break;
		case 7:
			printf("총 용량 : %d\n", Capacity(&que));
			break;
		case 8:
			printf("큐에 존재하는 데이터 갯수 : %d\n", Size(&que));
			break;
		case 9:
			if (IsEmpty(&que) != 0)
				printf("비어있습니다.\n");
			else
				printf("비어있지 않습니다.\n");
			break;
		case 10:
			if (IsFull(&que) != 0)
				printf("꽉 차 있네요.\n");
			else
				printf("꽉 차 있지않아요.\n");
			break;
		case 11:
			Clear(&que);
			printf("비우기 완료\n");
			break;
		}
	}
	Terminate(&que);

	return 0;
}