#include<stdio.h>
void merge(int ar[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int a[n1],b[n2];
	for(int i=0;i<n1;i++)
	{
		a[i]=ar[l+i];
	}
	for(int i=0;i<n2;i++)
	{
		b[i]=ar[i+m+1];
	}
	int i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(a[i]<=b[j])
		{
			ar[k++]=a[i++];
		}
		else
		{
			ar[k++]=b[j++];
		}
	}
	while(i<n1)
	{
		ar[k++]=a[i++];
	}
	while(j<n2)
	{
		ar[k++]=b[j++];
	}
}

void print(int ar[],int n)
{
	for(int i=0;i<n;i++)
		{
			printf("%d\n",ar[i]);
		}
}
void scan(int ar[],int n)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
}
void mergesort(int ar[],int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(ar,l,m);
		mergesort(ar,m+1,r);
		merge(ar,l,m,r);
	}
}
int main()
{
	int n;
	printf("Enter no of elements");
	scanf("%d",&n);
	int a[n];
	scan(a,n);
	print(a,n);
	printf("\nAfter sorting");
	mergesort(a,0,n-1);
	print(a,n);
}

