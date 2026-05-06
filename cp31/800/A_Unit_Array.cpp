#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        int sum = 0;
        int minus = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(arr[i] == -1){
                minus++;
            }
        }
        int oper = 0;
        while(sum < 0){
            oper++;
            sum += 2;
            minus--;
        }
        if(minus % 2 != 0){
            oper++;
            minus--;
        }
        cout << oper << endl;
    }
    return 0;
}