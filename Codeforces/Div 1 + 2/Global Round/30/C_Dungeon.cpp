#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        multiset<int> st;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            st.insert(x);
        }
        vector<pair<int,int>> temp(m);
        vector<pair<int,int>> temp1;
        vector<pair<int,int>> temp2;
        int ans = 0;
        for(int i=0; i<m; i++) cin >> temp[i].first;
        for(int i=0; i<m; i++) cin >> temp[i].second;
        for(int i=0; i<m; i++){
            if(temp[i].second){
                temp1.push_back(temp[i]);
            } else{
                temp2.push_back(temp[i]);
            }
        }
        // cout << "hi " << endl;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        for(auto it : temp1){
            int b = it.first;
            int c = it.second;
            auto pos = st.lower_bound(b);
            if(pos == st.end()) continue;
            ans++;
            int val = *pos;
            st.erase(pos);
            // cout << val << " ";
            val = max(val, c);
            st.insert(val);
            // cout << val << endl;
        }

        for(auto it : temp2){
            int b = it.first;
            int c = it.second;
            auto pos = st.lower_bound(b);
            if(pos == st.end()) continue;
            // cout << b << " " << c << endl;
            // for(auto im : st) cout << im << " ";
            // cout << endl;
            ans++;
            int val = *pos;
            st.erase(pos);
            if(st.empty()) break;
        }
        cout << ans << endl;
    }
    return 0;
}
