#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void checkStringSize(string &a, string &b){
        if(a.length()<b.length()){
            int correction = b.length() - a.length();
            string temp = a;
            a = "";

            for(int i = 0; i < correction; i++){
                a+="0";
            }
            a+=temp;
        }
        else{
            int correction = a.length() - b.length();
            string temp = b;
            b = "";
            for(int i = 0; i < correction; i++){
                b+="0";
            }
            b+=temp;
        }

    }
    string addBinary(string a, string b) {

        checkStringSize(a,b);
        string result = "";
        char carry = '0';
        for(int i = a.size()-1; i>=0; i--){
            if( (a[i] == '1') && (b[i] =='1') && (carry == '0')){
                result += '0';
                carry = '1';
                cout << "case 1 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }
            else if((a[i] == '1') && (b[i] =='1') && (carry == '1')){
                result += '1';
                carry = '1';
                cout  << "case 2 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }

            else if((a[i] == '1') && (b[i] =='0') && (carry == '0')){
                result += '1';
                carry = '0';
                cout  << "case 3 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }
            else if((a[i] == '0') && (b[i] =='1') && (carry == '0')){
                result += '1';
                carry = '0';
                cout  << "case 3.1 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }


            else if((a[i] == '1') && (b[i] =='0') && (carry == '1')){
                result += '0';
                carry = '1';
                cout  << "case 4 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }

            else if((a[i] == '0') && (b[i] =='1') && (carry == '1')){
                result += '0';
                carry = '1';
                cout  << "case 4.1 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }

            else if((a[i] == '0') && (b[i] == '0') && (carry == '1')){
                result += '1';
                carry = '0';
                cout << "case 5 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }
            else if((a[i] == '0') && (b[i] == '0') && (carry == '0')){
                result += '0';
                carry = '0';
                cout << "case 6 " << "index " << i << " result " << result << " carry " << carry << "\n";
            }
        }
        cout << result << "\n";
        cout << carry << "\n";

        if(carry == '1'){
            result += '1';
        }
        cout << result << "\n";

        string realResult ="";
        for(int i = result.size()-1; i>=0; i--){
            realResult += result[i];
        }


        return realResult;
    }
};

class Print{
public:
    void printSingle(string value){
        cout << "\n" << value;
    }

    void printVector(vector <int> nums){
         for (int num : nums) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
};

int main() {
    // Input
    string a = "1010";
    string b = "1011";

    // Create object of Solution class
    Solution sol;

    // Create object of Print class for printing the values
    Print print;

    

    // printing the value or values
    print.printSingle(sol.addBinary(a,b));


    return 0;
}


// leetcode
// by me-
/*
class Solution {
public:
    void checkStringSize(string &a, string &b){
        if(a.length()<b.length()){
            int correction = b.length() - a.length();
            string temp = a;
            a = "";

            for(int i = 0; i < correction; i++){
                a+="0";
            }
            a+=temp;
        }
        else{
            int correction = a.length() - b.length();
            string temp = b;
            b = "";
            for(int i = 0; i < correction; i++){
                b+="0";
            }
            b+=temp;
        }

    }
    string addBinary(string a, string b) {

        checkStringSize(a,b);
        string result = "";
        char carry = '0';
        for(int i = a.size()-1; i>=0; i--){
            if( (a[i] == '1') && (b[i] =='1') && (carry == '0')){
                result += '0';
                carry = '1';
            }
            else if((a[i] == '1') && (b[i] =='1') && (carry == '1')){
                result += '1';
                carry = '1';
            }

            else if((a[i] == '1') && (b[i] =='0') && (carry == '0')){
                result += '1';
                carry = '0';
            }
            else if((a[i] == '0') && (b[i] =='1') && (carry == '0')){
                result += '1';
                carry = '0';
            }


            else if((a[i] == '1') && (b[i] =='0') && (carry == '1')){
                result += '0';
                carry = '1';
            }

            else if((a[i] == '0') && (b[i] =='1') && (carry == '1')){
                result += '0';
                carry = '1';
            }

            else if((a[i] == '0') && (b[i] == '0') && (carry == '1')){
                result += '1';
                carry = '0';
            }
            else if((a[i] == '0') && (b[i] == '0') && (carry == '0')){
                result += '0';
                carry = '0';
            }
        }

        if(carry == '1'){
            result += '1';
        }

        string realResult ="";
        for(int i = result.size()-1; i>=0; i--){
            realResult += result[i];
        }
        
        return realResult;
    }
};
*/

// gpt solution
/*
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

*/