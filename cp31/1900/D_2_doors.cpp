#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> ans(n+1);
    vector<vector<int>> arr;
    for(int i=0; i<q; i++){
        int a, b, x;
        cin >> a >> b >> x;
        if(a > b) swap(a, b);
        arr.push_back({a,b,x});
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> notTake(n+1, vector<int>(30, 0));
    for(auto it : arr){
        int i = it[0];
        int j = it[1];
        int x = it[2];
        for(int k=0; k<30; k++){
            if(x&(1<<k)) continue;
            notTake[i][k] = 1;
            notTake[j][k] = 1;
        }
    }
    for(auto it : arr){
        int i = it[0];
        int j = it[1];
        int x = it[2];
        for(int k=0; k<30; k++){
            if(x&(1<<k)){
                if(ans[i]&(1<<k)) continue;
                if(ans[j]&(1<<k)) continue;
                if(notTake[j][k]){
                    ans[i] = (ans[i] | (1<<k));
                } 
            }
        }
    }
    for(auto it : arr){
        int i = it[0];
        int j = it[1];
        int x = it[2];
        for(int k=0; k<30; k++){
            if(x&(1<<k)){
                if(ans[i]&(1<<k)) continue;
                if(ans[j]&(1<<k)) continue;
                if(notTake[j][k]){
                    ans[i] = (ans[i] | (1<<k));
                } else{
                    ans[j] = (ans[j] | (1<<k));
                }
            }
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}