#include<iostream>//libreria de entrada y salida de datos
#include<graphics.h>//libreria Graphica
#include<conio.h>//Proveemos un sistema por consola
#include<math.h>//libreria matematica para la distancia y coordenadas
#include<String.h>//Usamos para evitar errores al convertir Strin en un Char o Puntero de Char
using namespace std;

struct Pueblo{//declaramos la estructura
	int id;
	char nombre[1];
	int x;
	int y;
	int hombres;
	int mujeres;
	int poblacion;
	float perCapita;
	int elevacion;
};

Pueblo ciudad[10] = {//ingresamos datos
	1,'A',12,15,22,12,0,2000,50,
	2,'B',18,64,24,14,0,1800,100,
	3,'C',52,45,26,16,0,1600,150,
	4,'D',13,12,28,22,0,1400,200,
	5,'E',28,60,30,24,0,1300,250,
	6,'F',62,80,32,26,0,2200,400,
	7,'G',19,56,10,28,0,2400,500,
	8,'H',49,55,12,30,0,1500,600,
	9,'I',23,12,14,32,0,1600,400,
	10,'J',30,5,15,16,0,1000,1000
	};

void eje(){//imprimimos el Eje
	setcolor(15);//ingresamos color
	settextstyle(4,0,3);//ingresamos formato, direccion y tamaño
	outtextxy(657,637,"X");//salida de texto para el eje X
	settextstyle(4,0,3);//ingresamos formato, direccion y tamaño
	outtextxy(45,15,"y");//salida de texto para el eje Y
	
	line(50,50,50,650);//int x1,y1 - int x2,y2
	line(50,650,650,650);//int x1,y1 - int x2,y2
	for(int i=60; i<600;i+=60){//sibujamos las lineas de coordenadas y
		setcolor(DARKGRAY);
		line(45,i+50,55,i+50);//int x1,y1 - int x2,y2
	}
	for(int i=60; i<=600;i+=60){//dibujamos el eje coordenado en x
		setcolor(DARKGRAY);
		line(i+50,645,i+50,655);//int x1,y1 - int x2,y2
	}
}

void numeracion(){//ingresamos l anumeracion
	setcolor(15);
	settextstyle(4,0,1);
	outtextxy(15,660,"0");
	
	outtextxy(15,580,"10"); 
	outtextxy(15,520,"20");
	outtextxy(15,460,"30");
	outtextxy(15,400,"40");
	outtextxy(15,340,"50");
	outtextxy(15,270,"60");
	outtextxy(15,210,"70");
	outtextxy(15,150,"80");
	outtextxy(15,90,"90");
	outtextxy(1,30,"100");
	for(int i=580;i>=30;i+=10){
		outtextxy(15,i,i/58); 
	}
	
	settextstyle(4,0,1);
	outtextxy(90,660,"10");
	outtextxy(150,660,"20");
	outtextxy(210,660,"30");
	outtextxy(270,660,"40");
	outtextxy(330,660,"50");
	outtextxy(390,660,"60");
	outtextxy(450,660,"70");
	outtextxy(510,660,"80");
	outtextxy(570,660,"90");
	outtextxy(630,660,"100");
}

