// Dates

let myDate = new Date()
// console.log(myDate); //2025-07-11T08:15:25.245Z
// console.log(myDate.toString()); // Fri Jul 11 2025 13:45:25 GMT+0530 (India Standard Time)
// console.log(myDate.toJSON()); // 2025-07-11T08:15:25.245Z
// console.log(myDate.toLocaleString()); //11/7/2025, 1:45:25 pm
// console.log(myDate.toDateString()); // Fri Jul 11 2025

let myCreatedDate = new Date (2023, 0, 23)
// console.log(myCreatedDate.toDateString());

let myTimeStamp = Date.now();
console.log(myTimeStamp);
console.log(myCreatedDate.getTime());