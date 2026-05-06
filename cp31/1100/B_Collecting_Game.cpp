#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr.begin(),arr.end());
        vector<ll> sum(n);
        ll total = 0;
        for(int i=0; i<n; i++){
            total += (ll)arr[i].first;
            sum[i] = total;
        }
        vector<pair<int,int>> collect(n);
        collect[n-1].second = n-1;
        collect[n-1].first = arr[n-1].second;
        for(int i=n-2; i>=0; i--){
            collect[i].first = arr[i].second;
            if(sum[i] >= arr[i+1].first) collect[i].second = collect[i+1].second;
            else collect[i].second = i;
        }
        sort(collect.begin(),collect.end());
        for(int i=0; i<n; i++) cout << collect[i].second << " ";
        cout << endl;
    }
    return 0;
}