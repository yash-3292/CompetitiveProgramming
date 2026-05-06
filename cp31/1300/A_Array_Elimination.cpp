#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> freq(30);
        for(int i=0; i<n; i++){
            cin >> arr[i];
            for(int j=0; j<30; j++){
                if(arr[i] & (1<<j)){
                    freq[j]++;
                }
            }
        }
        int ans = -1;
        for(int val : freq){
            if(val != 0){
                if(ans == -1) ans = val;
                else{
                    ans = __gcd(val, ans);
                }
            }
        }
        if(ans == -1){
            for(int i=1; i<=n; i++) cout << i << " ";
            cout << endl;
            continue;
        }
        vector<int> answer;
        for(int i=1; i*i<=ans; i++){
            if(ans % i == 0){
                answer.push_back(i);
                if(i != ans/i) answer.push_back(ans/i);
            }
        }
        sort(answer.begin(), answer.end());
        for(int val : answer) cout << val << " ";
        cout << endl;
    }
    return 0;
}