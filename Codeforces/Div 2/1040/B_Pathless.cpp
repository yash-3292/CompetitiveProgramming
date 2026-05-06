#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int sum = 0;
        int mpp[3] = {0};
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            sum += arr[i];
            mpp[arr[i]]++;
        }
        if(s < sum){
            for(int i=0; i<n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
            continue;
        }
        if(sum+1 == s){
            for(int i=0; i<mpp[0]; i++){
                cout << 0 << " ";
            }
            for(int i=0; i<mpp[2]; i++){
                cout << 2 << " ";
            }
            for(int i=0; i<mpp[1]; i++){
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}