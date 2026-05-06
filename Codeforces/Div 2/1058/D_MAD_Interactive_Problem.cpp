#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> unknown;
        vector<int> known;
        vector<int> ans(2*n);
        unknown.push_back(1);
        for(int i=2; i<=2*n; i++){
            unknown.push_back(i);
            
            cout << "?";
            cout << " " << unknown.size();
            for(auto it : unknown) cout << " " << it;
            cout << "\n";
            cout << flush;

            int val;
            cin >> val;
            if(val != 0){
                unknown.pop_back();
                ans[i-1] = val;
                known.push_back(i);
            } 
        }
        for(auto i : unknown){
            cout << "?";
            cout << " " << n+1;
            for(auto it : known) cout << " " << it;
            cout << " " << i;
            cout << "\n";
            cout << flush;

            int val;
            cin >> val;
            ans[i-1] = val;
        }
        
        cout << "!";
        for(auto it : ans) cout << " " << it;
        cout << "\n";
        cout << flush;
    }
    return 0;
}