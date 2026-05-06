#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        if(n%2 == 0 && k%2 == 0){
            cnt += n/k;
            n = n%k;
            if(n != 0) cnt++;
        } else if(n%2 == 0 && k%2 != 0){
            cnt += n/(k-1);
            n = n%(k-1);
            if(n != 0) cnt++;
        } else if(n%2 != 0 && k%2 != 0){
            cnt++;
            n = n - k;
            if(n >= k-1){
                cnt += n/(k-1);
                n = n%(k-1);
            }
            if(n != 0) cnt++;
        } else{
            cnt++;
            n = n - (k-1);
            if(n >= k){
                cnt += n/k;
                n = n%k;
            }
            if(n != 0) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}