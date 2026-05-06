#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        ll sum = 0;
        int isAllNeg = 1;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += (ll)arr[i];
            if(arr[i] >= 0) isAllNeg = 0;
        } 
        if(isAllNeg){
            cout << "NO" << endl;
            continue;
        }
        ll maxi = 0;
        ll sumi = 0;
        for(int i=0; i<n-1; i++){
            sumi += (ll)arr[i];
            if(sumi < 0) sumi = 0;
            maxi = max(maxi, sumi);
        }
        sumi = 0;
        for(int i=1; i<n; i++){
            sumi += (ll)arr[i];
            if(sumi < 0) sumi = 0;
            maxi = max(maxi, sumi);
        }
        if(sum > maxi){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}