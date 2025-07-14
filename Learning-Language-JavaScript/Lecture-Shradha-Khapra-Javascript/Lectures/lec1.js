// console.log("Hey!");
// console.log("Boss,");
// console.log("How you doing?");

let age = 4;
console.log("Age " + age);

// variable
// javaScript is dynamically typed.
// datatypes, primitive and non primitive
 
// var, let, const
// object
// let student = {
//     fullName : "It Doesn't Matter",
//     age : 123,
//     cgpa : 4.3,
//     isPass : true,
// };

const student = {
    fullName : "It Doesn't Matter",
    age : 123,
    cgpa : 4.3,
    isPass : true,
};

student["age"] = 13;
console.log(student.age);
console.log(student['age']);

/*const keyword, cannot be updated, but const object keys can be changed, but if you change all the keys then it will
be a error, as you are changing a const.
*/

student["fullName"] = 13;
student["age"] = 13;
student["cgpa"] = 13;
student["isPass"] = 13;
console.log(student.age);
console.log(student['age']);


// error as i am changing a const.
student = { //TypeError: Assignment to constant variable.
    fullName : "It Matter",
    age : 12,
    cgpa : 1.3,
    isPass : false,
};

console.log(student.age);
console.log(student['age']);

