let pOneInputName = document.querySelector('#pOneInputName');
let pTwoInputName = document.querySelector('#pTwoInputName');
let nextWordSelectionButton = document.querySelector('#nextWordSelectionButton');

nextWordSelectionButton.addEventListener('click', loadWordPickerScene)

function loadWordPickerScene() {
    if (validateNameInput()) {
        let playerOne = new Player(pOneInputName.value);
        let playerTwo = new Player(pTwoInputName.value);
        
        storagePlayers.push(playerOne);
        storagePlayers.push(playerTwo);
    
        document.querySelector('#nameSelectionSection').style.display = 'none';
        document.querySelector('#wordSelectionSection').style.display = 'block';
        document.querySelector('#gameDiv').style.display = 'none';
        document.querySelector('#nextRoundScene').style.display = 'none';
    
        pOneWordH1.innerText = storagePlayers[0].name;    
        pTwoWordH1.innerText = storagePlayers[1].name;
    }
}

function validateNameInput() {
    let valid = true;
    if (pOneInputName.value.trim() == '') {
        valid = false;
        pOneInputName.style.border = '1px solid red';
    }
    if (pTwoInputName.value.trim() == '') {
        valid = false;
        pTwoInputName.style.border = '1px solid red';
    }
    return valid;
}
    