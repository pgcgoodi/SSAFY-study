<template>
  <div>
    Child
    <div>이름: {{$store.state.name}}</div>
    <div>나이: {{$store.state.age}}</div>
    <ChildGrandchild></ChildGrandchild>
  </div>
</template>

<script>
import ChildGrandchild from './ChildGrandchild.vue';
export default {
  components:{
    ChildGrandchild
  }
};
</script>

<style>

</style>