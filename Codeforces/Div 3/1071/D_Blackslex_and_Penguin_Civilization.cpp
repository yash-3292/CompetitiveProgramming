#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vis((1<<n), 0);
        for(int x=n; x>=0; x--){
            int y = n-x;
            for(int i=0; i<(1<<y); i++){
                int val = (i<<x) + ((1<<x) - 1);
                if(!vis[val]){
                    vis[val] = 1;
                    cout << val << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}