#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        string s;
        cin >> s;
        int notspecial = 0;
        int special = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '0') notspecial += arr[i];
            else special += arr[i];
        }
        if(notspecial >= c && special > c){
            notspecial += special - c;
        }
        cout << notspecial << endl;
    }
    return 0;
}