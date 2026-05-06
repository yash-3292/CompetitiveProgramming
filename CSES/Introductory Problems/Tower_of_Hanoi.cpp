#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int a, int b, int c){
    if(n == 0) return ;
    hanoi(n-1, a, c, b);
    cout << a << " " << b << endl;
    hanoi(n-1, c, b, a);
}

int main()
{
    int n;
    cin >> n;
    int total = pow(2,n) - 1;
    cout << total << endl;
    hanoi(n, 1, 3, 2);
    return 0;
}