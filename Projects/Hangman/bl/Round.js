class Round {
    constructor(id, playerWithWord, playerWhoGuesses, word) {
        this.id = id;
        this.playerWithWord = playerWithWord;
        this.playerWhoGuesses = playerWhoGuesses;
        this.word = word;
        this.winner = null;
        this.finished = false;
    }
}