#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int x, y;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            int n;
            cin >> n;
            if(n == 1){
                x = i;
                y = j;
                break;
            }
        }
    }
    int ans = abs(3-x) + abs(3-y);
    cout << ans << endl;
    return 0;
}
