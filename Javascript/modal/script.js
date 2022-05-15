const modal = document.querySelector(".modal");
const overlay = document.querySelector(".overlay");
const showModalButtons = document.querySelectorAll(".show-modal");
const closeModalBtn = document.querySelector(".close-modal");

const showModal = function () {
    overlay.classList.remove("hidden");
    modal.classList.remove("hidden");
    console.log(modal.classList);
};

const closeModal = function () {
    overlay.classList.add("hidden");
    modal.classList.add("hidden");
    console.log(modal.classList);
};

showModalButtons.forEach(function (button) {
    button.addEventListener("click", showModal);
});
closeModalBtn.addEventListener("click", closeModal);
overlay.addEventListener("click", closeModal);

document.addEventListener("keyup", function (event) {
    if (event.key === "Escape" && !modal.classList.contains("hidden")) {
        closeModal();
    }
});
