const array = [1,2,3,4,5,6];

const result = array.map(data => data + 1);
// map은 원래 배열을 건드리지 않고 새로운 배열을 만듬

// 예제1
const arr1 = [1,2,3,4,5];
const result1 = arr1.map(data => data*data);

const arr2 = ["a", "bcd", "ef", "g"];
const result2 = arr2.map(data => data.length);