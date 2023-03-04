// 패키지를 가져오는 법
// require로 가져옴
// 내부에 있는 모듈은 ./~~

const puppeteer = require("puppeteer");

const main = async () => {
  // 브라우저 만들기
  const browser = await puppeteer.launch({
    // 기본값은 true
    headless:false
  })
  // 브라우저 페이지 만들기
  const page = await browser.newPage();
  // 페이지에서 주소로 이동하기
  await page.goto("https://comic.naver.com/webtoon?tab=mon");
  // 대기하는 법
  // waitForSelector -> 특정 selector가 올때까지 대기하는 역할
  await page.waitForSelector("#content .item img");
  // 크롤링 데이터 가져오기
  // node.js는 브라우저가 아닌 환경이기 때문에 document 사용 불가능
  // evaluate 안에서는 document 사용이 가능하다
  // headless = false
  const data = await page.evaluate(() => {
    const webToonlist = document.querySelectorAll("#content .item img");
    // querySelectorAll은 유사배열
    // -> Array.from으로 배열화 시킨 후에 배열 메서드 사용 가능
    const result = Array.from(webToonlist).map(li => li.getAttribute('alt'));
    return result;
  })
  console.log(data);
};

main();
