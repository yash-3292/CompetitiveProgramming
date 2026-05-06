#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int one = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] == 1) one++;
    }
    if(one != 0){
        int ans = n - one;
        cout << ans << endl;
        return 0;
    }

    int gcd = arr[0];
    for(int i=0; i<n; i++) gcd = __gcd(arr[i], gcd);
    if(gcd != 1){
        cout << -1 << endl;
        return 0;
    }
    int dist = n-1;
    for(int i=0; i<n; i++){
        int temp = arr[i];
        for(int j=i+1; j<n; j++){
            if(j-i >= dist) break;
            temp = __gcd(temp, arr[j]);
            if(temp == 1){
                dist = min(dist, j-i);
                break;
            }
        }
    }
    int ans = dist + n-1;
    cout << ans << endl;
    return 0;
}