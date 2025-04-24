function formatTextToSingleLine(text) {
    let formattedText = text.replace(/\t/g, '\\t').replace(/\n/g, '\\n');
    return formattedText;
}

document.getElementById('generate').addEventListener("click", function () {
    const input1 = document.getElementById('input1');
    const content = formatTextToSingleLine(input1.value);

    document.getElementById('output').innerText = content;

    const copyButton = document.createElement("button");
    copyButton.id = 'b-copy';
    copyButton.innerText = 'Copy Link';

    document.getElementById('copy-button').innerHTML = '';
    document.getElementById('copy-button').appendChild(copyButton);

    copyButton.addEventListener("click", function () {
        navigator.clipboard.writeText(content).then(function () {
            copyButton.innerText = "Link copied";
        }).catch(function (err) {
            console.error("Fehler beim Kopieren: ", err);
        });
    });
});
