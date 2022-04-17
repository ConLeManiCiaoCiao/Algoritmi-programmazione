## Esercizio 1

Si scriva un programma in C che:

1. legga da tastiera ( per righe o per colonne, a scelta) una matrice quadrata di dimensione uguale a 5x5.

2. rintracci se tale matrice contiene delle sequenze di elementi adiacenti uguali a zero di lunghezza uguale o maggiore di 3 ( in orizzontale o verticale).

3. visualizzi l'indice di riga ( o colonna) in cui tali sequenze si presentano.



\
\
Esempio:

Sia la matrice seguente:

0 0 0 4 5

1 2 0 4 5

1 0 0 4 0

1 2 3 4 5

1 0 0 0 0


La sequenza di valori "0 0 0" compare nella prima e nell'ultima riga e nella terza colonna e quindi occorre riportare una indicazione del tipo:

\
La sequenza compare nella riga 1

La sequenza compare nella riga 5

La sequenza compare nella colonna 3

Si osservi che la riga 3 non contiene la sequenza indicata in quanto i tre zeri non si
trovano in posizioni contigue.
