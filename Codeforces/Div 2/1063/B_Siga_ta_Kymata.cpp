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
        string s;
        cin >> s;
        int flag = 1;
        for(int i=0; i<n; i++){
            if(i == 0 && s[i] == '1'){
                flag = 0;break;
            } else if(i == n-1 && s[i] == '1'){
                flag = 0;break;
            } else if(s[i] == '1' && arr[i] == 1){
                flag = 0;break;
            } else if(s[i] == '1' && arr[i] == n){
                flag = 0;break;
            }
        }
        if(!flag){
            cout << -1 << endl;
            continue;
        }
        int mini = 0;
        int maxi = 0;
        for(int i=1; i<n; i++){
            if(arr[i] < arr[mini]){
                mini = i;
            }
            if(arr[i] > arr[maxi]){
                maxi = i;
            }
        }
        mini++; maxi++;
        cout << 5 << endl;
        cout << 1 << " " << mini << endl;
        cout << 1 << " " << maxi << endl;
        cout << mini << " " << n << endl;
        cout << maxi << " " << n << endl;
        cout << min(mini, maxi) <<  " " << max(mini, maxi) << endl;
    }
    return 0;
}