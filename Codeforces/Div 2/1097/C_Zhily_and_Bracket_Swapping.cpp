#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isReg(string& s){
    int n = s.size();
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a, b;
        cin >> a; 
        cin >> b;
        int net = 0;
        for(int i=0; i<n; i++){
            if(a[i] == '(') net++;
            else net--;
            if(b[i] == '(') net++;
            else net--;
        }
        if(net != 0){
            cout << "NO" << endl;
            continue;
        }
        if(!isReg(a) && !isReg(b)){
            cout << "NO" << endl;
            continue;
        }
        if(isReg(a) && isReg(b)){
            cout << "YES" << endl;
            continue;
        }
        if(!isReg(a)) swap(a,b);
        
        int extra = 0;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            if(a[i] == '(') arr[i] = 1;
            else arr[i] = -1;
            if(i != 0) arr[i] += arr[i-1];
        }
        extra = arr[n-1];
        for(int i=n-2; i>=0; i--){
            arr[i] = min(arr[i], arr[i+1]);
        }
        int val = 1;
        for(int i=0; i<n; i++){
            if(a[i] == '(' && b[i] == ')'){
                if(val <= extra){
                    if(arr[i] >= 2*val){
                        swap(a[i], b[i]);
                        val++;
                    }
                }
            }
        }

        if(isReg(a) && isReg(b)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}