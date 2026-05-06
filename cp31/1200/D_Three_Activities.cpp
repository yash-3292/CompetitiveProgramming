#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int maximum(vector<int> &a, vector<int> &b, vector<int> &c){
    int n = a.size();
    int sum = 0;
    int maxi = 0;
    int i1;
    for(int i=0; i<n; i++){
        if(a[i] > maxi){
            maxi = a[i];
            i1 = i;
        }
    }
    sum += maxi;
    maxi = 0;
    int j1;
    for(int i=0; i<n; i++){
        if(i == i1) continue;
        if(b[i] > maxi){
            maxi = b[i];
            j1 = i;
        }
    }
    sum += maxi;
    maxi = 0;
    for(int i=0; i<n; i++){
        if(i == i1 || i == j1) continue;
        if(c[i] > maxi){
            maxi = c[i];
        }
    }
    sum += maxi;
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        for(int i=0; i<n; i++) cin >> c[i];
        int maxi = 0;
        maxi = max(maxi, maximum(a,b,c));
        maxi = max(maxi, maximum(a,c,b));
        maxi = max(maxi, maximum(b,a,c));
        maxi = max(maxi, maximum(b,c,a));
        maxi = max(maxi, maximum(c,a,b));
        maxi = max(maxi, maximum(c,b,a));
        cout << maxi << endl;
    }
    return 0;
}