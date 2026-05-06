#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char,int> charFreq;
        for(int i=0; i<s.length(); i++){
            charFreq[s[i]]++;
        }
        int work = (n-k)/2;
        for(char i='a'; i<='z'; i++){
            work -= charFreq[i]/2;
            if(work <= 0){
                break;
            }
        }
        if(work <= 0){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}