#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> w(n+1);
        ll sum = 0;
        for(int i=1; i<=n; i++){
            cin >> w[i];
            sum += (ll)w[i];
        } 
        vector<int> degree(n+1, 0);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }
        vector<int> arr;
        for(int i=1; i<=n; i++){
            int sz = degree[i]-1;
            for(int j=0; j<sz; j++) arr.push_back(w[i]);
        }
        sort(arr.begin(), arr.end(), greater<int>());
        cout << sum << " ";
        for(auto it : arr){
            sum += it;
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}