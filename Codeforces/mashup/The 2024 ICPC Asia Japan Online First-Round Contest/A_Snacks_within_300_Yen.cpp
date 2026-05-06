#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        int sum = 0;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            if(x+sum <= 300){
                sum += x;
            } 
        }
        cout << sum << endl;
    }
    return 0;
}