#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m3 = 0;
        int m2 = 0;
        while(n % (int)pow(2,m2) == 0){
            m2++;
        }
        while(n % (int)pow(3,m3) == 0){
            m3++;
        }
        m2--;
        m3--;
        if(m2 > m3 || (int)pow(2,m2)*(int)pow(3,m3) != n){
            cout << -1 << endl;
            continue;
        }
        cout << 2*m3 - m2 << endl; 
    }
    return 0;
}
