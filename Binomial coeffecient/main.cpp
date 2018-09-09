#include <bits/stdc++.h>

using namespace std;
int bino(int n , int k)
{
    vector <vector<int> > v(n+1  ,vector<int>(k+1 , 0));
    int i , j;
    for (i =0;i<=n ;i++)
    {
        for (j=0 ; j <= min(i , j) ;j++)
        {
            if (i == j || j == 0)
            {
                v[i][j] = 1;
            }
            else
            {
                v[i][j] = v[i-1][j-1] + v[i-1][j];
            }
        }
    }
    return v[n][k];
}
int main()
{
    int n , k;
    cin >> n >> k;
    cout << bino(n , k) << "\n";
    return 0;
}
