const arr = [1,2,3,4];

arr.forEach((value) => {
  console.log(value);
})

const test = (value) =>{console.log(value)};
arr.forEach(test);
// 예제1
const A = [4,3,5,1,6,5];
let cnt = 0;
A.forEach((value) => {
  if (value % 2 === 1){
    cnt++;
  }
})
console.log(cnt);
// 예제2
const B = [-5,3,4,2,-7,-2,7];
const pplus = [];
const mminus = [];
B.forEach((value) => {
  if (value > 0) {
    pplus.push(value);
  }
  else {
    mminus.push(value);
  }
})
console.log(pplus, mminus);
// forEach는 값을 return하지 않음
