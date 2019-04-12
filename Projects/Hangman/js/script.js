'use strict';


let body = document.querySelector('body');
let wordWrapper = document.querySelector('#wordWrapper');
let keysKB_1 = document.querySelector('#keyboardLine1').childNodes;
let keysKB_2 = document.querySelector('#keyboardLine2').childNodes;
let keysKB_3 = document.querySelector('#keyboardLine3').childNodes;
let tryCount = document.querySelector('#tryCount').childNodes[0];
let drawing = document.querySelector('#dMain');
let playerTurn = document.querySelector('#playerTurn');
let nextRoundScene = document.querySelector('#nextRoundScene');
let playAgainButton = document.querySelector('#playAgainButton');

nextRoundScene.addEventListener('click', nextRoundActionButton)
playAgainButton.addEventListener('click', playAgain);
body.addEventListener('keypress', pressKey);

function setUpGame() {
	gameActual = storageGames.top();
	roundActual = gameActual.rounds.get(0);
	word = roundActual.word;
	

	initialize();

	gameStarted = true;
}

function pressKey(e) {
	if (gameStarted) {
		let keyDiv;

		if (e.key != undefined) {
			keyDiv = document.querySelector('#key' + e.key.toUpperCase());
			try {
				keyDiv.classList.add('keyHover');
				setTimeout(function() {
					keyDiv.classList.add('keyActive');
				}, 50);
			} catch (e) { }
		
		
			checkLetter(e.key.toUpperCase());
		} else {
			keyDiv = this;
			keyDiv.classList.add('keyActive');
		
			checkLetter(keyDiv.innerText);
		}
	}
	
	
	
}

function allKeyListeners() {
	for (let i = 0; i < keysKB_1.length; i++) {
		keysKB_1[i].addEventListener('click', pressKey);
	}

	for (let i = 0; i < keysKB_2.length; i++) {
		keysKB_2[i].addEventListener('click', pressKey);
	}

	for (let i = 0; i < keysKB_3.length; i++) {
		keysKB_3[i].addEventListener('click', pressKey);
	}
}

/* ----------------------- */

// correctSpace | correctLetter

function generateSpaces() {
	let spaces = word.length;

	for (let i = 0; i < spaces; i++) {
		let wordDiv = document.createElement('div');
		wordDiv.classList.add('letterSpace');

		let wordSpan = document.createElement('span');
		wordSpan.classList.add('letter');

		wordDiv.appendChild(wordSpan);
		wordWrapper.appendChild(wordDiv);
		
	}
}

function checkLetter(key) {
	if (gameStarted) {
		let indexWord = [];
		let divLetter, spanLetter, allWordLetters, letterIndex;
		
			
		// CORRECT LETTER
		if (word.toUpperCase().includes(key)) {
			allWordLetters = document.querySelector('#wordWrapper').childNodes;
			for (let i = 0; i < word.length; i++) {
				if (word[i].toUpperCase() == key) {
					indexWord.push(i);
				}
			}
			for (let i = 0; i < indexWord.length; i++) {
				letterIndex = indexWord[i]
				divLetter = allWordLetters[letterIndex];
				if (divLetter != undefined) {
					spanLetter = divLetter.childNodes[0];
					divLetter.classList.add('correctSpace');
					spanLetter.classList.add('correctLetter');
					spanLetter.innerText = word[letterIndex];
					correct++;
					if (correct == word.length) {
						
						// Winner
						if (roundActual.id == 6) {
							endGame(0);
						} else {
							nextRound(0);
						}
					}
				}		
			}
		
		
	
	
	
	
	
		// MISSED LETTER
		} else {
			if (!lettersTried.includes(key)) {
				updateDrawing(key);
			}	
		}
	}
	
}


