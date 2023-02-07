// 백틱 `
// 문자열과 자바스크립트 혼합 가능
const myName = "박근창";
const introduce = `제 이름은 ${myName} 입니다.`
console.log(introduce);

// 백틱은 엔터를 허용
const hello = `안녕하세요
저는
박근창입니다.`;
console.log(hello);

// insertAdjacentHTML 문자열로 된 html 태그 집어넣기
const a = `
<div class="a">
  안녕하세요
</div>
`
document.querySelector('body').insertAdjacentHTML('beforeend', a);

const b = (hello) => `
<div class="a">
  ${hello}
</div>
`