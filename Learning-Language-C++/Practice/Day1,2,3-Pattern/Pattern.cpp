#include <iostream>
using namespace std;

int main()
{
    // Pattern 1
    /*
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
    */

    /*
    int n = 4;
    for(int i = 1; i<=n; i++){ //outer loop
        for(int j = 1; j<=n; j++){ //inner loop
            cout << j << " ";
        }
        cout << endl;
    }
    */

    // Pattern 2
    /*
     * * * *
     * * * *
     * * * *
     * * * *
     */

    /*
    int n = 4;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=n; j++){
            cout << "* ";
        }
        cout << endl;
    }
    */

    // Pattern 3
    /*
    A B C D
    A B C D
    A B C D
    A B C D
    */
    /*
     int n = 4;
     for (int i = 0; i<n; i++){ //outter loop
         char ch = 'A'; //why written here? because ch value is changing in the inner loop and we want pattern to start with 'A'
         for (int j = 0; j<n; j++){ //inner loop
             cout << ch << " ";
             ch = ch + 1; // A is stored as 65 in the system and when we increase it by 1, number changes to 66, which is 'B' and then it is stored in ch. i.e. ch = B, this is implicit type conversion
         }
         cout << endl;
     }
     */

    // Pattern 4
    /*
    1 2 3 
    4 5 6 
    7 8 9 
    */
   /*
    int n = 3;
    int num = 1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    */

    // Pattern 5
    /*
    * 
    * * 
    * * * 
    * * * *  
    */
   /*
    int n = 4;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<i+1; j++){ //we can use "*" * i logic to print the patter, just import (#include <string> // Needed for std::string)
            cout << "*" << " ";  // use thiss (cout << string(i + 1, '*') << " ";) for string logic
        }
        cout << endl;
    }
    */

    // Pattern 6
    /*
    1
    22
    333
    4444
    */
   /*
    int n = 4;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=i; j++){
            cout << i;
        }
        cout << endl;
    }
    */

    // Pattern 7
    /*
    A
    BB
    CCC
    DDDD
    */
   /*
    int n = 4;
    char ch = 'A';
    for (int i = 0; i<n; i++){
        for (int j = 0; j<=i; j++){
            cout << ch;
        }
        ch ++;
        cout << endl;
    }
    */

    // Pattern 8
    /*
    1
    12
    123
    1234
    */
   /*
   int n = 4;
   for (int i = 1; i<=n; i++){
    for (int j = 1; j<=i; j++)
        cout << j;
    cout << endl;
   }
    */

    // Pattern 9
    /*
    1
    21
    321
    4321
    */
   /*
    int n = 4;
    for (int i = 1; i<=n; i++){
        for (int j = i; j>=1; j--)
            cout << j;
        cout << endl;
    }
    */

    // Pattern 10 (Floyd's Triangle)
    /*
    1 
    2 3 
    4 5 6 
    7 8 9 10 
    */
   /*
    int n = 4, num = 1; //if want a Alphabet Floyd's triangle then change (int num) to (char ch = 'A')
    for (int i = 0; i<n; i++){
        for (int j = 0; j<=i; j++){
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    */

    // Pattern 11
    /*
    1111
     222
      33
       4
    */
   /*
    int n = 4;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<i; j++){
            cout << " ";
        }
        for (int j = 0; j<n-i; j++){
            cout << i+1;
        }
        cout << endl;
    }
    */

    // Patter 12
    /*
    AAAA
     BBB
      CC
       D
    */
   /*
    int n = 4;
    char ch = 'A';
    for (int i = 0; i<n; i++){
        for (int j = 0; j<i; j++){
            cout << " ";
        }
        for (int j = 0; j<n-i; j++){
            cout << ch;
        }
        cout << endl;
        ch ++;
    }
    */

    // Patter 13
    /*
       1
      121
     12321
    1234321
    */
   /*
    int n = 4;
    for (int i = 0 ; i < n; i++){

        for (int j = 0; j<n-i-1; j++){
            cout << " ";
        }
        
        for (int j = 1; j <= i+1; j++){
            cout << j;
        }

        for( int j = i; j > 0; j--){
            cout << j;
        }

        cout << endl;
    }
    */
    
    // Patter 14 - Butterfly Pattern
    /*

    *      *
    **    **
    ***  ***
    ********
    ********
    ***  ***
    **    **
    *      *
    
    */
    int n = 4;
    for (int i = 1; i<=n; i++){
        // 1st square of star and space
        for (int j = 1; j<=n; j++){
            if (j<=i){
                cout << "*";
            }
            else{
                cout <<" ";
            }
            
        }
        // 2nd square of space and star
        for (int j = 1; j<=n; j++){
            if (j < n-(i-1)){
                cout << " ";
            }
            else{
                cout << "*";
            }
        
        }
        cout << endl;

    }
    for (int i = 1; i<=n; i++){
        //reverse the logic for the bottom of the pattern - it jsut happend (tukka lag gya)
        // 3rd square of star and space
        for (int j = n; j>=1; j--){
            if (j>=i){
                cout << "*";
            }
            else{
                cout <<" ";
            }
            
        }
        // 4th square of space and star
        for (int j = n; j>=1; j--){
            if (j > n-(i-1)){
                cout << " ";
            }
            else{
                cout << "*";
            }
        
        }
        cout << endl;
    }
}