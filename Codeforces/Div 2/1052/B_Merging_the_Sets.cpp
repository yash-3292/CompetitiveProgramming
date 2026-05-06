#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n);
        vector<int> freq(m+1, 0);
        for(int i=0; i<n; i++){
            int l;
            cin >> l;
            for(int j=0; j<l; j++){
                int s;
                cin >> s;
                arr[i].push_back(s);
                freq[s]++;
            }
        }
        bool check = 1;
        for(int i=1; i<=m; i++){
            if(freq[i] == 0){
                check = 0;
                break;
            }
        }
        if(!check){
            cout << "NO" << endl;
            continue;
        }
        int cnt = 0;
        for(auto a : arr){
            int flag = 1;
            for(auto val : a){
                freq[val]--;
                if(freq[val] == 0) flag = 0;
            }
            if(flag == 1) cnt++;
            for(auto val : a){
                freq[val]++;
            }
        }
        if(cnt >= 2){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}