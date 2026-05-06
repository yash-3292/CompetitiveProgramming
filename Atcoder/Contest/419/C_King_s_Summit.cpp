#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int minR = INT_MAX;
    int maxR = 0;
    int minC = INT_MAX;
    int maxC = 0;
    while(n--){
        int row, col;
        cin >> row >> col;
        minR = min(minR, row);
        maxR = max(maxR, row);
        minC = min(minC, col);
        maxC = max(maxC, col);
    }
    int ans = max((maxR-minR+1)/2, (maxC-minC+1)/2);
    cout << ans << endl;
    return 0;
}