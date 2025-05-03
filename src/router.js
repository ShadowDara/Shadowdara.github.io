import { createRouter, createWebHistory } from 'vue-router'

import MarkdownBlog from '@/pages/MarkdownBlog.vue'

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
    name: 'Blog',
    component: MarkdownBlog,
  },
  {
    path: '/projects',
    name: 'Projects',
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
  history: createWebHistory(),
  routes
})

export default router
