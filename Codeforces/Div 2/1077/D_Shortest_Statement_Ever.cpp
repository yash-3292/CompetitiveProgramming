#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void f(int x, int y, int p, int q, int& ans, pair<int, int>& ansp){
    int val = abs(x-p) + abs(y-q);
    if(val < ans){
        ans = val;
        ansp = {p, q};
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int com = (x&y);
        if(com == 0){
            cout << x << " " << y << endl;
            continue;
        }
        int ans = INT_MAX;
        pair<int, int> ansp = {-1, -1};
        int msb = 0;
        while((1<<msb) <= com) msb++;
        msb--;
        int val1 = 0;
        for(int i=msb; i>=0; i--){
            if(!(x&(1<<i) || (y&(1<<i)))) val1 += (1<<i);
        }
        f(x, y, (x-(x&y)) + val1, y, ans, ansp);
        f(x, y, x, (y-(x&y)) + val1, ans, ansp);
        int bit = msb;
        while(x&(1<<bit) || (y&(1<<bit))) bit++;
        int a = (x - (x&y)) + (1<<bit);
        for(int i=bit-1; i>=0; i--){
            if(a&(1<<i)) a = (a^(1<<i));
        }
        int b = (y - (x&y)) + (1<<bit);
        for(int i=bit-1; i>=0; i--){
            if(b&(1<<i)) b = (b^(1<<i));
        }
        f(x, y, a, y, ans, ansp);
        f(x, y, x, b, ans, ansp);
        cout << ansp.first << " " << ansp.second << endl;
    }
    return 0;
}