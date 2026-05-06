#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ans;
        vector<vector<int>> arr(n+1);
        for(int i=1; i<=n; i++){
            cout << "? " << i << " " << n << " ";
            for(int j=1; j<=n; j++){
                cout << j;
                if(j != n) cout << " "; 
            }
            cout << "\n" << flush;
            int x; 
            cin >> x;
            arr[x].push_back(i);
        }
        int i;
        for(int j=n; j>=1; j--){
            if(arr[j].size()){
                ans.push_back(arr[j][0]);
                i = j;
                break;
            }
        }
        i--;
        while(i){
            for(int val : arr[i]){
                cout << "? " << ans.back() << " " << 2 << " " << ans.back() << " " << val;
                cout << "\n" << flush;
                int x; 
                cin >> x;
                if(x == 2){
                    ans.push_back(val);
                    break;
                }
            }
            i--;
        }
        int m = ans.size();
        cout << "! " << ans.size() << " ";
        for(int i=0; i<m; i++){
            cout << ans[i];
            if(i != m-1) cout << " ";
        }
        cout << "\n" << flush;
    }
    return 0;
}