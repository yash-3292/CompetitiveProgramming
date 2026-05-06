#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        int allZero = 1;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] == 1) allZero = 0;
        }    
        if(allZero){
            cout << "YES" << endl;
            continue;
        }
        int i = 0;
        while(i != n){
            if(arr[i] == 1) break;
            i++;
        }
        int j = n-1;
        while(j != -1){
            if(arr[j] == 1) break;
            j--;
        }
        int val = j - i + 1;
        if(val <= x){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}