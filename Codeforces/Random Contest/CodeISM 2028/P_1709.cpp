#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int i, int n){
    int ans = i%n;
    if(ans == 0) return n;
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a, b;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        
        for(int i=n; i>0; i--){
            for(int j=1; j<i; j++){
                if(f(a[i], n) > f(a[i-1], n)){
                    
                }
            }
        }
    }
}