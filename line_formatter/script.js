// Funktion zum Formatieren des Textes auf eine einzige Zeile
function formatTextToSingleLine(text) {
    let formattedText = text.replace(/\t/g, '\\t').replace(/\n/g, '\\n');
    return formattedText;
}

document.getElementById('generate').addEventListener("click", function () {
    const input1 = document.getElementById('input1');  // Holen des Eingabefelds
    const content = formatTextToSingleLine(input1.value);  // Zugriff auf den Textwert des Eingabefelds

    // Ausgabe des formatierten Textes
    document.getElementById('output').innerText = content;

    // Erstelle den "Copy Link"-Button
    const copyButton = document.createElement("button");
    copyButton.id = 'b-copy';
    copyButton.innerText = 'Copy Link';

    // Füge den Button zum DOM hinzu
    document.getElementById('copy-button').innerHTML = '';  // Leeren des bestehenden Inhalts
    document.getElementById('copy-button').appendChild(copyButton);

    // Kopieren-Funktion
    copyButton.addEventListener("click", function () {
        navigator.clipboard.writeText(content).then(function () {
            copyButton.innerText = "Link copied";  // Button-Text nach dem Kopieren ändern
        }).catch(function (err) {
            console.error("Fehler beim Kopieren: ", err);
        });
    });
});
