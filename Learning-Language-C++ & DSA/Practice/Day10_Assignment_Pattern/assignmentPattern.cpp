#include <iostream>
using namespace std;
int pattern1(int n){
    /*
    5 5 5 5 5 5 5 5 5
    5 4 4 4 4 4 4 4 5
    5 4 3 3 3 3 3 4 4
    5 4 3 2 2 2 3 3 3
    5 4 3 2 1 2 2 2 2
    5 4 3 2 2 2 3 4 5
    5 4 3 3 3 3 3 4 5
    5 4 4 4 4 4 4 4 5
    5 5 5 5 5 5 5 5 5
    */

    // Pattern first row is printed 
    for (int i = 1; i <= 2*n - 1; i++){
        cout << n << " ";
    }
    cout << "\n";

    // Pattern first half i.e from 2nd row to n row printed.
    for (int i = 1; i <= n - 1; i++){
        // Pattern Section 1, sub section 1 printed.
        for (int j = n; j >= n-(i-1); j--){
            cout << j << " ";
        }
        // Pattern Section 1, sub section 2 printed.
        for (int j = 1; j < n-(i-1); j++){
            cout << n-i << " ";
        }

        // Pattern Section 2, sub section 1 printed.
        for(int j = 1; j <= n-(i+1); j++){
            cout << n-i << " ";
        }
        // Pattern Section 2, sub section 2 printed.
        for(int j = 1; j <= i; j++){
            cout << n-(i-1) << " ";
        }
        cout << "\n";
    }

    // Pattern second half i.e from n+1 row to 2*n-2 row printed.
    for (int i = 1; i <= n - 2; i++){
        // Pattern Section 1, sub section 1 printed.
        for (int j = 1; j <= n-i; j++){
            cout << n-(j-1) << " ";
        }
        // Pattern Section 1, sub section 2 printed.
        for (int j = 1; j <= i; j++){
            cout << i+1 << " ";
        }

        // Pattern Section 2, sub section 1 printed.
        for(int j = 1; j <= i; j++){
            cout << i+1 << " ";
        }
        
        // Pattern Section 2, sub section 2 printed.
        for(int j = n-(i+1); j >= 1; j--){
            cout << n-(j-1) << " ";
        }
        cout << "\n";
    }

    // Pattern last row is printed 
    for (int i = 1; i <= 2*n - 1; i++){
        cout << n << " ";
    }
    return 0;
}

int main(){
    int n = 5;
    pattern1(n);

    return 0;
}