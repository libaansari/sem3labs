const express = require("express");
const users= require("./mockdata.json");


const app = express();
const PORT = 8080;

//ROUTES
app.get("/api/users", (req,res)=> {
    return res.json(users);
});


app.listen(PORT, () => console.log(`server started at port :${PORT}`));