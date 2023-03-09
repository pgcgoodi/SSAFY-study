<template>
  <div>
    <h1>아들</h1>
    <div>
      {{halbaeData}}
    </div>
    <button @click="changeHalbaeData2">change2</button>
  </div>
</template>

<script>
export default {
  methods: {
    changeHalbaeData2() {
      this.$emit("changeHalbaeData2", "얍!!!")
    }
  },
  props: ["halbaeData"]
}
</script>
