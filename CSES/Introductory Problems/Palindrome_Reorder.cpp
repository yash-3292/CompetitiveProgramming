#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    map<char,int> freq;
    for(int i=0; i<n; i++){
        freq[s[i]]++;
    }
    int oddTimes = 0;
    char c;
    for(char i='A'; i<='Z'; i++){
        if(freq[i]%2 != 0){
            c = i;
            oddTimes++;
        }
    }
    if(n&1){
        if(oddTimes != 1){
            cout << "NO SOLUTION" << endl;
        } else{
            for(char i='A'; i<='Z'; i++){
                if(freq.find(i) != freq.end()){
                    for(int j=0; j<freq[i]/2; j++){
                        cout << i;
                    }
                }
            }
            cout << c;
            for(char i='Z'; i>='A'; i--){
                if(freq.find(i) != freq.end()){
                    for(int j=0; j<freq[i]/2; j++){
                        cout << i;
                    }
                }
            }
        }
    }
    else{
        if(oddTimes != 0) cout << "NO SOLUTION" << endl;
        else{
            for(char i='A'; i<='Z'; i++){
                if(freq.find(i) != freq.end()){
                    for(int j=0; j<freq[i]/2; j++){
                        cout << i;
                    }
                }
            }
            for(char i='Z'; i>='A'; i--){
                if(freq.find(i) != freq.end()){
                    for(int j=0; j<freq[i]/2; j++){
                        cout << i;
                    }
                }
            }
        }
    }
    return 0;
}
