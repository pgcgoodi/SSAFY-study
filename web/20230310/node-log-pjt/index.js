// 로그의 레벨 7
// error, warn, info, http, verbose, debug, silly
// 많이 쓰는 것: error, warn, info, debug
// error -> 에러 기록
// warn -> 에러는 아니지만 유의할 내용
// info -> 내용
// debug -> 상세한 데이터들

const express = require("express");
const morgan = require("morgan");
const logger = require("./utils/log");
const cors = require("cors");
const app = express();
app.use(express.json());
app.use(cors());
app.use(morgan("dev"));
const PORT = 8080;

app.use(express.static(__dirname + "/views"));

const fs = require("fs");
const { log } = require("console");
const { json } = require("express");

app.get("/api/logs", (req, res) => {
  logger.error("error 메세지");
  logger.warn("warn 메세지");
  logger.info("info 메세지");
  logger.http("http 메세지");
  logger.debug("debug 메세지");
  fs.readFile("./logs/2023-03-10-15.log", "utf-8", (err, data) => {
    const datalines = data.split("\r\n").slice(0, -1);
    const datajson = datalines.map((data) => JSON.parse(data));
    console.log(datajson);
    return res.json(datajson);
  });
})

app.listen(PORT, () => console.log(`${PORT} 서버 가동 중`));