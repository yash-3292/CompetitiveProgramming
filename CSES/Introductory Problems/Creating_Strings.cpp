#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int i, int n, string s, vector<int>& arr, set<string>& st){
    if(i == n){
        string t(n, 'a');
        for(int j=0; j<n; j++){
            t[j] = s[arr[j]];
        }
        st.insert(t);
        return;
    }

    for(int j=0; j<n; j++){
        if(arr[j] == -1){
            arr[j] = i;
            f(i+1, n, s, arr, st);
            arr[j] = -1;
        }
    }
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> arr(n, -1);
    set<string> st;
    f(0, n, s, arr, st);
    cout << st.size() << endl;
    for(auto it : st) cout << it << endl;
    return 0;
}