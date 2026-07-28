#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    vector<pair<int,int>> temp;
    for(auto it : freq){
        temp.push_back({it.first, it.second});
    }
    int sz = temp.size();
    for(int i=0; i<sz; i++){
        if(temp[i].second >= 4){
            cout << "Yes" << endl;
            return;
        }
    }
    int flag = 0;
    for(int i=0; i<sz; i++){
        if(i != 0 && temp[i-1].first + 1 != temp[i].first){
            flag = 0;
        }
        if(temp[i].second >= 2){
            if(flag){
                cout << "Yes" << endl;
                return; 
            } else{
                flag = 1;
            }
        }
    }
    cout << "No" << endl;
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