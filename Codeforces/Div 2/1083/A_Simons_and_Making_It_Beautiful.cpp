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
        int j;
        for(int i=0; i<n; i++){
            if(arr[i] == n){
                j = i;
                break;
            }
        }
        swap(arr[0], arr[j]);
        for(auto it : arr) cout << it << " ";
        cout << endl;
    }
    return 0;
}