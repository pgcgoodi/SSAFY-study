<template>
  <div>
    <h1>Home</h1>
    <ul v-if="menus.length">
      <li v-for="menu in menus" :key="menu.id">
        <div class="menu-name" @click="goDetail(menu.id)">메뉴 : {{ menu.name }}</div>
        <div>설명 : {{ menu.description }}</div>
        <hr />
      </li>
    </ul>
    <div v-else>
      <b-spinner variant="primary" style="width: 3rem; height: 3rem;" label="Large Spinner"></b-spinner>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      menus: [],
    };
  },
  async created() {
    try {
      const response = await axios.get("http://localhost:8080/api/menus");
      this.menus = response.data;
    } catch (error) {
      console.log(error);
    }
  },
  methods: {
    goDetail(id){
      this.$router.push(`/detail/${id}`);
    }
  }
};
</script>

<style scoped>
.menu-name{
  color: blue;
  text-decoration-line: underline;
  cursor: pointer;
}
</style>