const square = {
  width: 200,
  height: 200
};

const colorSquare = {
  ...square,
  color: "red"
};
console.log(colorSquare);
// 객체의 내용을 다른 객체로 가져올 때

const catTypeAnimals = ["고양이", "호랑이", "사자"];
const dogTypeAnimals = ["개", "늑대", "여우"];
const animals = [...catTypeAnimals, ...dogTypeAnimals, "비버"];
console.log(animals);
// 배열의 내용을 다른 배열로 가져옴

const chicken = {
  type: "양념",
  drumstick: 2,
  wing: 2
};

const {type, ...another} = chicken;
console.log(type, anoter);
// 객체의 나머지를 rest에 담기 