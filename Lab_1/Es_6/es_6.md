## Esercizio 6

Scrivere un programma per classificare un triangolo. Data la lunghezza dei tre
lati, il programma deve determinare innanzitutto se questi siano in grado di
formare un triangolo, se si allora deve determinare di che tipo: isoscele,
equilatero, scaleno.
Infine, il programma deve determinare se il triangolo è rettangolo.  

INPUTS: 3 numeri interi, variabili A,B,C
OUTPUT: Caratterizzazione del triangolo (messaggio di testo a video)

CONDIZIONI DA CONTROLLARE

Perché sia un triangolo, tre condizioni devono essere verificate:

1) A < B + C
2) B < A + C
3) C < A + B

Caratterizzazione del triangolo:

A = B = C equilatero
A = B oppure A = C oppure B = C isoscele
A != B != C scaleno

Per verificare che il triangolo sia rettangolo, le seguenti condizioni devono
essere verificate:

1) A*A = B*B + C*C
2) B*B = A*A + C*C
3) C*C = A*A + B*B
