const arr1 = [1,2,3];
const arr2 = [1,2,3];
console.log(arr1 === arr2);
// 배열과 객체는 비교 불가, 위의 결과는 false, 두 배열의 주소가 다르기 때문
// 빈 배열과 빈 객체도 비교 불가
// 빈 배열과 빈 객체는 긍정
// undefined, null, 0, false, 빈 문자열은 부정