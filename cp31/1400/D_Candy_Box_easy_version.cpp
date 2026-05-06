#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<int> freq(n+10, 0);
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            freq[x]++;
        }
        vector<int> arr(n+10,0);
        for(int i=0; i<n+10; i++){
            if(freq[i] > 0) arr[freq[i]]++;
        }
        int extra = 0;
        int ans = 0;
        for(int i=n+9; i>=1; i--){
            if(arr[i] == 0){
                if(extra){
                    ans += i;
                    extra--;
                }
            } else{
                ans += i;
                extra += arr[i]-1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}