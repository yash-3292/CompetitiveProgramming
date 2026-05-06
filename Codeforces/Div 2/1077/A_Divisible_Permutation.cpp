#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=(n+1)/2; i>=1; i--){
            cout << i << " ";
            if(n+1-i != i) cout << n+1-i << " ";
        }
        cout << endl;
    }
    return 0;
}