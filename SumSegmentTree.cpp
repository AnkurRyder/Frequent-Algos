#include <iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a(n); // INITIAL VECTOR
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	//Size of Segment Tree.

	int m = n;
	int count = 0;
	int max_size= 1;
	// count = minimum number of bits required to represent n
	while(n != 0) {
	n = n >> 1;
	count++;
	}
	n = m;
	// max_size= size of the array representing the segment tree
	max_size= (max_size<< (count)) –1;
	vector<int> v(max_size);
	SumSTree(a,0,n-1,v,0);
	return 0;
}

int SumSTree(vector<int> arr, int ss, int se, vector<int> &st, int si)
{
if (ss== se)
{
st[si] = arr[ss];
return arr[ss];
}
intmid = (ss+ se)/2;
st[si] = SumSTree(arr, ss, mid, st, si*2+1) + SumSTree(arr, mid+1, se, st, si*2+2);
return st[si];
}