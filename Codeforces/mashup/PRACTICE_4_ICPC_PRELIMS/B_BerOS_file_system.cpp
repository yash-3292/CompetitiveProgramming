#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string ans;
    cin >> ans;
    for(auto ch : s){
        if(!ans.empty() && ch == '/' && ans.back() == '/'){
            continue;
        } 
        ans.push_back(ch);
    }
    while(!ans.empty() && ans.back() == '/') ans.pop_back();
    if(ans.empty()) ans.push_back('/');
    cout << ans << endl;
    return 0;
}