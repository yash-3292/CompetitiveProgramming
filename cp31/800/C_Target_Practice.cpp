#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        vector<vector<char>> arr(10, vector<char>(10));
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cin >> arr[i][j];
            }
        }
        int sum = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(arr[i][j] == 'X'){
                    int temp1 = min(i, 9-i);
                    int temp2 = min(j, 9-j);
                    int temp = min(temp1, temp2);
                    sum += temp + 1;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}