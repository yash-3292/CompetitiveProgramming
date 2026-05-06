#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> arr(n-1);
    for(int i=0; i<(int)n-1; i++){
        cin >> arr[i];
    }
    ll realSum = (n*(n+1))/2;
    ll sum = 0;
    for(int i=0; i<(int)n-1; i++){
        sum += arr[i];
    }
    cout << realSum - sum << endl;
    return 0;
}