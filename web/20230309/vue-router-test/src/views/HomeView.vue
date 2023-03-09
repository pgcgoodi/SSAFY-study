<template>
  <div>
    <h1>할배</h1>
    {{ halbaeData }}
    <Parent
      :halbaeData="halbaeData"
      :halbaeData2="halbaeData2"
      @changeHalbaeData="changeHalbaeData"
    />
  </div>
</template>

<script>
import Parent from "../components/HomeParent.vue";

export default {
  components: {
    Parent,
  },
  data() {
    return {
      halbaeData: "나는 할배데이터!",
      halbaeData2: "할배요!",
    };
  },
  methods: {
    changeHalbaeData(text) {
      this.halbaeData = text;
    },
  },
};
</script>
