// scripts/post-build.js
import fs from 'fs';
import path from 'path';

const distPath = path.join(process.cwd(), 'dist'); // Gets absolute path to 'dist'

// Create .nojekyll
fs.writeFileSync(path.join(distPath, '.nojekyll'), 'disable jekyll');
console.log('Created dist/.nojekyll');
