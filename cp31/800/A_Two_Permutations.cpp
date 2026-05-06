#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n, a, b;
        cin >> n >> a >> b;
        if(n == a && n == b){
            cout << "Yes" << endl;
            continue;
        }
        if(n - a - b >= 2){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}