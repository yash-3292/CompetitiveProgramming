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
        if(s[0] == '0' && s[1] == '1'){
            cout << "NO" << endl;
            continue;
        } 
        if(s[n-2] == '1' && s[n-1] == '0'){
            cout << "NO" << endl;
            continue;
        } 
        int flag = 1;
        for(int i=1; i<n-1; i++){
            if(s[i] == '0' && s[i-1] == '1' && s[i+1] == '1'){
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector<int> temp(n);
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                if(i == n-1) temp[i] = i;
                else if(s[i+1] == '0'){
                    temp[i] = temp[i+1];
                } else{
                    temp[i] = i;
                }
            }
        }
        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                for(int j=temp[i]; j>=i; j--){
                    cout << j+1 << " ";
                }
                i = temp[i]+1;
            } else{
                cout << i+1 << " ";
                i++;
            }
        }
        cout << endl;
    }
    return 0;
}