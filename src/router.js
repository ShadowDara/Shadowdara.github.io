import { createRouter, createWebHistory } from 'vue-router'

import Blog from './blog/main.vue'
import Blog_03_05_2025 from './blog/03.05.2025.vue'

import Home from './pages/Home.vue'
import Webtools from './pages/Webtools.vue'

import Projects from './projects/Projects.vue'
import cmd_shortcut from './projects/open_terminal_on_shortcut.vue'

import NotFound from './pages/NotFound.vue'

const routes = [
  {
    path: '/',
    component: Home
  },
  {
    path: '/blog',
    component: Blog,
    children: [
      {
        path: '/blog/03.05.2025',
        component: Blog_03_05_2025
      }
    ]
  },
  {
    path: '/projects',
    component: Projects,
    children: [
      {
        path: '/projects/cmd_shortcut',
        component: cmd_shortcut
      }
    ]
  },
  {
    path: '/webtools',
    component: Webtools
  },
  // to create a 404 page
  {
    path: '/:pathMatch(.*)*',
    name: 'NotFound',
    component: NotFound }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
