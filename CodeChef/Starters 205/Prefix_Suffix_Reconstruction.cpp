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
        int val;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            val = arr[i];
        }
        if(val == 1){
            cout << -1 << endl;
            continue;
        }   
        vector<int> temp;
        for(int i=0; i<n; i++){
            int sz = (i==0 ? arr[i]-n : arr[i]);
            for(int j=0; j<sz; j++){
                temp.push_back(i+1);
            }
        }
        temp[n-1] = 1;
        for(int i=0; i<n; i++){
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}