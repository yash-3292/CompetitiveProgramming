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
        for(int i=0; i<n; i++){
            if(n-i == arr[i]) continue;
            int j = i+1;
            while(arr[j] != n-i) j++;
            reverse(arr.begin()+i, arr.begin()+j+1);
            break;
        }
        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}