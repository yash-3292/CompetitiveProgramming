#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int flag = 1;
        for(int i=1; i<n; i++){
            if(s[i-1] > s[i]) flag = 0;
        }
        if(flag){
            cout << "Bob" << endl;
            continue;
        }
        vector<int> ans;
        int i = 0;
        int j = n-1;
        while(i < j){
            while(i < j){
                if(s[i] == '1') break;
                i++;
            }
            while(i < j){
                if(s[j] == '0') break;
                j--;
            }
            if(i >= j) break;
            ans.push_back(i+1);
            ans.push_back(j+1);
            i++;
            j--;
        }
        sort(ans.begin(), ans.end());
        cout << "Alice" << endl;
        cout << ans.size() << endl;
        for(auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}