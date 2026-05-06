#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int i = 0;
        int j = 0;
        int cnt = 0;
        while(j - i + 1 <= k){
            if(s[j] == 'W') cnt++;
            j++;
        }
        j--;
        int mini = cnt;
        while(j != n-1){
            if(s[i] == 'W') cnt--;
            i++;
            j++;
            if(s[j] == 'W') cnt++;
            mini = min(cnt, mini);
        }
        cout << mini << endl;    
    }
    return 0;
}
