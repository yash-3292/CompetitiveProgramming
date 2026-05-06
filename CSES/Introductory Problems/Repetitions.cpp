#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    char c = 'C';
    int count = 0;
    int maxcount = 1;
    for(int i=0; i<s.size(); i++){
        if(c != s[i]){
            c = s[i];
            count = 1;
        } else {
            count++;
        }
        maxcount = max(maxcount, count);
    }
    cout << maxcount << endl;
    return 0;
}