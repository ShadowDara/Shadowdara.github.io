// scripts/post-build.js
import fs from 'fs';
import path from 'path';

const distPath = path.join(process.cwd(), 'dist'); // Gets absolute path to 'dist'

// Create .nojekyll
fs.writeFileSync(path.join(distPath, '.nojekyll'), 'disable jekyll');
console.log('Created dist/.nojekyll');

// Create .well-known directory
const wellKnownPath = path.join(distPath, '.well-known');
fs.mkdirSync(wellKnownPath, { recursive: true }); // recursive: true creates parent dirs
console.log('Created dist/.well-known');

// Create discord file
fs.writeFileSync(path.join(wellKnownPath, 'discord'), 'dh=68417c419816c9874a9d08fc0f92fb51b1976f35');
console.log('Created dist/.well-known/discord');
