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
        for(int i=0; i<n; i++){
            string x;
            cin >> x;
            if(s.empty()) s += x;
            else{
                if(s+x < x+s) s = s+x;
                else s = x+s;
            }
        }
        cout << s << endl;
    }
    return 0;
}