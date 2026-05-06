#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int g=0; g<t; g++){
        int n;
        cin >> n;
        int temp = n;
        int digit = 0;
        while(temp >= 10){
            temp /= 10;
            digit++;
        }
        cout << temp + 9*digit << endl;
        
    }
    return 0;
}