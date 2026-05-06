#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string pre;
        string suf;
        bool flag = false;
        for(int i=0; i<2*n-2; i++){
            string s;
            cin >> s;
            if(s.size() == n-1){
                if(!flag){
                    pre = s;
                    flag = true;
                } else{
                    suf = s;
                }
            }
        }
        flag = true;
        for(int i=0; i<n-2; i++){
            if(pre[i+1] != suf[i]){
                flag = false;
                break;
            }
        }
        if(!flag) swap(pre, suf);
        pre += suf[n-2];
        int i = 0;
        int j = n-1;
        flag = true;
        while(i <= j){
            if(pre[i] != pre[j]){
                flag = false;
                break;
            }
            i++;
            j--;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
