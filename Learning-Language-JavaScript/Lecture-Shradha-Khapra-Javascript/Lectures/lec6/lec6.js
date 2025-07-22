// alert("hey");
// console.log("Hello");

// window, is a global object, which is created by a browser and not by javaScript
// window.console.log("Hello2");

/*
full html code can be accessed by JS, as html get converted in to objects, present in document object, in window.
*/

// console.dir(window);
// console.dir(document.body);
// console.dir(document.head); // we can access DOM

// benifit of DOM, dynamic changes or manipulation in the page, like dark or light mode
// console.log(document.body.style.background = 'red'); // we can access style of body

// DOM manipulation
/* selection with id
document.getElementById('id').style.background = 'red';
document.getElementById('H4 heading').style.background = 'red';
*/

/* selection with class
document.getElementsByClassName('class').style.background = 'red'; // returns HTMLCollection, it is similar to array
let classHeading = document.getElementsByClassName('class heading');
console.log(classHeading);
*/

/*selection with tag
document.getElementsByTagName('h1').style.background = 'red'; // returns HTMLCollection, it is similar
let h1 = document.getElementsByTagName('h1');
console.log(h1);
*/

/* Query Selector, using this we can search with id, class, tag


let firstElement = document.querySelector("p"); // returns 1 element
console.log(firstElement);
let allElements = document.querySelectorAll("p"); // returns all elements
console.dir(allElements);
*/
