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

int Find(vector<int> addr , int a , int b)
{
    return (FindRoot(addr ,a) == FindRoot(addr , b));
}
void Union(vector <int>& addr ,int a ,int b)
{
    int p , q;
    p = FindRoot(addr , a);
    q = FindRoot(addr , b);
    addr[p] = addr[q];
}

int main()
{
    int w,p,q ,weight=0;
	int edges , nodes;
	cin >> nodes >>edges;
	std::vector<int> addr(nodes);
	std::vector<pair<int ,pair<int ,int> > > adj(edges);
	std::vector<pair<int ,pair<int ,int> > > incl;
	for (int i = 0; i < nodes; ++i)
	{
		addr[i] = i;
	}
	for (int i = 0; i < edges; ++i)
	{
		cin >>p >> q >>w;
		adj[i] = make_pair(w,make_pair(p,q));
	}
	sort(adj.begin(), adj.end());
	for(auto i : adj)
	{
		if(!Find(addr , i.second.first , i.second.second))
		{
			weight += i.first;
			Union(addr , i.second.first , i.second.second);
			incl.push_back(i);
		}
	}
	cout <<"Total weight" << weight << "\n";
	for(auto i :incl)
		cout <<i.second.first <<" " <<i.second.second << " " <<i.first <<"\n";
    return 0;
}
