#include<bits/stdc++.h>
using namespace std;

typedef double db;

void printing(double val){
    cout.setf(ios::fixed);
    cout << setprecision(12) << val << "\n";
}

db rec(int s, int w, int b){
    if(w == 0) return 0;
    if(b == 0){
        if(s == 0) return 1;
        else return 0;
    }
    db ans = 0;
    if(s == 0){
        ans += (db)(w)/(db)(w+b);
        db val = rec(1, b-1, w);
        val *= (db)(b)/(db)(w+b);
        ans += val;
    } else{
        db val = (db)(b)/(db)(w+b);
        b--;
        if(b != 0){
            db val1 = rec(0, b-1, w);
            val1 *= (db)(b)/(db)(w+b);
            val1 *= val;
            ans += val1;
        } 
        if(b != 0){
            db val1 = rec(0, b, w-1);
            val1 *= (db)(w)/(db)(w+b);
            val1 *= val;
            ans += val1;
        } 
    }
    return ans;
}

int main(){
    int w,b;
    cin >> w >> b;
    db ans = rec(0, w, b);
    printing(ans);
    return 0;
}
