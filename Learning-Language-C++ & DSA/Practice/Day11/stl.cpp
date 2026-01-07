#include <bits/stdc++.h>
using namespace std;

void pair1(){
    // pair is from utility librarys
    pair <int, int> p = {1,2}; //pair stores 2 values.
    // cout<< p.first << " and " << p.second;

    pair <int , pair <int , int>> x = {1, {2,3}}; // nested pair.
    // cout << x.first << " and " << x.second.first << " and " << x.second.second; //same we can do to store 4 or more values

    // we can declare a pair array.
    pair <int , int> arr[2] = { {1,2}, {3,4}};
    cout << arr[0].first << " and " << arr[0].second << " and " << arr[1].first << " and " << arr[1].second;
}


void vector1(){
    //vector size can change, it is dynamic in nature.
    // vector <int> v; //declaring datatype, this creates a empty container i.e {}

    // v.push_back(1); //add 1, i.e {1}
    // v.emplace_back(2); //adds 2, i.e {1, 2}, emplace is faster than push

    // vector <pair <int , int>> vec;
    // vec.push_back ({1,2});
    // vec.emplace_back(3,4); //see the syntx for both is different

    // vector <int> v1(5 , 100); // v is declared with 5 (size), containg 5 instances of 100, {100, 100, 100, 100 ,100}
    // vector <int> v2(10); // v2 is declared with 10, with any garbage value, pushback still increase the size.

    // vector <int> v3(v2); //v3 is copy of v2
    
    vector <int> vec1(3);
    vec1.push_back(1);
    vec1.emplace_back(3);
    cout<< vec1[0] << " and " << vec1[1]; //some issue.
}


int main(){
    // pair1(); // for pair

    vector1();

    return 0;
}
    