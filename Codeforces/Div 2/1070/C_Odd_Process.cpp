#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<ll> even;
        vector<ll> odd;
        for(int i=0; i<n; i++){
            if(arr[i]&1) odd.push_back(arr[i]);
            else even.push_back(arr[i]);
        }
        sort(even.begin(), even.end(), greater<ll>());
        sort(odd.begin(), odd.end(), greater<ll>());
        int ol = odd.size();
        int el = even.size();
        if(ol == 0){
            for(int i=0; i<n; i++){
                cout << 0 << " ";
            }
            cout << endl;
            continue;
        }
        vector<ll> prefeven(el);
        for(int i=0; i<el; i++){
            if(i == 0) prefeven[i] = even[i];
            else prefeven[i] = prefeven[i-1] + even[i];
        }
        for(int k=1; k<=n; k++){
            if(k <= el+1){
                if(k == 1) cout << odd[0] << " ";
                else{
                    ll sum = odd[0];
                    int e = k-1;
                    sum += prefeven[e-1];
                    cout << sum << " ";
                }
                continue;
            }
            if((k-el)%2 == 0){
                if(k == n){
                    cout << 0 << " ";
                } else{
                    if(el == 0){
                        cout << 0 << " ";
                        continue;
                    }
                    ll sum = odd[0];
                    if(el-2 >= 0) sum += prefeven[el-2];
                    cout << sum << " ";
                }
            } else{
                ll sum = odd[0];
                if(el) sum += prefeven[el-1];
                cout << sum << " ";
            }
        }
        cout << endl;
    }
    return 0;
}