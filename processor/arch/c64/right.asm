    cpx #$ff
    bne label()
    inc $00fb // decrament least significant byte of pointer, if you need more than 256 * 256 cells, please reconsider your life choices
label():
    inx
