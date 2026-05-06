#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll sum = 0;
    for(int i=0; i<n; i++){
        if((ll)arr[i] <= sum+1){
            sum += (ll)arr[i];
        } else{
            break;
        }
    }
    cout << sum+1 << endl;
    return 0;
}