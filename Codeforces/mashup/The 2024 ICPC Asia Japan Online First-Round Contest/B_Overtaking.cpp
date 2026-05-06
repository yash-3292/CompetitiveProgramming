#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=1; i<n; i++){
            a[i] = a[i]+a[i-1];
            b[i] = b[i]+b[i-1];
        }
        int lead = -1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(a[i] > b[i]){
                if(lead == 1) cnt++;
                lead = 0;
            } else if(a[i] < b[i]){
                if(lead == 0) cnt++;
                lead = 1;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}