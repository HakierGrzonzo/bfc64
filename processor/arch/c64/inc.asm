    lda ($fb),x
    cmp #$ff
    beq label()
    inc ($fb),x
label():
