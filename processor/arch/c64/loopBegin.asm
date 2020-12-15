loopBegin():
    lda ($fb),x
    cmp #$00
    bne label()
    jmp loopEnd()
label():
