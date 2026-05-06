#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int x = i;
            for(int j=0; j<n; j++){
                int ans = x%n;
                cout << ans << " ";
                x++;
            }
            cout << endl;
        }
    }
    return 0;
}