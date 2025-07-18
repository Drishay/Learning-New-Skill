// let markstud1 = 100;
// let markstud2 = 60;
// let marks = {
//     stud1: 98,
//     stud2: 70
// };

// let markstud = [80, 90, 87, 60];
// let random1 = ["hey", 89, 'a'];

// console.log(random1.length);

// // strings are immutable
// // arrays are mutable

// for( let i = 0; i<markstud.length; i++){
//     console.log(markstud[i]);
// }

// // for of
// for( let marks of markstud){
//     console.log(marks);
// }

// // for in // returs index

// for( let marks in markstud){
//     console.log(marks);
// } 

let values = [12,3,4,5,1,10];
// for(let i = 0; i < values.length; i++){
//     console.log(`Value at ${i} is ${values[i]}`);  //to use ${...} inside a string for variable interpolation, you need backticks (`), not single quotes (') or double quotes (").
//     values[i]*=10;
// }

// console.log(values);
// // array methods
// // arrayName.push(), add the element at last and return the updated length and changes are done in original array

// values.push(15);

// console.log(values);

// values.push(10,11,6);
// console.log(values);

// // arrayName.pop(), removes the last element and return the removed element

// console.log(values.pop());
// console.log(values);

// arrayName.toString(), doesn't change the orriginal array and return the string
console.log(values.toString());

// concat(), doesn't change the original, return new array
let name1 = ['b','f','s','d','a']
// let something = values.concat(name1)
console.log(values.concat(name1));


// unshift, same like push but in the start
// shift, same like pop but in the start


// slice()
// splice() , for replacement