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
    
}