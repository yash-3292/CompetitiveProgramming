#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        map<int,int> mpp;
        mpp[x] = 1;
        int i = 0;
        int cnt = 1;
        while(i < n){
            vector<int> temp;
            int pos = 1;
            for(auto it : mpp){
                if(it.first == arr[i]){
                    pos = 0;
                    break;
                }
                if(it.first%arr[i] == 0) temp.push_back(it.first/arr[i]);
            }
            if(!pos){
                mpp.clear();
                mpp[x] = 1;
                cnt++;
                continue;
            }
            for(auto it : temp) mpp[it] = 1;
            i++;
        }
        cout << cnt << endl;
    }
    return 0;
}