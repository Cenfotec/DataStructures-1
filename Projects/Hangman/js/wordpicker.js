let pOneWordH1 = document.querySelector('#pOneWordH1');
let pTwoWordH1 = document.querySelector('#pTwoWordH1');

let pOneInputWord = document.querySelector('#pOneInputWord');
let pTwoInputWord = document.querySelector('#pTwoInputWord');
let pOneButton = document.querySelector('#pOneButton');
let pTwoButton = document.querySelector('#pTwoButton');
let playGameButton = document.querySelector('#playGameButton');

let pOneWOne = document.querySelector('#pOneWOne');
let pOneWTwo = document.querySelector('#pOneWTwo');
let pOneWThree = document.querySelector('#pOneWThree');

let pTwoWOne = document.querySelector('#pTwoWOne');
let pTwoWTwo = document.querySelector('#pTwoWTwo');
let pTwoWThree = document.querySelector('#pTwoWThree');

let playerOneWords = new Cola();
let playerTwoWords = new Cola();

pOneButton.addEventListener('click', addWordToList);
pTwoButton.addEventListener('click', addWordToList);

playGameButton.addEventListener('click', loadGameScene)

function addWordToList() {
    if (this.getAttribute('data-player') == 'one') {
        if (validateWordPOneInput()) {
            addWordToWordBox('one', pOneInputWord.value.trim());
        }     
    } else if (this.getAttribute('data-player') == 'two') {
        if (validateWordPTwoInput()) {
            addWordToWordBox('two', pTwoInputWord.value.trim());
        }      
    }
}

function addWordToWordBox(player, word) {

    if (player == 'one') {
        if (pOneWOne.innerText == '1.') {
            pOneWOne.innerText = '1. ' + word.replace(/./g, '*');
            playerOneWords.push(pOneInputWord.value.trim())
        } else if (pOneWTwo.innerText == '2.') {
            pOneWTwo.innerText = '2. ' + word.replace(/./g, '*');
            playerOneWords.push(pOneInputWord.value.trim())
        } else if (pOneWThree.innerText == '3.') {
            pOneWThree.innerText = '3. ' + word.replace(/./g, '*');
            playerOneWords.push(pOneInputWord.value.trim())
        }
        pOneInputWord.value = '';
    } else if (player == 'two') {
        if (pTwoWOne.innerText == '1.') {
            pTwoWOne.innerText = '1. ' + word.replace(/./g, '*');
            playerTwoWords.push(pTwoInputWord.value.trim())
        } else if (pTwoWTwo.innerText == '2.') {
            pTwoWTwo.innerText = '2. ' + word.replace(/./g, '*');
            playerTwoWords.push(pTwoInputWord.value.trim())
        } else if (pTwoWThree.innerText == '3.') {
            pTwoWThree.innerText = '3. ' + word.replace(/./g, '*');
            playerTwoWords.push(pTwoInputWord.value.trim())
        }
        pTwoInputWord.value = '';
    }
}

function loadGameScene() {
    createGame();
    
    document.querySelector('#nameSelectionSection').style.display = 'none';
    document.querySelector('#wordSelectionSection').style.display = 'none';
    document.querySelector('#gameDiv').style.display = 'block';

    setUpGame();
}

function createGame() {
    let players = storagePlayers;
    players[0].words = playerOneWords;
    players[1].words = playerTwoWords;
    storagePlayers = players;


    let rounds = new Lista();

    let round1 = new Round(1, players[0], players[1], players[0].words.pop());
    let round2 = new Round(2, players[1], players[0], players[1].words.pop());

    let round3 = new Round(3, players[0], players[1], players[0].words.pop());
    let round4 = new Round(4, players[1], players[0], players[1].words.pop());

    let round5 = new Round(5, players[0], players[1], players[0].words.pop());
    let round6 = new Round(6, players[1], players[0], players[1].words.pop());
   
    rounds.add(round1);
    rounds.add(round2);
    rounds.add(round3);
    rounds.add(round4);
    rounds.add(round5);
    rounds.add(round6);

    let games = storageGames;
    let id = games.size()+1;

    let game = new Game(id, rounds);
    games.push(game);
    storageGames = games;
}

function validateWordPOneInput() {
    let valid = true;
    if (pOneInputWord.value.trim() == '') {
        valid = false;
        pOneInputWord.style.border = '1px solid red';
    }
    return valid;
}

function validateWordPTwoInput() {
    let valid = true;
    if (pTwoInputWord.value.trim() == '') {
        valid = false;
        pTwoInputWord.style.border = '1px solid red';
    }
    return valid;
}