#include<stdio.h>
#include<stdlib.h>
#define mytype int
#define MAXLEN 100
typedef struct SeqList{
	int len;
	mytype array[MAXLEN];
}SeqList;

mytype GetValue(SeqList* List,int n)//�õ���n��Ԫ�ص�ֵ 
{
	if(n > List->len||n < 0)
	{
		printf("erro");
		return -1;
	}
	else
	{
		return List->array[n-1];
	}
}
 
int Insert(SeqList* list,int n,mytype x)//����Ԫ�ص���n�������󷵻�-1���ɹ�����1 
{
	int i;
	if(n > list->len||n < 0||list->len == MAXLEN)
	{
		printf("erro");
		return -1;
	}
	else
	{
		for(i = list->len;i > n;i--)
		{
			list->array[i] = list->array[i-1];
			
		 }
		 list->array[n] = x;
		 list->len++;
		 return 1; 
	}
	return 1;
 }
 
int Delet(SeqList* list, int n)//ɾ����iԪ�� 
{
	int i;
	if(n > list->len||n <= 0)
	{
		printf("erro");
		return -1;
	}
	else
	{
		for(i = n;i < list->len;i++)
		{
			list->array[n-1] = list->array[n];
		}
	}
	list->len--;
}

int InsertSeq(SeqList* slist,mytype x)//�����������Ԫ�� 
{
	int n;//�ҵ�����λ��
	for(n = 0;n < slist->len;n++)
	{
		if(slist->array[n] > x)
		{
			break;
		}
	 }
	return Insert(slist,n,x);//���ò��뺯�� I 
}

void Test05(SeqList* list)//��ֳ�������ż��
{
	int i;
	SeqList* A = (SeqList*)malloc(sizeof(SeqList));//������ 
	SeqList* B = (SeqList*)malloc(sizeof(SeqList));//ż���� 
	A->len = 0;//��ʼ�� 
	B->len = 0;
	for(i = 0;i < list->len;i++)
	{
		if((i + 1) % 2 == 0)
		{
			B->array[B->len] = list->array[i];
			B->len++; 
		}
		else
		{
			A->array[A->len] = list->array[i];
			A->len++;
		}
	}
	printf("������Ϊ:\n");
	for(i = 0;i < A->len;i++)
	{
		printf("%3d",A->array[i]);
	}
	printf("ż����Ϊ:\n"); 
	for(i = 0;i < B->len;i++)
	{
		printf("%3d",B->array[i]);
	}
 }

SeqList* Test06(SeqList* A,SeqList* B)//�ҵ���������AB֮�еĹ���Ԫ�ط���C 
{
	int i = 0;
	int j = 0;//���AB���� 
	SeqList* C = (SeqList*)malloc(sizeof(SeqList));
	C->len = 0;
	while(i < A->len&&j < B->len)
	{
		if(A->array[i] == B->array[j])
		{
			C->array[C->len] = A->array[i];
			C->len++;
			i++;
			j++;
		}
		else if(A->array[i] < B->array[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	 }
	 return C; 
}
  
int DeletRepeat(SeqList* A)//ɾ������������ظ�Ԫ�� 
{
	int i;
	if(A->len == 0)
	{
		printf("ɾ��ʧ��");
		return -1;
	 } 
	SeqList* C = (SeqList*)malloc(sizeof(SeqList));//������ʱ����
	C->array[0] = A->array[0];
	C->len = 1;
	for(i = 1;i < A->len;i++)
	{
		if(C->array[C->len - 1] != A->array[i])
		{
			C->array[C->len] = A->array[i];
			C->len++;
		}
	}
	A->len = C->len;
	for(i = 0;i < A->len;i++)//��C���ƻ�A 
	{
		A->array[i] =  C->array[i];
	}
	printf("ɾ���ɹ�");
	return 1;
}  
  
int main()
{
	return 0;
}
