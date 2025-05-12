<template>
    <h1>No Fucking Cors</h1>
    <p>Generate a link to fetch which ignores CORS!</p>
    <input placeholder="your link:" id="input"></input> <button id="generate">Generate</button> <button id="copy">Copy</button>
    <div id="output">

    </div>
    <h3>PLEASE CONSIDER:</h3>
    <p>this is not a real solution to the CORS problem, it just bypasses it by using a proxy server. This is not recommended for production use.</p>
    <p>And the server is free hostet, so it not an unlimited Data usage, i you want to use the more often, host it yourself on a Server (e.g. Vercel) with the Source Code <a href="https://github.com/shadowdara/no-fucking-cors"><code>here</code></a> on Github!</p>
</template>

<script>
document.addEventListener("DOMContentLoaded", function () {
  document.getElementById("generate").addEventListener("click", generate);
  document.getElementById("copy").addEventListener("click", copy);

  function generate() {
    const input = document.getElementById("input").value;
    document.getElementById("output").innerHTML = `<h3>OUTPUT</h3><code id="out">https://no-fucking-cors.vercel.app/api?url=${input}</code>`;
    document.getElementById("copy").innerText = `Copy`;
  }

  function copy() {
    const output = document.getElementById("out").innerText;
    navigator.clipboard.writeText(output).then(function () {
      document.getElementById("copy").innerText = `Copied!`;
    }, function (err) {
      console.error("Could not copy text: ", err);
    });
  }
});
</script>
