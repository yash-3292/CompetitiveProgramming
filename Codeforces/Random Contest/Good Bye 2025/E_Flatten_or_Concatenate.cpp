#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    ll ans;
    cin >> ans;
    return ans;
}

ll f(int l, int r, ll sum){
    if(l == r) return sum;
    int low = l;
    int high = r;
    int ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        ll val = query(l, mid);
        if(2*val < sum){
            low = mid+1;
        } else if(2*val > sum){
            high = mid-1;
        } else{
            ans = mid;
            break;
        }
    }
    if(ans-l+1 <= r-ans){
        return f(l, ans, sum/2);
    } else{
        return f(ans+1, r, sum/2);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll sum = query(1, n);
        ll ans = f(1, n, sum);
        cout << "! " << ans << "\n";
        cout.flush();
    }
    return 0;
}
