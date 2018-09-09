#include <bits/stdc++.h>

using namespace std;
int v,e;
bool bfs(vector<vector<int> > Ar, int s , int t, vector<int>& parent)
{
    vector<bool> visited(v,0);
    queue<int> q;
    q.push(s);
    parent[s]= -1;
    visited[s]= true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i=0; i<v; i++)
        {
            if (visited[i]==false && Ar[u][i] > 0)
            {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }
    return (visited[t] == true);
}
int FordFulkerson(vector<vector<int> > A , int s, int t)
{
    vector<vector<int> > Ar(v , vector<int>(v , 0));
    for(int i=0 ;i <v ;i ++)
    {
        for(int j=0 ; j<v; j++)
        {
                Ar[i][j] = A[i][j];
        }
    }
    vector<int> parent(v);
    int max_flow = 0, u;
    int path_flow = INT_MAX;
    while(bfs(Ar , s, t, parent))
    {
        path_flow = INT_MAX;
        for (int i=t; i!=s; i=parent[i])
        {
            u = parent[i];
            path_flow = min(path_flow, Ar[u][i]);
        }

        for (int i=t; i != s; i=parent[i])
        {
            u = parent[i];
            Ar[u][i] -= path_flow;
            Ar[i][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return(max_flow);
}
int main()
{
    int p , q, w;
    cin >> v >>e;
    vector<vector<int> > A(v , vector<int>(v , 0));
    for(int i=0 ; i<e ; i++)
    {
        cin >> p >>q >>w;
        A[p][q] = w;
    }
    cin >> p >> q; //source and sink
    cout << FordFulkerson(A , p , q);
    return 0;
}
