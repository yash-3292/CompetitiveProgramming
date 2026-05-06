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
        int prev2 = 0;
        int prev3 = 0;
        int i = 0;
        int j = 0;
        ll ans = 0;
        while(j < n){
            if(arr[j]%6 == 0) i = j+1;
            else if(arr[j]%2 == 0) i = max(i, prev3+1);
            else if(arr[j]%3 == 0) i = max(i, prev2+1);
            if(arr[j]%2 == 0) prev2 = j;
            if(arr[j]%3 == 0) prev3 = j;
            ans += i;
            j++;
        }
        
    }
    return 0;
}