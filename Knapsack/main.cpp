#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ,v , w;
    cin >> n;
    vector<pair<int  ,int > > a(n);
    for (int i=0;i < n;i++)
    {
        cin >> v >> w;
        a[i] = make_pair(v, w);
    }
    vector<vector<int> > matr(n+1 , vector<int> (w+1 , 0));
    for (int i=0;i<n+1;i++ )
    {
        for (int j =0;j <w;j++)
        {
            if (a[i].second <= j)
            {
                matr[i][j] = max(matr[i-1][j] , matr[i-1][j-a[i].second]+ a[i].first);
            }
            else
            {
                matr[i][j] = matr[i-1][j];
            }
        }
    }
    return 0;
}
