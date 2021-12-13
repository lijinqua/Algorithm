//#include<stdlib.h>
//#include<stdio.h>
#include<iostream>
using namespace std;
 struct node
{
	int date;
	struct node * next;
};


int main()
{
//尾插：
	  node *head;
	  node *tail;
	  node *search;
	  head=tail=NULL;
	for(int i=0;i<4;i++)
	{
		//struct node * new_node=(struct node *)malloc(sizeof( node));
		 node *new_node=new node;
		

		new_node->date=i+1;
		new_node->next=NULL;//这一点在不带头节点的插入是必须的，不指空就无法进行下一步的判断。
		if(head==NULL)
		{
			head=new_node;
			tail=new_node;
		}
		else
		{
			tail->next=new_node;
			tail=new_node;
		}
			//tail=new_node;
	}
	node * p=NULL;
	p=head;
	int m=0;
	while(p!=NULL)
	{
		m=m+1;
		printf("p:%d\n",p->date);
		p=p->next;
	}
	printf("m:%d\n",m);
	struct node *p2=NULL;
	p2=head;
	
	struct node *head2=NULL;
	for(int i=0;i<m;i++)
	{
		struct node * new_node2=new node;

		new_node2->date=p2->date;//
		printf("insert date:%d\n",new_node2->date);
		new_node2->next=NULL;
		if(head2==NULL)
		{
			head2=new_node2;
		}
		else
		{
			new_node2->next=head2;
			head2=new_node2;
		}
		p2=p2->next;//
	}
	struct node *search3;
	search3=head2;
	while(search3!=NULL)
	{
		printf("%d\n",search3->date);
		search3=search3->next;
	}
	
}
