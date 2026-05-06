#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int i = 0;
        int j = n-1;
        int flag = 1;
        while(i <= j){
            if(s[i] != s[j]){
                flag = 0;
                break;
            }
            i++;
            j--;
        }
        if(flag){
            cout << 0 << endl;
            continue;
        }
        char x = s[i];
        char y = s[j];
        i = 0;
        j = n-1;
        int flag1 = 1;
        int cnt1 = 0;
        while(i <= j){
            if(s[i] != s[j]){
                if(s[i] == x){
                    cnt1++;
                    i++;
                } else if(s[j] == x){
                    cnt1++;
                    j--;
                } else{
                    flag1 = 0;
                    break;
                }
            } else{
                i++;
                j--;
            }
        } 
        i = 0;
        j = n-1;
        int flag2 = 1;
        int cnt2 = 0;
        while(i <= j){
            if(s[i] != s[j]){
                if(s[i] == y){
                    cnt2++;
                    i++;
                } else if(s[j] == y){
                    cnt2++;
                    j--;
                } else{
                    flag2 = 0;
                    break;
                }
            } else{
                i++;
                j--;
            }
        } 
        if(!flag1 && !flag2){
            cout << -1 << endl;
            continue;
        }
        if(!flag1){
            cout << cnt2 << endl;
            continue;
        } 
        if(!flag2){
            cout << cnt1 << endl;
            continue;
        }
        int cnt = min(cnt1, cnt2);
        cout << cnt << endl;
    }
    return 0;
}