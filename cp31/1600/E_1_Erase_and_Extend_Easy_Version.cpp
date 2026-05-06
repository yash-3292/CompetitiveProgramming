#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int size = n;
    for(int i=1; i<n; i++){
        string temp = s.substr(i);
        if(s <= temp){
            size = i;
            break;
        }
    }
    string pattern = s.substr(0, size);
    while(pattern.size() >= 2){
        if(pattern.front() > pattern.back()) break;
        pattern.pop_back();
    }
    size = pattern.size();
    for(int i=0; i<k; i++){
        cout << pattern[i%size];
    }
    return 0;
}