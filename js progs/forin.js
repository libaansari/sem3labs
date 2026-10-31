let x = { //x is a object
    name: "xyz",
    age:32,
    'is married' : false
};

for (const key in x) {
    if (Object.hasOwnProperty.call(x, key)) {
        console.log(key,x[key]);
    }
}