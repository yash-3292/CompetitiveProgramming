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
        int val = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(s[val] == 'R') val++;
            else val--;
            maxi = max(maxi, val);
        }
        cout << maxi+1 << endl;
    }
    return 0;
}