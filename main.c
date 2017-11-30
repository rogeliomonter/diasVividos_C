/*
     Días vividos 
     Ingresa la fecha de tu nacimiento 
     Muestra cuantos días has vivido y cuenta los años bisiestos
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char a_oNacString[4];
    char mesNacString[10];
    char diaNacString[2];
    
    char a_oHoyString[4];
    char mesHoyString[10];
    char diaHoyString[2];
    
    int a_oNac = 0;
    int mesNac = 0;
    int diaNac = 0;
    
    int a_oHoy = 0;
    int mesHoy = 0;
    int diaHoy = 0;
    
    int bisiestos =0;
    
    const char *nombreMes[12];
    
    nombreMes[0] = "enero";
    nombreMes[1] = "febrero";
    nombreMes[2] = "marzo";
    nombreMes[3] = "abril";
    nombreMes[4] = "mayo";
    nombreMes[5] = "junio";
    nombreMes[6] = "julio";
    nombreMes[7] = "agosto";
    nombreMes[8] = "septiembre";
    nombreMes[9] = "octubre";
    nombreMes[10] = "noviembre";
    nombreMes[11] = "diciembre";
    
    int diasMes[12];
    
    diasMes[0] = 31;
    diasMes[1] = 28;
    diasMes[2] = 31;
    diasMes[3] = 30;
    diasMes[4] = 31;
    diasMes[5] = 30;
    diasMes[6] = 31;
    diasMes[7] = 31;
    diasMes[8] = 30;
    diasMes[9] = 31;
    diasMes[10] = 30;
    diasMes[11] = 31;
    
    printf("Escribe tu fecha de nacimiento\n");
    printf("Escribe el a_o\n");
    //fflush(stdout);
    scanf("%s",a_oNacString);
    printf("Escribe el mes\n");
    //fflush(stdout);
    scanf("%s",mesNacString);
    printf("Escribe el dia\n");
    //fflush(stdout);
    scanf("%s",diaNacString);
    
    a_oNac = atoi(a_oNacString);
    mesNac = atoi(mesNacString);
    diaNac = atoi(diaNacString);
    
    if (mesNac) {
        strcpy (mesNacString, nombreMes[mesNac-1]);
    } else {
        int i=0;
        while (i<12) {
            if(strcmp(mesNacString, nombreMes[i])==0) {
                mesNac = i+1;
                i=12;
            } else {
                i++;
            }
        }
    }
    
    printf("Escribe la fecha de hoy\n");
    printf("Escribe el a_o\n");
    //fflush(stdout);
    scanf("%s",a_oHoyString);
    printf("Escribe el mes\n");
    //fflush(stdout);
    scanf("%s",mesHoyString);
    printf("Escribe el dia\n");
    //fflush(stdout);
    scanf("%s",diaHoyString);
    
    a_oHoy = atoi(a_oHoyString);
    mesHoy = atoi(mesHoyString);
    diaHoy = atoi(diaHoyString);
    
    if (mesHoy) {
        strcpy (mesHoyString, nombreMes[mesHoy-1]);
    } else {
        int i=0;
        while (i<12) {
            if(strcmp(mesHoyString, nombreMes[i])==0) {
                mesHoy = i+1;
                i=12;
            } else {
                i++;
            }
        }
    }
    
    printf("Hoy es %d de %s de %d\n", diaHoy, mesHoyString, a_oHoy);
    printf("Naciste el %d de %s de %d\n", diaNac, mesNacString, a_oNac);
    
    int diasNacimiento = 0;
    int diasenMesNacimiento = 0;
    if(a_oNac%4 == 0 && a_oNac%100 != 0 || a_oNac%400 == 0) { //verificamos si el mes de nacimiento es bisiesto
        if(mesNac==2) { //si nacio en febrero
            diasNacimiento = 29 - diaNac;
            
        } else if(mesNac<2){ // si es antes de febreo
            diasNacimiento = diasMes[mesNac-1] - diaNac + 1;
        } else if (mesNac>2) { // si es despues de febrero
            diasNacimiento = diasMes[mesNac-1] - diaNac;
        }
        bisiestos++;
    } else {//si no es bisiesto
        diasNacimiento = diasMes[mesNac-1] - diaNac;
    }
    
    for(int i=mesNac; i<12; i++) { //recorremos los meses
        diasNacimiento += diasMes[i];
    }
    
    int j=0;
    for(int i=a_oNac; i<a_oHoy-1; i++) {
        //printf("%d", j);
        if(i%4 == 0 && i%100 != 0 || i%400 == 0) {
            diasNacimiento += 366;
            bisiestos ++;
        } else {
            diasNacimiento += 365;
        }
        //j++;
    }
    for(int i=0; i<mesHoy-1; i++) { //recorremos los meses
        diasNacimiento += diasMes[i];
    }
    if(a_oHoy%4 == 0 && a_oHoy%100 != 0 || a_oHoy%400 == 0) { //verificamos si el mes en curso es bisiesto
        if(mesHoy<=2){ // si estamos antes de febreo
            diasNacimiento += diaHoy;
        } else if (mesNac>2) { // si estamos despues de febrero
            diasNacimiento += diaHoy+1;
        }
        bisiestos++;
    } else {
        diasNacimiento += diaHoy;
    }
    
    printf("Has vivido %d dias\n", diasNacimiento);
    printf("Y en tu vida has pasado %d a_os bisiestos\n", bisiestos);
    return 0;
}


