#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        unordered_map<int, int> aMap;
        unordered_map<int, int> bMap;
        for(int i=0; i<n; i++){
            cin >> a[i];
            aMap[a[i]] = 1;
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
            bMap[b[i]] = 1;
        }
        int aMex = -1;
        int bMex = -1;
        for(int i=0; i<=n; i++){
            if(aMap[i] == 0){
                aMex = i;
                break;
            }
        }
        for(int i=0; i<=n; i++){
            if(bMap[i] == 0){
                bMex = i;
                break;
            }
        }
        int x = -1;
        int y = -1;
        set<int> st;
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            if(a[i] != b[i]){
                st.insert(a[i]);
                st.insert(b[i]);
            } else{
                mpp[a[i]] = 1;
            }
        }
        for(auto val : st){
            if(val != aMex && val != bMex){
                if(mpp[val] == 0){
                    if(x == -1){
                        x = val;
                    } else{
                        y = val;
                        break;
                    }
                }
            }
        }
        vector<int> temp;
        temp.push_back(aMex);
        temp.push_back(bMex);
        if(x != -1) temp.push_back(x);
        if(y != -1) temp.push_back(y);
        sort(temp.begin(), temp.end());
        int ans = max(temp[0], temp[1]);
        cout << ans << endl;
    }
    return 0;
}