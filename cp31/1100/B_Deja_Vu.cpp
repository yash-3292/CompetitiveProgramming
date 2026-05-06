#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        vector<pair<int,int>> arr(n); 
        for(int i=0; i<n; i++){
            cin >> a[i];
            int j = 0;
            ll val = 1;
            while(a[i] % val == 0){
                j++;
                val *= 2;
            }
            j--;
            arr[i].first = j;
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        while(q--){
            int x;
            cin >> x;
            ll num = (ll)pow(2,x-1);
            for(int i=n-1; i>=0; i--){
                if(arr[i].first >= x){
                    a[arr[i].second] += num;
                    arr[i].first = x - 1;
                } else{
                    break;
                }
            }
        }
        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}