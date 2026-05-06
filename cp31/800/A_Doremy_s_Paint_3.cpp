#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n ;i++){
            cin >> arr[i];
        }
        int a = arr[0];
        int b;
        int elementNo = 1;
        int aNo = 1;
        int bNo = 0;
        for(int i=1; i<n; i++){
            if(elementNo == 1){
                if(arr[i] == a) aNo++;
                else{
                    b = arr[i];
                    bNo++;
                    elementNo++;
                }
            } else if(elementNo == 2){
                if(arr[i] == a) aNo++;
                else if(arr[i] == b) bNo++;
                else{
                    elementNo++;
                }
            } else if(elementNo == 3){
                break;
            }
        }
        if(elementNo == 3){
            cout << "No" << endl;
            continue;
        }
        if(elementNo == 1){
            cout << "Yes" << endl;
            continue;
        }
        if(n % 2 == 0 && aNo == bNo){
            cout << "Yes" << endl;
            continue;
        }
        if(n%2 != 0){
            if(aNo == bNo-1 || aNo == bNo+1){
                cout << "Yes" << endl;
                continue;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}