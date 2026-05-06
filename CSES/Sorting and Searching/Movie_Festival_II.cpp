#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), comp);
    multiset<int> st;
    int ans = 0;
    for(int i=0; i<n; i++){
        auto it = st.upper_bound(arr[i].first);
        if(it != st.begin()){
            it--;
            st.erase(it);
            st.insert(arr[i].second);
            ans++;
        } else{
            if(st.size() < k){
                st.insert(arr[i].second);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}