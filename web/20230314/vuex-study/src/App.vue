<template>
  <div id="app">
    <div>이름: {{$store.state.name}}</div>
    <div>나이: {{$store.state.age}}</div>
    <AppChild></AppChild>
  </div>
</template>

<script>
import AppChild from "./components/AppChild.vue";
export default{
  components:{
    AppChild
  }
};
</script>


<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

nav {
  padding: 30px;
}

nav a {
  font-weight: bold;
  color: #2c3e50;
}

nav a.router-link-exact-active {
  color: #42b983;
}
</style>
