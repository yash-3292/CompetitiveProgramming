#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> freq;
        int flag = 0;
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            if(freq[num] > 0) flag = 1;
            freq[num]++;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
