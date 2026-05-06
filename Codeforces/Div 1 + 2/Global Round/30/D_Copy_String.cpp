#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, kmax;
        cin >> n >> kmax;
        string s, t;
        cin >> s;
        cin >> t;
        if(s[0] != t[0]){
            cout << -1 << endl;
            continue;
        }
        vector<int> arr(n);
        int flag = 1;
        int maxi = 0;
        for(int i=n-1; i>=0; i--){
            int r;
            if(i == n-1) r = 0;
            else r = max(0, arr[i+1]-1);
            int k = -1;
            for(int j=i-r; j>=i-kmax; j--){
                char ch = (j >= 0) ? s[j] : s[0];
                if(t[i] == ch){
                    k = i-j;
                    break;
                }
            }
            if(k == -1){
                flag = 0;
                break;
            } else{
                arr[i] = k;
                maxi = max(maxi, k);
            }
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        }
        cout << maxi << endl;
        string prev = s;
        string cur = s;
        for(int j=0; j<maxi; j++){
            for(int i=0; i<n; i++){
                if(i == 0) cur[i] = prev[i];
                if(arr[i] > 0){
                    cur[i] = prev[i-1];
                    arr[i]--;
                }
            }
            cout << cur << endl;
            prev = cur;
        }
    }
    return 0;
}
