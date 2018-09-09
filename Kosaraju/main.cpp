#include <bits/stdc++.h>

using namespace std;
int v;

void dfs(vector<vector<int> > Adj , stack<int>& s , int j , vector<bool>& visited)
{
    visited[j] = true;
    vector<int>::iterator it;
    for (it = Adj[j].begin();it != Adj[j].end() ;it++){
        if (!visited[*it])
        {
            dfs(Adj , s , *it , visited);
        }
    }
    s.push(j);
}

void Rdfs(vector<vector<int> > Adj , int j , vector<bool>& visited)
{
    visited[j] = true;
    cout << j << " ";
    vector<int>::iterator it;
    for (it = Adj[j].begin();it != Adj[j].end() ;it++){
        if (!visited[*it])
        {
            Rdfs(Adj , *it , visited);
        }
    }
}

void Kosaraju(vector<vector<int> > Adj)
{
    int top;
    vector<bool> visited(v , false);
    stack<int> s;
    vector<int>::iterator it;
    for(int i =0 ;i <v ;i++)
    {
        for(it=Adj[i].begin(); it <= Adj[i].end();i++)
        {
            if(!visited[*it])
                dfs(Adj , s , *it , visited);
        }
        for (int i=0; i< v ;i++)
            visited[i] = false;
        vector<vector<int> > AdjR(v);
        for(int i =0 ;i <v ;i++)
        {
            for(it = Adj[i].begin() ; it != Adj[i].end() ; it++)
            {
                AdjR[*it].push_back(i);
            }
        }
        while(!s.empty())
        {
            top = s.top();
            s.pop();
            if(!visited[top]){
                Rdfs(AdjR , top , visited);
                cout <<"\n";
            }
        }
    }
}
int main()
{
    int e , p ,q;
    cin >> v >> e;
    vector<vector<int> > Adj(v);
    for (int i=0 ; i<e ;i++ )
    {
        cin >> p >>q;
        Adj[p].push_back(q);
    }
    Kosaraju(Adj);
    return 0;
}
