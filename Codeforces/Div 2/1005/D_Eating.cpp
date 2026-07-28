#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> prexor(n);
    arr[0] = arr[0];
    for(int i=1; i<n; i++){
        prexor[i] = (prexor[i-1] ^ arr[i]);
    }
    vector<int> maxind(n);
    for(int i=0; i<n; i++){
        for(int j=29; j>=0; j--){
            if(arr[i]&(1<<j)){
                maxind[i] = j;
                break;
            }
        }
    }
    vector<vector<int>> temp(30, vector<int>(n));
    for(int i=29; i>=0; i--){
        int ind = -1;
        for(int j=0; j<n; j++){
            if(maxind[j] >= i) ind = j;
            temp[i][j] = ind;
        }
    }
    while(q--){
        int x;
        cin >> x;
        int j = n-1;
        for(int i=29; i>=0; i--){
            if(x&(1<<i)){
                // cout << x << " " << i << " ";
                int pj = j;
                j = temp[i][j];
                if(j == -1) break;
                x = (x ^ prexor[j]);
                x = (x ^ prexor[pj]);
                if(arr[j] > x) break;
                x = (x ^ arr[j]);
                j--;
                // cout << endl;
            }
            if(j == -1) break;
        }
        // cout << j << " ";
        cout << n-(j+1) << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}