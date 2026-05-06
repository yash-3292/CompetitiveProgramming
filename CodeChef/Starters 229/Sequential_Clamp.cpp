#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = INT_MAX;
        while(n--){
            int a, b;
            cin >> a >> b;
            if(x > b) x = b;
            if(x < a) x = a;
        }
        cout << x << endl;
    }
    return 0;
}