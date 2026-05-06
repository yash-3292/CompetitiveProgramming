#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        long long n, k;
        cin >> n >> k;
        if(n%2 == 0){
            cout << "YES" << endl;
        } else{
            if(k%2 != 0){
                cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}