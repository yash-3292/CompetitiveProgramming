#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    ll sum = 0;
    int maxi = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
        sum += arr[i]; 
    }
    if(sum&1){
        cout << "NO" << endl;
        return 0;
    }
    if(sum-(ll)maxi >= (ll)maxi){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}