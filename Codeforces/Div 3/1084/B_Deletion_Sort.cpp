#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        if(is_sorted(arr.begin(), arr.end())){
            cout << n << endl;
        } else{
            cout << 1 << endl;
        }
    }
    return 0;
}