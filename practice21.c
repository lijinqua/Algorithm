/*********************************************************************************************************************************
 * 请编写一个函数，用于 删除单链表中某个特定节点 。在设计函数时需要注意，你无法访问链表的头节点 head ，只能直接访问 要被删除的节点 。
 *
 * 题目数据保证需要删除的节点 不是末尾节点 。
 * 输入：head = [4,5,1,9], node = 5
 * 输出：[4,1,9]
 * 解释：指定链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9 
 *******************************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node
{
	int date;
	struct node * next;
}node;

void deletnode(struct node * p)
{
	struct node *p2;
	p2=p->next;

	p->date=p->next->date;
	p->next=p->next->next;
	free(p2);//并不是java，应该需要对原有的next指向的地址进行保存，到最后进行释放。
}
int main()
{
	struct	node * head;
	struct	 node * node;
	struct	 node *new_node;
	struct	node *tail;
	struct	node *serch;
	struct  node *delete;
	struct  node *serch2;
	node=(struct node *)malloc(sizeof(node));
	head=tail=node;
	for(int i=0;i<4;i++)
	{
		new_node=(struct node *)malloc(sizeof(node));
		new_node->next=NULL;
		new_node->date=i+1;
		tail->next=new_node;//而不是node->next=new_node?:因为tail时刻指向最后的节点，但是如果是node的话，则会直接将头节点的next域给指出去了。
	 	tail=new_node;
	}
	tail->next=NULL;
	serch=head;	
	serch=serch->next->next;
	
	delete=serch;
	deletnode(delete);
	serch2=head;
	while(serch2->next!=NULL)
	{
		serch2=serch2->next;
		printf("%d\n",serch2->date);
	}

	
		
}


//思路：
/*只能访问要删除的节点，那就将删除的节点当作头节点和头指针，因为只有一根指针，而指针里面存放的是指向下一个结构体的地址，所以不能对前面的结构体进行访问，故而可以李代桃僵；
 *将下一个节点的值换过来，然后把下个节点给删除。将原来的节点给指过去，此时后面被删除的节点虽然还是有指向下一个节点的地址，但是指向他的节点没了，导致他也无法被访问。但此时的内存还没被给占用。并且用一个新指针保存被删除节点的地址，最后全部用完了之后free。
*/










