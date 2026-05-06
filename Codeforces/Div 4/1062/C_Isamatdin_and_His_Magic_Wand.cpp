#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int odd = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]&1) odd++;
        }
        if(odd == 0 || odd == n){
            for(auto it : arr) cout << it << " ";
            cout << endl;
            continue;
        } 
        sort(arr.begin(), arr.end());
        for(auto it : arr) cout << it << " ";
        cout << endl;
    }
    return 0;
}