#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int i = 0; 
    int j = n-1; 
    int x = 1;
    while(i <= j){
        if(arr[i] == x){
            i++;
        } else if(arr[j] == x){
            j--;
        } else{
            cout << "NO" << endl;
            return;
        }
        x++;
    }
    cout << "YES" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}