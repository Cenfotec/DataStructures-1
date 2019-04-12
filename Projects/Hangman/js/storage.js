document.querySelector('#nameSelectionSection');
document.querySelector('#wordSelectionSection').style.display = 'none';
document.querySelector('#gameDiv').style.display = 'none';
document.querySelector('#nextRoundScene').style.display = 'none';
document.querySelector('#endGameSection').style.display = 'none';

let storagePlayers = [];
let storageGames = new Pila();
let gameActual;
let roundActual;

let gameStarted = false;
let word = '';
let lettersTried = [];
let misses = 0;
let correct = 0;
let maxTries = 6;
let maxMisses = 6;