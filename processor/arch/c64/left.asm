    cpx #$00
    bne label()
    dec $00fb // decrament least significant byte of pointer, if you need more than 256 * 256 cells, please reconsider your life choices
label():
    dex
