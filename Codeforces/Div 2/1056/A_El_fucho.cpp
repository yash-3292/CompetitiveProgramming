#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int temp = n;
        int cnt = 0;
        while(temp > 1){
            cnt += temp/2;
            if(temp&1){
                temp = temp/2+1;
            } else{
                temp = temp/2;
            }
        }
        temp = n-1;
        while(temp > 1){
            cnt += temp/2;
            if(temp&1){
                temp = temp/2+1;
            } else{
                temp = temp/2;
            }
        }
        cnt++;
        cout << cnt << endl;
    }
    return 0;
}