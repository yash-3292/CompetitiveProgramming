#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int sumi;
    int cnt = 0;
    for(int i=0; i<n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = a+b+c+d;
        if(i == 0) sumi = sum;
        else{
            if(sum > sumi) cnt++;
        }
    }
    int ans = cnt+1;
    cout << ans << endl;
    return 0;
}