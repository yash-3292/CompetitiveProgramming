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
        vector<int> permut;
        for(int i=0; i<n; i++) cin >> arr[i];
        int flag = 1;
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]) cnt++;
            else{
                if(cnt < 2){
                    flag = 0;
                    break;
                } else{
                    int prev = permut.size();
                    permut.push_back(cnt+prev);
                    for(int j=1; j<cnt; j++){
                        permut.push_back(j+prev);
                    }
                }
                cnt = 1;
            }
        }
        if(cnt < 2){
            flag = 0;
        } else{
            int prev = permut.size();
            permut.push_back(cnt+prev);
            for(int j=1; j<cnt; j++){
                permut.push_back(j+prev);
            }
        }
        if(flag){
            for(int i=0; i<permut.size(); i++){
                cout << permut[i] << " ";
            }
            cout << endl;
        } else{
            cout << -1 << endl;
        }
    }
    return 0;
}
