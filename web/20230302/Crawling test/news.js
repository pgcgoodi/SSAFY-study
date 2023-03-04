const puppeteer = require("puppeteer");

const main = async () => {
  const brower = await puppeteer.launch({
    headless:false
  })
  const page = await brower.newPage();
  await page.goto("https://news.daum.net/digital#1");
  await page.waitForSelector(".list_newsmajor .link_txt");
  const data = await page.evaluate(() => {
    const newsscript = document.querySelectorAll(".list_newsmajor .link_txt");
    const result = Array.from(newsscript).map(li => li.textContent);
    return result;
  })
  console.log(data);
}

main();