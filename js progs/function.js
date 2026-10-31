/*function oneton(n){
    for (let i=1;i<=n; i++){
        console.log(i);
    }
    console.log();
}
oneton(33);


//let num= Math.ceil(Math.random()*10);
//console.log(num);

function getRandomInt(min, max){
    return Math.floor(Math.random() * (max-min +1)) + min;
}
const randomnum = getRandomInt(-10,10);
console.log(Randomnum);
}*/
function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

const randomNum = getRandomInt(-10, 10);
console.log(randomNum);