/*给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 */









typedef struct node
{
	int date;
	struct node *next;
}node;











#include<stdlib.h>

#include<stdio.h>

int main()
{
	struct node *head,*head2;
	struct node *tail,*tail2;
	struct node *node;
	struct node *new_node;
	struct node *node2;
	struct node *new_node2;
	struct node *serch;
	node=(struct node *)malloc(sizeof(node));
	head=tail=node;
	
	
	for(int i=1;i<6;i++)
	{
		new_node=(struct node *)malloc(sizeof(node));
		new_node->date=i;
		new_node->next=NULL;
		tail->next=new_node;
		tail=new_node;
	}
	tail->next=NULL;
	
	serch=head;
	int i=0;
	while(serch->next!=NULL)
	{
	 	serch=serch->next;
	        i++;
	//	printf("%d\n",serch->date);
	}
		

	int *a=(int *)malloc(i*sizeof(int));
	
	struct node *serch2;
	
	serch2=head;
	int m=0;

	while(serch2->next!=NULL)
	{
		serch2=serch2->next;
		a[m]=serch2->date;
		m++;
	//	printf("%d\n",serch2->date);

		
	}
	//找到了a[m];
	/*	printf("eran m :%d\n",m);
	for(int n=0;n<m;n++)
	{
		printf("%d\n",a[n]);
	}*/
	//头插
	
	node2=(struct node *)malloc(sizeof(node));
	head2=tail2=node2;
	head2->next;
	for(int i=0;i<m;i++)
	{
		new_node2=(struct node *)malloc(sizeof(node));
		new_node2->date=a[i];
		new_node2->next=head2->next;
		node2->next=new_node2; //如果是带头节点的head指针，一直不能动i,不带头节点的头插法才能动。

	}
	struct node *serch3;
	serch3=head2;
	while(serch3->next!=NULL)
	{
		serch3=serch3->next;
		printf("%d\n",serch3->date);
	}
}





/*链表反转：
 （1）先遍历出所有多少个值。用一个标志位来计数；
 （2）分配一个数组，存放这些值；
 （3）将这些值用头插法重新分配。
 */





























