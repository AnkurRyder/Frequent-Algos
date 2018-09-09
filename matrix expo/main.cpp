#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000000

int k;
vector<vector<ll> > mul(vector<vector<ll> > A, vector<vector<ll> > B){
    vector<vector<ll> > C(k+1, vector<ll>(k+1));
    for(int i = 1;i<=k;i++){
        for(int j = 1;j<=k;j++){
            for(int x = 1;x<=k;x++)
                C[i][j] = (C[i][j] + A[i][x]*B[x][j]) % MOD;
        }
    }
    return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A, ll p){
    if(p == 1)
        return A;
    if(p & 1)
        return mul(A,pow(A,p-1));
    vector<vector<ll> > X = pow(A,p/2);
    return mul(X,X);
}

int main() {
    int t;
    cin >> t;
    vector <ll> b(10);
    vector <ll> c(10);
    while(t--)
    {
        cin >> k;
        vector<ll> F1(k+1);
        for(int i =0 ;i < k ; i++)
        {
            cin >> b[i];
            F1[i+1] = b[i];
        }
        for(int i =0 ;i < k ; i++)
        {
            cin >> c[i];
        }
        int n;
        cin >> n;
        if(n <= k)
        {
            cout << b[n-1] <<"\n";
            return 0;
        }
        vector<vector <ll> > T(k+1 , vector<ll> (k+1 , 0));
        for(int i = 1 ; i <= k ;i++ ){
            T[i][i+1] = 1;
            T[k][i] = c[k-i];
        }
        ll res =0 ;
        T = pow(T , n-k);
        for(int i = 1;i <= k;i++)
            res = (res + T[k][i]*F1[i]) % MOD;
        cout << res % MOD <<"\n";
    }
}
