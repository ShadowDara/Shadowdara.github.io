import { minify } from "html-minifier-terser";
import fs from "fs";
import path from "path";

const distDir = "./dist";

let totalBefore = 0;
let totalAfter = 0;

async function processFile(filePath) {
  const originalContent = fs.readFileSync(filePath, "utf8");
  const originalSize = fs.statSync(filePath).size;

  const minified = await minify(originalContent, {
    collapseWhitespace: true,
    removeComments: true,
    minifyCSS: true,
    minifyJS: true,
  });

  fs.writeFileSync(filePath, minified);

  const newSize = Buffer.byteLength(minified, "utf8");

  totalBefore += originalSize;
  totalAfter += newSize;
}

async function walk(dir) {
  const files = fs.readdirSync(dir);

  for (const file of files) {
    const fullPath = path.join(dir, file);
    const stat = fs.statSync(fullPath);

    if (stat.isDirectory()) {
      await walk(fullPath); // 🔥 wichtig
    } else if (file.endsWith(".html")) {
      await processFile(fullPath); // 🔥 wichtig
    }
  }
}

function format(bytes) {
  return (bytes / 1024).toFixed(2) + " KB";
}

async function run() {
  await walk(distDir);

  const saved = totalBefore - totalAfter;
  const percent = totalBefore === 0 ? 0 : ((saved / totalBefore) * 100).toFixed(1);

  console.log("\n📊 Build Minify Summary");
  console.log("------------------------");
  console.log(`Before: ${format(totalBefore)}`);
  console.log(`After : ${format(totalAfter)}`);
  console.log(`Saved : ${format(saved)} (${percent}%)`);
}

run();
