#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        vector<int> zeros(n,0);
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            int temp = arr[i];
            int digits = 0;
            int flag = 1;
            while(temp != 0){
                digits++;
                if(temp%10 == 0){
                    if(flag) zeros[i]++;
                } else{
                    flag = 0;
                }
                temp /= 10;
            }
            sum += digits;
        }
        sort(zeros.begin(), zeros.end());
        for(int i=n-1; i>=0; i-=2){
            sum -= zeros[i];
        }
        if(sum > m) cout << "Sasha" << endl;
        else cout << "Anna" << endl;
    }
}