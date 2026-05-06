#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int cut(int x){
    if(x == 1) return 0;
    int y;
    if(x&1) y = (int)((double)x/2.0) + 1;
    else y = x/2;
    return (1 + cut(y));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ,m, a, b;
        cin >> n >> m >> a >> b;
        int max1 = max(a-1, n-a);
        int max2 = max(b-1, m-b);
        int total1;
        int total2;
        int x = n-max1;
        total1 = cut(x) + cut(m) + 1;
        int y = m-max2;
        total2 = cut(n) + cut(y) + 1;
        int totalCut = min(total1,total2);
        cout << totalCut << endl;
    }
    return 0;
}