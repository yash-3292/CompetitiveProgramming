#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x<0) arr[i] = 1;
        else arr[i] = 0;
    }
    ll negAns = 0;
    ll posAns = 0;
    ll one = 0;
    ll zero = 0;
    ll cnt = 0;
    for(int i=0; i<n; i++){
        cnt ^= (ll)arr[i];
        if(cnt == 0){
            posAns += zero+1;
            negAns += one;
            zero++;
        } else{
            posAns += one;
            negAns += zero+1;
            one++;
        }
    }
    cout << negAns << " " << posAns << endl;
    return 0;
}