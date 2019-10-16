#include<stdio.h>
#include<stdlib.h>
#define mytype int 
typedef struct Node
{
	mytype date;
	struct Node* next;
}Node;

void Travel(Node* head)
{
	Node *p = head->next;
	while(p != NULL)
	{
		printf("%d\n",p->date);
		p = p->next;
	}
}

Node* Tail_Creat_list() //β��
{
	Node* p1,*p2,*head;
	int fal;
	head = (Node*)malloc(sizeof(Node));
	if(head==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
        	exit(1);
    	}
	head->next = NULL;
	mytype val;
	printf("�Ƿ��������1����0�˳�");
	scanf("%d",&fal);
	while(fal)
	{
		p1 = (Node*)malloc(sizeof(Node));
		if(p1==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
        	exit(1);
    	}
    	printf("������\n");
		scanf("%d",&p1->date);
		if(head->next == NULL)
		{
			head->next = p1;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		printf("�Ƿ��������1����0�˳�");
		scanf("%d",&fal);
	}
	p2->next = NULL;
	return head;
 }
 
 Node* Head_Creat_list()//ͷ�� 
 {
 	Node* p1,*head;
 	int fal;
 	head = (Node*)malloc(sizeof(Node));
	if(head==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
        	exit(1);
    	}
	head->next = NULL;
	printf("�Ƿ��������1����0�˳�");
	scanf("%d",&fal);
	while(fal)
	{
		p1 = (Node*)malloc(sizeof(Node));
		if(p1==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
        	exit(1);
    	}
    	printf("������\n");
		scanf("%d",&p1->date);
		p1->next = head->next;
		head->next = p1;
		printf("�Ƿ��������1����0�˳�");
		scanf("%d",&fal);
	}
	return head;
  }
void DestoryList(Node* head)//�������� 
{
	Node* p,*q = head;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	printf("���ٳɹ�\n");
}
int Len_List(Node* head)//�������� 
{
	int len = 0;
	Node *p = head->next;
	while(p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

int Find_Index(Node* head,int i)//����ָ��λ��Ԫ�� 
{
	int n = i;
	Node* p = head;
	if(i < 0||i > Len_List(head)||head == NULL)
	{
		printf("����ʧ��/n");
		return -1;
	}
	else
	{
		while(i > 0)
		{
			i--;
			p = p->next;
		}
	}
	return p->date;
}

int Insert(Node* head)//����Ԫ�� 
{
	int x,i;
	Node* p = head;
	Node* q = (Node*)malloc(sizeof(Node));
	printf("���������Ԫ�ز���λ��\n");
	scanf("%d%d",&x,&i);
	if(q==NULL)
    	{
        	printf("����ռ�ʧ�ܣ�");
        	exit(1);
    	}
	if(i < 0)
	{
		printf("erro\n");
		return -1;
	}
	while(i > 0)
	{
		if(p->next == NULL)
		{
			printf("�������\n");
			return 0;
		}
		p = p->next;
		i--;
	}
	q->date = x;
	q->next = p->next;
	p->next = q;
	printf("����ɹ�\n");
	return 1;
 }
 
 int Find_element(Node* head,mytype x)//Ѱ��Ԫ�� 
 {
 	Node* p = head;
 	while(p != NULL)
 	{
 		if(p->date == x)
 		{
 			return x;
		 }
		 p = p->next;
	 }
	 printf("û�ҵ�\n");
	 return -1;
  }
  
 int Delet(Node* head)//ɾ��Ԫ��
 {
 	int i;
 	Node* p = head;
 	Node* q;
 	printf("������ɾ��λ��\n");
	scanf("%d",&i);
 	if(i < 0)
 	{
 		printf("�������");
 		return -1;
	 }
	 while(i > 0)
	{
		if(p->next == NULL)
		{
			printf("�������\n");
			return 0;
		}
		p = p->next;
		i--;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	printf("ɾ���ɹ�\n");
	return 1;
}

int SeqLinkListInsert(Node* head)//�������в���Ԫ�� 
{
	Node* p = head;
	Node* q = (Node*)malloc(sizeof(Node));
	printf("���������Ԫ��\n");
	scanf("%d",&q->date);
	q->next =NULL;
	while(1)
	{
		if(q->date < p->next->date||p->next == NULL)
		{
			q->next = p->next;
			p->next = q;
			printf("����ɹ�\n");
			return 1;
		}
		else
		{
			p = p->next;
		}
	}
}

void SplitList(Node* head,Node** A,Node** B)//�������Ϊ����������ż������ ע��ִ�д�����������ַ��ͬ 
{
	
	int i;
	Node* n = NULL; 
	Node* t = NULL;
	Node* p = head->next;
	Node* q = *A;
	Node* r = *B;
	while(p != NULL)
	{
		
		n = (Node*)malloc(sizeof(Node));
		n->date = p->date;
		
		n->next = NULL;
		
		if(n->date % 2 == 1)
		{
			q->next = n;
			q = n;
		}
		else
		{
			r->next = n;
			r = n;
		}
		
		p = p->next;
	}
	printf("����Ϊ:\n");
	Travel(*A);
	printf("ż��Ϊ:\n");
	Travel(*B);
}

Node* AddCommonToList(Node* list1,Node* list2)//��������������ͬԪ�� 
{
	Node* p = list1->next;
	Node* q = list2->next;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* n,*m;
	m = head;
	while(p != NULL&&q != NULL)
	{
		n = (Node*)malloc(sizeof(Node));
		if(p->date == q->date)
		{
			n->date = p->date;
			m->next = n;
			m = n;
		}
		else if(p->date < q->date)
		{
			p = p->next;
		}
		else
		{
			q = q->next;
		}
	 }
	 return head; 
}

void DeletR(Node* head)//ɾ���������������ظ�Ԫ�� 
{
	Node *p = head->next;
	Node *t;
	while(p != NULL&&p->next != NULL)
	{
		if(p->date < p->next->date)
		{
			p = p->next;
		}
		else
		{
			t = p->next;
			p->next = t->next;
			free(t);
		}
	}
	printf("ɾ���ɹ�\n");
}

void UnitList(Node* lsa,Node* lsb)
{
	Node* p = lsa;
	Node* q = lsb->next;
	Node* t = NULL;
	while(p->next != NULL&&q != NULL)
	{
		printf("q = %d\n",q->date);
		if(p->next->date > q->date)
		{
			t = q;
			
			q = q->next;
			t->next = p->next;
			p->next = t;
			p = p->next;
			
		}
		else if(p->next->date < q->date)
		{
			p = p->next;
		}
		
	}
	printf("q = %d\n",q->date);
	if(p->next == NULL)
	{
		p->next = q;
	}
	printf("�ϲ��ɹ�\n");
}



int main()
{	
	Node* ls1 = Tail_Creat_list();
	
//	Node* A = (Node*)malloc(sizeof(Node));
//	Node* B = (Node*)malloc(sizeof(Node));
//	Travel(ls1);
//	SplitList(ls1,&A,&B);
	
	Node* ls2 = Tail_Creat_list();
	Travel(ls2);
	UnitList(ls1,ls2);
	Travel(ls1);
}
 
