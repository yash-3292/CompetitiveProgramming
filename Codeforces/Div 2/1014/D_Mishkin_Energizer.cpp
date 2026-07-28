#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr;
    for(int i=0; i<n; i++){
        if(s[i] == 'L') arr.push_back(0);
        else if(s[i] == 'I') arr.push_back(1);
        else arr.push_back(2);
    }
    vector<int> cnt(3,0);
    for(int i=0; i<n; i++){
        cnt[arr[i]]++;
    }
    int maxi = 0;
    for(int i=0; i<3; i++){
        if(cnt[i] == n){
            cout << -1 << endl;
            return;
        }
        maxi = max(maxi, cnt[i]);
    }
    vector<int> ans;
    while(true){
        if(cnt[0] == maxi && cnt[1] == maxi && cnt[2] == maxi){
            break;
        }
        int flag = 0;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] == arr[i+1]) continue;
            int val;
            vector<int> vis(3,0);
            vis[arr[i]] = 1;
            vis[arr[i+1]] = 1;
            for(int j=0; j<3; j++) if(!vis[j]) val = j;
            if(cnt[val] == maxi) continue;
            flag = 1;
            cnt[val]++;
            ans.push_back(i);
            arr.insert(arr.begin()+i+1, val);
            break;
        }
        if(!flag) break;
    }
    if(cnt[0] == maxi && cnt[1] == maxi && cnt[2] == maxi){
        cout << ans.size() << endl;
        for(auto it : ans) cout << it+1 << endl;
        return;
    }
    ans.clear();
    arr.clear();
    for(int i=0; i<n; i++){
        if(s[i] == 'L') arr.push_back(0);
        else if(s[i] == 'I') arr.push_back(1);
        else arr.push_back(2);
    }
    for(int i=0; i<3; i++) cnt[i] = 0;
    for(int i=0; i<n; i++){
        cnt[arr[i]]++;
    }
    maxi++;
    while(true){
        if(cnt[0] == maxi && cnt[1] == maxi && cnt[2] == maxi){
            break;
        }
        int flag = 0;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i] == arr[i+1]) continue;
            int val;
            vector<int> vis(3,0);
            vis[arr[i]] = 1;
            vis[arr[i+1]] = 1;
            for(int j=0; j<3; j++) if(!vis[j]) val = j;
            if(cnt[val] == maxi) continue;
            flag = 1;
            cnt[val]++;
            ans.push_back(i);
            arr.insert(arr.begin()+i+1, val);
            break;
        }
        if(!flag) break;
    }   
    if(cnt[0] == maxi && cnt[1] == maxi && cnt[2] == maxi){
        cout << ans.size() << endl;
        for(auto it : ans) cout << it+1 << endl;
    } else{
        cout << -1 << endl;
    }
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