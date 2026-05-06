#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "def.h"

void questao1_1() {
    // Item a
    vetor vQ1 = {2,0,4}; // 5nC
    vetor vQ2 = {-3,0,5}; // -2nC

    vetor vq = {1,-3,7}; // 1 nC

    vetor vd1 = calcVetorDistancia(vQ1, vq);
    vetor vd2 = calcVetorDistancia(vQ2, vq);

    vetor fel1 = calcForcaEletrica(
        calcCampoEletrico(vd1, 5e-9),
        1e-9);

    vetor fel2 = calcForcaEletrica(
        calcCampoEletrico(vd2, -2e-9),
        1e-9);

    vetor Fres = calcSomaVetorial(fel1, fel2);

    printf("Questao 1)\n");
    printf("Item a (Forca eletrica):\n");
    printf("Componente x: %.15le [N]\n", Fres.x);
    printf("Componente y: %.15le [N]\n", Fres.y);
    printf("Componente z: %.15le [N]\n", Fres.z);

    // Item B

    vetor Eres ={
        Fres.x/1e-9,
        Fres.y/1e-9,
        Fres.z/1e-9
    };
    printf("\n");
    printf("Item b (Campo eletrico):\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);
}

double funcao_Q6(double r, double th, double phi) {
    double dV = r * r * sin(th); // Jacobiano
    return 10 * (r - 4) * (r - 5) * sin(th) * sin(phi / 2.0) * dV;
}

void questao1_6() {
    printf("Questao 6)\n");
    intgD3 limites ={4,5,0,(25.0/180)*M_PI, (0.9*M_PI), (1.1*M_PI)};
    printf("Q = %.5le [C]\n\n", monte_carlo_3D(limites, funcao_Q6, 1e6));
}

void questao1_7() {
    vetor vQ1 = {1,2,1};
    vetor vQ2 = {-1,0,2};
    vetor vQ3 = {2,1,3};

    vetor d13 = calcVetorDistancia(vQ1, vQ3);
    vetor d23 = calcVetorDistancia(vQ2, vQ3);

    vetor fel1 = calcForcaEletrica(
        calcCampoEletrico(d13, 2e-6),
        -3e-6);

    vetor fel2 = calcForcaEletrica(
        calcCampoEletrico(d23, -4e-6),
        -3e-6);

    vetor Fres = calcSomaVetorial(fel1, fel2);

    printf("Questao 7)\n");
    printf("Componente x: %.5le [N]\n", Fres.x);
    printf("Componente y: %.5le [N]\n", Fres.y);
    printf("Componente z: %.5le [N]\n\n", Fres.z);
}

double funcao_Q9a(double x) {
   return 12* x * x * 1e-3;
}

double funcao_Q9b(double r, double z) {
    double dS = 3; // Jacobiano
    return 3 * z * z *1e-9 * dS;
}

double funcao_Q9c(double r, double th, double phi) {
    double dV = r * r * sin(th); // Jacobiano
    return 10/(r*sin(th)) * dV;
}

void questao1_9() {
    printf("Questao 9)\n");

    //Item a
    printf("Item a)\n");
    intgD1 limites = {0,5};
    printf("Q = %.5le C\n", simpson_13(limites, funcao_Q9a, 100));


    //Item b:
    printf("Item b)\n");
    intgD2 limites2 = {0, 2*M_PI, 0,4};
    printf("Q = %.5le C\n", monte_carlo_2D(limites2, funcao_Q9b, 1e6));


    //Item c:
    printf("Item c)\n");
    intgD3 limites3 = {0,4,0,M_PI,0, 2*M_PI};
    printf("Q = %.5le C\n\n", monte_carlo_3D(limites3, funcao_Q9c, 1e7));
}

void questao1_10() {
    vetor vQ1 = {-2,2,0}; // +Q
    vetor vQ2 = {-2, -2,0}; // -2Q
    vetor vQ3 = {2, -2,0}; // -Q
    vetor vQ4 = {2,2,0}; // +2Q

    vetor ponto = {0,0,6};

    vetor vd1 = calcVetorDistancia(vQ1, ponto);
    vetor vd2 = calcVetorDistancia(vQ2, ponto);
    vetor vd3 = calcVetorDistancia(vQ3, ponto);
    vetor vd4 = calcVetorDistancia(vQ4, ponto);

    vetor ce1 = calcCampoEletrico(vd1, 15 *1e-6);
    vetor ce2 = calcCampoEletrico(vd2, -30 *1e-6);
    vetor ce3 = calcCampoEletrico(vd3, -15 *1e-6);
    vetor ce4 = calcCampoEletrico(vd4, 30 *1e-6);

    vetor Eres = calcSomaVetorial(
        calcSomaVetorial(ce1, ce2),
        calcSomaVetorial(ce3,ce4)
        );

    printf("Questao 10)\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);
}

void questao1_12(){
    vetor dist = {1,1,2};
    vetor Eres = calcCampoEletrico(dist, -1e-8);

    printf("Questao 12)\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);
}

void questao2() {
    double carga1 = (10.0/10)*1e-6;

    vetor ponto = {0,10,0};

    double passo = 1.0/10;
    double posicao = -0.5 +(passo/2.0);

    vetor Eres = {0,0,0};
    int i;
    for (i=0;i<10;i++) {
        vetor vQ = {0,0,posicao};

        vetor dist = calcVetorDistancia(vQ, ponto);
        Eres = calcSomaVetorial(Eres, calcCampoEletrico(dist, carga1));
        posicao += passo;
    }

    printf("Questao 2)\n");
    printf("Teste com 10 cargas:\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);

    // Para 15 cargas
    double carga2 = (10.0/15)*1e-6;
    passo = 1.0/15;
    posicao = -0.5 +(passo/2.0);

    Eres.x = 0.0;
    Eres.y = 0.0;
    Eres.z = 0.0;


    for (i=0;i<15;i++) {
        vetor vQ = {0,0,posicao};
        vetor dist = calcVetorDistancia(vQ, ponto);
        Eres = calcSomaVetorial(Eres, calcCampoEletrico(dist, carga2));
        posicao += passo;
    }
    printf("Teste com 15 cargas:\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);

    // Para 30 cargas
    double carga3 = (10.0/30)*1e-6;
    passo = 1.0/30;
    posicao = -0.5 +(passo/2.0);

    Eres.x = 0.0;
    Eres.y = 0.0;
    Eres.z = 0.0;


    for (i=0;i<30;i++) {
        vetor vQ = {0,0,posicao};
        vetor dist = calcVetorDistancia(vQ, ponto);
        Eres = calcSomaVetorial(Eres, calcCampoEletrico(dist, carga3));
        posicao += passo;
    }
    printf("Teste com 30 cargas:\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);

}
void questao3() {
    double carga1 = (10.0/10)*1e-6;

    vetor ponto = {0,0,10};

    double passo = (2*M_PI)/10;
    double posicao = 0;
    double R = 0.159;

    vetor Eres = {0,0,0};
    int i;
    for (i=0;i<10;i++) {
        vetor vQ = {R*cos(posicao),R*sin(posicao),0};
        vetor dist = calcVetorDistancia(vQ, ponto);
        Eres = calcSomaVetorial(Eres, calcCampoEletrico(dist, carga1));
        posicao += passo;
    }
    printf("Questao 3)\n");
    printf("Teste com 10 cargas:\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);

    double carga2 = (10.0/15)*1e-6;

     passo = (2*M_PI)/15;
     posicao = 0;

    Eres.x = 0.0;
    Eres.y = 0.0;
    Eres.z = 0.0;

    for (i=0;i<15;i++) {
        vetor vQ = {R*cos(posicao),R*sin(posicao),0};
        vetor dist = calcVetorDistancia(vQ, ponto);
        Eres = calcSomaVetorial(Eres, calcCampoEletrico(dist, carga2));
        posicao += passo;
    }

    printf("Teste com 15 cargas:\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);

    double carga3 = (10.0/30)*1e-6;

    passo = (2*M_PI)/30;
    posicao = 0;

    Eres.x = 0.0;
    Eres.y = 0.0;
    Eres.z = 0.0;

    for (i=0;i<30;i++) {
        vetor vQ = {R*cos(posicao),R*sin(posicao),0};
        vetor dist = calcVetorDistancia(vQ, ponto);
        Eres = calcSomaVetorial(Eres, calcCampoEletrico(dist, carga3));
        posicao += passo;
    }

    printf("Teste com 30 cargas:\n");
    printf("Componente x: %.5le [V/m]\n", Eres.x);
    printf("Componente y: %.5le [V/m]\n", Eres.y);
    printf("Componente z: %.5le [V/m]\n\n", Eres.z);

}

int main(void) {
   questao1_1();
   questao1_6();
   questao1_7();
   questao1_9();
   questao1_10();
   questao1_12();

   questao2();
   questao3();

   getchar();
    return 0;
}
