const express = require("express");
const app = express();
const PORT = 8080;

const cors = require("cors");
app.use(cors());

const { pool } = require("./db");
// json 형식의 데이터를 받아오기 위해 필요한 세팅
app.use(express.json());

app.get("/api/menus", async (req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus");
    if (data[0]) {
      return res.json(data[0]);
    }
  } catch (error) {
    console.log(error);
  }
});

app.post("/api/menus", async (req, res) => {
  console.log(req.body);
  try {
    const data = await pool.query(`INSERT INTO menus (menu_name, menu_description, menu_img_link)
    VALUES (?, ?, ?)`, [req.body.menu_name, req.body.menu_description, req.body.menu_img_link]);
    return res.json(data);
  } catch (error) {
    console.log(error);
  }
});

app.listen(PORT, () => console.log(`this server is listening on ${PORT}`));
