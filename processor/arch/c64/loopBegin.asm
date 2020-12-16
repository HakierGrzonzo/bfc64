loopBegin():
    lda ($fb),y
    cmp #$00
    bne label()
    jmp loopEnd()
label():
