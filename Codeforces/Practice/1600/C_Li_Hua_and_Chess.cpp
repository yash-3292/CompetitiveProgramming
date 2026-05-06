#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int k;
        cout << "? 1 1\n";
        cout << flush;
        cin >> k;
        if(k >= n){
            int row;
            cout << "? 1 " << k+1 << "\n";
            cout << flush;
            cin >> row;
            cout << "! " << row+1 << " " << k+1 << "\n";
            cout << flush;
        } else if(k >= m){
            int col;
            cout << "? " << k+1 << " " << "1\n";
            cout << flush;
            cin >> col;
            cout << "! " << k+1 << " " << col+1 << "\n";
            cout << flush;
        } else{
            int p;
            int q;
            cout << "? 1 " << k+1 << "\n";
            cout << flush;
            cin >> p;
            cout << "? " << k+1 << " " << "1\n";
            cout << flush;
            cin >> q;
            if(p < k){
                cout << "! " << p+1 << " " << k+1 << "\n";
                cout << flush;
            } else if(q < k){
                cout << "! " << k+1 << " " << q+1 << "\n";
                cout << flush;
            } else{
                cout << "! " << k+1 << " " << k+1 << "\n";
                cout << flush;
            }
        }
    }
    return 0;
}