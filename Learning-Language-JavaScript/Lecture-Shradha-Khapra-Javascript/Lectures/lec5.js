// Functions in Js, Block of code that perform a specific task, can be invoked whenever needed
// example
/*
console.log();
"abc".toUpperCase();
*/

/*
function defination
function functionName(){

}

function call
functionName();
*/
// function functionName(){
//     console.log("Hello, This is a Function");
// }
// functionName();

// function save us from redundency 
// input variable in the function is know as parameter, they are like local varibles of function and have a block scope, same like let

// function functionName(msg){
//     console.log(msg);
// }
// functionName("Hey! fellas!")

/*

function sumTwo(a,b){
    let sum = a+b;
    return sum;
}
console.log(sumTwo(5,6));

// arrow function, compact way of writing a function, part of Modern JS
const arrowSum = (a,b) => {
    console.log(a+b);
}

console.log(arrowSum); // return the function defination
console.log(arrowSum(5,3));

*/

// in javaScript, function could be passed as parameter

/*
function abc(){
    console.log("hello");
}
function myfun(abc){ //function could be passed as normal variable in another function or could be returned as normal variable
    return abc;
}
*/

// forEach method 
/*
arr.forEach(callBackFunction)
Call back is a function passed as an argument to another function
Here, it is a function to execute for each element in the array
arr.forEach((val)) =>{
    console.log(val);
}
*/
// example for the callback function

// let arr = ["hey", "i am", 1,2,3,4, "one"];
// arr.forEach(function printVal(val){ // val = value at each index
//     console.log(val);
// })

// arr.forEach((val)=>{ // generally we provide arrow function
//     console.log(val);
// })

// there are 3 parameter for forEach, (value, index, arr)

// arr.forEach((val, index, arr1)=>{ // generally we provide arrow function
//     console.log(val, index, arr1);
// })


/* Higher Order function/methods - function which takes other function as 
parameter or can return a function - like forEach Function, as there is a 
call back Function
*/

// let arr = [2,5,1,3,4,6];
// arr.forEach((value, index)=>{
//     console.log(value*value, index);
// });

// table of 5, using forEach and arrow function
let arr1 = [0,1,2,3,4,5,6,7,8,9,10];
/*
let printTable = (value, index) => {
    let num = 5;
    console.log(`${num} X ${index} = ${num*value}`);
}
arr1.forEach(printTable);
*/

// some more important array methods
/*
1- map method, similar to a forEach, only difference is that it returns a 
new array with the value its callback returns
arr.map(callbackFnx(value, index, array))

let newArr = arr.map((val)=>{
    return val*2;
})

arr1.map((val)=>{
    console.log(val);
});

*/

/*
2- filter method, creates a new array of elements that give true for a condition/filtee
let newArr = arr.filter( (val) =>{
   return val%2 == 0; 
});

let evenArr = arr1.filter((val)=>{
    return val%2===0;
}) ;

console.log(evenArr);

*/


/*
3- reduce method, return a single value, by performing some operatios &
reduces the array to a single value.

arr.reduce((accumulator, currentValue)=> accumulator + currentValue, initialValue,
);

let output = arr1.reduce((res, curr)=>{
    return res+curr;
});
let max = arr1.reduce((res, curr)=>{
    return res>curr? res:curr;
});
console.log(max);

*/