#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int ans = 0;
        for(int i=0; i<3; i++){
            int val = 0;
            int skip = 0;
            for(int j=0; j<n; j++){
                int rating;
                cin >> rating;
                if(skip) continue;
                int temp = val | rating;
                if((temp | x) == x) val = temp;
                else{
                    skip = 1;
                    continue;
                }
            }
            ans |= val;
        }
        if(ans == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}