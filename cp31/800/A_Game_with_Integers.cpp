#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%3==0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    return 0;
}