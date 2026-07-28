#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int val = 0;
    for(int i=0; i<n; i++){
        val = (val | arr[i]);
    }
    int temp = 0;
    vector<int> ans;
    for(int i=0; i<n; i++){
        temp = (temp | arr[i]);
        if(temp == val){
            ans.push_back(i);
            temp = 0;
        } 
    }
    val = ans.size() - 1;
    val = n - 1 - val;
    cout << val << endl;
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