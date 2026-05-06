#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string temp;
        for(auto ch : s){
            if(!temp.empty() && temp.back() == 'A' && ch == 'B'){
                temp.pop_back();
            } else{
                temp.push_back(ch);
            }
        }
        string ans;
        for(auto ch : temp){
            if(!ans.empty() && ans.back() == 'B' && ch == 'B'){
                ans.pop_back();
            } else{
                ans.push_back(ch);
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}