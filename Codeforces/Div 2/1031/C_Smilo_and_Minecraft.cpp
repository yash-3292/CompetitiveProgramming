#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int gold = 0;
        vector<vector<char>> arr(n, vector<char>(m));
        vector<pair<int,int>> goldi;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 'g'){
                    gold++;
                    goldi.push_back(make_pair(i,j));
                } 
            }
        }
        int mini = 1e5;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == '.'){
                    int dig = 0;
                    for(pair<int,int> val : goldi){
                        int x = val.first;
                        int y = val.second;
                        if(abs(x-i) > k-1) continue;
                        if(abs(y-j) > k-1) continue;
                        dig++;
                    }
                    mini = min(mini, dig);
                }
            }
        }
        int ans = gold - mini;
        cout << ans << endl;
    }
    return 0;
}