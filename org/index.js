const express = require("express");

const app = express();

app.get("/", (req, res) => {
    res.send("Hello");
});

app.get("/about", (req, res) => {
    res.send(`Hello from about page. Hey ${req.query.name}, you are ${req.query.age}`);
});

app.listen(3080, () => {
    console.log("Server started");
});