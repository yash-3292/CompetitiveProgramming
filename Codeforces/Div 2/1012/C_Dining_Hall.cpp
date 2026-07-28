#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    set<vector<int>> st1;
    set<vector<int>> st2;
    int sq = 1;
    while(sq*(sq+1) <= 2*n) sq++;
    sq++;   
    for(int i=0; i<sq; i++){
        for(int j=0; j<sq; j++){
            st1.insert({3*i+3*j+2, 3*i+1, 3*j+1});
            st2.insert({3*i+3*j+2, 3*i+1, 3*j+1});
            st1.insert({3*i+3*j+3, 3*i+1, 3*j+2});
            st1.insert({3*i+3*j+3, 3*i+2, 3*j+1});
            st1.insert({3*i+3*j+6, 3*i+2, 3*j+2});
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            auto v = *st2.begin();
            cout << v[1] << " " << v[2] << endl;
            st1.erase(v);
            st2.erase(v);
        } else{
            auto v = *st1.begin();
            cout << v[1] << " " << v[2] << endl;
            if((v[1]%3 == 1) && (v[2]%3 == 1)){
                st2.erase(v);
            }
            st1.erase(v);
        }
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