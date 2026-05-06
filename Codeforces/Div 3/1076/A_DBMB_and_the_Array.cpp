#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s, x;
        cin >> n >> s >> x;
        int sum = 0;
        for(int i=0; i<n; i++){
            int e;
            cin >> e;
            sum += e;
        }
        if(sum <= s && (s-sum)%x == 0){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}