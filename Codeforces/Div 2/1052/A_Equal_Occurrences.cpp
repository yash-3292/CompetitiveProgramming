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
        for(int i=0; i<n; i++) cin >> arr[i];
        int cnt = 1;
        vector<int> temp;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]) cnt++;
            else{
                temp.push_back(cnt);
                cnt = 1;
            }
        }
        temp.push_back(cnt);
        n = temp.size();
        int ans = 0;
        sort(temp.begin(), temp.end(), greater<int>());
        for(int i=0; i<n; i++){
            ans = max(ans, (i+1)*temp[i]);   
        }
        cout << ans << endl;
    }
    return 0;
}