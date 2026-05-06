#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n), a(n);
        vector<int> arr(n+1);
        for(int i=0; i<n; i++) cin >> p[i];
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++){
            arr[p[i]] = i+1;
        }
        int flag = 1;
        for(int i=1; i<n; i++){
            if(arr[a[i-1]] > arr[a[i]]){
                flag = 0;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}