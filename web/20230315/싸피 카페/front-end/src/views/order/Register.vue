<template>
  <div>
    <div class="form-wrapper">
      <div>주문 메뉴 : <input v-model="name" type="text"></div>
      <div>수량 : <input v-model="quantity" type="text"></div>
      <div>요청 사항 : <input v-model="request" type="text"></div>
      <button @click="create">주문 등록</button>
    </div>
  </div>
</template>

<script>
import { api } from "@/utils/axios";

export default {
  data(){
    return {
      name: null,
      quantity: null,
      request: null,
    }
  },
  methods: {
    async create(){
      if (!this.name || !this.quantity || !this.request){
        alert("빈 값이 있습니다 내용을 전부 작성해주세요");
      }
      const result = await api.orders.create(
        this.name,
        this.quantity,
        this.request
      );
    }
  }
};
</script>

<style scoped>

</style>