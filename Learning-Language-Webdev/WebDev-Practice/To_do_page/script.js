// To-Do List Logic
const addBtn = document.getElementById("add-btn");
const newTodoInput = document.getElementById("new-todo");
const todoList = document.getElementById("todo-list");

// Function to add a new to-do
function addTodo() {
  const todoText = newTodoInput.value.trim();
  if (todoText === "") return; // Prevent empty tasks

  // Create a new list item
  const listItem = document.createElement("li");
  listItem.className = "todo-item";

  // Add Check Button
  const checkBtn = document.createElement("button");
  checkBtn.className = "check-btn";
  checkBtn.innerHTML = "✔";
  checkBtn.addEventListener("click", () => {
    listItem.classList.toggle("completed"); // Toggle completed class
  });

  // Add To-Do Text
  const todoSpan = document.createElement("span");
  todoSpan.textContent = todoText;

  // Add Delete Button
  const deleteBtn = document.createElement("button");
  deleteBtn.className = "delete-btn";
  deleteBtn.innerHTML = "✖";
  deleteBtn.addEventListener("click", () => {
    listItem.remove(); // Remove the list item
  });

  // Append Check Button, To-Do Text, and Delete Button to the list item
  listItem.appendChild(checkBtn);
  listItem.appendChild(todoSpan);
  listItem.appendChild(deleteBtn);

  // Append the list item to the to-do list
  todoList.appendChild(listItem);

  // Clear the input field
  newTodoInput.value = "";
}

// Event Listener for Add Button
addBtn.addEventListener("click", addTodo);

// Allow adding tasks with the Enter key
newTodoInput.addEventListener("keypress", (e) => {
  if (e.key === "Enter") {
    addTodo();
  }
});

// Function to update the date and time
function updateDateTime() {
  const currentDateElement = document.getElementById("current-date");
  const currentTimeElement = document.getElementById("current-time");

  const now = new Date();

  // Format the date (e.g., January 25, 2025)
  const dateOptions = { year: "numeric", month: "long", day: "numeric" };
  currentDateElement.textContent = now.toLocaleDateString(undefined, dateOptions);

  // Format the time (e.g., 10:15:32 AM)
  const timeOptions = { hour: "2-digit", minute: "2-digit", second: "2-digit", hour12: true };
  currentTimeElement.textContent = now.toLocaleTimeString(undefined, timeOptions);
}

// Update date and time every second
setInterval(updateDateTime, 1000);
updateDateTime(); // Initial call to display date and time immediately
