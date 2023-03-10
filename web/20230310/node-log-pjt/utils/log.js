// winston -> node의 대표적인 로그 라이브러리
// winston-daily-rotate-file -> 로그 관리 라이브러리
const winston = require("winston");
const {format} = winston;
const {combine} = format;
require("winston-daily-rotate-file");

const transport = new winston.transports.DailyRotateFile({
  // info level 까지만 보여주겠다
  level: "info",
  // 파일 이름
  filename: "./logs/%DATE%.log",
  // 날짜 형식
  datePattern: "YYYY-MM-DD-HH",
  zippedArchive: true,
  // 파일의 최대 크기
  maxSize: "20m",
  // 보관할 최대 로그 수
  maxFiles: "1d",
  format: combine(
    format.timestamp({format: "YYYY-MM-DD HH:mm:ss"}), 
    format.json())
});

const logger = winston.createLogger({
  transports: [transport]
});

module.exports = logger;