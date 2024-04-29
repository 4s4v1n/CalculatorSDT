 function hexCharacterToDecimal(character) {
    if (character === "A" || character === "a") {
        return 10
    }
    if (character === "B" || character === "b") {
        return 11
    }
    if (character === "C" || character === "c") {
        return 12
    }
    if (character === "D" || character === "d") {
        return 13
    }
    if (character === "E" || character === "e") {
        return 14
    }
    if (character === "F" || character === "f") {
        return 15
    }
    return Number(character)
}   
