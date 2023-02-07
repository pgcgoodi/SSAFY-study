const abc = {
  name: "치킨",
  type: "후라이드"
};
const {name, type} = abc;
console.log(name, type);
// 객체에서 필요한 정보를 가져옴

const arr = [1,2];
const [one, two] = arr;
console.log(one);
// 배열에서 필요한 정보를 가져옴

const sampleFunc = () => {
  return [1,2];
}
const [first, second] = sampleFunc();
console.log(first, second);
// 함수에서 return값을 여러개 받아오고 싶을 때