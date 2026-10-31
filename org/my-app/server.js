const express = require("express");
const app = express();

app.get("/", (req, res) => {
  res.send("Hello from Express");
});

app.listen(8080, () => {
  console.log("Server running on port 6000");
});

