#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=i+1; j<n; j++){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    int flag = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i][j-i-1]+arr[j][k-j-1] < arr[i][k-i-1]){
                    flag = 1;
                }
            }
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}