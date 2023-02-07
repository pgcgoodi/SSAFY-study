const array = [3,5,4,2];
const filteredArray = array.filter(data => data > 3);
// filter -> 특정 조건을 만족하는 값들을 배열로 가져올 수 있다
// 예제1
const bucketList = [
  {
    id: 1,
    text: "여행 가기",
    done: false,
  },
  {
    id: 2,
    text: "치킨 먹기",
    done: true,
  },
  {
    id: 3,
    text: "코딩 하기",
    done: true,
  },
  {
    id: 4,
    text: "요리 하기",
    done: false,
  },
]
const newArray = bucketList.filter(data => data.done === false);