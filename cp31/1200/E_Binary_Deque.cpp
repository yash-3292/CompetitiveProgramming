#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int one = 0;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] == 1){
                one++;
            } 
        }
        if(one < s){
            cout << -1 << endl;
            continue;
        } else if(one == s){
            cout << 0 << endl;
            continue;
        }
        int k = one - s;
        vector<int> prefix;
        prefix.push_back(0);
        vector<int> suffix;
        suffix.push_back(0);
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                prefix.push_back(i+1);
            }
        }
        for(int i=n-1; i>=0; i--){
            if(arr[i] == 1){
                suffix.push_back(n-i);
            }
        }
        int mini = 1e7;
        for(int i=0; i<=k; i++){
            mini = min(mini, prefix[i]+suffix[k-i]);
        }
        cout << mini << endl;
    }
    return 0;
}