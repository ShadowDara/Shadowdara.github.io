import { createRouter, createWebHashHistory } from 'vue-router'

import Home from './pages/main/Home.vue'
import home_redirection from './components/home_redirection.vue'

import DevBlog from './pages/md/DevBlog.vue'

import Webtools from './pages/main/Webtools.vue'

import Projects from './pages/main/Projects.vue'

import AboutMe from './pages/md/About_me.vue'

import More from './pages/main/More.vue'
import Changelog from './pages/md/page_changelog.vue'
import pageLinktree from './pages/md/page_linktree.vue'

import NotFound from './components/NotFound.vue'

const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/home',
    name: 'Home - Redirection',
    component: home_redirection
  },
  {
    path: '/devblog',
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
  {
    path: '/more',
    name: 'More Content',
    component: More
  },
  {
    path: '/more/changelog',
    name: 'Changelog',
    component: Changelog
  },
  {
    path: '/more/page_linktree',
    name: 'Page Linktree',
    component: pageLinktree
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
