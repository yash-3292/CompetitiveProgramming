#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 int128;

istream& operator>>(istream& in, int128& x){
    string s;
    in >> s;
    x = 0;
    int sign = 1;
    int i = 0;

    if(s[0] == '-'){
        sign = -1;
        i = 1;
    }

    for(; i<s.size(); i++){
        x = x*10 + (s[i]-'0');
    }

    x *= sign;
    return in;
}

ostream& operator<<(ostream& out, int128 x){
    if(x == 0){
        out << 0;
        return out;
    }

    if(x < 0){
        out << '-';
        x = -x;
    }

    string s;
    while(x){
        s += (x%10)+'0';
        x /= 10;
    }

    reverse(s.begin(), s.end());
    out << s;
    return out;
}

bool check(int128 mid, int128 k, vector<int128>& arr){
    int128 n = arr.size();
    for(int128 i=0; i<n; i++){
        if(arr[i] < mid){
            int128 x = mid-arr[i];
            int128 ind = i+1;
            int128 req = x/ind;
            if(x%ind != 0) req++;
            if(req > k) return false;
            k -= req;
        }
    }
    return true;
}

void solve(){
    int128 n, k;
    cin >> n >> k;
    vector<int128> arr(n);
    for(int128 i=0; i<n; i++) cin >> arr[i];
    int128 l = 0;
    int128 r = 1e25;
    int128 ans = -1;
    while(l <= r){
        int128 mid = l + (r-l)/2;
        if(check(mid, k, arr)){
            ans = mid;
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}