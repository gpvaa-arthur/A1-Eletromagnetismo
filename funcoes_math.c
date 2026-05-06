//
// Created by Arthur on 22/04/2026.
//

#include <time.h>

#include "def.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "mtwister.h"

vetor calcVetorDistancia(vetor v1, vetor v2) {
    vetor dist = {
        v2.x-v1.x,
        v2.y-v1.y,
        v2.z-v1.z
    };
    return dist;
}

double calcVetorModulo(vetor v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}
vetor calcVetorUnit(vetor v, double modulo){
    vetor vetorUnit = {
        v.x/modulo,
        v.y/modulo,
        v.z/modulo
    };
    return vetorUnit;
}

vetor calcSomaVetorial(vetor v1, vetor v2) {
    vetor soma = {
        v1.x+v2.x,
        v1.y+v2.y,
        v1.z+v2.z
    };
    return soma;
}

vetor calcCampoEletrico(vetor d, double Q) {
    double modVetor = calcVetorModulo(d);
    vetor vetorUnit = calcVetorUnit(d, modVetor);
    double campoModulo = K *Q/(modVetor*modVetor);

    vetor campoEletrico ={
        vetorUnit.x*campoModulo,
        vetorUnit.y*campoModulo,
        vetorUnit.z*campoModulo
    };
    return campoEletrico;
}
vetor calcForcaEletrica(vetor v, double q) {
    v.x *= q;
    v.y *= q;
    v.z *= q;
    return v;
}

double simpson_13(intgD1 D1, double (*f)(double), int N) {
    if (N%2 != 0) N++;

    double h =(D1.b - D1.a)/ N;
    double soma = f(D1.a) + f(D1.b);

    for (int i=1; i<N; i++) {
        double x = D1.a + i*h;

        if (i% 2 != 0) {
            soma += 4 * f(x);
        }
        else {
            soma += 2 * f(x);
        }
    }
    return (h/3.0) *soma;
}

double monte_carlo_2D(intgD2 D2, double (*f)(double, double), int N) {
    MTRand random = seedRand(1042);
    int i;
    double soma = 0.0;
    double funcao;

    printf("phi: [%lf, %lf] | z: [%lf, %lf] \n", D2.a, D2.b, D2.c, D2.d);
    for (i=0; i<N;i++) {
        double x = D2.a + genRand(&random)*(D2.b-D2.a);
        double y = D2.c + genRand(&random)*(D2.d-D2.c);

        //Função a ser integrada:
        funcao = f(x,y);

        soma+= funcao;

    }
    double volume_espaço = (D2.b-D2.a)*(D2.d-D2.c);

    return (soma/N) * volume_espaço;

}


double monte_carlo_3D(intgD3 D3, double (*f)(double, double, double), int N) {
   MTRand random = seedRand(1042);
   int i;
   double soma = 0.0;
   double funcao;

   printf("Limites: r: [%f, %f] | th: [%f, %f] | phi: [%f, %f]\n", D3.a, D3.b, D3.c, D3.d, D3.e, D3.f);

    for (i =0; i<N;i++) {
        double r = D3.a + genRand(&random)*(D3.b-D3.a);
        double th = D3.c + genRand(&random)*(D3.d-D3.c);
        double phi = D3.e + genRand(&random)*(D3.f-D3.e);

        //Função a ser integrada
        funcao =  f(r, th, phi); // Questão 6

        soma += funcao;
    }

    double volume_espaço = (D3.b-D3.a) * (D3.d-D3.c) * (D3.f-D3.e);

    return (soma/N) * volume_espaço;
}