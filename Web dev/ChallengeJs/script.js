//creating variables
const txt = document.querySelector("#txt");
const age = document.querySelector("#age");
const btn = document.querySelector("#submit");
const paragraph = document.querySelector("#display");

btn.addEventListener("click", function(){
    let n = txt.value;
    let a = age.value;
    paragraph.innerHTML = "Hello " + n + 
    " Your age is " + a;
})