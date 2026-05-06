#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n; 
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int flag = 1;
        map<int, int> freq;
        for(int i=0; i<n; i++){
            int place = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if(place == 0){
                flag = 0;
                break;
            }
            place--;
            freq[place]++;
        }
        if(flag == 0){
            cout << 0 << endl;
            continue;
        }
        int total = 0;
        ll comb = 1;
        for(int i=n-1; i>=0; i--){
            total += freq[i];
            if(total == 0){
                flag = 0;
                break;
            }
            comb = ((ll)total * comb) % mod;
            total--;
        }
        if(flag == 0){
            cout << 0 << endl;
            continue;
        }
        cout << comb << endl;
    }
    return 0;
}
