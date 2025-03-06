function getLocalStorageSize() {
    let total = 0;
    for (let i = 0; i < localStorage.length; i++) {
        const key = localStorage.key(i);
        const value = localStorage.getItem(key);
        total += key.length + value.length;
    }
    return (total / 1024).toFixed(2); // Konvertiert Bytes in KB und gibt zwei Dezimalstellen zurück
}
