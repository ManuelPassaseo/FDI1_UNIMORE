.586
.model flat
.code

_assitoa proc
push ebp
mov ebp, esp
push esi
push edi
push ebx


mov ebx, dword ptr[ebp + 16] ;stringa
mov cl, byte ptr[ebp + 8]

call cifre

mov esi, eax
mov byte ptr[ebx + esi + 1], 0
mov ax, word ptr[ebp + 8]
mov dl, 10


Inizio:
	DEC esi
	CMP esi, -1
	JE Fine
	
	CBW
	IDIV dl
	mov byte ptr[ebx + esi], ah
	JMP Inizio
Fine:
	mov eax, 0

pop ebx
pop edi
pop esi
mov esp, ebp
pop ebp

ret

_assitoa endp

cifre proc

mov eax, ecx
mov esi, 0
mov edi, 10
A:	
	CMP EAX, 0
	JE B
	CDQ
	DIV edi
	INC esi
	JMP A
B:
	mov eax, esi

ret
cifre endp



end