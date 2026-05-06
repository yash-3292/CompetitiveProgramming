#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> s(n);
        vector<int> t(n);
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            x = x%k;
            x = min(x, k-x);
            s[i] = x;
        }
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            x = x%k;
            x = min(x, k-x);
            t[i] = x;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}