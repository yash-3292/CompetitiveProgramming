#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> freq(200, 0);
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }
        int ans = -1;
        for(int i=0; i<200; i++){
            if(freq[i] == 0){
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}