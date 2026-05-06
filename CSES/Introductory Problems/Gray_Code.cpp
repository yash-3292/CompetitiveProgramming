#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<pow(2,n); i++){
        string s = bitset<32>(i^(i/2)).to_string();
        s = s.substr(32-n,31);
        cout << s << endl;
    }
    return 0;
}
