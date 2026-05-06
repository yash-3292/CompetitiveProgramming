#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int query(int a, int b){
    cout << "? " << a << " " << b << "\n";
    cout << flush;
    int x;
    cin >> x;
    return x;
}

int find(int l, int r){
    if(l == r) return l;
    int mid1 = l + (r-l)/3;
    int mid2 = r - (r-l)/3;
    
    int product = query(mid1, mid2);
    
    if(product == mid1*mid2){
        return find(mid2+1, r);
    } else if(product == mid1*(mid2+1)){
        return find(mid1+1, mid2);
    } else{
        return find(l, mid1);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int ans = find(2, 999);
        cout << "! " << ans << "\n";
        cout << flush;
    }
    return 0;
}