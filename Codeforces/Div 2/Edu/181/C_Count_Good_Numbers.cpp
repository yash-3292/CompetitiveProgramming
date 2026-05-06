#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        vector<int> arr1 = {2,3,5,7,30,70,42,105};
        vector<int> arr2 = {6,10,14,15,21,35,210};
        ll nums = 0;
        for(int val : arr1){
            nums += r/(ll)val - (l-1)/(ll)val;
        }
        for(int val : arr2){
            nums -= r/(ll)val - (l-1)/(ll)val;
        }
        ll ans = r-l+1 - nums;
        cout << ans << endl;
    }
    return 0;
}