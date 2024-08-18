document.addEventListener("DOMContentLoaded", (event) => {
    gsap.registerPlugin(TextPlugin, Flip, ScrollTrigger, Observer, ScrollToPlugin, Draggable, MotionPathPlugin, EaselPlugin, PixiPlugin, TextPlugin, RoughEase, ExpoScaleEase, SlowMo, CustomEase)
    // gsap code here!
});

let tween1 = gsap.to("#box1", {
    x: 500,
    y: 225,
    duration: 3,
    rotation: 360,
    repeat: 2, //repeat and yoyo work together
    yoyo: true,
    ease: "power1.inout",
    // runBackwards: true,
    startAt: { x: -500 },
    opacity: 0.5,
    scale: 2,
    backgroundColor: "pink",
    color: "black",
    paused: true
    // onComplete : can do anything here like calling a function or something else
})

document.getElementById("play").addEventListener("click", () => {
    tween1.play()
})
document.getElementById("pause").addEventListener("click", () => {
    tween1.pause()
})

let t1 = gsap.timeline({});
t1.to("#box2", { x: 500, duration: 3 }) //similar to gsap.to
t1.to("#box3", { x: 500, duration: 3 }) //now these events occur one after the other
//if we write t1.to("#box3", { x: 500, duration: 3 }, 2 ) then it will override everything and begin the box3 animation at 2s after start of timeline
//if we write t1.to("#box3", { x: 500, duration: 3 }, "-=1") then it will override everything and begin the animation of box3 1s before the animation of previous element ends, we can di +=1 similarly

let tween2 = gsap.to("#box6", {
    scrollTrigger: {
        trigger: "#box6",
        markers: true, //used for debugging
        toggleActions: "play pause resume reset", //this is the best structure
        start: "top center",
        end: "bottom 500px"
    },
    delay: 0.5,
    x: 500,
    duration: 3,
    ease: "power1.inout"
})

let tween3 = gsap.to("#box10", {
    scrollTrigger: {
        trigger: "#box10",
        markers: true, //used for debugging
        toggleActions: "play pause resume reset", //this is the best structure
        scrub: 3, //vaise to true rakhte hain ise, but increasing number means smoother and smoother
        start: "top 600px",
        end: "bottom 300px"
    },
    delay: 0.5,
    x: 500,
    duration: 3,
    ease: "power1.inout"
})

let t2 = gsap.timeline();

let tween4 = t2.to("#headingMessage", {
    delay: 2,
    duration: 3,
    color: "red",
    text: "Thanks to Nikhil I go to know it",
    ease: "power1.inout",
})

let tween5 = t2.to("#appearMessage", {
    delay: 2,
    duration: 3,
    color: "blue",
    text: "No I'm not gay",
    ease: "power1.inout",
    repeat : 3,
    yoyo : true
})