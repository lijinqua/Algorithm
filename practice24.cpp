/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
  输入：l1 = [1,2,4], l2 = [1,3,4]
  输出：[1,1,2,3,4,4]
  输入：l1 = [1,2,4], l2 = [1,3,4]
  输出：[1,1,2,3,4,4]
  输入：l1 = [], l2 = []
  输出：[]
  */
//#include<stdio.h>
//#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct node
{
	int date;
	struct node * next;

}node;


//这个插入算法存在6种情况。
node * sort_node(struct node * l1,struct node * l2,struct node * head,struct node * tail)
{
		 
		//情况一：刚插入时，L1它就是空的，直接返回L2的头节点就行; 
		if(l1==NULL&&head==NULL)
		{
			return l2;
		}
		//情况二：刚插入时，L2它就是空的，直接返回L1的头节点就行;
		if(l2==NULL&&head==NULL)
		{
			return l1;
		}
		//情况三:插到一半，L1给插空了，现在要把L2剩下的给补全；
		if(l1==NULL) 
		{
			struct node *search;
			search=l2;
			while(search!=NULL)
			{
				struct node * new_node=new node;
				new_node->date=search->date;
				new_node->next=NULL;
				if(head==NULL)
				{
					tail=head=new_node;
				}
				else
				{
					tail->next=new_node;
					tail=new_node;
				}
				search=search->next;
			}
			return head;
		}
		//情况四：插到一半，L2给插空了，现在要把L1给补全;
		if(l2==NULL)
		{
			struct node * search2;
			search2=l1;
			while(search2!=NULL)
			{
				struct node *new_node2=new node;
				new_node2->date=search2->date;
				new_node2->next=NULL;
				if(head==NULL)
				{
					head=tail=new_node2;
				}
				else
				{
					tail->next=new_node2;
					tail=new_node2;
				}
				search2=search2->next;
			}
			return head;
		}
		
		//情况五：正常插入，L1的值先插入;
		if(l1->date<=l2->date)
		{
			struct node * new_node=new node;
			new_node->date=l1->date;
			new_node->next=NULL;
			if(head==NULL)
			{
				tail=head=new_node;
			}
			else
			{
				tail->next=new_node;
				tail=new_node;
			}
			sort_node( l1->next,l2,head,tail);
		}
		//情况六:正常插入，L2的值先插入;
		if(l1->date>l2->date)
		{
			 struct node * new_node=new node;
			 new_node->next=NULL;
			 new_node->date=l2->date;
			 if(head==NULL)
			 { 
				tail=head=new_node;
			 }
			 else
			 {
			 	tail->next=new_node;
			 	tail=new_node;
			 }
			 sort_node( l1, l2->next,head,tail);
		}
		return head;
}		
		



int main()
{
//不带头节点的尾插
	struct node  *head;
	struct node  *tail; 	
	struct node  *search;
	head=tail=NULL;
	for(int i=0;i<4;i++)
	{
		struct	node *new_node=new node;
		new_node->next=NULL;
		new_node->date=i+2;
		if(head==NULL)
		{
			tail=head=new_node; //tail跟head相同，一个时时刻刻指向头节点，一个时时刻刻指向尾节点。
		}
		else
		{
			
			tail->next=new_node;
			tail=new_node;
		}
		//tail=new_node;
	}
	search=head;

	while(search!=NULL)
	{
		printf("%d\n",search->date);
		search=search->next;
	}

	 printf("l1 end\n");
	struct node  *head2;
	struct node  *tail2;
	struct node  *search2;
	head2=tail2=NULL;
	for(int i=0;i<4;i++)
	{
		struct  node *new_node2=new node;
		new_node2->next=NULL;
		new_node2->date=i+1;
		if(head2==NULL)
		{
			tail2=head2=new_node2;
		}
		else
		{
			tail2->next=new_node2;
			tail2=new_node2;
		}
	}
	struct node *search9;
	search9=head2;
	while(search9!=NULL)
	{
		  printf("%d\n",search9->date);
		  search9=search9->next;
	}
	printf("l2 end\n");
	struct node *head3;
	struct node *tail3;
	tail3=head3=NULL;
	struct node *head5;
	head5=sort_node(head,head2,head3,tail3);


	search2=head5;
	while(search2!=NULL)
	{
		printf("%d\n",search2->date);
		search2=search2->next;
	}
}
									               
/*
 * 总结:一定要考虑一条队列先插完，而还有一段没插完的情况；
 * new 比 malloc还用多了
 */


















































































