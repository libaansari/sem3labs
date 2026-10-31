let s= "  NaTiOnALity   ";
console.log(s.toUpperCase());
console.log(s.toLowerCase());
let s2=s.toUpperCase(); //this will do nothing 
console.log(s,s2);
console.log(s.trim()); //removes the starting and ending spaces
console.log(s.length()); //tells the length also counts the spaces
console.log(s2.indexOf('a')); //aage se indexing
console.log(s2.lastIndexOf('a')); //peeche se index
console.log(s2.charAt(3)); //10th and 11th line has same function
console.log(s2[3]);
console.log(s2.slice(2)); //cuts the substring here second index se aage ka sb kuch print hojega 
//agr 2 args daale ho slice wale function mai toh woh uss indedx se udhr tk wale index tk dega

let s3= "he is at a protest";
console.log(s3);
let arr=s3.split(' ');
for(const ele of arr){
    console.log(ele);
}

let s3= "he,is,at,a,protest";
console.log(s3);
let arr=s3.split(' ');
for(const ele of arr){
    console.log(ele);
}
