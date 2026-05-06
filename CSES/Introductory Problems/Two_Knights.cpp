#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int count = 0;
    int num = 0;
    for(int i=1; i<=n; i++){
        ll l = i*i;
        cout << (l*(l-1))/2 - 8*num << endl;;
        num += count;
        count++;
    }
    return 0;
}