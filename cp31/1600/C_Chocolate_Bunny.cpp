#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> ans(n+1, -1);
    stack<int> st;
    for(int i=1; i<=n; i++) st.push(i);
    while(st.size() > 1){
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        int val1, val2;
        cout << "? " << i << " " << j << "\n";
        cout << flush;
        cin >> val1;
        cout << "? " << j << " " << i << "\n";
        cout << flush;
        cin >> val2;
        if(val1 > val2){
            ans[i] = val1;
            st.push(j);
        } else{
            ans[j] = val2;
            st.push(i);
        }
    }
    int ind = st.top();
    st.pop();
    ans[ind] = n;
    cout << "!";
    for(int i=1; i<=n; i++) cout << " " << ans[i];
    cout << "\n";
    cout << flush;
    return 0;
}