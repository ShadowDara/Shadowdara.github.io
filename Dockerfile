FROM node:22.23.4

WORKDIR /app

RUN npm install -g bun

COPY package.json bun.lock* ./

RUN bun install

COPY . .

EXPOSE 4321

CMD ["bun", "run", "dev", "--", "--host", "0.0.0.0"]
