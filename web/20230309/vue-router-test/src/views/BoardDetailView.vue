<template>
  <div>
    <h1>Detail</h1>
    <div>여기는 {{id}}의 디테일 페이지입니다!</div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      id: null,
    }
  },
  created() {
    // router: 프로그램, route: 각각의 페이지 경로
    console.log(this.$router);
    console.log(this.$route.params.id);
    this.id = this.$route.params.id;
  }
}
</script>