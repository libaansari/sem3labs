//1000 is 1 sec

/*function h(){
    console.log("hhhh");
}
function b(){
    console.log("bbbbb");
}

setTimeout(h, 2*22);
setTimeout(b,2*20);


setTimeout(function(){
    console.log("hhhh");
},2*1000);

setTimeout(function(){
    console.log("yyyy");
},2*1000);

*/ 

//printing 1 to 10 but with the delay of 1 sec after each number gets printed
 for (let i=1; i<=15; i++){
    setTimeout(function(){
        console.log(i);
    }, i*1000)
 }