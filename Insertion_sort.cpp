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
	//Code for insertion sort
	for (int i = 1; i < n-1; ++i)
	{
		key=v[i];
		for(int j=i-1;j>0 && v[j]>key;j--)
		{
			v[j+1]=v[j];
		}
		v[j+1]=key;
	}
	return 0;
}