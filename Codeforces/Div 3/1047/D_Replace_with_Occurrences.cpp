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
        map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            mpp[x].push_back(i);
        }
        int flag = 1;
        for(auto it : mpp){
            if(it.second.size() % it.first != 0){
                flag = 0;
                break;
            } 
        }
        if(!flag){
            cout << -1 << endl;
            continue;;
        }
        int cnt = 0;
        for(auto it : mpp){
            int k = it.first;
            int m = it.second.size();
            for(int i=0; i<m; i++){
                if(i%k == 0) cnt++;
                arr[it.second[i]] = cnt;
            }
        }
        for(auto val : arr){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}