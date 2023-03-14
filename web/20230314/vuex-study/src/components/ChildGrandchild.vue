<template>
  <div>
    Grandchild
    <input v-model="name">
    <button @click="changeName">이름 변경</button>
    <button @click="changeAge">나이 변경</button>
  </div>
</template>

<script>
export default {
  data(){
    return{
      name:""
    }
  },
  methods:{
    changeName(){
      this.$store.commit("SET_MY_NAME", this.name);
    },
    changeAge(){
      this.$store.commit("SET_MY_AGE", 3000);
    }
  }
}
</script>

<style>

</style>