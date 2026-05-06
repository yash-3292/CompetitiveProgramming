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
        int diff = 0;
        vector<int> arr(n);
        for(int i=0; i<n ;i++){
            if(s[i] == 'a'){
                diff++;
                arr[i] = 1;
            } 
            else{
                diff--;
                arr[i] = -1;
            }
        }
        if(diff == 0){
            cout << 0 << endl;
            continue;
        }
        int sum = 0;
        map<int,int> mpp;
        mpp[0] = -1;
        int mini = -1;
        for(int i=0; i<n; i++){
            sum += arr[i];
            mpp[sum] = i;
            int val = sum - diff;
            if(mpp.find(val) != mpp.end()){
                int len = i - mpp[val];
                if(mini == -1) mini = len;
                else mini = min(mini, len);
            }
        }
        if(mini == n){
            cout << -1 << endl;
        } else{
            cout << mini << endl;
        }
    }
    return 0;
}