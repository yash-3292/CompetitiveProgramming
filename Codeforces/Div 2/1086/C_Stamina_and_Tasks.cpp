#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> c(n), p(n);
        for(int i=0; i<n; i++) cin >> c[i] >> p[i];
        double x = 0;
        for(int i=n-1; i>=0; i--){
            if((double)c[i] > ((double)p[i]*x)/(double)100){
                x = (double)c[i] + (double)(100-p[i])/(double)100 * x;
            }
        }
        cout << setprecision(16) << x << endl;
    }
    return 0;
}