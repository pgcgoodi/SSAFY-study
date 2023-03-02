// 패키지를 가져오는 법
// require로 가져옴
// 내부에 있는 모듈은 ./~~

const puppeteer = require("puppeteer");

const main = async () => {
  // 브라우저 만들기
  const browser = await puppeteer.launch({
    // 기본값은 true
    headless:true
  })
  // 브라우저 페이지 만들기
  const page = await browser.newPage();
  // 페이지에서 주소로 이동하기
  await page.goto("https://www.naver.com");
  // 스크린샷 찍기
  await page.screenshot({path: "screenshot.jpg", fullPage:true});
  // pdf 따기 (headless:true 에서만 동작)
  await page.pdf({path: "test.pdf", format:'A4'});
  // 브라우저 종료하기
  await browser.close();
};

main();
