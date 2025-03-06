const slides = document.querySelector('.slides');
let index = 0;

function nextSlide() {
    index = (index + 1) % 3; // 3 Bilder, also zurück auf 0 nach dem letzten
    slides.style.transform = `translateX(-${index * 100}%)`;
}

// Starte die Slideshow mit einer Pause zwischen den Übergängen
setInterval(nextSlide, 3000); // Alle 3 Sekunden wechseln (2.5s Pause, 0.5s Slide)
