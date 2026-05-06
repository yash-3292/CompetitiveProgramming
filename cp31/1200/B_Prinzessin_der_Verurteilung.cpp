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
        map<string, int> mpp;
        for(int i=0; i<n; i++){
            for(int j=1; j<=n-i; j++)
                mpp[s.substr(i, j)]++;
        }
        string st;
        string ans;
        int flag = 0;
        for(char i='a'; i<='z'; i++){
            if(mpp[st+i] == 0){
                flag = 1;
                ans = st+i;
                break;
            }
        }
        if(flag){
            cout << ans << endl;
            continue;
        }
        for(char i='a'; i<='z'; i++){
            for(int j='a'; j<='z'; j++){
                string str = st + i;
                str += j;
                if(mpp[str] == 0){
                    flag = 1;
                    ans = str;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag){
            cout << ans << endl;
            continue;
        }
        for(char i='a'; i<='z'; i++){
            for(int j='a'; j<='z'; j++){
                for(int k='a'; k<='z'; k++){
                    string str = st + i;
                    str += j;
                    str += k;
                    if(mpp[str] == 0){
                        flag = 1;
                        ans = str;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag){
            cout << ans << endl;
            continue;
        }
        for(char i='a'; i<='z'; i++){
            for(int j='a'; j<='z'; j++){
                for(int k='a'; k<='z'; k++){
                    for(int l='a'; l<='z'; l++){
                        string str = st + i;
                        str += j;
                        str += k;
                        str += l;
                        if(mpp[str] == 0){
                            flag = 1;
                            ans = str;
                            break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        cout << ans << endl;
    }
    return 0;
}