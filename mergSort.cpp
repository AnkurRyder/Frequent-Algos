#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	mergesort(v,0,n-1);
	return 0;
}

void mergesort(std::vector<int> v[], int low, int high)
{
	if(low<high){
		int mid=(low+high)/2;
		mergesort(v,low,mid);
		mergesort(v,mid+1,high);
		merge(v,low,mid,high);
	}
}

void merge(std::vector<int> v[],int low, int mid ,int high)
{
	int i=low,j=;mid+1,count=0;
	std::vector<int> b(high-low+1);
	while(count<high-low+1 && i<=mid && j<=high)
	{
		if(v[i]<=v[j])
			b[count++]=v[i++];
		else
			b[count++]=v[j++];
	}
	while(count<high-low+1)
	{
		if(j!=high+1)
			b[count++]=v[j++];
		if (i!=mid+1)
		{
			b[count++]=v[i++];
		}
	}
	for (int i = low,j=0; i <= high; ++i,j++)
	{
		a[i]=b[j];
	}
}