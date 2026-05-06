#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<vector<int>> arr;
        vector<int> a(1<<n);
        for(int i=0; i<(1<<n); i++) cin >> a[i];
        arr.push_back(a);
        for(int i=1; i<n; i++){
            vector<int> temp;
            for(int j=0; j<arr[i-1].size(); j+=2){
                temp.push_back(arr[i-1][j]^arr[i-1][j+1]);
            }
            arr.push_back(temp);
        }
        while(q--){
            int b, c;
            cin >> b >> c;
            b--;
            int ans = 0;
            int prev = a[b];
            int curr = c;
            int j = b;
            for(int i=0; i<n; i++){
                if(j&1){
                    int val1 = ((arr[i][j] ^ prev) ^ curr);
                    int val2 = arr[i][j-1];
                    if(val1 <= val2){
                        ans += (1<<i);
                    }
                } else{
                    int val1 = ((arr[i][j] ^ prev) ^ curr);
                    int val2 = arr[i][j+1];
                    if(val1 < val2){
                        ans += (1<<i);
                    }
                }
                j /= 2;
            }
            cout << ans << endl;
        }
    }
    return 0;
}