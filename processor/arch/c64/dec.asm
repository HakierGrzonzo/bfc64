    lda ($fb),y
    cmp #$00
    beq label()
    clc
    sbc #$00
    sta ($fb),y
label():
