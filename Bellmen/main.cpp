#include <bits/stdc++.h>

using namespace std;

int Bellmen(std::vector<std::vector<pair < int, int> > > adj ,int n ,int v)
{
    vector<int> dis(n, INT_MAX);
    int a , b ,w;
    vector<pair<int ,int> >::iterator k;
    dis[0]=0;
    for (int i = 0;i <v-1 ;i++ )
    {
        for (int j =0; j< n ;j++ )
        {
            for (k = adj[j].begin();k != adj[j].end();k++ )
            {
                a = j;
                b = (*k).first;
                w = (*k).second;
                if (dis[b] != INT_MAX && dis[a] > dis[b] + w)
                {
                    dis[a] = dis[b] + w;
                }
            }
        }
    }
    for (int j =0; j< n ;j++ )
    {
        for (k = adj[j].begin();k != adj[j].end();k++ )
        {
            a = j;
            b = (*k).first;
            w = (*k).second;
            if (dis[b] != INT_MAX && dis[a] > dis[b] + w)
            {
                return 0;
            }
        }
    }
    for (int i =0;i < n ;i++ )
    {
        cout << dis[i] <<"\n";
    }
    return 1;
}

int main()
{
    int n ,v;
	cin >> n >>v;
	int a , b, c;
	std::vector<std::vector<pair < int, int> > > adj(n);
	for (int i = 0; i < v; ++i)
	{
		cin >> a >>b >>c;
		adj[a].push_back(make_pair(b ,c));
	}
	cout << Bellmen(adj , n , v);
    return 0;
}
