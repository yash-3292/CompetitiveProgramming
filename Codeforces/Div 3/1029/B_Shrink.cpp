#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n&1){
            for(int i=1; i<=n; i+=2){
                cout << i << " ";
            }
            for(int i=n-1; i>=2; i-=2){
                cout << i << " ";
            }
            cout << endl;
        } else{
            for(int i=1; i<=n; i+=2){
                cout << i << " ";
            }
            for(int i=n; i>=2; i-=2){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}