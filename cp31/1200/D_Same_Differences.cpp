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
        map<int,int> mpp;
        ll sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            int val = arr[i] - i;
            mpp[val]++;
            sum += (ll)(mpp[val] - 1);
        }
        cout << sum << endl;
    }
    return 0;
}