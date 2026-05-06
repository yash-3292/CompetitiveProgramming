#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char,int> mpp;
        for(int i=0; i<n; i++){
            mpp[s[i]]++;
        }
        int flag = 0;
        for(int i=1; i<n-1; i++){
            if(mpp[s[i]] >= 2){
                flag = 1;
                break;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}