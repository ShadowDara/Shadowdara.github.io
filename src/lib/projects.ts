import fs from "fs";
import yaml from "js-yaml";

export function getProjects() {
  const file = fs.readFileSync("./src/config/projects.yaml", "utf8");
  const data = yaml.load(file);
  return data.projects;
}
