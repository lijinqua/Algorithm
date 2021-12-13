/*回文链表
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 * 输入：head = [1,2,2,1]
 * 输出：true
 * 输入：head = [1,2]
 * 输出：false
 */
#include<iostream>
using namespace std;


typedef struct node
{
	int date;
	struct node * next;
}node;
int  ssss(node * head);
node *flip(node *head);


	bool Test(node *head)
	{	

		if(head==NULL)
		{
			return true;
		}
		
		node * pop;
		int i=0;
		pop=head;
		node *server;	
		while(pop!=NULL)
		{       
			//计数；
			i=i+1;
			pop=pop->next;
		}
		int b;
		b=i%2;
		if(b==0)
		{
			int m=i/2;
			node *search2=NULL;
			node * new_list;
			search2=head;
			//找到要反转的节点；
			for(int b=0;b<m;b++)
			{
				search2=search2->next;
			}
			//反转,得到反转后的节点;
			new_list=flip(search2);
			
			while(new_list!=NULL)
			{
				if(head->date!=new_list->date)
				{
					return false;

				}
				new_list=new_list->next;
				head=head->next;
			}
			return true;
		}
		if(b!=0)
		{
			int m=i/2;
			node *search2=NULL;
			node * new_list1;
			search2=head;
			//跳到一半+1的位置
			for(int c=0;c<m+1;c++)
			{
				search2=search2->next;
			}
			//得到要开始反转的节点:
			new_list1=flip(search2);	
			while(new_list1!=NULL)
			{
				if(head->date!=new_list1->date)
				{
					return false;
				}
				new_list1=new_list1->next;
				head=head->next;
			}
			return true;
		}

		return true;
	}
int ssss(node *head)
{
	node *mmm;
	mmm=head;
	int d=0;
	while(mmm!=NULL)
	{
		printf("now head !=; serch after:%d\n",mmm->date);
		d=d+1;
		mmm=mmm->next;
	}
	return d;
}

				
			
			
node*  flip(node * p)
{
	node * head=NULL;//头插别忘初始化！
	while(p!=NULL)
	{
		node *new_node=new node;
		new_node->date=p->date;
		new_node->next=NULL;
		if(head==NULL)
		{
			head=new_node;
		}
		else
		{
			new_node->next=head;
			head=new_node;
		}
		p=p->next;
	}
	return head;
}
		

	
	node * create2()
	{
		node *head,*tail,*new_node1,*new_node2,*new_node3,*new_node4,*new_node5;
		new_node1=new node;
		new_node1->date=1;
		new_node1->next=NULL;
		head=tail=new_node1;
		
		new_node2=new node;
		new_node2->date=2;
		new_node2->next=NULL;
		tail->next=new_node2;
		tail=new_node2;
		
		new_node3=new node;
		new_node3->date=3;
		new_node3->next=NULL;
		tail->next=new_node3;
		tail=new_node3;

		new_node4=new node;
		new_node4->date=4;
		new_node4->next=NULL;
		tail->next=new_node4;
		tail=new_node4;
		
		new_node5=new node;
		new_node5->date=5;
		new_node5->next=NULL;
		tail->next=new_node5;
		tail=new_node5;

		return head;
	}









int main()
{
	
	node * head;
	bool m;
	head=create2();//创建表；
	m=Test(head);
	cout<<m<<endl;


}
//回文链表：
//正着读或者倒着读，其结果都是一样的，有2种方法对其进行处理：
//1.直接全部头插链表，然后一次对比；
//2.找到中间节点，然后再头插;



