#ifndef ___IntQueue
#define ___IntQueue

//큐를 구현하는 구조체
typedef struct {
	int max;		//큐의 최대 용량
	int num;		//현재의 요소 개수
	int front;		//프런드
	int rear;		//리어
	int* que;		//큐의 맨 앞 요소에 대한 포인터
} IntQueue;

int Initialize(IntQueue* q, int max);

int Enque(IntQueue* q, int x);

int Deque(IntQueue* q, int* x);

int Peek(const IntQueue* q, int* x);

void Clear(IntQueue* q);

int Capacity(const IntQueue* q);

int Size(const IntQueue* q);

int IsEmpty(const IntQueue* q);

int IsFull(const IntQueue* q);

int Search(const IntQueue* q, int x);

int Search2(const IntQueue* q, int x);

void Print(const IntQueue* q);

void Terminate(IntQueue* q);

#endif // !___IntQueue
