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
        int ans = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() >= arr[i]) st.pop();
            if(st.empty() || st.top()+1 != arr[i]){
                ans++;
                while(!st.empty()) st.pop();
            }
            st.push(arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}