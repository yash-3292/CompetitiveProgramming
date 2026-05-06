#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int f1 = 0;
        int f2 = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x == 1) f1 = 1;
        } 
        for(int i=0; i<m; i++){
            int x;
            cin >> x;
            if(x == 1) f2 = 1;
        } 
        if(f1 == 0 || f2 == 0){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl; 
        }
    }
    return 0;
}