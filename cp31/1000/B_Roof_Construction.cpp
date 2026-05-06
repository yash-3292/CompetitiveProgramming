#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        n--;
        int i = 1;
        while(n / i != 0){
            i *= 2;
        }
        i /= 2;
        for(int j=n; j>=i; j--){
            cout << j << " ";
        }
        for(int j=0; j<i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
