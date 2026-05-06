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
        for(int i=0; i<n; i++) cin >> arr[i];
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        for(int i=0; i<n; i++) cout << 2 << " ";
        cout << endl;
    }
    return 0;
}