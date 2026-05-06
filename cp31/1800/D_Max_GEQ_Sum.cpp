#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid(vector<int> arr){
    arr.insert(arr.begin(), 0);
    int n = arr.size();
    vector<ll> pre(n);
    pre[0] = (ll)arr[0];
    for(int i=1; i<n; i++) pre[i] = pre[i-1] + (ll)arr[i];
    vector<int> pge(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        pge[i] = (st.empty()) ? 0 : st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    vector<int> pse(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && pre[st.top()] >= pre[i]){
            st.pop();
        }
        pse[i] = (st.empty()) ? -1 : st.top();
        st.push(i);
    }
    for(int i=1; i<n; i++){
        if(pge[i] <= pse[i-1]) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        int flag = isValid(arr);
        reverse(arr.begin(), arr.end());
        flag = (flag & isValid(arr));
        if(flag){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}