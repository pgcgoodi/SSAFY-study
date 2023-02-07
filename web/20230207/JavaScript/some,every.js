const array = [1,2,3,4,5];
// some은 하나의 조건만 만족해도 true를 반환
const result1 = array.some(element => element < 0);
const result2 = array.some(element => element > 4);

// every는 모든 조건을 만족해야 true를 반환
const result3 = array.every(element => element > 0);
const result4 = array.every(element => element > 3);