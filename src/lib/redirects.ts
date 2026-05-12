import fs from "fs";
import yaml from "js-yaml";

export function loadRedirects() {
  const file = fs.readFileSync("./src/config/redirects.yaml", "utf8");
  return yaml.load(file) as any[];
}
