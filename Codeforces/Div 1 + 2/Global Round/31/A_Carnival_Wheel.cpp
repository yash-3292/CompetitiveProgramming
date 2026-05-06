#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        b = (b%n);
        int maxi = a;
        int temp = (a + b) % n;
        while(temp != a){
            maxi = max(maxi, temp);
            temp = (temp+b) % n;
        }
        cout << maxi << endl;
    }
    return 0;
}