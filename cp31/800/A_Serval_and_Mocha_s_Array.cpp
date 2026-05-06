#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a == 0){
        return b;
    } 
    return gcd(b%a, a);
}

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int val = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                val = min(val, gcd(arr[i], arr[j]));
            }
        }
        if(val <= 2){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}