//
// Created by Arthur on 22/04/2026.
//

#ifndef AT1ELETROMAG_DEF_H
#define AT1ELETROMAG_DEF_H

#define K 8.987e9

typedef struct vetor { // Armazena componentes x,y,z
        double x;
        double y;
        double z;
} vetor;


typedef struct intgD1 {
        double a;
        double b;
}intgD1;

typedef struct intgD2{
        //1
        double a;
        double b;
        //2
        double c;
        double d;

}intgD2;

typedef struct intgD3{
        //1
        double a;
        double b;
        //2
        double c;
        double d;
        //3
        double e;
        double f;

}intgD3;

// Funções para manipulações vetoriais:
vetor calcVetorDistancia(vetor v1, vetor v2);
vetor calcVetorUnit(vetor v, double modulo);
double calcVetorModulo(vetor v);
vetor calcSomaVetorial(vetor v1, vetor v2);

vetor calcCampoEletrico(vetor d, double Q);
vetor calcForcaEletrica(vetor v, double q);

//Calculo de integral em diferentes dimensões:

double simpson_13(intgD1 D1, double (*f)(double), int N);
double monte_carlo_2D(intgD2 D2, double (*f)(double, double), int N);
double monte_carlo_3D(intgD3 D3, double(*f)(double, double, double), int N);

#endif //AT1ELETROMAG_DEF_H