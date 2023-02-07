const datas = [1,2,3,4,5];

// const accResult = datas.reduce((acc, cur) => {
//   console.log(acc, cur);
//   return acc + cur;
// }, 1); // 1은 초기 acc

const accResult = datas.reduce((acc, cur) => {
  console.log(acc, cur);
  return acc + cur;
}); // acc의 초기값이 없을 경우 배열의 첫 번째가 acc가 되고 cur은 배열의 두 번째가 됨

console.log(accResult);

// 예제
const studentInfo = [
  {
    name: "jony",
    age: 30,
  },
  {
    name: "sylvie",
    age: 30,
  },
  {
    name: "nana",
    age: 1,
  },
];

const newStudentInfo = studentInfo.reduce((acc, cur) => {
  acc.push(cur.name);
  return acc;
}, []);
console.log(newStudentInfo);

const thirtyStudent = studentInfo.reduce((acc, cur) => {
  if (cur.age === 30) {
    acc.push(cur.name);
  }
  return acc;
}, []);
console.log(thirtyStudent);

// map, filter, forEach는 두번째 파라미터에 idx(index)를 추가 가능