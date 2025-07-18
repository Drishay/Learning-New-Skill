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