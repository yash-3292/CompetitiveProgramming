#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        vector<int> arr(r+1);
        for(int i=0; i<=r; i++) arr[i] = i;
        int i = 29;
        ll ans = 0;
        for(int j=r; j>0; j--){
            if(arr[j] != j) continue;
            while((j&(1<<i)) == 0) i--;
            int val = (~j) & ((1<<(i+1)) - 1);
            ans += 2*(val | j);
            arr[j] = val;
            arr[val] = j;
        }
        cout << ans << endl;
        for(int i=0; i<=r; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}