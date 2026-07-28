#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt0 = 0;
        int cnt1 = 0;
        int cntm1 = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x == 1) cnt1++;
            else if(x == 0) cnt0++;
            else cntm1++;
        }
        if(cnt1 > 0 && cntm1 == 0) cout << -1 << " ";
        else if(cnt1 >= 2) cout << -1 << " ";
        if(cnt1 > 0 && cntm1 > 0) cout << 0 << " ";
        else if(cnt1 == 0 && cntm1 == 0) cout << 0 << " "; 
        if(cntm1 > 0 && cnt1 == 0) cout << 1 << " ";
        else if(cntm1 >= 2) cout << 1 << " ";
        cout << endl;
    }
    return 0;
}