function updateDrawing(key) {
	// GAME OVER	
	if (misses == maxTries) {
		// Loser
		if (roundActual.id == 6) {
			endGame(1);
		} else {
			nextRound(1);
		}	

	// UPDATE MISSES
	} else {
		if (misses < maxMisses && correct < word.length) {
			misses++;
			lettersTried.push(key);
			tryCount.innerText = misses + "/" + maxMisses;
				

			let dStage = (misses == 1) ? 'dHead.png' : (misses == 2) ? 'dBody.png' :
						(misses == 3) ? 'dLeftArm.png' : (misses == 4) ? 'dRightArm.png' :
						(misses == 5) ? 'dLeftLeg.png' : 'dRightLeg.png';
			drawing.src = './img/' + dStage;

			if (misses == maxTries) {

				// Loser
				if (roundActual.id == 6) {
					endGame(1);
				} else {
					nextRound(1);
				}
				
			}
		}

	}
	
	
	
}

function initializeElements() {
	tryCount.innerText = misses + "/" + maxMisses;
}

function nextRound(winnerState) {
	updateRound(winnerState);
	nextRoundScene.style.display = 'block';
	document.querySelector('#roundWinnerH1').innerText = 'Winner: ' + roundActual.winner.name;

	// Update round actual
	roundActual = storageGames.top().rounds.get(roundActual.id);
}

function nextRoundActionButton() {
	updateStorage();
	initialize();
	document.querySelector('#nextRoundScene').style.display = 'none';
}


function updateRound(winnerState) {
	// 0 = won - 1 = lost
	if (winnerState == 0) {	
		roundActual.winner = roundActual.playerWhoGuesses;
	} else if (winnerState == 1) {
		roundActual.winner = roundActual.playerWithWord;
	}
	roundActual.finished = true;
	

	for (let i = 0; i < storageGames.top().rounds.size(); i++) {
		if (roundActual.id == (i+1)) {
			storageGames.top().rounds.get(i).winner = roundActual.winner;
			storageGames.top().rounds.get(i).finished = roundActual.finished;
		}
	}

	

	
	
}

function updateStorage() {
	word = roundActual.word;
	lettersTried = [];
	misses = 0;
	correct = 0;
	maxTries = 6;
	maxMisses = 6;
}

function initialize() {
	let keys = document.getElementsByClassName('key');
	for (let i = 0; i < keys.length; i++) {
		keys[i].classList.remove('keyHover', 'keyActive');
	}
	wordWrapper.innerHTML = '';

	playerTurn.innerText = roundActual.playerWhoGuesses.name + "'s turn";

	allKeyListeners();
	generateSpaces();
	initializeElements();

	drawing.src = './img/dMain.png';
}

function endGame(winnerState) {
	gameStarted = false;
	updateRound(winnerState);
	updateStorage();
	document.querySelector('#gameDiv').style.display = 'none';
	document.querySelector('#endGameSection').style.display = 'block';
	
	// Player one
	document.querySelector('#pOneNameH1').innerText = storagePlayers[0].name;

	// Calculate player one wins
	let pOneWins = 0;
	for (let i = 0; i < gameActual.rounds.size(); i++) {
		if (gameActual.rounds.get(i).winner == storagePlayers[0]) {
			pOneWins++;
		}
	}

	// Player two
	document.querySelector('#pTwoNameH1').innerText = storagePlayers[1].name;

	// Calculate player two wins
	let pTwoWins = 0;
	for (let i = 0; i < gameActual.rounds.size(); i++) {
		if (gameActual.rounds.get(i).winner == storagePlayers[1]) {
			pTwoWins++;
		}
	}

	// Compare wins
	if (pOneWins > pTwoWins) {
		storagePlayers[0].wins++;
	} else if (pOneWins < pTwoWins) {
		storagePlayers[1].wins++;
	} else if (pOneWins == pTwoWins) {
		document.querySelector('#endGameMessage').innerText = "It's a tie!";
	}

	// Set wins
	document.querySelector('#pOneTotalWinsH1').innerText = 'Wins: ' + storagePlayers[0].wins;
	document.querySelector('#pTwoTotalWinsH1').innerText = 'Wins: ' + storagePlayers[1].wins;

}

function playAgain() {
	document.querySelector('#endGameSection').style.display = 'none';
	document.querySelector('#wordSelectionSection').style.display = 'block';

	pOneWOne.innerText = '1.';
	pOneWTwo.innerText = '2.';
	pOneWThree.innerText = '3.';

	pTwoWOne.innerText = '1.';
	pTwoWTwo.innerText = '2.';
	pTwoWThree.innerText = '3.';
}