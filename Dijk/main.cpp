#include <bits/stdc++.h>

using namespace std;

void dijk(vector<vector <pair<int , int> > > adj , int s, int n)
{
    int u;
    set<pair <int , int> > dist;
    vector<int> weig(n , INT_MAX);
    pair<int ,int> temp;
    dist.insert(make_pair(0 , s));
    weig[s] = 0;
    while(!dist.empty())
    {
        temp = *(dist.begin());
        dist.erase(dist.begin());
        u = temp.second;
        vector< pair<int , int > >::iterator i;
        for (i = adj[u].begin() ;i != adj[u].end() ;i++ )
        {
            if(weig[(*i).first] > weig[u] + (*i).second)
            {
                if (weig[(*i).first] != INT_MAX)
                    dist.erase(dist.find(make_pair(weig[(*i).first], (*i).first)));
                weig[(*i).first] = weig[u] + (*i).second;
                dist.insert(make_pair(weig[(*i).first] , (*i).first));
            }
        }
    }
    for (int j =0;j <n ;j++ )
    {
        cout << weig[j] <<"\n";
    }
}

int main()
{
    int n , v , a,  b , w, s;
    cin >> n >> v;
    cin >> s;
    vector<vector <pair<int , int> > > adj(n);
    for (int i=0; i< v; i++ )
    {
        cin >> a >> b >> w;
        adj[b].push_back(make_pair(a,w));
        adj[a].push_back(make_pair(b,w));
    }
    dijk(adj , s , n);
    return 0;
}
