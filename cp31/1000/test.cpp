#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int maxi = 0;
    for(int i=1; i<n; i++){
        maxi = max(maxi, arr[i]^arr[i-1]);
    }
    cout << maxi << endl;
    return 0;
}
