#include<stdio.h>
#include<stdlib.h>
#define mytype int
#define MAXLEN 100
typedef struct SeqList{
	int len;
	mytype array[MAXLEN];
}SeqList;

mytype GetValue(SeqList* List,int n)//得到第n个元素的值 
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
 
int Insert(SeqList* list,int n,mytype x)//插入元素到第n个，错误返回-1，成功返回1 
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
 
int Delet(SeqList* list, int n)//删除第i元素 
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

int InsertSeq(SeqList* slist,mytype x)//递增数列添加元素 
{
	int n;//找到插入位置
	for(n = 0;n < slist->len;n++)
	{
		if(slist->array[n] > x)
		{
			break;
		}
	 }
	return Insert(slist,n,x);//调用插入函数 I 
}

void Test05(SeqList* list)//拆分成奇数与偶数
{
	int i;
	SeqList* A = (SeqList*)malloc(sizeof(SeqList));//奇数集 
	SeqList* B = (SeqList*)malloc(sizeof(SeqList));//偶数集 
	A->len = 0;//初始化 
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
	printf("奇数集为:\n");
	for(i = 0;i < A->len;i++)
	{
		printf("%3d",A->array[i]);
	}
	printf("偶数集为:\n"); 
	for(i = 0;i < B->len;i++)
	{
		printf("%3d",B->array[i]);
	}
 }

SeqList* Test06(SeqList* A,SeqList* B)//找到递增集合AB之中的共有元素放入C 
{
	int i = 0;
	int j = 0;//存放AB长度 
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
  
int DeletRepeat(SeqList* A)//删除递增有序表重复元素 
{
	int i;
	if(A->len == 0)
	{
		printf("删除失败");
		return -1;
	 } 
	SeqList* C = (SeqList*)malloc(sizeof(SeqList));//保存临时数据
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
	for(i = 0;i < A->len;i++)//将C复制回A 
	{
		A->array[i] =  C->array[i];
	}
	printf("删除成功");
	return 1;
}  
  
int main()
{
	return 0;
}
