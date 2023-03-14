<template>
  <div>
    <h1>Detail</h1>
    <div>{{menuId}} 번 메뉴 디테일 페이지입니다.</div>
    <div>{{menu.name}}</div>
    <div>{{menu.description}}</div>
    <div>{{menu.image_src}}</div>
  </div>
</template>

<script>
import axios from "axios";
export default {
  data(){
    return {
      menuId: -1,
      menu: {},
    }
  },
  async created(){
    this.menuId = this.$route.params.id;
    try {
      const response = await axios.get(`http://localhost:8080/api/menus/${this.menuId}`);
      this.menu = response.data;
    } catch(error){
      console.log(error);
    }
  },
}
</script>
