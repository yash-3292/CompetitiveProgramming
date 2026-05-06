#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        if(x > val){
            x = val;
            cout << 1 << endl;
        } else{
            cout << 0 << endl;
        }
    }
    return 0;
}