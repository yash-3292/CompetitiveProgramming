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
        map<int,int> freq;
        int cnt = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(freq[arr[i]] == 0){
                cnt++;
                freq[arr[i]] = 1;
            }
        }
        if(cnt > 1){
            cout << 2 << endl;
        } else{
            cout << -1 << endl;
        }
    }
    return 0;
}