#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> st;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            st.insert(x);
        } 
        int ans = 0;
        int cnt = 0;
        vector<int> arr;
        for(auto it : st){
            arr.push_back(it);
        }
        n = arr.size();
        for(int i=n-1; i>=0; i--){
            if(i == n-1 || arr[i]+1 != arr[i+1]){
                cnt = 1;
            } else{
                cnt++;
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}