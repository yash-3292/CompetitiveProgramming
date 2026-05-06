#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    if(n % 4 == 0){
        cout << "YES" << endl;
        int i=1;
        int j = n;
        cout << n/2 << endl;
        while(i <= j){
            cout << i << " " << j << " ";
            i += 2;
            j -= 2;
        }
        cout << endl;
        cout << n/2 << endl;
        i=2;
        j = n-1;
        while(i <= j){
            cout << i << " " << j << " ";
            i += 2;
            j -= 2;
        }
        cout << endl;
    } else if((n+1) % 4 == 0){
        cout << "YES" << endl;
        cout << (n+1)/2 << endl;
        cout << "1 2 ";
        int i=4;
        int j = n;
        while(i <= j){
            cout << i << " " << j << " ";
            i += 2;
            j -= 2;
        }
        cout << endl;
        cout << ((n+1)/2)-1 << endl;
        cout << "3 ";
        i=5;
        j = n-1;
        while(i <= j){
            cout << i << " " << j << " ";
            i += 2;
            j -= 2;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}