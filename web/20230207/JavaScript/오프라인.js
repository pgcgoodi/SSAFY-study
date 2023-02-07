const students = [
  {
    name: "김도훈",
    age: 26,
    address: "경남 창원시"
  },
  {
    name: "김기홍",
    age: 27,
    address: "광주광역시"
  },
  {
    name: "김택우",
    age: 30,
    address: "인천광역시"
  },
]

students.forEach((student)=>{
  console.log(student.name);
});
// forEach : return 값이 없으므로 단순히 배열에 각각 접근할 때 사용

const names = students.map((student)=>{
  return student.name;
});
// map : 새로운 배열을 만들고 싶을 때, 크기는 원래 배열과 같음

const over30people = students.filter((student)=>{
  return student.age >= 30;
});
// filter : 조건에 맞는 새로운 배열을 만듬 따라서 크기가 다름

// 예제1
const arr = [1,2,3,4,5,6,7,8,9,10];
const even = arr.filter((num) => num%2 === 0);
const multiten = even.map((num) => num*10);

// 예제2
const orderList = [
  {
    menu: "치킨",
    price: 17000,
    event: false,
    count: 50,
  },
  {
    menu: "돈까스",
    price: 8500,
    event: true,
    count: 99,
  },
  {
    menu: "마라탕",
    price: 8000,
    event: false,
    count: 100,
  },
  {
    menu: "쫄면",
    price: 6500,
    event: false,
    count: 0,
  },
  {
    menu: "짜장면",
    price: 5500,
    event: true,
    count: 30,
  },
]

// const newList1 = orderList.filter((li) => li.count > 0);
// const newList2 = newList1.map((li) => {
//   if(li.event === true) li.price = li.price * 90 / 100;
//   return li;
// });

const newOrderList = orderList
  .filter((order) => order.count !== 0)
  .map((order) => {
    const newOrder = structuredClone(order);
    if (order.event) {
      newOrder.saledPrice = (newOrder.price * 9) / 10;
      return newOrder;
    }
    newOrder.saledPrice = newOrder.price;
    return newOrder;
  });
console.log(orderList); // 원래 배열은 손상되지 않는다.
console.log(newOrderList); // 새로운 메뉴 리스트

// 예제3
const bucketLists = [
  {id: 3, text: "여행 가기", done: false},
  {id: 2, text: "치킨 가기", done: true},
  {id: 1, text: "코딩 가기", done: false},
];
const getValues = (indecator) => 
  bucketLists.map((bucketList) => bucketList[indecator]);
console.log(getValues("id"));
console.log(getValues("text"));
console.log(getValues("done"));

// 예제 4
const removeList = (id) => bucketLists.filter((el) => el.id !== id);

console.log(removeList(1));

// 예제5
const toggle = (id) => {
  const newBucketLists = structuredClone(bucketLists);
  const ret = newBucketLists.filter((el) => el.id === id);
  if (ret[0].done) {
    ret[0].done = false;
  } else {
    ret[0].done = true;
  }
  return newBucketLists;
};

console.log(toggle(1));