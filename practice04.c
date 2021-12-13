/*                                                            test 04                                                */

/*给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

输入: [1,2,3,1]
输出: true

输入: [1,2,3,4]
输出: false

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/
#include<stdio.h>
#define False 0
#define True  1
int  Arry(int *arr,int n)
{ 
	for(int i=0;i<n;i++)
	{
		int k=arr[i];                      //在进行数组重复判断时，从下标i=0开始设置一个标志，从k=i+1个位置开始遍历;重复进行操作。
		for(int m=i+1;m<n;m++)
		{
			if(arr[m]==k)
			{
				return True;	
			}
			else{
				return False;
			}

		}
	}
}

int main()
{
	int array[]={1,2,3,4,5};
	int m=Arry(array,5);
	char str[20]="";
	char *p;
	p=str;
	if(m==1)
	{	
		p="True";//字符串赋值和字符串指针的赋值是不一样的，指针可以直接=；而字符串只能strcat和strncpy(目标，源字符串，要拷贝源字符串的大小）
	}
	else
	{
		p="False";
	}
	printf("%s\n",p);
	
}
	

