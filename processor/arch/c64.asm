BasicUpstart2(start)
*=$4000
start:
    //jsr $ff87
    jsr $ff81
    lda #$02
    sta $d020
    sta $d021
    lda #$01
    sta $0286
    jmp loop

msg:
    .text ">"

draw_text:
    ldx #$00

draw_loop:
    lda msg,x
    cmp #$00
    beq loop_end
    jsr $ffd2
    inx
    jmp draw_loop
loop_end:
    rts

loop:
    jsr draw_text
readkey:
    jsr $ffe4
    cmp #$00
    beq readkey
    jsr $ffd2
    jmp loop
