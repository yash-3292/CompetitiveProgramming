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
        int x = 0;
        for(int i=0; i<n; i++){
            cout << min(arr[i], x) << " "; 
            if(arr[i] <= x) continue;
            x++;
        }
        cout << endl;
    }
    return 0;
}