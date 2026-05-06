#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            arr[i].first = a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
            arr[i].second = b[i];
        } 
        sort(arr.begin(), arr.end());
        int cnt = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;
        vector<ll> stealCoin(n);
        stealCoin[0] = 0;
        for(int i=0; i<n-1; i++){
            if(cnt != k){
                pq.push(arr[i].second);
                sum += (ll)arr[i].second;
                cnt++;
            } else{
                int mini = pq.top();
                if(mini < arr[i].second){
                    pq.pop();
                    pq.push(arr[i].second);
                    sum = sum + (ll)arr[i].second - (ll)mini;
                }
            }
            stealCoin[i+1] = sum;
        }
        for(int i=0; i<n; i++){
            cout << stealCoin[a[i]-1] << " ";
        }
        cout << endl;
    }
    return 0;
}