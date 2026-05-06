#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        vector<int> moves(n, 0);
        for(int i=0; i<n; i++){
            if(s[i] == 'C'){
                cnt = 0;
                continue;
            }
            else if(s[i] == 'B'){
                moves[i] = cnt;
            }
            else{
                cnt++;
            }
        }
        ll sum = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'A'){
                cnt = 0;
                continue;
            }
            else if(s[i] == 'B'){
                moves[i] = max(moves[i], cnt);
                sum += (ll)moves[i];
            }
            else cnt++;
        }
        cout << sum << endl;
    }
    return 0;
}