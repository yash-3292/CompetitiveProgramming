#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        deque<int> dq;
        for(int i=0; i<n; i++) cin >> arr[i];
        dq.push_back(arr[0]);
        for(int i=1; i<n; i++){
            int f = dq.front();
            int b = dq.back();
            if(i&1){
                if(f > b) dq.push_front(arr[i]);
                else dq.push_back(arr[i]);
            } else{
                if(f > b) dq.push_back(arr[i]);
                else dq.push_front(arr[i]);
            }
        }
        int ans = min(dq.front(), dq.back());
        cout << ans << endl;
    }
    return 0;
}