#include <stdio.h>
int n,sorted[100],count;
int merge(int list[],int left,int mid,int right)
{
	int i,j,k,l;
	i = left;
	j = mid + 1;
	k = left;
	while(i<=mid&&j<=right)
	{
		if(list[i]<list[j])
		{
			sorted[k++] = list[i++];
		}
		else
		{
			sorted[k++] = list[j++];
		}
	}
	if(i>mid)
	{
		for(l = j;l<=right;l++)
		{
			sorted[k++] = list[l];
		}
	}
	else
	{
		for (l = i;l<=mid;l++)
		{
			sorted[k++] = list[l];
		}
	}
	for(l = left;l<=right;l++)
	{
		list[l] = sorted[l];
	}
}
void mergesort(int list[],int left, int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		mergesort(list,left,mid);
		mergesort(list,mid+1,right);
		merge(list,left,mid,right);
		
	}
}
int main() 
{
	
int list[65];
	scanf("%d",&n);
	for(int i = 0; i<n;i++)
	{
		scanf("%d",&list[i]);
	}
	mergesort(list,0,n-1);
	for(int i = 0; i<n;i++)
	{
		printf("%d ",list[i]);
	}
}
