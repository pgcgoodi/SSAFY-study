<template>
  <div>
    <h1>아빠</h1>
    <div>
      {{ halbaeData }}
    </div>
    <div>
      {{ halbaeData2 }}
    </div>
    <button @click="changeHalbaeData">change</button>
    <Child :halbaeData="halbaeData" @changeHalbaeData2="changeHalbaeData2" />
  </div>
</template>

<script>
import Child from "./ParentChild.vue";

export default {
  components: {
    Child,
  },
  props: ["halbaeData", "halbaeData2"],
  methods: {
    changeHalbaeData() {
      // emit => 부모의 함수를 실행해달라고 요청
      this.$emit("changeHalbaeData", "랄랄라")
    },
    changeHalbaeData2(text) {
      this.$emit("changeHalbaeData", text)
    },
  },
};
</script>
