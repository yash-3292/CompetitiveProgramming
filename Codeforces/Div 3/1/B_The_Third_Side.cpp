#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        ll value = 0;
        for(int i=0; i<n; i++){
            value += arr[i];
        }
        value -= n-1;
        cout << value << endl;
    }
    return 0;
}