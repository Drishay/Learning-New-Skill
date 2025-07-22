let btn1 = document.querySelector("#button1");
btn1.onclick = () =>{
    console.log("Button 1 was clicked");
    let a = 10;
    console.log(++a);
}

let btn2 = document.querySelector("#btn2");
btn2.ondblclick= () =>{
    console.log('button got 2 clicked');
}