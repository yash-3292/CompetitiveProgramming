#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MaxR = 1e6 + 5;
vector<int> spf(MaxR);
void pre(){
    for(int i=0; i<MaxR; i++){
        spf[i] = i;
    }
    for(int i=2; i<MaxR; i++){
        if(spf[i] == i){
            for(int j=2*i; j<=MaxR; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> primeDivisor(int n){
    vector<int> arr;
    int temp = n;
    while(temp != 1){
        int spfno = spf[temp];
        arr.push_back(spfno);
        temp /= spfno;
    }
    return arr;
}

int main(){
    pre();
    int t;
    cin >> t;
    while(t--){
        int x, y, k;
        cin >> x >> y >> k;
        int GCD = __gcd(x, y);
        x /= GCD;
        y /= GCD;
        vector<int> arr1 = primeDivisor(x);
        vector<int> arr2 = primeDivisor(y);
        int flag = 1;
        for(int val : arr1){
            if(val > k){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout << -1 << endl;
            continue;
        }
        for(int val : arr2){
            if(val > k){
                flag = 0;
                break;
            }
        }
        if(flag == 0){
            cout << -1 << endl;
            continue;
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=k; i>=2; i--){
            while(x % k == 0){
                x /= k;
                cnt1++;
            }
            if(x == 1) break;
        }
        for(int i=k; i>=2; i--){
            while(y % k == 0){
                y /= k;
                cnt2++;
            }
            if(y == 1) break;
        }
        int ans = cnt1 + cnt2;
        cout << ans << endl;
    }
    return 0;
}