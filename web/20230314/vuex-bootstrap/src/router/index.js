import Vue from 'vue'
import VueRouter from 'vue-router'
import Main from "../views/MainView.vue"
import List from "../views/todos/ListView.vue"
import Detail from "../views/todos/DetailView.vue"

Vue.use(VueRouter)

const routes = [
  {
    path: "/",
    name: "main",
    component: Main,
  },
  {
    path: "/todos",
    name: "list",
    component: List,
  },
  {
    path: "/todos/:id",
    name: "detail",
    component: Detail,
  }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
