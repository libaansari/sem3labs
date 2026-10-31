//call function is a function which is passed inside a function 
function Products(a,b,c){
    return a*b*c;
}
function fun(x,y){
    console.log(x-y);
}
fun(Products(4,5,6),7);