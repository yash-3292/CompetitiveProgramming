#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];
        sort(b.begin(), b.end(), greater<int>());
        int j = 0;
        for(int i=0; i<n; i++){
            while(j < m && b[j] > a[i] && b[j] > a[n-1]){
                cout << b[j] << " ";
                j++;
            }
            cout << a[i] << " ";
        }
        while(j < m){
            cout << b[j] << " ";
            j++;
        }
        cout << endl;
    }
    return 0;
}