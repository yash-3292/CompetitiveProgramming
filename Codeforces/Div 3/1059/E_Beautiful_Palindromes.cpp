#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<int> vis(n+1, 0);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            vis[arr[i]] = 1;
        }
        int val = -1;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                val = i;
                break;
            }
        }
        if(val == -1){
            for(int i=0; i<k; i++) cout << arr[i] << " ";
            cout << endl;
        } else{
            cout << val << " ";
            if(k == 1){
                cout << endl;
                continue;
            }
            int val1 = -1;
            for(int i=1; i<=n; i++){
                if(i != arr[n-1] && i != val){
                    val1 = i;
                    break;
                }
            }
            cout << val1 << " ";
            vector<int> temp;
            for(int i=1; i<=n; i++){
                if(i!=val && i!=val1) temp.push_back(i);
            }
            for(int i=0; i<k-2; i++){
                cout << temp.back() << " ";
                temp.pop_back();
            }
            cout << endl;
        }
    }
    return 0;
}