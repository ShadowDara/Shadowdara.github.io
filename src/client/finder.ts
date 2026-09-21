export type Os = "mac" | "windows" | "linux";

export const installCommands: Record<Os, string> = {
  mac: "curl -fsSL https://raw.githubusercontent.com/ShadowDara/finder/refs/heads/main/install.sh | sh",
  linux:
    "curl -fsSL https://raw.githubusercontent.com/ShadowDara/finder/refs/heads/main/install.sh | sh",
  windows:
    'powershell -c "irm raw.githubusercontent.com/ShadowDara/finder/refs/heads/main/install.ps1 | iex"',
};
