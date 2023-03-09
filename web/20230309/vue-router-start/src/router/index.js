import Vue from 'vue'
import VueRouter from 'vue-router'
import Main from '../views/AppMain.vue'
import About from '../views/AppAbout.vue'
import Board from '../views/AppBoard.vue'

Vue.use(VueRouter)

const routes = [
  {
    path: "/",
    name: "main",
    component: Main
  },
  {
    path: "/about",
    name: "about",
    component: About
  },
  {
    path: "/board",
    name: "board",
    component: Board
  },
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
