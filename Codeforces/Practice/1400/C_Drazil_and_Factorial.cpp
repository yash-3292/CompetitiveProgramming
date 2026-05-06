#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr;
    for(int i=0; i<n; i++){
        if(s[i] == '2') arr.push_back(2);
        if(s[i] == '3') arr.push_back(3);
        if(s[i] == '4'){
            arr.push_back(2);
            arr.push_back(2);
            arr.push_back(3);
        } 
        if(s[i] == '5') arr.push_back(5);
        if(s[i] == '6'){
            arr.push_back(5);
            arr.push_back(3);
        } 
        if(s[i] == '7') arr.push_back(7);
        if(s[i] == '8'){
            arr.push_back(2);
            arr.push_back(2);
            arr.push_back(2);
            arr.push_back(7);
        }
        if(s[i] == '9'){
            arr.push_back(3);
            arr.push_back(3);
            arr.push_back(2);
            arr.push_back(7);
        }
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for(auto it : arr) cout << it;
    cout << endl;
    return 0;
}