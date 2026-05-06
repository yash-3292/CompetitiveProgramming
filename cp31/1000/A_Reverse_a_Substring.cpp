#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int val = 0;
    for(int i=1; i<n; i++){
        if(s[i] < s[i-1]){
            val = i;
            break;
        }
    }
    if(val){
        cout << "YES" << endl;
        cout << val << " " << val+1 << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}