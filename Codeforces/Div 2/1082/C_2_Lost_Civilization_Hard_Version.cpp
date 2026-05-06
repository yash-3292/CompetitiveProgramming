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
        stack<int> st;
        vector<int> mark(n, 0);
        vector<int> extra(n,0);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(st.empty() || arr[st.top()]+1 != arr[i]){
                mark[i] = 1;
                while(!st.empty()) st.pop();
            } else{
                extra[st.top()+1] += n-i;
                extra[i] -= n-i;
            }
            st.push(i);
        }
        ll sum = 0;
        ll val = 0;
        for(int i=0; i<n; i++){
            val += mark[i];
            sum += val;
        }
        ll ans = 0;
        ans += sum;
        for(int i=1; i<n; i++){
            sum--;
            sum += extra[i];
            if(mark[i] == 1){
                sum -= n-i;
            } 
            ans += sum;
        }
        cout << ans << endl;
    }
    return 0;
}