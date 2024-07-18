const wrapper = document.querySelectorAll(".cardWrap");

wrapper.forEach((element) => {
    let state = {
        mouseX: 0,
        mouseY: 0,
        height: element.clientHeight,
        width: element.clientWidth,
    };

    element.addEventListener("mousemove", (ele) => {
        const card = element.querySelector(".card");
        const cardBg = card.querySelector(".card-img-top");
        state.mouseX = ele.pageX - element.offsetLeft - state.width / 2;
        state.mouseY = ele.pageY - element.offsetTop - state.height / 2;

        // parallax angle in card
        const angleX = (state.mouseX / state.width) * 30;
        const angleY = (state.mouseY / state.height) * -30;
        card.style.transform = `rotateY(${angleX}deg) rotateX(${angleY}deg) `;
    });

    element.addEventListener("mouseout", () => {
        const card = element.querySelector(".card");
        card.style.transform = `rotateY(0deg) rotateX(0deg) `;
    });
});
