const name = document.querySelector(
  "li:nth-child(1) > div.box-contents > a > strong"
);
console.log(name.textContent);
const rate = document.querySelector(
  "li:nth-child(1) > div.box-contents > div > strong > span"
);
console.log(rate.textContent);
const open = document.querySelector(
  "li:nth-child(1) > div.box-contents > span.txt-info > strong"
);
console.log(open.textContent);
// 1등 영화 정보 출력



const secname = document.querySelector(
  "li:nth-child(2) > div.box-contents > a > strong"
);
secname.textContent = "삼겹살과 그대라면";
const secrate = document.querySelector(
  "li:nth-child(2) > div.box-contents > div > strong > span"
);
secrate.textContent = "5%";
const secopen = document.querySelector(
  "li:nth-child(2) > div.box-contents > span.txt-info > strong"
);
secopen.textContent = "1985.07.07 개봉";
// 2등 영화 정보 변경



const thrname = document.querySelector(
  "li:nth-child(3) > div.box-contents > a > strong"
);
const temp = name.textContent;
name.textContent = thrname.textContent;
thrname.textContent = temp;

const fstimg = document.querySelector(
  "li:nth-child(1) > div.box-image > a > span > img"
);
const thrimg = document.querySelector(
  "li:nth-child(3) > div.box-image > a > span > img"
);
const tempimg = fstimg.src;
fstimg.src = thrimg.src;
thrimg.src = tempimg;
// 1등과 3등 영화 제목과 포스터 변경



const array = [];
const boxContents = document.querySelectorAll(".box-contents");
console.log(boxContents);
for (let i = 0; i < 19; i++) {
  let title = boxContents[i].querySelector("a > strong");
  array.push(title);
}
console.log(array);
// 전체 제목 저장