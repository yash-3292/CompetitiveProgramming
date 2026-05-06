#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll k, x;
        cin >> k >> x;
        ll total = ((ll)1<<(ll)(k+1));
        ll i = x;
        ll j = total-x;
        vector<int> ans;
        while(i != j){
            if(i < j){  
                ans.push_back(1);
                j -= i;
                i *= 2;
            } else{
                ans.push_back(2);
                i -= j;
                j *= 2;
            }
        }
        cout << ans.size() << endl;
        int n = ans.size();
        for(int l=n-1; l>=0; l--) cout << ans[l] << " ";
        cout << endl;
    }
    return 0;
}