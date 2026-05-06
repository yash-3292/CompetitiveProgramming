#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int cnt = 0;
    cnt += arr[0]%2;
    cnt += arr[1]%2;
    cnt += arr[2]%2;
    int flag;
    if(cnt >= 2) flag = 0;
    else flag = 1;
    for(int i=0; i<n; i++){
        if(flag == arr[i]%2){
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}