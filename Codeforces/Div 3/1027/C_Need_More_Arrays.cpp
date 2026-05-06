#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> arr;
        int val;
        cin >> val;
        arr.push_back(val);
        for(int i=1; i<n; i++){
            int val;
            cin >> val;
            if(arr.back() != val){
                arr.push_back(val);
            }
        }
        n = arr.size();
        int flag = 0;
        int cnt = 1;
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1] + 1){
                if(flag == 0) flag = 1;
                else {
                    cnt++;
                    flag = 0;
                }
            } else{
                cnt++;
                flag = 0;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}