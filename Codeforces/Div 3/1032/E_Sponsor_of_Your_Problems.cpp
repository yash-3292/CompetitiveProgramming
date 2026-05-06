#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        vector<int> arr1;
        vector<int> arr2;
        int temp = l;
        while(temp != 0){
            arr1.push_back(temp%10);
            temp /= 10;
        }
        temp = r;
        while(temp != 0){
            arr2.push_back(temp%10);
            temp /= 10;
        }
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        int n = arr1.size();
        int flag = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(flag){
                if(arr1[i] < 9) break;
                else if(arr2[i] > 0) break;
                ans++;
                continue;
            }
            if(arr1[i] == arr2[i]){
                ans += 2;
            } else if(arr2[i] - arr1[i] == 1){
                flag = 1;
                ans++;
            } else{
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}