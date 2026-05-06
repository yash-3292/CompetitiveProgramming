#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        vector<int> mpp(n+1);
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            mpp[arr[i]] = i;
        } 
        for(int i=1; i<=n; i++){
            if(arr[i] <= 2) continue;
            while(true){
                int j = mpp[arr[i]-1];
                int k = mpp[arr[i]-2];
                if(i > j || i > k) break;
                arr[i] -= 2;
                arr[j] += 1;
                arr[k] += 1;
                mpp[arr[i]] = i;
                mpp[arr[j]] = j;
                mpp[arr[k]] = k;
            }
        }
        for(int i=1; i<=n; i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}