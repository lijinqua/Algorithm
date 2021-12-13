/*                                                                test05                                                               */


/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 输入: [2,2,1]
 * 输出: 1
 * 输入: [4,1,2,1,2]
 * 输出: 4
 */
#include<stdio.h>
int Foundnum(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		int key=arr[i];
		for(int k=i+1;k<n;k++)
		{
			if(key==arr[k])
			{
				break;
			}
			else
			{
				return key;
			}
		}
	}
}
int main()
{
	int arr[]={4,1,2,1,2};
	int m;
	m=Foundnum(arr,5);
	printf("%d\n",m);
}
