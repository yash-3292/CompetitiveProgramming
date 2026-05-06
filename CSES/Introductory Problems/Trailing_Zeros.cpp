#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int i = 1;
    while(n / (int)pow(5,i) != 0){
        cnt += (int)floor((double)n / (double)pow(5,i));
        i++;
    }
    cout << cnt << endl;
    return 0;
}