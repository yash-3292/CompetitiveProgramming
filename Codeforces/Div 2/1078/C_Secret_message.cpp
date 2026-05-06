#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool f(int d, vector<int>& arr, string& ans){
    vector<int> v(d, (1<<26)-1);
    int n = arr.size();
    for(int i=0; i<n; i++){
        v[i%d] = (v[i%d] & arr[i]);
    }
    for(int i=0; i<d; i++) if(!v[i]) return false;
    string s;
    for(int i=0; i<d; i++){
        int j = 0;
        while(!(v[i]&(1<<j))) j++;
        s += ('a'+j); 
    }
    while(ans.size() < n) ans += s;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for(int i=0; i<k; i++){
            string s;
            cin >> s;
            for(int j=0; j<n; j++){
                int b = s[j]-'a';
                arr[j] = (arr[j] | (1<<(b)));
            }
        }
        string ans;
        for(int i=1; i<=n; i++){
            if(n%i==0){
                if(f(i, arr, ans)) break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}