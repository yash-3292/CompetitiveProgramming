#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n+1);
    vector<pair<ll,int>> temp;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        temp.push_back({arr[i], i});
    } 
    sort(temp.begin(), temp.end());
    vector<int> order(n);
    for(int i=0; i<n; i++) order[i] = temp[i].second;
    for(auto it : order) cout << it << " ";
    cout << endl;
    return 0;
}