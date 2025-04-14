; gini.asm
global modificar_indices_asm

section .text

; void modificar_indices_asm(DatosGini* datos, int cantidad)
modificar_indices_asm:
    push ebp
    mov ebp, esp

    mov esi, [ebp + 8]     ; puntero a datos
    mov ecx, [ebp + 12]    ; cantidad

.loop:
    cmp ecx, 0
    jle .fin

    ; accedemos al campo 'indice' que está después de 4 bytes (int year)
    fld dword [esi + 4]     ; cargar float
    fld1                    ; cargar 1.0
    faddp st1, st0          ; sumar y dejar en st0
    fstp dword [esi + 4]    ; guardar resultado

    add esi, 8              ; pasar a la siguiente estructura
    dec ecx
    jmp .loop

.fin:
    pop ebp
    ret
section .note.GNU-stack noalloc noexec nowrite progbits
