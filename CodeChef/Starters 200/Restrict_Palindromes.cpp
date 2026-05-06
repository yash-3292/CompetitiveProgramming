#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            if(i%3 == 0) cout << "a";
            else if(i%3 == 1) cout << "b";
            else cout << "c";
        }
        cout << endl;
    }
    return 0;
}