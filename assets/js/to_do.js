// Funktion zum Laden der Aufgaben aus dem localStorage
function loadTasks() {
    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    const taskList = document.getElementById('taskList');
    taskList.innerHTML = '';

    tasks.forEach((task, index) => {
        const li = document.createElement('li');
        
        // Button zum Entfernen der Aufgabe
        const deleteButton = document.createElement('button');
        deleteButton.textContent = 'Löschen';
        deleteButton.onclick = function() {
            removeTask(index);
        };

        // Löschen-Button vor der Aufgabe
        li.appendChild(deleteButton);
        li.appendChild(document.createTextNode(' ' + task));
        taskList.appendChild(li);
    });
}

// Funktion zum Hinzufügen einer Aufgabe
function addTask() {
    const taskInput = document.getElementById('newTask');
    const newTask = taskInput.value.trim();

    if (newTask) {
        const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
        tasks.push(newTask);
        localStorage.setItem('tasks', JSON.stringify(tasks));
        taskInput.value = ''; // Eingabefeld leeren
        loadTasks(); // Aufgaben neu laden
    }
}

// Funktion zum Entfernen einer Aufgabe
function removeTask(index) {
    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    tasks.splice(index, 1); // Aufgabe aus dem Array entfernen
    localStorage.setItem('tasks', JSON.stringify(tasks));
    loadTasks(); // Aufgaben neu laden
}

// Beim Laden der Seite Aufgaben aus dem localStorage laden
window.onload = loadTasks;