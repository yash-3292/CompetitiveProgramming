#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n = 100;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    ll rem = 0;
    vector<int> ans;
    for(int i=49; i>=0; i--){
        for(int j=0; j<n; j++){
            rem += (ll)(arr[j][i]-'0');
        }
        ans.push_back(rem%10);
        rem /= 10;
    }
    while(rem){
        ans.push_back(rem%10);
        rem /= 10;
    }
    for(int i=ans.size()-1; i>=ans.size()-10; i--){
        cout << ans[i];
    }
    return 0;
}