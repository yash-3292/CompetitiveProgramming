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
        for(int i=0; i<n; i++) cin >> arr[i];
        int i = 0;
        int j = n-1;
        int flag = 0;
        int gcd;
        while(i <= j){
            int diff = abs(arr[i] - arr[j]);
            if(diff != 0){
                if(flag == 0){
                    gcd = diff;
                    flag = 1;
                } else{
                    gcd = __gcd(gcd, diff);
                }
            }
            i++;
            j--;
        }
        if(flag == 0){
            cout << 0 << endl;
        } else{
            cout << gcd << endl;
        }
    }
    return 0;
}