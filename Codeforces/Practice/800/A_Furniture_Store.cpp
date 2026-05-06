#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> ans;
        int val = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] >= val){
                ans.push_back(i+1);
            } else{
                val = arr[i];
            }
        }
        cout << ans.size() << endl;
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}