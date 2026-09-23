FROM node:22-bookworm

WORKDIR /workspace

# Useful development tools
RUN apt-get update \
    && apt-get install -y git curl \
    && rm -rf /var/lib/apt/lists/*

# Enable Corepack for package managers such as pnpm/yarn
RUN corepack enable

EXPOSE 4321

CMD ["bash"]
