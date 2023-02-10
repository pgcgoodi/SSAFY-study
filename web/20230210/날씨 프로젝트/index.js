async function setRenderBackground() {
  // body의 background에 주소를 넣어도 되지만
  // 일부러 axios 요청으로 이미지 받아옴
  // blob => 이미지, 사운드, 비디오 등 멀티미디어 데이터를 다룰때 사용
  const result = await axios.get("https://picsum.photos/1280/720", {
    responseType : "blob"
  });
  // URL.createObjectURL -> 임시 URL을 만든다(페이지 내에서만 유용)
  // 받아온 데이터를 임시 URL로 만들어서 그 URL의 body에 넣는다
  const imageURL = URL.createObjectURL(result.data);
  document.querySelector('body').style.backgroundImage = `url(${imageURL})`;
  const key = "ab0b5b1c4227b2fa5f82951d1e25aeb8";
  // API 호출방법
  // api.openweathermap.org/data/2.5/forecast?lat={lat}&lon={lon}&appid={API key}
  // 도시명으로 찾는 방법
  // api.openweathermap.org/data/2.5/forecast?q={city name}&appid={API key}
}

function setTime() { // 시간 갱신
  const timer = document.querySelector(".timer");
  setInterval(() => {
    const date = new Date();
    timer.textContent = `${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`;
  }, 1000)
}

function setMemo() {
  memoInput = document.querySelector(".memo-input");
  memoInput.addEventListener("keyup", (evt) => {
    if (evt.code === "Enter" && evt.currentTarget.value) {
      localStorage.setItem("todo", evt.currentTarget.value);
      getMemo();
    }
  })
}

function getMemo() {
  const memo = document.querySelector(".memo");
  const memoValue = localStorage.getItem("todo");
  memo.textContent = memoValue;
}

function deleteMemo() {
  document.addEventListener("click", (evt) => {
    if (evt.target.classList.contains("memo")) {
      localStorage,removeItem("todo");
      evt.target.textContent = "";
    }
  })
}

function getPosition(options) {
  return new Promise(function (resolve, reject) {
    navigator.geolocation.getCurrentPosition(resolve, reject, options);
  });
}

async function renderWeather() {
  const position = await getPosition();
  const latitude = position.coords.latitude;
  const longitude = position.coords.longitude;
  console.log(axios.get(`http://api.openweathermap.org/data/2.5/forecast?lat=${latitude}&lon=${longitude}&appid=${key}`));
}

function allRender() {
  setRenderBackground();
  setTime();
  setMemo();
  getMemo();
  deleteMemo();
  renderWeather();

  // 5초 마다 해당 콜백함수 반복
  setInterval(() => {
    setRenderBackground();
  }, 5000)
}

allRender();