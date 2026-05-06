#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int cur, vector<int>& l, vector<int>& r){
    if(cur == -1) return 0;
    return 1 + max(f(l[cur], l, r), f(r[cur], l, r));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<int> l(n, -1), r(n, -1);
        stack<int> st;
        for(int i=0; i<n; i++){
            int leftdom = -1;
            while(!st.empty() && arr[st.top()] <= arr[i]){
                leftdom = st.top();
                st.pop();
            }
            l[i] = leftdom;
            if(!st.empty()){
                r[st.top()] = i;
            }
            st.push(i);
        }
        int root;
        while(!st.empty()){
            root = st.top();
            st.pop();
        }
        int num = f(root, l, r);
        int ans = n - num;
        cout << ans << endl;
    }
    return 0;
}