#include <bits/stdc++.h>

using namespace std;

int FindRoot(vector <int> addr , int a)
{
    while (addr[a] != a)
    {
        addr[a] = addr[addr[a]];
        a = addr[a];
    }
    return a;
}

int find(vector<int> addr , int a , int b)
{
    return (FindRoot(addr ,a) == FindRoot(addr , b));
}
void Union(vector <int> A , vector <int>& addr ,int a ,int b)
{
    int p , q;
    p = FindRoot(addr , a);
    q = FindRoot(addr , b);
    addr[p] = addr[q];
}
int main()
{
    int n ,a ,b;
    cin >>n;
    vector<int> A(n);
    vector<int> addr(n);
    for (int i=0;i < n ;i++)
    {
        A[i] = i;
        addr[i] = i;
    }
    while(1)
    {
        cin >> a >> b;
        Union(A , addr ,a ,b);
        cin >> a >>b;
        cout << find(addr ,a,b)<<"\n";
    }
    return 0;
}
