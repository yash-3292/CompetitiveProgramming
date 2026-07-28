#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f1(vector<int>& arr, int k, vector<int>& ans1){
    int n = arr.size();
    vector<int> ans(n);
    unordered_map<int,int> complete;
    int size = 1;
    vector<int> temp(k);
    for(int i=0; i<k; i++) temp[i] = i;
    for(int i=0; i<n; i++){
        int mini = k-1;
        int prevUsed = 0;
        if(i != 0 && size-complete.size() <= n-i-1){
            prevUsed = 1;
            mini = min(mini, (arr[i]+ans[i-1]) % k);
        }
        for(int j=0; j<=mini; j++){
            int x = (j - arr[i] + k) % k;
            int req = temp[x];
            if(req >= size){
                int val = req+1-complete.size();
                if(val <= n-i){
                    size = req + 1;
                    mini = min(mini, j);
                    break;
                }
            } else{
                if(complete.find(req) == complete.end()){
                    mini = min(mini, j);
                    break;
                } else if(req + k < size){
                    if(i == 0 || req != ans[i-1]){
                        mini = min(mini, j);
                        temp[x] = req+k;
                        break;   
                    }
                } else{
                    if(i == 0 || req != ans[i-1]){
                        int val = req+k+1-complete.size();
                        if(val <= n-i){
                            size = req + k + 1;
                            mini = min(mini, j);
                            temp[x] = req + k;
                            break;
                        }
                    }
                }
            }
        }
        ans[i] = (mini - arr[i] + k) % k;
        ans[i] = temp[ans[i]];
        complete[ans[i]] = 1;
        if(i != 0 && (ans[i-1]%k) != (ans[i]%k)){
            temp[ans[i-1]%k] = ans[i-1]+k;
        }
    }
    for(int i=0; i<n; i++){
        ans1[i] = (arr[i]+ans[i]) % k;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> ans1(n);
    f1(arr, k, ans1);
    for(auto it : ans1) cout << it << " ";
    cout << endl;
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