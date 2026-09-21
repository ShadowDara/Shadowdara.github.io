import { type Os, installCommands } from "./finder";

const commands = installCommands as Record<Os, string>;

function detectOs(): Os {
  const ua = navigator.userAgent;

  if (ua.includes("Mac")) return "mac";
  if (ua.includes("Win")) return "windows";

  return "linux";
}

const terminalCommand = document.querySelector<HTMLElement>("[data-command]");

const copyButton = document.querySelector<HTMLButtonElement>("[data-copy]");

const osButtons = document.querySelectorAll<HTMLButtonElement>(".os-btn");

function updateCommand(os: Os) {
  if (!terminalCommand) return;

  terminalCommand.textContent = commands[os];

  osButtons.forEach((button) => {
    button.classList.toggle("primary", button.dataset.os === os);
  });
}

copyButton?.addEventListener("click", async () => {
  const os = detectOs();
  const command = commands[os];

  await navigator.clipboard.writeText(command);

  const original = copyButton.textContent;

  copyButton.textContent = "copied";

  setTimeout(() => {
    copyButton.textContent = original;
  }, 1400);
});

osButtons.forEach((button) => {
  button.addEventListener("click", () => {
    const os = button.dataset.os as Os;

    updateCommand(os);
  });
});

updateCommand(detectOs());
