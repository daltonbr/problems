#include <stdio.h>
#include <math.h>

typedef struct {
	int qde;		// quantidade de jogadores no ataque
	int jog[11];	// lista de jogadores
	int avancado;
} Ataque; 

typedef struct {
    int qde;     	// quandidade de jogadores na defesa
    int jog[11];    // lista de jogadores
    int recuado1;
    int recuado2;
} Defesa;

// Function declarations

void carregaAtaque(Ataque *, int);	 // monta o time de ataque
void organizaAtaque(Ataque *, int ); // encontra atacante mais avançado
void carregaDefesa(Defesa *, int);	 // monta o time de defesa
void organizaDefesa(Defesa *, int);  // encontra os dois defensores mais recuados
char lance(Ataque, Defesa);          // verifica se tem impedimento na jogada

// Function Development

void carregaAtaque(Ataque *a, int qde) {
	int i;
	a->qde = qde;
	for (i=0; i<a->qde; i++) {
		scanf("%d", &a->jog[i]);
	}
}

void organizaAtaque(Ataque *a, int qde) { // ao avançar na disciplina, usar método de ordenação aprendido no vetor
	int i;
	a->avancado = a->jog[0];
	for (i=1; i<a->qde; i++) {
		if (a->jog[i] > a->avancado) a->avancado = a->jog[i];
	}
}

void carregaDefesa(Defesa *d, int qde) {
	int i;
	d->qde = qde;
	for (i=0; i<d->qde; i++) {
		scanf("%d", &d->jog[i]);
	}
}

void organizaDefesa(Defesa *d, int qde) { // ao avançar na disciplina, usar método de ordenação aprendido no vetor
	int i;
	if (d->jog[0] < d->jog[1]) {
		    d->recuado1 = d->jog[0];
    		d->recuado2 = d->jog[1];
	}
	else {
		    d->recuado1 = d->jog[1];
    		d->recuado2 = d->jog[0];
	}
	for (i=2; i<d->qde; i++) {
		if (d->jog[i] < d->recuado2) {
			if (d->jog[i] <= d->recuado1) {
				d->recuado2 = d->recuado1;
				d->recuado1 = d->jog[i];
			}
			else
				d->recuado2 = d->jog[i];
		} 
	}
}

char lance(Ataque a, Defesa d) {
	if (a.avancado < d.recuado2) return 'Y';
	else                         return 'N';
} 


// main
int main()
{
    Ataque timeA; 
    Defesa timeD;
	char impedido;
	int QdeA, QdeD;
	
    while (1){
    	scanf("%d %d", &QdeA, &QdeD);
    	if (QdeA == 0) break;
    	
    	carregaAtaque(&timeA, QdeA);
    	organizaAtaque(&timeA, QdeA);
    	
    	carregaDefesa(&timeD, QdeD);
    	organizaDefesa(&timeD, QdeD);
    	
    	impedido = lance(timeA, timeD);
    	printf("%c\n", impedido);
    }
 
    return 0;
}
