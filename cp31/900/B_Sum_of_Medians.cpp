#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ,k;
        cin >> n >> k;
        vector<int> arr(n*k);
        for(int i=0; i<n*k; i++) cin >> arr[i];
        int pos = (int)ceil(double(n)/2.0);
        int lP = n - pos + 1;
        ll sum = 0;
        for(int i=1; i<=k; i++){
            sum += (ll)arr[(n*k)-lP*i];
        }
        cout << sum << endl;
    }
    return 0;
}