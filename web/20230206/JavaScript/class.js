// const studentInfo = {
//   name: "이자룡",
//   age: 31,
//   address: "경기도 군포시",
//   family: ["나", "와이프", "고양이"],
//   skill: {
//     client: ["vue.js", "vanilla", "react"],
//     server: ["django", "php", "node.js"],
//     db: ["sqlite", "mongo", "mysql", "postgresql"],
//   },
//   sayHi: () => console.log("hi!!!!!!!!"),
// };

// studentInfo.sayHi();

// StudentInfo = {
//   name: String,
//   age: Number,
//   address: String,
//   family: Array,
//   skill: Object,
//   sayHi: Function,
// };

// const student1 = new StudentInfo();
// student1의 type은 StudentInfo(내가 만든 type)

// class는 내가 만든 type
// class StudentInfo {
//   constructor(name, age) {
//     this.name = name;
//     this.age = age;
//     this.address = "";
//   }
//   sayMyName() {
//     console.log(`my name is ${this.name}`);
//   }
//   setAddress(address) {
//     this.address = address;
//   }
//   getAddress() {
//     return this.address;
//   }
//   useMethod() {
//     this.sayMyName();
//   }
// }

// const student1 = new StudentInfo("jony", 30);
// student1.sayMyName();
// student1.setAddress("경기 군포시 산본동");
// console.log(student1.getAddress());
// student1.useMethod();

// class를 사용하지 않고 객체를 생성
const student1 = {
  name: "",
  age: -1,
  address: "",
  // key와 value가 같을 경우 하나로 축약 가능
  constructor: function (name, age) { // 화살표 함수는 this에 접근 불가능
    this.name = name;
    this.age = age;
  },
  sayMyName: function() {
    console.log(`my name is ${this.name}`);
  }, // : function은 축약 가능
  setAddress: (address) => (this.address = address),
  getAddress: () => this.address,
  useMethod: function() {
    this.sayMyName();
  },
};

student1.constructor("jony", 30);
// class가 아닌 student1이라는 객체를 만들었으므로 student2에는 적용이 안됨
// student2라는 객체를 다시 만들어야함
student2.constructor("david", 50);

student1.sayMyName();
student1.setAddress("경기 군포시 산본동");
console.log(student1.getAddress());
student1.useMethod();
// 예제1
class Lawyer {
  constructor (name, age, info) {
    this.name = name;
    this.age = age;
    this.info = info;
  }
  introduce() {
    console.log(`이름: ${this.name}`);
    console.log(`나이: ${this.age}`);
    console.log(`자기소개: ${this.info}`);
  }
}
const lawyer1 = new Lawyer("우영우", 27, "기러기 토마토 스위스 역삼역");
const lawyer2 = new Lawyer("최수연", 27, "봄날의 햇살");

lawyer1.introduce();
lawyer2.introduce();
// 예제2
class Hero {
  constructor (name, HP) {
    this.name = name;
    this.HP = HP;
  }
  showHP() {
    console.log(this.HP);
  }
  run() {
    this.HP -= 10;
  }
}

const hero1 = new Hero("batman", 100);
hero1.showHP();
hero1.run();
hero1.run();
hero1.showHP();
// 예제3
class Person {
  constructor (name, hp) {
    this.name = name;
    this.hp = hp;
  }
  hello() {
    console.log(`${this.name}`);
  }
}

class Avengers extends Person {
  constructor(name, hp, power, skill) {
    super(name, hp);
    this.power = power;
    this.skill = skill;
  }
  information() {
    console.log(`${this.name}`);
    console.log(`${this.hp}`);
    console.log(`${this.power}`);
    console.log(`${this.skill}`);
  }
  fly() {
    console.log(`비행중`);
  }
}

const batman = new Avengers("batman", 100, 100, 100);
batman.information();