void graficarPueblo(){//convertimos cada ciudad 
	for(int i=0;i<10;i++){
		//circle(ciudad[i].x*7,780-ciudad[i].y*7,2);
		setcolor(2);//seteamos color
		settextstyle(4,0,3);//damos estilo al texto, fuente, direccion y tamaño
		outtextxy(50+ciudad[i].x*6,650-ciudad[i].y*6,"."); //imprimimos la estructura modificando el alcance de cada par ordenadoen un punto
		settextstyle(4,0,2);//asignamos fornmato color y tamaño
		outtextxy(60+ciudad[i].x*6,640-ciudad[i].y*6,ciudad[i].nombre); //salida de texto, al costado del punto para señalar ubicacion
		
	}
}
void graficarCercanas(int x, int y,int k){//graficamos los grupos
	for(int i=0;i<10;i++){
		setcolor(3);//color
		settextstyle(4,0,3);//formato, tyamaño y direccion
		outtextxy(50+ciudad[i].x*6,650-ciudad[i].y*6,".");//mostramos un punto en ele eje ordenado exacto
		setcolor(1);//seteamos color
		settextstyle(4,0,2);//seteamos estilo,direccion y ytamaño
		outtextxy(60+ciudad[i].x*6,640-ciudad[i].y*6,ciudad[i].nombre); //mostramos el nombre aumentando 60 pixeles de acuerdo al tamaño
	}
	circle(50+x*6,650-y*6,k*20);//Consideramos el Radio en unidades de 6 entonces 10unidades x6vconsider	
}
void graficarC(int x,int y, int n,int k){ //graficamos recursivamente 
	if(n==3){
		return;
	}else{
		circle(50+x*6,650-y*6,k*20);//circunferencias en base a la grupacion de datos
		return graficarC(x,y,n+1,k);//retornamos recursivamente
	}
}
float distancia(int x1, int y1,int x2,int y2){//funcion para hallar la distancia entre dos ciudades que devuelve la distancia
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));//formula de la distancia de dos puntos, debe retornar como una funcion 
}

int buscar(string c){//buscamos y guardamos el identificador en la variable aux
	int aux;
	for(int i=0;i<10;i++){
		if(c == ciudad[i].nombre){//buscamos el identificador y lo retornamos
			aux = i;
		}
	}return aux;
}
void graficarDisten30(string ciuda){//recibimos como parametro el nombre de la ciudad
		int aux;//declaramos suma y auxiliar
		int arreglo[10];//ejercvicio 1, para ingresar los identificadores en una rreglo
	aux = buscar(ciuda);//obtenemos el identificaodr de la ciudad ingresada
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) < 30){//Si la distancia es menor a 30
			arreglo[i] = ciudad[i].id;//guardamos elidentificador en el arreglo
			cout<<endl<<arreglo[i]<<endl;
		}
	}
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) <30){//si la distancia de los puntos es menor a 30 mosntramos
			setcolor(5);//color
			settextstyle(4,0,3);//damos formato al texto
			outtextxy(50+ciudad[i].x*6,650-ciudad[i].y*6,".");//imostramos el punto coordenado
			setcolor(6);//seteamos color
			settextstyle(4,0,2);//damos formato al texto
			outtextxy(60+ciudad[i].x*6,640-ciudad[i].y*6,ciudad[i].nombre);//mostramos el nombre al costado del punto
		}
	}	
}

void graficarDisten50(string ciuda){//recibimos el parametro de la ciudad
		int aux,suma=0;//declaramos variables de trabajo
	aux = buscar(ciuda);//obtenemos de la funcion buscar el identificador
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) == 50 && ciudad[i].perCapita>1500){//Si es 50km de distancia y al menos 1500 de PERCAPITA
			suma = suma + ciudad[i].poblacion; //sumamamos l apoblacion
		}
	}
	cout<<"La suma es: "<<suma<<endl;
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) == 50 && ciudad[i].perCapita>1500){//la distancia es 50km de distancia y al menos 1500 de PERCAPITA
		setcolor(5);//color
		settextstyle(4,0,3);
		outtextxy(50+ciudad[i].x*6,650-ciudad[i].y*6,".");//imprimirmos en pantalla elparordenado
		setcolor(6);//seteamos color
		settextstyle(4,0,2);
		outtextxy(60+ciudad[i].x*6,640-ciudad[i].y*6,ciudad[i].nombre);//imprimimos el nombre al costado
		}
	}	
}

