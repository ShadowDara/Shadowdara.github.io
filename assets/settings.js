const infos = document.getElementById("infos");
const openBtn = document.getElementById("openInfoBtn");

const info_pop_up = `<div class="modal-content"><span class="closeBtn">&times;</span>
    <h2>Shadowdara.github.io</h2>
    <p>This is a cool popup window!</p>
</div>`

openBtn.onclick = function () {
    infos.innerHTML = info_pop_up

    const closeBtn = document.querySelector(".closeBtn");
    closeBtn.onclick = function () {
        infos.style.display = "none";
    }

    infos.style.display = "block";
}

window.onclick = function (event) {
    if (event.target == infos) {
        infos.style.display = "none";
    }
}

document.getElementById('generate').addEventListener("click", async function () { });
