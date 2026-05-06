#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(n == 1){
            cout << "NO" << endl;
            continue;
        }
        int isSame = 1;
        for(int i=1; i<n; i++){
            if(s[i] != s[i-1]){
                isSame = 0;
            }
        }
        if(isSame == 1){
            cout << "NO" << endl;
            continue;
        }
        if(k > 0){
            cout << "YES" << endl;
            continue;
        } 
        int small = 0;
        int i=0, j=n-1;
        while(i < j){
            if(s[i] < s[j]){
                small = 1;
                break;
            } else if(s[i] > s[j]){
                break;
            } else {
                i++;
                j--;
            }
        }
        if(small == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}