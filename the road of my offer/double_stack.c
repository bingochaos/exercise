#define MAX_LEN 100;

struct double_stack
{
	int topindexA = -1;
	int topindexB = MAX_LEN;
	int a[MAX_LEN];
};

void pushA(int a[], int i)
{
	if(topindexA >= topindexB)
		return;

	topindexA ++;
	a[topindexA] = i;
}

int popA(int a[])
{
	if(topindexA == -1)
		printf("A is empty\n");

	int tmp = a[topindexA];
	topindexA --;
	return tmp;

}

void pushB(int a[], int i)
{
	if(topindexB <= topindexA)
		return;

	topindexB --;
	a[topindexB] = i;
}

int popB(int a[])
{
	if(topindexB == MAX_LEN)
		printf("B is empty\n");

	int tmp = a[topindexB];
	topindexB --;
	return tmp;
}