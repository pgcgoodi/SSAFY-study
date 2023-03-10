const express = require("express");
const morgan = require("morgan");
const axios = require("axios");
const app = express();
const PORT = 8080;

app.use(morgan("dev"));

// 템플릿 엔진으로 ejs를 사용
app.set("view engine", "ejs");
// 해당 ejs에서 활용할 경로를 ./views 폴더로 활용
app.set("views", "./views");

app.get("/", (req, res) => {
  // ejs에서 화면을 그리는 방식
  // router / -> 수신 -> index.ejs를 해석해서 완전한 html을 만들어서 리턴
  res.render("index", {name:"온유"})
})

app.get("/holder", async(req, res) => {
  const result = await axios.get("https://jsonplaceholder.typicode.com/todos");
  res.render("holder-list", {data: result.data});
})

// axios로 jsonpalceholder 요청 -> 데이터를 그려보기
 app.get("/holder/:id", async(req, res) => {
  const result = await axios.get(`https://jsonplaceholder.typicode.com/todos/${req.params.id}`);

  res.render("holder", {data: result.data});
 })

app.listen(PORT, () => console.log(`${PORT} 서버 구동 중`));