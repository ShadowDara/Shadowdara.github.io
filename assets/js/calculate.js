function addDateField() {
    const container = document.getElementById("dateFields");
    const newInput = document.createElement("input");
    newInput.type = "date";
    newInput.className = "dateInput";
    container.appendChild(newInput);
}

function calculateAllTimes() {
    const inputs = document.querySelectorAll(".dateInput");
    const resultsDiv = document.getElementById("results");
    resultsDiv.innerHTML = "";

    inputs.forEach((input, index) => {
        const inputDate = input.value;
        if (!inputDate) return;

        const [year, month, day] = inputDate.split("-");
        const startDate = new Date(year, month - 1, day);
        const now = new Date();

        let years = now.getFullYear() - startDate.getFullYear();
        let months = now.getMonth() - startDate.getMonth();
        let days = now.getDate() - startDate.getDate();

        if (days < 0) {
            months--;
            days += new Date(now.getFullYear(), now.getMonth(), 0).getDate();
        }
        if (months < 0) {
            years--;
            months += 12;
        }

        const resultText = `Datum ${index + 1}: ${days} Tage, ${months} Monate, ${years} Jahre`;
        const resultP = document.createElement("p");
        resultP.innerText = resultText;
        resultsDiv.appendChild(resultP);
    });
}