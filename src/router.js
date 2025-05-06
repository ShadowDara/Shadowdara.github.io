import { createRouter, createWebHashHistory } from 'vue-router'

import DevBlog from './pages/DevBlog.vue'
import AboutMe from './pages/About_me.vue'

import Home from './pages/Home.vue'
import Webtools from './pages/Webtools.vue'

import Projects from './pages/Projects.vue'

import NotFound from './pages/NotFound.vue'

const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/blog',
    name: 'Dev Blog',
    component: DevBlog
  },
  {
    path: '/about_me',
    name: 'About me',
    component: AboutMe
  },
  {
    path: '/projects',
    name: 'Projects',
    component: Projects
  },
  {
    path: '/webtools',
    name: 'Webtools',
    component: Webtools
  },

  // to create a 404 page
  {
    path: '/:pathMatch(.*)*',
    name: 'NotFound',
    component: NotFound }
]

const router = createRouter({
  history: createWebHashHistory(),
  routes
})

export default router
