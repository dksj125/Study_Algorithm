#ifndef ___IntQueue
#define ___IntQueue

//ť�� �����ϴ� ����ü
typedef struct {
	int max;		//ť�� �ִ� �뷮
	int num;		//������ ��� ����
	int front;		//������
	int rear;		//����
	int* que;		//ť�� �� �� ��ҿ� ���� ������
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
