#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> nextPos(26, n);
    vector<int> thres(n);
    for(int i=n-1; i>=0; i--){
        int val = s[i] - 'a';
        int mini = n;
        int secMini = n;
        for(int j=0; j<26; j++){
            if(j == val) continue;
            int x = nextPos[j];
            if(x <= mini){
                secMini = mini;
                mini = x;
            } else if(x <= secMini){
                secMini = x;
            }
        }
        thres[i] = secMini;
        nextPos[val] = i;
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        if(l == r || s[l] != s[r] || thres[l] < r){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
    }
    return 0;
}