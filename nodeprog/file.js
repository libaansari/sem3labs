//file handling = file ke upr operation krna 

const fs= require('fs');

//sync path blockign request
//fs.writeFileSync("./test.txt", "hey there");

//async non blocking request
//fs.writeFile("./test.txt", "hey there async", (err) => {})

//non blocking..

fs.readFile("contacts.txt", "utf-8", (err, result) => {});