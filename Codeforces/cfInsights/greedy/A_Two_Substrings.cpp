#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    while(i < n-1){
        if(s[i] == 'A' && s[i+1] == 'B'){
            i += 2;
            while(i < n-1){
                if(s[i] == 'B' && s[i+1] == 'A'){
                    cout << "YES" << endl;
                    return 0;
                }
                i++;
            }
            break;
        }
        i++;
    }
    i = 0;
    while(i < n-1){
        if(s[i] == 'B' && s[i+1] == 'A'){
            i += 2;
            while(i < n-1){
                if(s[i] == 'A' && s[i+1] == 'B'){
                    cout << "YES" << endl;
                    return 0;
                }
                i++;
            }
            break;
        }
        i++;
    }
    cout << "NO" << endl;
    return 0;
}