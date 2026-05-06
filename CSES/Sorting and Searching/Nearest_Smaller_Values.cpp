#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        int ans = st.empty() ? 0 : st.top()+1;
        cout << ans << " ";
        st.push(i);
    }
    return 0;
}