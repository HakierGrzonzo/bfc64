label():
    jsr $ffcf
    cmp #$00
    beq label()
    sta ($fb),y
