#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int l, int r){
    if(l == r) return l;
    int mid = (l+r)/2;
    cout << "? " << l << " " << mid << "\n";
    cout << flush;
    int total = mid - l + 1;
    int outsider = 0;
    for(int i=0; i<total; i++){
        int x;
        cin >> x;
        if(x < l || x > mid) outsider++; 
    }
    int insider = total-outsider;
    if(insider&1){
        return f(l,mid);
    } else{
        return f(mid+1,r);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = f(1,n);
        cout << "! " << ans << "\n";
        cout << flush;
    }
    return 0;
}