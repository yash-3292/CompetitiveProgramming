#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    for(int i=n; i>=1; i--){
        if(i == 1) cout << i << endl;
        else cout << i << ","; 
    }
    return 0;
}