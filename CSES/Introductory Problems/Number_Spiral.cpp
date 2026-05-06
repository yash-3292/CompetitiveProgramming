#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        ll i, j;
        cin >> i >> j;
        if(i >= j){
            if(i % 2 == 0){
                cout << i*i - j + 1 << endl;
            } else {
                cout << (i-1)*(i-1) + j << endl;
            }
        } else{
            if(j % 2 == 0){
                cout << (j-1)*(j-1) + i << endl;
            } else {
                cout << j*j - i + 1 << endl;
            }
        }
    }
    return 0;
}