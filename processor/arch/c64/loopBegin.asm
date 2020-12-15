loopBegin():
    lda ($fb),x
    cmp #$00
    beq loopEnd()
