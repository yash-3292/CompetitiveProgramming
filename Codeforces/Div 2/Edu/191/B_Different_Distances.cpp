#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr1 = {1, 2, 1, 2, 2, 1, 1, 2};
    vector<int> arr2 = {1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3};
    if(n&1){
        for(auto it : arr2) cout << it << " ";
        for(int i=3; i<n; i+=2){
            for(auto it : arr1){
                cout << it+i << " ";
            }
        }
        cout << endl;
    } else{
        for(int i=0; i<n; i+=2){
            for(auto it : arr1){
                cout << it+i << " ";
            }
        }
        cout << endl;
    }
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