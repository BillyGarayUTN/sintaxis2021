#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct Tcopias
{
char especie[12];
  
}copias[100] ;

struct Tcotizacion
{
    char especie[12];
    char compra[10];
    char venta[10];
	char apertura[10];
	char maximo[10];
	char minimo[10];
}Vcotizacion[100] ;

void opcionUno(){
    FILE *f;
    char *pchar;
    char buffer[2048];
    char especie[10];

    if (f= fopen("SSL-TP2.html","rt"))
    {
        while (fgets(buffer,2048,f))
        {
            if ((pchar = strstr(buffer, "data-order")) && strstr(buffer, "Cdo.</td>"))     
            {	
            	if ((strstr(buffer, ">-")) && strstr(buffer, "% </span>"))
				{
				
                /*Escribamos el nombre de la especie */
              while (*pchar != '>')
                    pchar++;
                int i = 0;
                pchar++;
                while(*pchar != '<')
                {
                    especie[i] = *pchar;
                    i++;
                    pchar++;
                }
                especie[i] = '\0';
                printf("Las Especies con Vencimiento contado y variacion negativa son: %s\n", especie);
           		}
            }
        }
        fclose(f);
    }
return;    
}
//fin de funcion UNO

void opcionDos(){
        FILE *f;
    char *token;
    char *pchar;
    char buffer[2048];
    char especie[10];
    char compra[10];
    char venta[10];
    char apertura[10];
    char minimo[10];
    char maximo[10];
    int  j =0;
    int y =0;
    if (f= fopen("SSL-TP2.html","rt"))
    {
        while (fgets(buffer,2048,f))
        {
            if ((pchar = strstr(buffer, "data-order")) && strstr(buffer, "Cdo.</td>"))     
            {	
				
				
                /*Escribamos el nombre de la especie */
                while (*pchar != '>')
                    pchar++;
                int i = 0;
                pchar++;
                while(*pchar != '<')
                {
                    especie[i] = *pchar;
                    i++;
                    pchar++;
                }
                especie[i] = '\0';
                
                 /*Escribamos compra */

                // repito hasta 6 veces que es la posocion del '>'
                for (int a=0;a<6;a++) {             
                while (*pchar != '>')
                    pchar++;
                i = 0;
                pchar++;
                }
                
                while(*pchar != '<')
                {
                    compra[i] = *pchar;
                    i++;
                    pchar++;
                }
                compra[i] = '\0';


                //Escribamos venta
                for ( int b=0;b<2;b++) {        //CAMBIO
                while (*pchar != '>')
                    pchar++;
                i = 0;
                pchar++;
                }
                
                while(*pchar != '<')
                {
                    venta[i] = *pchar;
                    i++;
                    pchar++;
                }
                venta[i] = '\0';

                //Escribamos apertura 
                for (int c=0;c<12;c++) {           //CAMBIO    
                while (*pchar != '>')
                    pchar++;
                i = 0;
                pchar++;
                }
                
                while(*pchar != '<')
                {
                    apertura[i] = *pchar;
                    i++;
                    pchar++;
                }
                apertura[i] = '\0';

                //Escribamos minimo 
                for (int d=0;d<2;d++) {           //CAMBIO
                while (*pchar != '>')
                    pchar++;
                i = 0;
                pchar++;
                }
                
                while(*pchar != '<')
                {
                    minimo[i] = *pchar;
                    i++;
                    pchar++;
                }
                    minimo[i] = '\0';

                
                //Escribamos maximo
                for (int e=0;e<2;e++) {             //CAMBIO
                while (*pchar != '>')
                    pchar++;
                i = 0;
                pchar++;
                }
                
                while(*pchar != '<')
                {
                    maximo[i] = *pchar;
                    i++;
                    pchar++;
                }
                    maximo[i] = '\0';

                // agregando codigo para meterlo a un struct los resultadoss
                strcpy(Vcotizacion[j].especie, especie);
                strcpy(Vcotizacion[j].compra, compra);
                strcpy(Vcotizacion[j].venta, venta);
                strcpy(Vcotizacion[j].apertura, apertura);
                strcpy(Vcotizacion[j].minimo, minimo);
                strcpy(Vcotizacion[j].maximo, maximo);

                j++;
            }
        
        }

        // ARmo en htaml de salida y meto todo los datos que fui agregando 
        FILE *g;
         g = fopen("salida-reporte-2.html", "wt");
         fprintf(g,"<html><body>\n");
         fprintf(g,"<h1>Punto 2 Listado de Cotizaciones</h1>\n");
         fprintf(g,"<table border=1>\n");
        fprintf(g,"<th>Especie</th><th>Compra</th><th>Venta</th><th>Apertura</th><th>Minimo</th><th>Maximo</th>\n");
        int n= 0;
         while (strlen(Vcotizacion[n].especie) != 0)
        {
           fprintf(g,"<tr>\n");
           fprintf(g,"<td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td>\n",Vcotizacion[n].especie,Vcotizacion[n].compra,Vcotizacion[n].venta,Vcotizacion[n].apertura,Vcotizacion[n].minimo,Vcotizacion[n].maximo);
            fprintf(g,"</tr>\n");
           n++;
        }
          fprintf(g, "</table>");
         fprintf(g, "</body>");
        fprintf(g, "</html>");
        fclose(g);



        //Vamos a escribir un HTML con los datos:
    FILE *t;
    t = fopen("salida-reporte-2.csv", "wt");

    fprintf(t,"especie;compra;venta;apertura;minimo;maximo\n");
    int i= 0;
    while (strlen(Vcotizacion[i].especie) != 0)
    {
        fprintf(t,"%s;%s;%s;%s;%s;%s\n",Vcotizacion[i].especie,Vcotizacion[i].compra,Vcotizacion[i].venta,Vcotizacion[i].apertura,Vcotizacion[i].minimo,Vcotizacion[i].maximo);
        i++;
    }
    fclose(t);
    fclose(f);

    }

    return;
}
//Fin de funcionDOS
void opcionTres(){
    FILE *f;
    
    float valVenta;
    float valCompra;
    float valApertura;
    char compra[10];
    char venta[10];
    char apertura[10];
    char *uchar;
    char *pchar;
    char *qchar;
    char buffer[2048];
    char especie[10];
    char reporteEspecie[10];
    char coinciden[10];
    int contador = 0;
    int n= 0;
    int j = 0;
    if (f= fopen("SSL-TP2.html","rt"))
    {
        while (fgets(buffer,2048,f))
        {   
            if ((pchar = strstr(buffer, "data-order")) && strstr(buffer, "Cdo.</td>"))      
            {	int k=0;
                int i = 0;
                
                //  Tomo todos las especies con variacion negativas
                uchar = pchar;

                if ((strstr(buffer, ">-")) && strstr(buffer, "% </span>"))
				{
				/*Escribamos el nombre de la especie */
              while (*uchar != '>'){
                    uchar++;}
                int i = 0;
                uchar++;
                while(*uchar != '<')
                 {
                    reporteEspecie[i] = *uchar;
                    i++;
                    uchar++;
                }
                 reporteEspecie[i] = '\0';
                  //  printf("Las Especies con Vencimiento contado y variacion negativa son: %s\n", reporteEspecie);
           		}
                    
                //Busco un punto adicional que me atrape  compra venta y apertura
                qchar = strstr(buffer, "data-order");

                // busco compra
                for (int j=0;j<7;j++) {
                while (*qchar != '>')
                    qchar++;
                i = 0;
                qchar++;
                }
                
                while(*qchar != '<')
                {
                    compra[i] = *qchar;
                    i++;
                    qchar++;
                }
                compra[i] = '\0';

                //busco venta

                for (int j=0;j<2;j++) {
                while (*qchar != '>'){
                    qchar++;}
                i = 0;
                qchar++;
                }
                
                while(*qchar != '<')
                {
                    venta[i] = *qchar;
                    i++;
                    qchar++;
                }
                venta[i] = '\0';

                //Busco apertura

                for (int j=0;j<12;j++) {
                while (*qchar != '>'){
                    qchar++;}
                i = 0;
                qchar++;
                }
                
                while(*qchar != '<')
                {
                    apertura[i] = *qchar;
                    i++;
                    qchar++;
                }
                apertura[i] = '\0';

                // FIN DE BUSQUEDAS

                // Copio los valores a la esturctura 
                valCompra = atof(compra);
                valVenta = atof(venta);
                valApertura = atof(apertura);
                

             /*   printf("%f\n",valCompra);
                printf("%f\n",valVenta);
                printf("%f\n\n",valApertura);  
            */
                
            	if ((valApertura>valVenta)&&(valApertura>valCompra))  // aqui pongo las condiciones  apertura > compra y venta 
				{
				//  printf("Coincide\n");
                /*Escribamos el nombre de la especie */
                while (*pchar != '>'){
                    pchar++;}
                int k = 0;
                pchar++;
                while(*pchar != '<')
                {
                    especie[k] = *pchar;
                    k++;
                    pchar++;
                    
                }
                especie[k] = '\0';
                                        
               // strcpy(coinciden[i], especie);
               // printf("Las Especies que cumplen son %s\n", especie );
                
                //Me guardo una copia

                strcpy(copias[j].especie,especie);

              //  printf("que me guarde %s Esto \n",copias[j].especie);
              //            j++;
                  
                //TERMINA IF

              //  printf("\n valor de j es %i",j);
                
                //Armo el html 
                           
                j++;      
           		}  
            
            }

              //Armo el html 
                FILE *g;
                g = fopen("salida-Reporte-3.html", "wt");
                fprintf(g,"<html><body>\n");
                fprintf(g,"<h1>Listado Reporte N°3 </h1>\n");
                fprintf(g,"<table border=1>\n");
                fprintf(g,"<th>Especie</th>\n");
                  
                    int n=0;
                 //   fprintf(g,"<td> <span style=\"color:#10da10;\">%s</span></td",especie); 
                    while (strlen(copias[n].especie) != 0 ){
                        fprintf(g,"<tr>\n");

                        fprintf(g,"<td><span style=\"color:#10da10;\">%s</span></td>",copias[n].especie);

                     //   printf(" \n ALARMA %s       ",copias[n].especie); 
                        
                         fprintf(g,"</tr>\n");
                        n++;
                    }
                    fprintf(g, "</table>");
                    fprintf(g, "</body>");
                    fprintf(g, "</html>");
                    fclose(g);

        }   
        fclose(f);       
    }

    return;
}

