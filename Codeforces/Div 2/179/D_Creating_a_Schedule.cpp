#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        for(int i=0; i<m; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            int j = i/2;
            for(int k=0; k<6; k++){
                if(i%2 == k%2) cout << arr[j] << " ";
                else cout << arr[m-1-j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}