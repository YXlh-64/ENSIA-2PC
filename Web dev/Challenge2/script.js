//creating variables
const display = document.querySelector("#display");
let str = "";
for(let i = 0; i <= 10 ; ++i){
    for(let j = 0; j <= 10 ; ++j){
        str += i*j + "\t";
    }
    str+="\n";
}
display.innerHTML = str;