int main(){  
    printf("*********************************************************************************\n\n");
    printf("Programa de informes de la pagina de acciones lideres de bolsar.info \n  \n");

    printf("A continuacion ingrese la opcion segun el informe que desea realizar: \n\n" );

    printf("Opcion 1: Especies cuya %% de variacion es negativo.\n");
    printf("Opcion 2: Listado en archivo .CSV de ESPECIES,COMPRA,VENTA,APERTURA,MAX,MIN.\n");
    printf("Opcion 3: Reporte en archivo .HTML de ESPECIES cuyo COMPRA y VENTA es menor a APERTURA.\n");
    printf("Opcion 4: Salir del programa.\n");
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); 

    printf("Ingrese una OPCION: ");
    int opcion;
    scanf("%d", &opcion);//ingrese la opcion.

    while (opcion != 4)
    {
    switch(opcion) {
    case 1:
    //Inicio del caso 1
    printf("Elegiste la opcion 1\n");
    opcionUno();

    printf("\n Ingrese una OPCION: ");
    scanf("%d", &opcion);//ingrese la opcion.
    //Fin del caso 1

    break; 
    case 2:
    //Inicio del caso 2
    printf("Elegiste la opcion 2\n");
    opcionDos();
    printf("\nReporte creado en: salida-reporte-2.html y salida-reporte-2.csv \n");
    printf("\n Ingrese una OPCION: ");
    scanf("%d", &opcion);//ingrese la opcion.
    //Fin del caso 2
    break; 
    case 3:
    //Inicio del caso 3
    printf("Elegiste la opcion 3\n");
    opcionTres();
    printf("\nReporte creado salida-Reporte-3.html\n");
    printf("\n Ingrese una OPCION: ");
    scanf("%d", &opcion);//ingrese la opcion.
    //Fin del caso 3
    break;

    default :
    printf("\n Ingrese una opcion: ");
    scanf("%d", &opcion);//ingrese la opcion.
    }    

}

    //Mensaje de salida del programa.
    printf("\n\n.......................Gracias por usar nuestro Programa ...................\n");
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
   
    system("pause");
     return  0;
}

