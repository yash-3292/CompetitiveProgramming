#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> arr(n, 1e9);
        int val = 1e9;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                val = 0;
            } else{
                val++;
            }
            arr[i] = min(arr[i], val);
        }
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                val = 0;
            } else{
                val++;
            }
            arr[i] = min(arr[i], val);
        }
        int maxi = 0;
        for(int i=0; i<n; i++) maxi = max(maxi, arr[i]);
        cout << maxi << endl;
    }
    return 0;
}