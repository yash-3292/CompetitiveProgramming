#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        map<int, int> fM1;
        map<int, int> fM2;
        int cnt = 1;
        fM1[a[0]]++;
        for(int i=0; i<n; i++){
            if(a[i] == a[i-1]) cnt++;
            else cnt = 1;
            if(fM1.find(a[i]) == fM1.end()) fM1[a[i]]++;
            else fM1[a[i]] = max(fM1[a[i]], cnt);
        }
        cnt = 1;
        fM2[b[0]]++;
        for(int i=0; i<n; i++){
            if(b[i] == b[i-1]) cnt++;
            else cnt = 1;
            if(fM2.find(b[i]) == fM2.end()) fM2[b[i]]++;
            else fM2[b[i]] = max(fM2[b[i]], cnt);
        }
        int maxi = 0;
        for(int i=1; i<=2*n; i++){
            maxi = max(maxi, fM1[i]+fM2[i]);
        }
        cout << maxi << endl;
    }
    return 0;
}
