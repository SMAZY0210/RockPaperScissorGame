// THIS CODE WAS CREATED BY SMAZY0210
let person = prompt("Please enter your name");

if (person != null) {
  person = person.trimStart("");
  document.getElementById("username").innerHTML =
    person.charAt(0).toUpperCase() + person.slice(1) + "'s score: ";
}
const options = ["ROCK", "PAPER", "SCISSOR"];

let pcschoice, plrchoice, result;

let round = 0,
  pc_score = 0,
  plr_score = 0,
  draw = 0;

function plar() {
  if (plrchoice == "ROCK") {
    document.getElementById("plr").src = "img/rock.png";
  } else if (plrchoice == "PAPER") {
    document.getElementById("plr").src = "img/paper.png";
  } else if (plrchoice == "SCISSOR") {
    document.getElementById("plr").src = "img/scissors.png";
  }
}
function pc() {
  if (pcschoice == "ROCK") {
    document.getElementById("pc").src = "img/rock-reversed.png";
  } else if (pcschoice == "PAPER") {
    document.getElementById("pc").src = "img/paper-reversed.png";
  } else if (pcschoice == "SCISSOR") {
    document.getElementById("pc").src = "img/scissors-reversed.png";
  }
}
function game(clid) {
  pcschoice = options[Math.floor(Math.random() * 3)];
  plrchoice = clid;
  plar();
  pc();
  if (pcschoice == plrchoice) {
    round++;
    draw++;
    result = "Round Draw";
  } else if (
    (pcschoice == "SCISSOR" && plrchoice == "ROCK") ||
    (pcschoice == "ROCK" && plrchoice == "PAPER") ||
    (pcschoice == "PAPER" && plrchoice == "SCISSOR")
  ) {
    round++;
    result = "Player Won";
    plr_score += 1;
  } else if (
    (pcschoice == "ROCK" && plrchoice == "SCISSOR") ||
    (pcschoice == "PAPER" && plrchoice == "ROCK") ||
    (pcschoice == "SCISSOR" && plrchoice == "PAPER")
  ) {
    round++;
    result = "PC Won";
    pc_score += 1;
  }

  document.getElementById("RoundResult").innerHTML = result;
  document.getElementById("round").innerHTML = round;
  document.getElementById("pcscr").innerHTML = pc_score;
  document.getElementById("plrscr").innerHTML = plr_score;
  document.getElementById("draw").innerHTML = draw;
}

function end() {
  document.body.innerHTML =
    "THANKS for playing this rock paper scissor game developed by SMAZY0210";
}
