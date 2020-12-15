    lda ($fb),x
    cmp #$00
    beq label()
    dec ($fb),x
label():
