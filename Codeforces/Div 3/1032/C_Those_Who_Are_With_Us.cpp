#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int maxi = 0;
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];
                maxi = max(maxi, arr[i][j]);
            }
        }
        vector<pair<int,int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == maxi){
                    ans.push_back(make_pair(i,j));
                }
            }
        }
        int size = ans.size();
        if(size == 1 || size == 2){
            cout << maxi-1 << endl;
            continue;
        }
        int row = ans[0].first;
        int col = -1;
        int flag = 1;
        for(int i=1; i<size; i++){
            if(col == -1){
                if(ans[i].first != row){
                    col = ans[i].second;
                }
            } else{
                if(ans[i].first != row && ans[i].second != col){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){
            cout << maxi-1 << endl;
            continue;
        }
        row = -1;
        col = ans[0].second;
        flag = 1;
        for(int i=1; i<size; i++){
            if(row == -1){
                if(ans[i].second != col){
                    row = ans[i].first;
                }
            } else{
                if(ans[i].first != row && ans[i].second != col){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag){
            cout << maxi-1 << endl;
            continue;
        }
        cout << maxi << endl;
    }
    return 0;
}