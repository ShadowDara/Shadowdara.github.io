const info_pop_up = `<div class="modal-content"><span class="closeBtn">&times;</span>
    <h2>Shadowdara.github.io</h2>
    <div>
        <p><button><a href="/index.html">Home</a></button></p>
        <p><button><a href="https://github.com/ShadowDara/Shadowdara.github.io">Source</a></button></p>
    </div>
</div>`

const infos = document.getElementById("infos");

infos.innerHTML = info_pop_up

const openBtn = document.getElementById("openInfoBtn");
const closeBtn = document.querySelector(".closeBtn");

openBtn.onclick = function () {
    infos.style.display = "block";
}

closeBtn.onclick = function () {
    infos.style.display = "none";
}

window.onclick = function (event) {
    if (event.target == infos) {
        infos.style.display = "none";
    }
}
