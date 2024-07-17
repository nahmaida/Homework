function reset(button) {
    button.style.backgroundColor =
        getComputedStyle(button).getPropertyValue("--darker");
    button.style.color = getComputedStyle(button).getPropertyValue("--base");
}

function getAnswerMC(correct) {
    const name = "#mc" + correct[0];
    const container = document.querySelector(name);
    const buttons = container.querySelectorAll("button");

    for (const button of buttons) {
        button.onclick = () => {
            const answer = document.getElementById(correct[0] + ":answer");
            if (button.id == correct) {
                button.style.backgroundColor =
                    getComputedStyle(button).getPropertyValue("--correct");
                answer.style.color =
                    getComputedStyle(button).getPropertyValue("--correct");
                answer.innerHTML = "Correct!";
            } else {
                button.style.backgroundColor =
                    getComputedStyle(button).getPropertyValue("--incorrect");
                answer.style.color =
                    getComputedStyle(button).getPropertyValue("--incorrect");
                answer.innerHTML = "Incorrect";
                setTimeout(() => {
                    reset(button);
                }, 1000);
            }
        };
    }
}

function getAnswerFR(id, correct) {
    const button = document.getElementById(id + "_b");

    button.onclick = () => {
        const answer = document.getElementById(id + "_ans").value;
        const answerField = document.getElementById(id + ":answer");
        if (answer.toLowerCase().trim() == correct) {
            button.style.backgroundColor =
                getComputedStyle(button).getPropertyValue("--correct");
            answerField.style.color =
                getComputedStyle(button).getPropertyValue("--correct");
            answerField.innerHTML = "Correct!";
        } else {
            button.style.backgroundColor =
                getComputedStyle(button).getPropertyValue("--incorrect");
            answerField.style.color =
                getComputedStyle(button).getPropertyValue("--incorrect");
            answerField.innerHTML = "Incorrect";
            setTimeout(() => {
                reset(button);
            }, 1000);
        }
    };
}

getAnswerMC("0:1");
getAnswerMC("1:3");
getAnswerMC("2:0");
getAnswerFR("fr0", "sarajevo");
getAnswerFR("fr1", "cambridge");
getAnswerFR("fr2", "maori");
