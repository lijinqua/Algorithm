/*给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 输入：head = [1], n = 1
 * 输出：[]
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 */

#include <stdlib.h>
#include<stdio.h>

typedef struct node
{
	int date;
	struct node *next;
}node;

int main()
{
	struct node *head=NULL;
	struct node * tail=NULL;
	struct node * node;
	struct node * new_node;
	struct node * serch;
	node=(struct node*)malloc(sizeof(node));
	head=tail=node;
	for(int i=1;i<6;i++)
	{
		new_node=(struct node *)malloc(sizeof(node));
		new_node->date=i;
		new_node->next=NULL;
		tail->next=new_node;
		tail=new_node;
	}
	//new_node->next=NULL;
	
	struct node *tail2=head;
	struct node *tail3=head;
	for(int i=0;i<1;i++)   //倒数第二个节点，其实也只移动了一位而已；
	{
		tail2=tail2->next;
	}
	while(tail2->next!=NULL)
	{
		tail2=tail2->next;
		tail3=tail3->next;
	}
          
	tail3->date=tail3->next->date;
	tail3->next=tail3->next->next;
	serch=head;
	while(serch->next!=NULL)
	{
		serch=serch->next;
		printf("%d\n",serch->date);
	}
	
}
	
//思路：相距为n,就找2个节点也相距为n，让第二节点移动到最末尾，那第一个节点，它就是倒数第n个节点。











































