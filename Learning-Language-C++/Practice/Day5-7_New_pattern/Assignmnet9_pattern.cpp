#include <iostream>
using namespace std;
int main(){
    int n = 5;
    for (int i = 1; i <=n-1; i++){
        if(i%2 == 0){
            for(int j = 1; j<=i; j++){
                if(j%2 == 0){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
        }else{
            for(int j = 1; j<=i; j++){
                if(j%2 == 0){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
        } 
        for(int j = 1; j<=((2*n-1)-2*i); j++){
            cout << " ";
        }

        for(int j = 1; j<=i; j++){
            if(j%2 == 0){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }

    for(int i = 1; i<=2*n-1; i++){
        if(i%2 == 0){
            cout << " ";
        }
        else{
            cout << "*";
        }
    }
    cout << endl;


    for (int i = 1; i <=n-1; i++){
        if(i%2 == 0){
            for(int j = 1; j<=n-i; j++){
                if(j%2 == 0){
                    cout << " ";
                }
                else{
                    cout << "*";
                }
            }
        }else{
            for(int j = 1; j<=n-i; j++){
                if(j%2 == 0){
                    cout << "*";
                }
                else{
                    cout << " ";
                }
            }
        }
        for(int j = 1; j<=(2*(i-1)+1); j++){
            cout << " ";
        }

        for(int j = 1; j<=n-i; j++){
            if(j%2 == 0){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }
}