void graficarDisten50_varones(string ciuda){//recibimos la ciudad como parametro
		int aux,suma=0;//asignamosvalores
	aux = buscar(ciuda);//obtenemos el identificador en un auxiliar
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) == 50 && ciudad[i].elevacion < 800){//Si esta a 50KM y al menosla elevacion es 800
			suma = suma + ciudad[i].hombres;//sumamos los varones de la ciudad que coincide
		}
	}
	cout<<"La suma de los Varones es: "<<suma<<endl;
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) == 50 && ciudad[i].elevacion < 800){//Si esta a 50KM y al menosla elevacion es 800
		setcolor(10);//color
		settextstyle(4,0,3);//asignamos formato,tamaño y direccion
		outtextxy(50+ciudad[i].x*6,650-ciudad[i].y*6,".");//imprimirmos en un punto el par ordenado
		setcolor(10);//seteamos color
		settextstyle(4,0,2);//asignamos formato,tamaño y direccion
		outtextxy(60+ciudad[i].x*6,640-ciudad[i].y*6,ciudad[i].nombre);//imprimimos laciudad nombre y demas
		}
	}	
}

void graficarDisten50_arreglo(string ciuda){//recibimos como parametro el nombre de la ciudad
		int aux;//declaramos suma y auxiliar
		int arreglo2[10];//ejercvicio 1, para ingresar los identificadores en una rreglo
	aux = buscar(ciuda);//obtenemos el identificaodr de la ciudad ingresada
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) == 50 && ciudad[aux].elevacion >800){//Si la distancia es menor a 30
			arreglo2[i] = ciudad[i].id;//guardamos elidentificador en el arreglo
			cout<<endl<<arreglo2[i]<<endl;//ingresamos los datos en el arereglo
		}
	}
	for(int i=0;i<10;i++){
		if(distancia(ciudad[aux].x,ciudad[aux].y,ciudad[i].x,ciudad[i].y) == 50 && ciudad[aux].elevacion >800){//si la distancia de los puntos es menor a 30 mosntramos
			setcolor(5);//color
			settextstyle(4,0,3);//damos formato al texto
			outtextxy(50+ciudad[i].x*6,650-ciudad[i].y*6,".");//imostramos el punto coordenado
			setcolor(6);//seteamos color
			settextstyle(4,0,2);//damos formato al texto
			outtextxy(60+ciudad[i].x*6,640-ciudad[i].y*6,ciudad[i].nombre);//mostramos el nombre al costado del punto
		}
	}	
}

void percapita(){//ordenamos de manera descendente usando burbuja perCapita
	int aux;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (ciudad[j].perCapita > ciudad[j + 1].perCapita){
                    aux = ciudad[j].perCapita;
                    ciudad[j].perCapita = ciudad[j+1].perCapita;
                    ciudad[j+1].perCapita = aux;
                }
            }
        }
}

