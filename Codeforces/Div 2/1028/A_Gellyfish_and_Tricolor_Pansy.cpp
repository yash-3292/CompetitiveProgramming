#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mini1 = min(a, c);
        int mini2 = min(b, d);
        if(mini1 >= mini2){
            cout << "Gellyfish" << endl;
        } else{
            cout << "Flower" << endl;
        }
    }
    return 0;
}