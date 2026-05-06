#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> p(k);
        for(int i=0; i<k; i++){
            int x;
            cin >> x;
            p[i] = x-1;
        }
        int x =  arr[p[0]];
        vector<int> pre(n, 0);
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1];
            if(arr[i] != arr[i-1]) pre[i]++;
        }
        for(auto it : pre) cout << it << " ";
        cout << endl;
    }
    return 0;
}
