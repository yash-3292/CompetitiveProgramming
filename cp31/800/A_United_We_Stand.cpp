#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int isSame = 1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(a[i] != a[0]){
                isSame = 0;
            }
            maxi = max(maxi, a[i]);
        }
        if(isSame){
            cout << -1 << endl;
            continue;
        }
        vector<int> b;
        vector<int> c;
        for(int i=0; i<n; i++){
            if(a[i] == maxi){
                c.push_back(a[i]);
            } else {
                b.push_back(a[i]);
            }
        }
        cout << b.size() << " " << c.size() << endl;
        for(int i=0; i<b.size(); i++){
            cout << b[i] << " ";
        }
        cout << endl;
        for(int i=0; i<c.size(); i++){
            cout << c[i] << " ";
        }
        cout << endl;
        
    }
    return 0;
}