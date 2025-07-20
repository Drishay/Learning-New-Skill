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