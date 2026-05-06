#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(k&1){
            for(int i=0; i<k; i++) cout << n << " ";
            cout << endl;
            continue;
        }
        for(int i=0; i<k-2; i++) cout << n << " ";
        int x = -1;
        int y = -1;
        for(int i=0; i<31; i++){
            if((n & (1<<i))){
                y = x;
                x = i;
            }
        }
        if(y == -1){
            cout << n << " " << 0 << endl;
            continue;
        }
        int val1 = (1<<x) + (1<<y)-1;
        int val2 = (n ^ val1);
        cout << val1 << " " << val2 << endl;
    }
    return 0;
}