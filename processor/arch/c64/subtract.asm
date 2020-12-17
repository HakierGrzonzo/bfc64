    lda ($fb),y
    clc
    cmp #value()
    bcs label() //if lower than number
    lda #$00
    jmp label2()
label():
    sec
    sbc #value()
label2():
    sta ($fb),y
