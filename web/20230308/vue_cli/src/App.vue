<template>
  <div>
    <h1>parent</h1>
    <AppChild/>
  </div>
</template>

<script>
import AppChild from "./components/AppChild.vue"
export default {
  components: {
    AppChild
  }
}
</script>

<style>

</style>