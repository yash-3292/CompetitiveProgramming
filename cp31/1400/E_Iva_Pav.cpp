#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int giveAnd(vector<int>& freq1, vector<int>& freq2){
    int ans = 0;
    for(int i=0; i<31; i++){
        if(freq1[i]==freq2[i]){
            ans |= (1<<i);
        }
    }
    return ans;
}

int giveAnd(vector<int>& freq){
    int ans = 0;
    for(int i=0; i<31; i++){
        if(freq[i] == 0){
            ans |= (1<<i);
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];
        vector<vector<int>> preZero(n, vector<int>(31));
        for(int i=0; i<n; i++){
            for(int j=0; j<31; j++){
                if(i == 0) preZero[i][j] = 0;
                else preZero[i][j] = preZero[i-1][j];
                if((arr[i]&(1<<j)) == 0){
                    preZero[i][j]++;
                }
            }
        }
        int q;
        cin >> q;
        while(q--){
            int l, k;
            cin >> l >> k;
            l--;
            if(arr[l] < k){
                cout << -1 << " ";
                continue;
            } 
            int i = l;
            int j = n-1;
            int r = -1;
            while(i <= j){
                int mid = i+(j-i)/2;
                int ans;
                if(l == 0) ans = giveAnd(preZero[mid]);
                else ans = giveAnd(preZero[l-1], preZero[mid]);
                if(ans >= k){
                    r = mid;
                    i = mid+1;
                } else{
                    j = mid-1;
                }
            }
            cout << r+1 << " ";
        }
        cout << endl;
    }
    return 0;
}