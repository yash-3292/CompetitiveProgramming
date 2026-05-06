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
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = arr[0];
        for(int i=1; i<n; i++) pre[i] = min(pre[i-1], arr[i]);
        suf[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--) suf[i] = max(suf[i+1], arr[i]);
        int flag = 1;
        for(int i=1; i<n; i++){
            if(pre[i-1] > suf[i]) flag = 0;
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl; 
    }
    return 0;
}