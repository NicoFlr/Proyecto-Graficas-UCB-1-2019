#include <vector>
#include <iostream>

#include "Vector3D.h"
#include "Esfera.h"
#include "ViewPlane.h"

#include "Utilitarios.h"
#include "Plano.h"
#include "Triangulo.h"
#include "LuzPuntual.h"
#include <algorithm> 
#include <math.h>

using namespace std;

double acotar(double n)
{
    if ( n > 1.0)
    {
        return 1.0;
    }
    else
    {
        return n;
    }
}

ColorRGB obtenerColorPixel(const Rayo& r, vector<ObjetoGeometrico*> objetos, LuzPuntual luz){
    
    ColorRGB color;

    color.r = 0.0;
    color.g = 0.0;
    color.b = 0.0;

    double t;
    double tmin = 2000000;    
    Vector3D n;
    Punto3D q;

    Vector3D h;
    for(int i = 0; i < objetos.size(); i++) {
        if( objetos[i]->hayImpacto(r, t, n, q) && t < tmin){
           // color.r = objetos[i]->obtenerColor().r;
           // color.g = objetos[i]->obtenerColor().g;
           // color.b = objetos[i]->obtenerColor().b;

            //h = ((-1)*r.d).hat();
            //color.r = acotar( 0.1 + luz.color.r * objetos[i]->obtenerColor().r * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            //color.g = acotar( 0.1 + luz.color.g * objetos[i]->obtenerColor().g * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));
            //color.b = acotar( 0.1 + luz.color.b * objetos[i]->obtenerColor().b * std::max(0.0, n * (luz.posicion - q).hat()) + luz.color.r * objetos[i]->obtenerColor().r * pow(max(0.0, n * h), 1000));

            //color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion-q).hat() );
            //color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion-q).hat() );
            //color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion-q).hat() );

            color.r = objetos[i]->obtenerColor().r * luz.color.r * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().r * luz.color.r * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            color.g = objetos[i]->obtenerColor().g * luz.color.g * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().g * luz.color.g * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
            color.b = objetos[i]->obtenerColor().b * luz.color.b * std::max(0.0, n * (luz.posicion - q).hat() ) + objetos[i]->obtenerColor().b * luz.color.b * pow(std::max(0.0, n * ((-1)*r.d + (luz.posicion - q).hat()).hat() ),10000);
           
            tmin = t;
        }
    }
    return color;
}

