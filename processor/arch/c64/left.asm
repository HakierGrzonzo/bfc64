    cpy #$00
    bne label()
    dec $00fb + 1 // decrament least significant byte of pointer, if you need more than 256 * 256 cells, please reconsider your life choices
label():
    dey
