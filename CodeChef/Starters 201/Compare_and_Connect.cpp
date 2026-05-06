#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n == 0){
            for(int i=0; i<m-2; i++) cout << "><";
            cout << ">=>";
        } else if(m == 0){
            for(int i=0; i<n-2; i++) cout << "<<";
            cout << "<=<";
        } else{
            for(int i=0; i<n-1; i++) cout << "<<";
            cout << "<<>";
            for(int i=0; i<m-1; i++) cout << "<>";
        }
        cout << endl;
    }
    return 0;
}