#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int px,py,qx,qy;
        cin >> px >> py >> qx >> qy;
        vector<int> a(n);
        int sum = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            sum += a[i];
            maxi = max(maxi, a[i]);
        } 
        ll sqrdist = (ll)abs(px-qx) * (ll)abs(px-qx) + (ll)abs(py-qy) * (ll)abs(py-qy);
        db dist = sqrt(sqrdist);
        if(dist > (db)sum){
            cout << "No" << endl;
            continue;
        }
        if((db)maxi > (db)sum - (db)maxi + dist){
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}