void mayores(){//ordenamos de manera descendente usando burbuja poblacion
	int aux;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (ciudad[j].poblacion > ciudad[j + 1].poblacion){
                    aux = ciudad[j].poblacion;
                    ciudad[j].poblacion = ciudad[j+1].poblacion;
                    ciudad[j+1].poblacion = aux;
                }
            }
        }	
}
void menu(){
	int opcion,mayor=0,mayor2=0,aux,aux2,k;
	string cda;
	for(int i = 0; i < 10; i++){
        ciudad[i].poblacion = ciudad[i].hombres +ciudad[i].mujeres;
	}
	do{
		cout<<"***************************";
		cout<<"\n\tMENU DE OPCIONES: "<<endl;
		cout<<"1. Mostrar la tabla"<<endl;
		cout<<"2. Mostrar Grafico"<<endl;
		cout<<"3. Grafico(3)"<<endl;
		cout<<"4. Ciudades Mas Pobladas"<<endl;
		cout<<"5. Ciudad que disten 50KM"<<endl;
		cout<<"6. Suma Varones Ciudad 50KM"<<endl;
		cout<<"7. Ciudad Guardar Arreglo 800msnm"<<endl;
		cout<<"15. Salir"<<endl;
		cout<<"***************************"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
			      cout<<"************************************************************************************"<<endl;
					cout<<" Id"<<" "
					<<" Nombre"<<" "
					<<"    Ubicacion (x,y)   "<<" "
					<<"Hombres"<<""
					<<" Mujeres"<<""
					<<" Poblacion"<<""
					<<"  Percapita"<<""
					<<"  Elevacion"<<""<<endl;
                        cout<<"************************************************************************************"<<endl;
					for(int i = 0; i < 10; i++){
                        ciudad[i].poblacion = ciudad[i].hombres +ciudad[i].mujeres;
						cout<<" "<<ciudad[i].id;
						cout<<" \t"<<ciudad[i].nombre;
						cout<<" \t    "<<ciudad[i].x<<","<<ciudad[i].y<<"	";
						cout<<" \t"<<ciudad[i].hombres;
						cout<<" \t"<<ciudad[i].mujeres;
						cout<<" \t  "<<ciudad[i].poblacion;
						cout<<" \t   "<<ciudad[i].perCapita;
						cout<<" \t"<<ciudad[i].elevacion<<endl;
					}
                        cout<<"************************************************************************************"<<endl;
						cout<<"\n";
				system("pause");		
				break;		
			case 2:
					initwindow(1000,800,"Valerio Gomez",0,0,false,true);
					eje();//graficamos el efe
					numeracion();//graficamos la numeracion
					graficarPueblo();
					getch();
   			case 3://
   				cout<<"Mostrando Agrupacion de ciudades con Mayor Poblacion"<<endl;
   				cout<<"Ingrese K: ";
   				cin>>k;
			   for(int i=0;i<10;i++){
						if(ciudad[i].poblacion > mayor){
							mayor=ciudad[i].poblacion;
							aux=ciudad[i].id;//guardamos el ID de la ciudad con mayor poblacion
						}
				}
				initwindow(1000,800,"Valerio Gomez",0,0,false,true);//iniciamos pantalla en 1000x800
				eje();//graficamos el efe
				numeracion();//graficamos la numeracion
				graficarCercanas(ciudad[aux].x,ciudad[aux].y,k);//graficamos pasando parametros del auxiliar
				graficarC(13,12,0,k);
				graficarC(62,80,0,k);
				getch();
				break;
			case 4: cout<<"Ingrese Ciudad: ";
				cin>>cda;
				initwindow(1000,800);//iniciamos pantalla en 1000x800
				eje();//graficamos el efe
				numeracion();//graficamos la numeracion
				graficarDisten30(cda);//graficamos pasando parametros delnombre de la ciudad
			 getch();
			break;
			case 5: cout<<"Ingrese Ciudad: ";
				cin>>cda;
				initwindow(1000,800);//iniciamos pantalla en 1000x800
				eje();//graficamos el efe
				numeracion();//graficamos la numeracion
				graficarDisten50(cda);//graficamos pasando parametros delnombre de la ciudad
			 getch();
			break;
			case 6: cout<<"Ingrese Ciudad: ";
				cin>>cda;
				initwindow(1000,800);//iniciamos pantalla en 1000x800
				eje();//graficamos el eje
				numeracion();//graficamos la numeracion
				graficarDisten50_varones(cda);//graficamos pasando parametros delnombre de la ciudad
			 getch();
			break;
			case 7: cout<<"Ingrese Ciudad: ";
				cin>>cda;
				initwindow(1000,800);//iniciamos pantalla en 1000x800
				eje();//graficamos el eje
				numeracion();//graficamos la numeracion
				graficarDisten50_arreglo(cda);//graficamos pasando parametros delnombre de la ciudad
			 getch();
			break;			
		}system("cls");
	}
      while(opcion!=5);
}


main(){
	

	menu();
	getch();
	return 0;
}
