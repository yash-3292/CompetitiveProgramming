#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<pair<pair<char,int>, pair<char,int>>> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
    }
    vector<int> prio(n);
    int p = 0;
    for(int i=n-1; i>=0; i--){
        prio[i] = p;
        if(arr[i].first.first == '+' && arr[i].second.first == '+'){
            continue;
        }
        if(arr[i].first.first == '+' && arr[i].second.first == 'x'){
            p = 1;
        }
        if(arr[i].first.first == 'x' && arr[i].second.first == '+'){
            p = 0;
        }
        if(arr[i].first.first == 'x' && arr[i].second.first == 'x'){
            if(arr[i].first.second > arr[i].second.second) p = 0;
            else if(arr[i].first.second < arr[i].second.second) p = 1;
        }
    }
    ll a = 1;
    ll b = 1;
    for(int i=0; i<n; i++){
        ll extra = 0;
        if(arr[i].first.first == '+'){
            extra += (ll)arr[i].first.second;
        } else {
            extra += a * (ll)(arr[i].first.second - 1);
        }
        if(arr[i].second.first == '+'){
            extra += (ll)arr[i].second.second;
        } else {
            extra += b * (ll)(arr[i].second.second - 1);
        }
        if(prio[i] == 0){
            a += extra;
        } else{
            b += extra;
        }
    }
    ll ans = a + b;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}