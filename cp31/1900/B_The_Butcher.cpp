#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

static bool comp1(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
    return p1.first > p2.first;
}

static bool comp2(const pair<ll,ll>& p1, const pair<ll,ll>& p2){
    return p1.second > p2.second;
}

bool check(ll h, ll w, vector<pair<ll,ll>>& arr){
    int n = arr.size();
    vector<pair<ll,ll>> arr1 = arr;
    vector<pair<ll,ll>> arr2 = arr;
    sort(arr1.begin(), arr1.end(), comp1);
    sort(arr2.begin(), arr2.end(), comp2);
    map<pair<int,int>,int> mpp1;
    map<pair<int,int>,int> mpp2;
    int i = 0;
    int j = 0;
    while(i < n && j < n){
        int flag = 0;
        while(i < n){
            if(mpp2[arr1[i]] > 0){
                mpp2[arr1[i]]--;
                i++;
            } else{
                if(h == arr1[i].first){
                    flag = 1;
                    w -= arr1[i].second;
                    mpp1[arr1[i]]++;
                    i++;
                } else{
                    break;
                }
            }
        }
        while(j < n){
            if(mpp1[arr2[j]] > 0){
                mpp1[arr2[j]]--;
                j++;
            } else{
                if(w == arr2[j].second){
                    flag = 1;
                    h -= arr2[j].first;
                    mpp2[arr2[j]]++;
                    j++;
                } else{
                    break;
                }
            }
        }
        if(!flag) return false; 
    }
    return true;
}

void solve(){
    ll n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
    ll area = 0;
    ll maxh = 0;
    ll maxw = 0;
    for(ll i=0; i<n; i++){
        area += arr[i].first * arr[i].second;
        maxh = max(maxh, arr[i].first);
        maxw = max(maxw, arr[i].second);
    }
    vector<pair<ll,ll>> ans;
    if(area%maxh == 0){
        ll h = maxh;
        ll w = area/h;
        if(check(h, w, arr)) ans.push_back({h,w});
    }
    if(area%maxw == 0){
        ll w = maxw;
        ll h = area/w;
        if(check(h, w, arr)) ans.push_back({h,w});
    }
    if(ans.size() == 1 || ans[0] == ans[1]){
        cout << 1 << endl;
        cout << ans[0].first << " " << ans[0].second << endl;
    } else{
        cout << ans.size() << endl;
        for(auto it : ans) cout << it.first << " " << it.second << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}