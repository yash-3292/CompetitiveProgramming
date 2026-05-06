#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int computeXor(int n){
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n + 1;
    else return 0; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int Xor = computeXor(a-1);
        int temp = Xor ^ b;
        int ans;
        if(temp == 0) ans = a;
        else if(temp == a) ans = a + 2;
        else ans = a + 1;
        cout << ans << endl;
    }
    return 0;
}
