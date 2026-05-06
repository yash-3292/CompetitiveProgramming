#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

db f(int a, int b, int c, int n, vector<vector<vector<db>>>& dp){
    if(a < 0 || b < 0 || c < 0) return 0;
    if(a == 0 && b == 0 && c == 0) return 0;

    if(dp[a][b][c] != -1) return dp[a][b][c];

    db ans = (db)n + (db)a*f(a-1, b+1, c, n, dp) + (db)b*f(a, b-1, c+1, n, dp) + (db)c*f(a, b, c-1, n, dp);
    ans = ans/(db)(a+b+c);

    return dp[a][b][c] = ans;
}

int main(){
    int n;
    cin >> n;
    int one = 0;
    int two = 0;
    int three = 0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x == 1) one++;
        else if(x == 2) two++;
        else three++;
    }
    vector<vector<vector<db>>> dp(n+1, vector<vector<db>>(n+1, vector<db>(n+1, -1)));
    db ans = f(three, two, one, n, dp);
    cout << setprecision(14) << ans << endl;
    return 0;
}