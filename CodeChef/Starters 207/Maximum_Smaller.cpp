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
        vector<int> realArr(n); 
        vector<int> ans(n+1);
        map<int,int> freq;
        for(int i=0; i<n; i++){
            cin >> arr[i].first;
            realArr[i] = arr[i].first;
            arr[i].second = i+1;
            freq[realArr[i]]++;
        }
        int flag = 1;
        for(auto it : freq){
            if(it.second == 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << n << endl;
            map<int,vector<int>> mpp;
            for(int i=0; i<n; i++) mpp[realArr[i]].push_back(i+1);
            for(auto it : mpp){
                int sz = it.second.size();
                for(int i=0; i<sz; i++){
                    ans[it.second[i]] = it.second[(i-1+sz)%sz];
                }
            }
            for(int i=1; i<=n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
            continue;
        }
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            ans[arr[i].second] = arr[(i-1+n)%n].second;
        }
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(realArr[ans[i]-1] <= realArr[i-1]) cnt++;
        }
        cout << cnt << endl;
        for(int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}