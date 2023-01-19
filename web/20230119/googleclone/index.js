// 토글 버튼
const toggleButton = document.querySelector(".toggle-button");
// 배경
const bodyBackground = document.querySelector("body");
// header-nav
const headerNav = document.querySelector(".header-nav-list-wrapper");
// bookmark-wrapper
const bookmarkWrapper = document.querySelector(".bookmark-wrapper");
// search-input
const searchInput = document.querySelector("#search-input");
// img-icon-wrapper
const imgIconWrappers = document.querySelectorAll(".img-icon-wrapper");
// bookmark-text
const bookmarkTexts = document.querySelectorAll(".bookmark-text");

toggleButton.addEventListener("click", function() {
  toggleButton.textContent = "다크 모드";
  if (toggleButton.classList.contains("toggle-button-darkmode")) {
    toggleButton.textContent = "일반 모드";
  }

  toggleButton.classList.toggle("toggle-button-darkmode");
  bodyBackground.classList.toggle("body-background-darkmode");
  headerNav.classList.toggle("text-darkmode");

  for (let i = 0; i < imgIconWrappers.length; i++) {
    imgIconWrappers[i].classList.toggle("img-icon-wrapper-darkmode");
  }

  for (let i = 0; i < bookmarkTexts.length; i++) {
    bookmarkTexts[i].classList.toggle("text-darkmode");
  }
})

searchInput.addEventListener("keyup", function (evt) {
  if (evt.code === "Enter") {
    if (!evt.target.value) {
      alert("검색어를 입력하지 않으셨습니다!");
      return;
    }
    const googleSearch = "https://www.google.com/search?q=";

    window.open(googleSearch + evt.target.value, "_blank");
  }
})