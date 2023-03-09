<template>
  <div>
    <h1>BOARD</h1>
    <div>
      <router-link to="/board/1">1번으로 가자</router-link>
    </div>
    <div>
      <router-link to="/board/2">2번으로 가자</router-link>
    </div>
    <div>
      <router-link to="/board/456">456번으로 가자</router-link>
    </div>
    <button @click="go789">Go 789</button>
  </div>
</template>

<script>
export default{
  methods: {
    go789() {
      this.$router.push("/board/789");
    }
  }
}
</script>