#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int l = 1;
    int r = 2*n+1;
    int ans1 = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        cout << "? ";
        cout << mid << " ";
        for(int i=1; i<=mid; i++) cout << i << " ";
        cout << "\n";
        cout << flush;
        int x;
        cin >> x;
        x += mid;
        if(x&1){
            ans1 = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    int ans2 = -1;
    l = 1;
    r = ans1-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        cout << "? ";
        cout << mid+1 << " ";
        cout << ans1 << " ";
        for(int i=1; i<=mid; i++) cout << i << " ";
        cout << "\n";
        cout << flush;
        int x;
        cin >> x;
        x += mid+1;
        if(x&1){
            ans2 = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    int ans3 = -1;
    l = 1;
    r = ans2-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        cout << "? ";
        cout << mid+2 << " ";
        cout << ans1 << " " << ans2 << " ";
        for(int i=1; i<=mid; i++) cout << i << " ";
        cout << "\n";
        cout << flush;
        int x;
        cin >> x;
        x += mid+2;
        if(x&1){
            ans3 = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    cout << "! " << ans3 << " " << ans2 << " " << ans1 << "\n";
    cout << flush;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}