#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int open = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
        }
        if(open * 2 != n){
            cout << -1 << endl;
            continue;
        } 
        int cnt = 0;
        int flag1 = 1;
        for(int i=0; i<n; i++){
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt < 0){
                flag1 = 0;
                break;
            }
        }
        cnt = 0;
        int flag2 = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt < 0){
                flag2 = 0;
                break;
            }
        }
        if(flag1 || flag2){
            cout << 1 << endl;
            for(int i=0; i<n; i++){
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }
        cnt = 0;
        int j = n-1;
        vector<int> val(n, 1);
        for(int i=0; i<n; i++){
            if(val[i] == 2) continue;
            if(s[i] == '(') cnt++;
            else cnt--;
            if(cnt < 0){
                cnt = 0;
                val[i] = 2;
                while(s[j] != '(') j--;
                val[j] = 2;
                j--;
            }
        }
        cout << 2 << endl;
        for(int i=0; i<n; i++){
            cout << val[i] << " ";
        }
        cout << endl;
    }
    return 0;
}