int main() {
    //LUZ
    LuzPuntual luz(1.0, 1.0, 1.0, 0, 0, -50);

    // ESCENA--------------------------------------------------------------------------------------------
    
    //Base
    //Triangulo principal
    Punto3D A(-275, -225, 0);
    Punto3D B(275, -225,0);
    Punto3D C(0, 400, 0);
    Triangulo t(A,C,B);
    t.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior izquierdo 1
    Punto3D ATII1(-275, -400, 0);
    Punto3D BTII1(-135, -225, 0);
    Punto3D CTII1(-275, -225, 0);
    Triangulo t2(ATII1,CTII1,BTII1);
    t2.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior izquierdo 2
    Punto3D ATII2(-275, -400, 0);
    Punto3D BTII2(-275, -225, 0);
    Punto3D CTII2(-300, -300, 0);
    Triangulo t3(ATII2,CTII2,BTII2);
    t3.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior izquierdo 3
    Punto3D ATII3(-275, -400, 0);
    Punto3D BTII3(-300, -300, 0);
    Punto3D CTII3(-300, -360, 0);
    Triangulo t4(ATII3,CTII3,BTII3);
    t4.establecerColor(1.0,0.2,0.7);
    
    //Triangulo inferior derecho 1
    Punto3D ATID1(275, -400, 0);
    Punto3D BTID1(275, -225, 0);
    Punto3D CTID1(135, -225, 0);
    Triangulo t5(ATID1,CTID1,BTID1);
    t5.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior derecho 2
    Punto3D ATID2(275, -400, 0);
    Punto3D BTID2(300, -300, 0);
    Punto3D CTID2(275, -225, 0);
    Triangulo t6(ATID2,CTID2,BTID2);
    t6.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior derecho 3
    Punto3D ATID3(275, -400, 0);
    Punto3D BTID3(300, -360, 0);
    Punto3D CTID3(300, -300, 0);
    Triangulo t7(ATID3,CTID3,BTID3);
    t7.establecerColor(1.0,0.2,0.7);

    //Triangulo inferior medio 1
    Punto3D ATIM1(-115, -300, 0);
    Punto3D BTIM1(135, -225, 0);
    Punto3D CTIM1(-135, -225, 0);
    Triangulo t8(ATIM1,CTIM1,BTIM1);
    t8.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior medio 2
    Punto3D ATIM2(115, -300, 0);
    Punto3D BTIM2(135, -225, 0);
    Punto3D CTIM2(-115, -300, 0);
    Triangulo t9(ATIM2,CTIM2,BTIM2);
    t9.establecerColor(1.0,0.2,0.7);
    //Triangulo inferior medio 3
    Punto3D ATIM3(0, -400, 0);
    Punto3D BTIM3(115, -300, 0);
    Punto3D CTIM3(-115, -300, 0);
    Triangulo t10(ATIM3,CTIM3,BTIM3);
    t10.establecerColor(1.0,0.2,0.7);
    //---------------------------------------------------------------------------------------------------------------------
    //Cuerpo IZQUIERDO
    Punto3D ACI1(0, 290, 35);
    Punto3D BCI1(0, 400, 0);
    Punto3D CCI1(-25, 335, 0);
    Triangulo tci1(ACI1,CCI1,BCI1);
    tci1.establecerColor(1.0,0.1,0.9);

    Punto3D ACI2(0, 190, 100);
    Punto3D BCI2(25, 335, 0);
    Punto3D CCI2(-25, 335, 0);
    Triangulo tci2(ACI2,CCI2,BCI2);
    tci2.establecerColor(1.0,0.1,0.9);

    Punto3D ACI3(0, 190, 100);
    Punto3D BCI3(-25, 335, 0);
    Punto3D CCI3(-60, 265, 0);
    Triangulo tci3(ACI3,CCI3,BCI3);
    tci3.establecerColor(1.0,0.1,0.9);

    Punto3D ACI4(0, -195, 40);
    Punto3D BCI4(0, 190, 100);
    Punto3D CCI4(-90, -113, 40);
    Triangulo tci4(ACI4,CCI4,BCI4);
    tci4.establecerColor(1.0,0.1,0.9);

    Punto3D ACI5(-60, -25, 0);
    Punto3D BCI5(0, 190, 100);
    Punto3D CCI5(-60, 265, 0);
    Triangulo tci5(ACI5,CCI5,BCI5);
    tci5.establecerColor(1.0,0.1,0.9);

    Punto3D ACI6(-50, 210, 25);
    Punto3D BCI6(-60, 218, 0);
    Punto3D CCI6(-108, 175, 0);
    Triangulo tci6(ACI6,CCI6,BCI6);
    tci6.establecerColor(1.0,0.1,0.9);

    Punto3D ACI7(-98, 167, 25);
    Punto3D BCI7(-50, 210, 25);
    Punto3D CCI7(-108, 175, 0);
    Triangulo tci7(ACI7,CCI7,BCI7);
    tci7.establecerColor(1.0,0.1,0.9);

    Punto3D ACI8(-85, 50, 68);
    Punto3D BCI8(-43, 180, 50);
    Punto3D CCI8(-83, 135, 50);
    Triangulo tci8(ACI8,CCI8,BCI8);
    tci8.establecerColor(1.0,0.1,0.9);

    //REVISAR LA ALTURA!!!!!
    Punto3D ACI9(-60, -25, 72);
    Punto3D BCI9(-43, 180, 50);
    Punto3D CCI9(-85, 50, 68);
    Triangulo tci9(ACI9,CCI9,BCI9);
    tci9.establecerColor(1.0,0.1,0.9);

    Punto3D ACI10(-90, -113, 72);
    Punto3D BCI10(-60, -25, 50);
    Punto3D CCI10(-85, 50, 68);
    Triangulo tci10(ACI10,CCI10,BCI10);
    tci10.establecerColor(1.0,0.1,0.9);

    Punto3D ACI11(-85, 50, 72);
    Punto3D BCI11(-83, 135, 50);
    Punto3D CCI11(-108, 175, 68);
    Triangulo tci11(ACI11,CCI11,BCI11);
    tci11.establecerColor(1.0,0.1,0.9);

    Punto3D ACI12(-120, 38, 72);
    Punto3D BCI12(-85, 50, 50);
    Punto3D CCI12(-108, 175, 68);
    Triangulo tci12(ACI12,CCI12,BCI12);
    tci12.establecerColor(1.0,0.1,0.9);

    Punto3D ACI13(-90, -113, 72);
    Punto3D BCI13(-85, 50, 50);
    Punto3D CCI13(-120, 38, 68);
    Triangulo tci13(ACI13,CCI13,BCI13);
    tci13.establecerColor(1.0,0.1,0.9);

    //Checkpoint

    Punto3D ACI14(-90, -113, 72);
    Punto3D BCI14(-120, 38, 50);
    Punto3D CCI14(-121, -25, 68);
    Triangulo tci14(ACI14,CCI14,BCI14);
    tci14.establecerColor(1.0,0.1,0.9);

    Punto3D ACI15(-125, -243, 72);
    Punto3D BCI15(-90, -113, 50);
    Punto3D CCI15(-121, -50, 68);
    Triangulo tci15(ACI15,CCI15,BCI15);
    tci15.establecerColor(1.0,0.1,0.9);

    Punto3D ACI16(0, -355, 72);
    Punto3D BCI16(0, -248, 50);
    Punto3D CCI16(-90, -113, 68);
    Triangulo tci16(ACI16,CCI16,BCI16);
    tci16.establecerColor(1.0,0.1,0.9);

    Punto3D ACI17(0, -355, 72);
    Punto3D BCI17(-90, -113, 50);
    Punto3D CCI17(-120, -220, 68);
    Triangulo tci17(ACI17,CCI17,BCI17);
    tci17.establecerColor(1.0,0.1,0.9);

    Punto3D ACI18(-121, -25, 72);
    Punto3D BCI18(-108, 175, 50);
    Punto3D CCI18(-305, -253, 68);
    Triangulo tci18(ACI18,CCI18,BCI18);
    tci18.establecerColor(1.0,0.1,0.9);

    Punto3D ACI19(-300, -305, 72);
    Punto3D BCI19(-121, -25, 50);
    Punto3D CCI19(-305, -253, 68);
    Triangulo tci19(ACI19,CCI19,BCI19);
    tci19.establecerColor(1.0,0.1,0.9);

    Punto3D ACI20(-124, -145, 72);
    Punto3D BCI20(-121, -25, 50);
    Punto3D CCI20(-300, -305, 68);
    Triangulo tci20(ACI20,CCI20,BCI20);
    tci20.establecerColor(1.0,0.1,0.9);

    Punto3D ACI21(-295, -381, 72);
    Punto3D BCI21(-124, -145, 50);
    Punto3D CCI21(-300, -305, 68);
    Triangulo tci21(ACI21,CCI21,BCI21);
    tci21.establecerColor(1.0,0.1,0.9);

    Punto3D ACI22(-125, -220, 72);
    Punto3D BCI22(-124, -145, 50);
    Punto3D CCI22(-295, -381, 68);
    Triangulo tci22(ACI22,CCI22,BCI22);
    tci22.establecerColor(1.0,0.1,0.9);

    Punto3D ACI23(-300, -305, 72);
    Punto3D BCI23(-321, -295, 68); //-305, -253, 50
    Punto3D CCI23(-305, -253, 50);
    Triangulo tci23(ACI23,CCI23,BCI23);
    tci23.establecerColor(1.0,0.1,0.9);

    Punto3D ACI24(-295, -381, 72);
    Punto3D BCI24(-330, -350, 68); //-300, -305, 50
    Punto3D CCI24(-300, -305, 50);
    Triangulo tci24(ACI24,CCI24,BCI24);
    tci24.establecerColor(1.0,0.1,0.9);

    Punto3D ACI25(-330, -350, 72);
    Punto3D BCI25(-300, -305, 68); //-300, -305, 50
    Punto3D CCI25(-321, -295, 50);
    Triangulo tci25(ACI25,CCI25,BCI25);
    tci25.establecerColor(1.0,0.1,0.9);










    //-------------------------------------------------------------------------------------------------------------------
    //Cuerpo DERECHO
    Punto3D ACD1(0, 290, 35);
    Punto3D BCD1(25, 335, 0);
    Punto3D CCD1(0, 400, 0);
    Triangulo tcd1(ACD1,CCD1,BCD1);
    tcd1.establecerColor(1.0,0.1,0.9);

    Punto3D ACD3(0, 190, 100);
    Punto3D BCD3(60, 265, 0);
    Punto3D CCD3(25, 335, 0);
    Triangulo tcd3(ACD3,CCD3,BCD3);
    tcd3.establecerColor(1.0,0.1,0.9);

    Punto3D ACD4(0, -195, 40);
    Punto3D BCD4(90, -113, 40); //0, 190, 100
    Punto3D CCD4(0, 190, 100);
    Triangulo tcd4(ACD4,CCD4,BCD4);
    tcd4.establecerColor(1.0,0.1,0.9);

    Punto3D ACD5(60, -25, 0);
    Punto3D BCD5(60, 265, 0); //0, 190, 100
    Punto3D CCD5(0, 190, 100);
    Triangulo tcd5(ACD5,CCD5,BCD5);
    tcd5.establecerColor(1.0,0.1,0.9);

    Punto3D ACD6(50, 210, 25);
    Punto3D BCD6(108, 175, 0); //60, 218, 0
    Punto3D CCD6(60, 218, 0);
    Triangulo tcd6(ACD6,CCD6,BCD6);
    tcd6.establecerColor(1.0,0.1,0.9);

    Punto3D ACD7(98, 167, 25);
    Punto3D BCD7(108, 175, 0); //50, 210, 25
    Punto3D CCD7(50, 210, 25);
    Triangulo tcd7(ACD7,CCD7,BCD7);
    tcd7.establecerColor(1.0,0.1,0.9);

    Punto3D ACD8(85, 50, 68);
    Punto3D BCD8(83, 135, 50); //43, 180, 50
    Punto3D CCD8(43, 180, 50);
    Triangulo tcd8(ACD8,CCD8,BCD8);
    tcd8.establecerColor(1.0,0.1,0.9);

    //REVISAR LA ALTURA!!!!!
    Punto3D ACD9(60, -25, 72);
    Punto3D BCD9(85, 50, 68); //43, 180, 50
    Punto3D CCD9(43, 180, 50);
    Triangulo tcd9(ACD9,CCD9,BCD9);
    tcd9.establecerColor(1.0,0.1,0.9);

    Punto3D ACD10(90, -113, 72);
    Punto3D BCD10(85, 50, 68); //60, -25, 50
    Punto3D CCD10(60, -25, 50);
    Triangulo tcd10(ACD10,CCD10,BCD10);
    tcd10.establecerColor(1.0,0.1,0.9);

    Punto3D ACD11(85, 50, 72);
    Punto3D BCD11(108, 175, 68); //83, 135, 50
    Punto3D CCD11(83, 135, 50);
    Triangulo tcd11(ACD11,CCD11,BCD11);
    tcd11.establecerColor(1.0,0.1,0.9);

    Punto3D ACD12(120, 38, 72);
    Punto3D BCD12(108, 175, 68); //85, 50, 50
    Punto3D CCD12(85, 50, 50);
    Triangulo tcd12(ACD12,CCD12,BCD12);
    tcd12.establecerColor(1.0,0.1,0.9);

    Punto3D ACD13(90, -113, 72);
    Punto3D BCD13(120, 38, 68); //85, 50, 50
    Punto3D CCD13(85, 50, 50);
    Triangulo tcd13(ACD13,CCD13,BCD13);
    tcd13.establecerColor(1.0,0.1,0.9);

    //Checkpoint

    Punto3D ACD14(90, -113, 72);
    Punto3D BCD14(121, -25, 68); //120, 38, 50
    Punto3D CCD14(120, 38, 50);
    Triangulo tcd14(ACD14,CCD14,BCD14);
    tcd14.establecerColor(1.0,0.1,0.9);

    Punto3D ACD15(125, -243, 72);
    Punto3D BCD15(121, -50, 68); //90, -113, 50
    Punto3D CCD15(90, -113, 50);
    Triangulo tcd15(ACD15,CCD15,BCD15);
    tcd15.establecerColor(1.0,0.1,0.9);

    Punto3D ACD16(0, -355, 72);
    Punto3D BCD16(90, -113, 68); //0, -248, 50
    Punto3D CCD16(0, -248, 50);
    Triangulo tcd16(ACD16,CCD16,BCD16);
    tcd16.establecerColor(1.0,0.1,0.9);

    Punto3D ACD17(0, -355, 72);
    Punto3D BCD17(120, -220, 68); //90, -113, 50
    Punto3D CCD17(90, -113, 50);
    Triangulo tcd17(ACD17,CCD17,BCD17);
    tcd17.establecerColor(1.0,0.1,0.9);

    Punto3D ACD18(121, -25, 72);
    Punto3D BCD18(305, -253, 68); //108, 175, 50
    Punto3D CCD18(108, 175, 50);
    Triangulo tcd18(ACD18,CCD18,BCD18);
    tcd18.establecerColor(1.0,0.1,0.9);

    Punto3D ACD19(300, -305, 72);
    Punto3D BCD19(305, -253, 68); //121, -25, 50
    Punto3D CCD19(121, -25, 50);
    Triangulo tcd19(ACD19,CCD19,BCD19);
    tcd19.establecerColor(1.0,0.1,0.9);

    Punto3D ACD20(124, -145, 72);
    Punto3D BCD20(300, -305, 68); //121, -25, 50
    Punto3D CCD20(121, -25, 50);
    Triangulo tcd20(ACD20,CCD20,BCD20);
    tcd20.establecerColor(1.0,0.1,0.9);

    Punto3D ACD21(295, -381, 72);
    Punto3D BCD21(300, -305, 68); //124, -145, 50
    Punto3D CCD21(124, -145, 50);
    Triangulo tcd21(ACD21,CCD21,BCD21);
    tcd21.establecerColor(1.0,0.1,0.9);

    Punto3D ACD22(125, -220, 72);
    Punto3D BCD22(295, -381, 68); //124, -145, 50
    Punto3D CCD22(124, -145, 50);
    Triangulo tcd22(ACD22,CCD22,BCD22);
    tcd22.establecerColor(1.0,0.1,0.9);

    Punto3D ACD23(300, -305, 72);
    Punto3D BCD23(305, -253, 50); //321, -295, 68
    Punto3D CCD23(321, -295, 68);
    Triangulo tcd23(ACD23,CCD23,BCD23);
    tcd23.establecerColor(1.0,0.1,0.9);

    Punto3D ACD24(295, -381, 72);
    Punto3D BCD24(300, -305, 50); //330, -350, 68
    Punto3D CCD24(330, -350, 68);
    Triangulo tcd24(ACD24,CCD24,BCD24);
    tcd24.establecerColor(1.0,0.1,0.9);

    Punto3D ACD25(330, -350, 72);
    Punto3D BCD25(321, -295, 50); //300, -305, 68
    Punto3D CCD25(300, -305, 68);
    Triangulo tcd25(ACD25,CCD25,BCD25);
    tcd25.establecerColor(1.0,0.1,0.9);

    //======================================================================================================================
    //Metemos los objetos a la Escena
    vector<ObjetoGeometrico*> escena;

    //BASE--------------------------------
    escena.push_back(&t);
    escena.push_back(&t2);
    escena.push_back(&t3);
    escena.push_back(&t4);
    escena.push_back(&t5);
    escena.push_back(&t6);
    escena.push_back(&t7);
    escena.push_back(&t8);
    escena.push_back(&t9);
    escena.push_back(&t10);


    //CUERPO---------------------------
    // - Izquierdo
    escena.push_back(&tci1);
    escena.push_back(&tci2);
    escena.push_back(&tci3);
    escena.push_back(&tci4);
    escena.push_back(&tci5);
    escena.push_back(&tci6);
    escena.push_back(&tci7);
    escena.push_back(&tci8);
    escena.push_back(&tci9);
    escena.push_back(&tci10);
    escena.push_back(&tci11);
    escena.push_back(&tci12);
    escena.push_back(&tci13);
    escena.push_back(&tci14);
    escena.push_back(&tci15);
    escena.push_back(&tci16);
    escena.push_back(&tci17);
    escena.push_back(&tci18);
    escena.push_back(&tci19);
    escena.push_back(&tci20);
    escena.push_back(&tci21);
    escena.push_back(&tci22);
    escena.push_back(&tci23);
    escena.push_back(&tci24);
    escena.push_back(&tci25);

    //- Derecho
    escena.push_back(&tcd1);
    escena.push_back(&tcd3);
    escena.push_back(&tcd4);
    escena.push_back(&tcd5);
    escena.push_back(&tcd6);
    escena.push_back(&tcd7);
    escena.push_back(&tcd8);
    escena.push_back(&tcd9);
    escena.push_back(&tcd10);
    escena.push_back(&tcd11);
    escena.push_back(&tcd12);
    escena.push_back(&tcd13);
    escena.push_back(&tcd14);
    escena.push_back(&tcd15);
    escena.push_back(&tcd16);
    escena.push_back(&tcd17);
    escena.push_back(&tcd18);
    escena.push_back(&tcd19);
    escena.push_back(&tcd20);
    escena.push_back(&tcd21);
    escena.push_back(&tcd22);
    escena.push_back(&tcd23);
    escena.push_back(&tcd24);
    escena.push_back(&tcd25);

    //==========================================================================



    //Plano
     Punto3D AP(0,-1500,0);
     Vector3D v(0.1,0.1,0.1);
     Plano p(AP,v.hat());
     //p.establecerColor(0.3,0.4,0.9);
    p.establecerColor(0.5,0.75,1);
    escena.push_back(&p);

    ColorRGB color_pixel;

    //VIEWPLANE
    int hres = 1000;
    int vres = 1000;
    double s = 1.0;
    ViewPlane vp(hres, vres, s);

    // UTILITARIO PARA GUARDAR IMAGEN -------------------------------------------------------------------
    int dpi = 72;
    int width = vp.hres;
    int height = vp.vres;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];

    // ALGORITMO RAYTRACER
    for(int fil = 0; fil < vp.vres; fil++)
    {
        for ( int col = 0; col < vp.hres; col++) 
        {
             // Disparamos un rayo
            Vector3D direccion(0.0, 0.0, -1.0);
            double x_o = vp.s * ( col - vp.hres/2 + 0.5 );
            double y_o = vp.s * ( fil - vp.vres/2 + 0.5 );
            double z_o = 100;
            Punto3D origen(x_o, y_o, z_o);
            Rayo rayo(origen, direccion);

            color_pixel = obtenerColorPixel(rayo, escena, luz);

            pixeles[fil*width+col].r = color_pixel.r;
            pixeles[fil*width+col].g = color_pixel.g;
            pixeles[fil*width+col].b = color_pixel.b;
        }
    }    
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}