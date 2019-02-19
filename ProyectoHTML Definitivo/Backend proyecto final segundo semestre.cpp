#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

using namespace std;

struct ComentariosHoteles{
    char comentario[1000];
    string comentariosDeHoteles[100];
    int puntuacionHoteles[100];
};

struct TodosHoteles{
    string nombresDeHoteles[100];          //Contiene el nombre de todos los hoteles
    string ubicacionesDeHoteles[100];          //Contiene la ubicacion de todos los hoteles
    int estrellasDeHoteles[100];           //Contiene las estrellas de todos los hoteles
    int preciosPorNocheDeHoteles[100];            //Contiene los precios por noche de todos los hoteles
    int cantHabitacionesIndividualesDeHoteles[100];           //Contiene la cantidad de habitaciones disponibles individuales de todos los hoteles
    int cantHabitacionesDoblesDeHoteles[100];          //Contiene la cantidad de habitaciones dobles disponibles de todos los hoteles
    int cantHabitacionesFamiliaresDeHoteles[100];            //Contiene la cantidad de habitaciones familiares disponibles de todos los hoteles
    
    int preciosParqueadero[100];
    int preciosRestaurante[100];
    int preciosPiscina[100];
    int preciosSauna[100];
    int preciosGimnasio[100];
    int preciosSpa[100];
    int preciosInternet[100];
    
    int cantHabitacionesReservadas[100];
    int cantFiltrosReservados[100];
    
    int preciosTotales[100];
};

struct DatosHotel{
    struct TodosHoteles todosLosHoteles;         //Contiene todos los datos de todos los hoteles
    struct ComentariosHoteles comentariosHoteles;           //Contiene todos los comentarios de el hotel
    int cantHoteles;          //Contiene la cantidad de hoteles que hay en la pagina
	   
    char nombreHotel[100];           //Contiene el nombre del hotel
    char ubicacionHotel[100];           //Contiene la ubicacion del hotel
    int cantEstrellas;           //Contiene la cantidad de estrellas
	int precioPorNoche;           //Contiene el precio por noche
    int cantHabitacionesIndividuales;        //Contiene la cantidad de habitaciones individuales disponibles
    int cantHabitacionesDobles;           //Contiene la cantidad de habitaciones dobles disponibles
    int cantHabitacionesFamiliares;          //Contiene la cantidad de habitaciones familiares disponibles
    
    int precioParqueadero;
    int precioRestaurante;
    int precioPiscina;
    int precioSauna;
    int precioGimnasio;
    int precioSpa;
    int precioInternet;
    
    int precioTotal;
};

struct TodosUsuarios{
    string NombresUsuarios[100];         //Contiene el nombre de todos los usuarios
    long long int CedulasUsuarios[100];          //Contiene la cedula de todos los usuarios
    string UsersUsuarios[100];          //Contiene los username de todos los usuarios
    string ContrasUsuarios[100];          //Contiene la contraseña de todos los usuarios 
};

struct TodosAdministradores{
    string NombresAdministradores[100];           //Contiene el nombre de todos los administradores
    long long int CedulasAdministradores[100];           //Contiene la cedula de todos los administradores
    string UsersAdministradores[100];          //Contiene el usuario de todos los administradores
    string ContrasAdministradores[100];          //Contiene las contraseñas de todos los administradores
};

struct DatosUsuario{
    struct TodosUsuarios todosLosUsuarios;
    int cantUsuarios;
    char Name[100];      //Contiene el nombre de la persona
    long long int ID;      //Contiene la cedula de la persona
    char User[100];       //Contiene el nombre de usuario con el que se vá a ingresar
    char password[100];        //Contiene la contraseña con la que el usuario va a ingresar
};

struct DatosAdministrador{
    struct TodosAdministradores todosLosAdmin;
    int cantAdministradores;
    char NameAdmin[100];      //Contiene el nombre de el administrador
    long long int IDAdmin;      //Contiene la cedula de el administrador
    char UserAdmin[100];       //Contiene el nombre de usuario con el que se va a ingresar como administrador
    char passwordAdmin[100];        //Contiene la contraseña con la que el usuario va a ingresar como administrador
};



//--------------------------------------------------//
//ESTAS SON LAS FIRMAS DE LAS FUNCIONES DEL PROGRAMA//
//--------------------------------------------------//

void InicializaContadores(DatosHotel &datosDelHotel);

void Escribir_ingreso_de_datos_del_admin(DatosHotel &datosDelHotel);
void Escribir_terminos_y_condiciones(DatosHotel &datosDelHotel);
void Escribir_principal_del_admi(DatosHotel &datosDelHotel);
void Escribir_presentacion(DatosHotel &datosDelHotel);
void Escribir_principal(DatosHotel &datosDelHotel);
void Escribir_registro(DatosHotel &datosDelHotel);
void Escribir_factura(DatosHotel &datosDelHotel, int posHotelAReservar);

void IngresarDatos(DatosUsuario &datosDelUsuario);
void RegistroUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void RegistroAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado, DatosUsuario &datosDelUsuario);
void MenuPrincipal(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador, DatosHotel &datosDelHotel);
void DefineTipoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void Loguearse(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador, DatosHotel &datosDelHotel);
void LoguearseComoAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado, DatosHotel &datosDelHotel);
void LoguearseComoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosHotel &datosDelHotel);
void OpcionesAdministrador(DatosHotel &datosDelHotel);
void OpcionesUsuario(DatosHotel &datosDelHotel);
void MuestraHoteles(DatosHotel &datosDelHotel);
void IngresarHoteles(DatosHotel &datosDelHotel);
void BuscaHotelAReservar(DatosHotel &datosDelHotel);
void BuscaHotelesPorCiudad(DatosHotel &datosDelHotel);
void ReservarHotel(string nombreDeHotelAReservar, int posHotelAReservar);
void MuestraFacturaActual(DatosHotel &datosDelHotel, int &posHotelAReservar);
void MuestraTodosLosHoteles(DatosHotel &datosDelHotel, int &posHotelAReservar);
void MuestraInfoHotel(DatosHotel &datosDelHotel, int &posHotelAReservar);
string getDate();
string GetDay();
string GetMonth();
string GetYear();
string getHour();
void FechaAQuedarse(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Opiniones(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Parqueadero(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Restaurante(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Piscina(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Sauna(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Gimnasio(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Spa(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Internet(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Filtros(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Comentar(DatosHotel &datosDelHotel, int &posHotelAReservar);
void Puntuar(DatosHotel &datosDelHotel, int &posHotelAReservar);
void ReservaHabitacionIndividual(DatosHotel &datosDelHotel, int &posHotelAReservar);
void ReservaHabitacionDoble(DatosHotel &datosDelHotel, int &posHotelAReservar);
void ReservaHabitacionFamiliar(DatosHotel &datosDelHotel, int &posHotelAReservar);
int returnInt();
string returnString();


void MuestraDatosUsuarios(DatosUsuario &datosDelUsuario, bool &estaRegistrado);
void MuestraDatosAdmins(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado);
//---------------------------//
//AQUI TERMINAN LAS FIRMAS   //
//---------------------------//

//FUNCION PRINCIPAL
int main()
{
    struct DatosUsuario datosDelUsuario;        //Variable que referencia la estructura con los datos del usuario.
    struct DatosAdministrador datosDelAdministrador;       //Variable que referencia la estructura con los datos del administrador
    struct DatosHotel datosDelHotel;
    bool estaRegistrado = false;        //Contiene la verificacion si el usuario está registrado o no.
    system("color 1B");
    
    InicializaContadores(datosDelHotel);
    //Realiza la maquetacion de la vista.
    Escribir_ingreso_de_datos_del_admin(datosDelHotel);
	Escribir_terminos_y_condiciones(datosDelHotel);
	Escribir_principal_del_admi(datosDelHotel);
	Escribir_presentacion(datosDelHotel);
	Escribir_principal(datosDelHotel);
	Escribir_registro(datosDelHotel);
	Escribir_factura(datosDelHotel, 0);
	
    MenuPrincipal(datosDelUsuario, estaRegistrado, datosDelAdministrador, datosDelHotel);
    //RegistroUsuario(datosDelUsuario, estaRegistrado);        //Registra al usuario si no lo está, si lo está, pide los datos para loguearse
    //RegistroUsuario(datosDelUsuario, estaRegistrado);
    
    //Lectura();
    system("PAUSE");
    return 0;
}

void InicializaContadores(DatosHotel &datosDelHotel){
     
     for(int i = 0; i < 100; i++){
          datosDelHotel.todosLosHoteles.cantHabitacionesReservadas[i] = 0;
          datosDelHotel.todosLosHoteles.cantFiltrosReservados[i] = 0;
     }
}

//El menu que se inicia al comienzo de el programa
void MenuPrincipal(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador, DatosHotel &datosDelHotel){ 
    int op = 1;       //Es la opcion que va a tomar el usuario
    datosDelUsuario.cantUsuarios = 0;       //Dice que al principio del programa hay 0 usuarios
    datosDelAdministrador.cantAdministradores = 0;        //Dice que al principio del programa hay 0 administradores
    datosDelHotel.cantHoteles = 0;
    datosDelHotel.precioTotal = 0;
    //Se ejecuta si op es diferente de 0
    while(op != 0){
        system("cls");
        //Muestra las opciones que se pueden ejecutar
        cout<<"Ingrese 1 para registrarte"<<endl;
        cout<<"Ingrese 2 para loguearse"<<endl;
        cout<<"Ingrese 3 para mostrar todos los usuarios corrientes"<<endl;
        cout<<"Ingrese 4 para mostrar todos los Administradores"<<endl;
        cin>>op;       //Guarda el valor de la opcion que se ejecutará
		  
        switch(op){
            case 1:{
                //Ejecuta el registro o loguea al usuario dependiendo de si está registrado o no
                DefineTipoUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);
                system("pause");
                break;
            }
            
			case 2:{
                Loguearse(datosDelUsuario, estaRegistrado, datosDelAdministrador, datosDelHotel);
                //system("start Frontend_proyecto_final_segundo_semestre.html");
                //system("start https://www.trivago.com.co/?aDateRange%5Barr%5D=2019-02-13");
                system("pause");
                break;
            }
            
			case 3:{
                MuestraDatosUsuarios(datosDelUsuario, estaRegistrado);
                system("pause");
                break;
            }
            
			case 4:{
                MuestraDatosAdmins(datosDelAdministrador, estaRegistrado);
                system("pause");
                break;
            }
        }
    }
}

void IngresarHoteles(DatosHotel &datosDelHotel){
    system("cls");
    system("start Ingreso_de_datos.html");
    cout<<"Ingrese el nombre del hotel= ";
    fflush(stdin);
    gets(datosDelHotel.nombreHotel);
    cout<<endl;
     
    cout<<"Ingrese la ubicacion del hotel= ";
    fflush(stdin);
    gets(datosDelHotel.ubicacionHotel);
    cout<<endl;
     
	cout<<"Ingrese la cantidad de estrellas que tiene el hotel= ";
    fflush(stdin);
    cin>>datosDelHotel.cantEstrellas;
    cout<<endl;
     
    cout<<"Ingrese el costo por noche en el hotel= ";
    fflush(stdin);
    cin>>datosDelHotel.precioPorNoche;
    cout<<endl;
     
    cout<<"Ingrese la cantidad de habitaciones individuales disponibles= ";
    fflush(stdin);
	cin>>datosDelHotel.cantHabitacionesIndividuales;
    cout<<endl;
     
    cout<<"Ingrese la cantidad de habitaciones dobles= ";
    fflush(stdin);
    cin>>datosDelHotel.cantHabitacionesDobles;
    cout<<endl;
     
    cout<<"Ingrese la cantidad de habitaciones familiares= ";
    fflush(stdin);
    cin>>datosDelHotel.cantHabitacionesFamiliares;
    cout<<endl;
    
    cout<<"Ingrese el precio de el parqueadero por dia= ";
    fflush(stdin);
    cin>>datosDelHotel.precioParqueadero;
    cout<<endl;
    
    cout<<"Ingrese el precio de el restaurante por dia= ";
    fflush(stdin);
    cin>>datosDelHotel.precioRestaurante;
    cout<<endl;
    
    cout<<"Ingrese el precio de la piscina por dia= ";
    fflush(stdin);
    cin>>datosDelHotel.precioPiscina;
    cout<<endl;
    
    cout<<"Ingrese el precio de el sauna por dia= ";
    fflush(stdin);
    cin>>datosDelHotel.precioSauna;
    cout<<endl;
    
    cout<<"Ingrese el precio de el gimnasio por dia= ";
    fflush(stdin);
    cin>>datosDelHotel.precioGimnasio;
    cout<<endl;
    
    cout<<"Ingrese el precio de el spa por dia= ";
    fflush(stdin);
    cin>>datosDelHotel.precioSpa;
    cout<<endl;
    
    cout<<"Ingrese el precio de el internet por dia= ";
    fflush(stdin);
    cin>>datosDelHotel.precioInternet;
    cout<<endl;
    
    datosDelHotel.todosLosHoteles.nombresDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.nombreHotel;
    datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.ubicacionHotel;
    datosDelHotel.todosLosHoteles.estrellasDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantEstrellas;
    datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.precioPorNoche;
    datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantHabitacionesIndividuales;
    datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantHabitacionesDobles;
    datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantHabitacionesFamiliares;
    datosDelHotel.todosLosHoteles.preciosParqueadero[datosDelHotel.cantHoteles] = datosDelHotel.precioParqueadero;
    datosDelHotel.todosLosHoteles.preciosRestaurante[datosDelHotel.cantHoteles] = datosDelHotel.precioRestaurante;
    datosDelHotel.todosLosHoteles.preciosPiscina[datosDelHotel.cantHoteles] = datosDelHotel.precioPiscina;
    datosDelHotel.todosLosHoteles.preciosSauna[datosDelHotel.cantHoteles] = datosDelHotel.precioSauna;
    datosDelHotel.todosLosHoteles.preciosGimnasio[datosDelHotel.cantHoteles] = datosDelHotel.precioGimnasio;
    datosDelHotel.todosLosHoteles.preciosSpa[datosDelHotel.cantHoteles] = datosDelHotel.precioSpa;
    datosDelHotel.todosLosHoteles.preciosInternet[datosDelHotel.cantHoteles] = datosDelHotel.precioInternet;
    datosDelHotel.cantHoteles++;
    
    Escribir_principal(datosDelHotel);
}

void MuestraHoteles(DatosHotel &datosDelHotel){ 
    for(int i = 0; i < datosDelHotel.cantHoteles; i++){
        cout<<"Nombre del hotel= "<<datosDelHotel.todosLosHoteles.nombresDeHoteles[i]<<endl;
        cout<<"Ubicacion del hotel= "<<datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[i]<<endl;
        cout<<"Estrellas del hotel= "<<datosDelHotel.todosLosHoteles.estrellasDeHoteles[i]<<endl;
        cout<<"Precios por dia del hotel= "<<datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[i]<<endl;
        cout<<"habitaciones individuales del hotel= "<<datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[i]<<endl;
        cout<<"habitaciones dobles del hotel= "<<datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[i]<<endl;
        cout<<"habitaciones familiares del hotel= "<<datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[i]<<endl;
    }
}

void ReservarHotel(DatosHotel &datosDelHotel, int posHotelAReservar){
     
    system("cls");
     
    int op = 1;
     
    while(op != 0){
        system("cls");
        cout<<"BIENVENIDO AL HOTEL "<<datosDelHotel.todosLosHoteles.nombresDeHoteles[posHotelAReservar]<<".\n"<<endl;      
                 
        cout<<"Que tipo de habitacion desea reservar?\n"<<endl;
           
        cout<<"Ingrese 1 para reservar una habitacion individual"<<endl;
        cout<<"Ingrese 2 para reservar una habitacion doble"<<endl;
        cout<<"Ingrese 3 para reservar una habitacion familiar"<<endl;
        cout<<"Ingrese 4 para mostrar informacion sobre el hotel"<<endl;
        cout<<"Ingrese 5 para mostrar su factura actual"<<endl;
        cout<<"Ingrese 0 para cerrar el programa"<<endl;
           
        cin>>op;
           
        switch(op){
        	case 1:{
        		cout<<"\nReserva habitacion individual"<<endl;
        		ReservaHabitacionIndividual(datosDelHotel, posHotelAReservar);
				break;
			}
            
			case 2:{
				cout<<"\nReserva habitacion doble"<<endl;
				ReservaHabitacionDoble(datosDelHotel, posHotelAReservar);
				break;
			}
			
			case 3:{
				cout<<"\nReserva habitacion familiar"<<endl;
				ReservaHabitacionFamiliar(datosDelHotel, posHotelAReservar);
				break;
			} 
            
            case 4:{
				cout<<"\nMuestra informacion del hotel"<<endl;
				MuestraInfoHotel(datosDelHotel, posHotelAReservar);
				break;
			}
            
            case 5:{
				cout<<"\nMuestra informacion del hotel"<<endl;
				MuestraFacturaActual(datosDelHotel, posHotelAReservar);
				break;
			}
        }
    }
}

void MuestraFacturaActual(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls");
     Escribir_factura(datosDelHotel, posHotelAReservar);
     system("start Facturar.html");
     cout<<"Su valor total a pagar es= "<<datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar]<<endl;
     system("pause");
}

void MuestraTodosLosHoteles(DatosHotel &datosDelHotel){
     for(int i = 0; i < datosDelHotel.cantHoteles; i++){
          for(int j = 0; j < datosDelHotel.cantHoteles; j++){
               if(datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[j] > datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[j+1]){
                     int temp = datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[j];
                     string temp1 = datosDelHotel.todosLosHoteles.nombresDeHoteles[j];
                     string temp2 = datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[j];
                     int temp3 = datosDelHotel.todosLosHoteles.estrellasDeHoteles[j];
                     int temp4 = datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[j];
                     int temp5 = datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[j];
                     int temp6 = datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[j];
                     int temp7 = datosDelHotel.todosLosHoteles.preciosParqueadero[j];
                     int temp8 = datosDelHotel.todosLosHoteles.preciosRestaurante[j];
                     int temp9 = datosDelHotel.todosLosHoteles.preciosPiscina[j];
                     int temp10 = datosDelHotel.todosLosHoteles.preciosSauna[j];
                     int temp11 = datosDelHotel.todosLosHoteles.preciosGimnasio[j];
                     int temp12 = datosDelHotel.todosLosHoteles.preciosSpa[j];
                     int temp13 = datosDelHotel.todosLosHoteles.preciosInternet[j];
                     
                     datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[j] = datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[j + 1];
                     datosDelHotel.todosLosHoteles.nombresDeHoteles[j] = datosDelHotel.todosLosHoteles.nombresDeHoteles[j + 1];
                     datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[j] = datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[j + 1];
                     datosDelHotel.todosLosHoteles.estrellasDeHoteles[j] = datosDelHotel.todosLosHoteles.estrellasDeHoteles[j + 1];
                     datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[j] = datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[j + 1];
                     datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[j] = datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[j + 1];
                     datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[j] = datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[j + 1];
                     datosDelHotel.todosLosHoteles.preciosParqueadero[j] = datosDelHotel.todosLosHoteles.preciosParqueadero[j + 1];
                     datosDelHotel.todosLosHoteles.preciosRestaurante[j] = datosDelHotel.todosLosHoteles.preciosRestaurante[j + 1];
                     datosDelHotel.todosLosHoteles.preciosPiscina[j] = datosDelHotel.todosLosHoteles.preciosPiscina[j + 1];
                     datosDelHotel.todosLosHoteles.preciosSauna[j] = datosDelHotel.todosLosHoteles.preciosSauna[j + 1];
                     datosDelHotel.todosLosHoteles.preciosGimnasio[j] = datosDelHotel.todosLosHoteles.preciosGimnasio[j + 1];
                     datosDelHotel.todosLosHoteles.preciosSpa[j] = datosDelHotel.todosLosHoteles.preciosSpa[j + 1];
                     datosDelHotel.todosLosHoteles.preciosInternet[j] = datosDelHotel.todosLosHoteles.preciosInternet[j + 1];
                     
                     datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[j + 1] = temp;
                     datosDelHotel.todosLosHoteles.nombresDeHoteles[j + 1] = temp1;
                     datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[j + 1] = temp2;
                     datosDelHotel.todosLosHoteles.estrellasDeHoteles[j + 1] = temp3;
                     datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[j + 1] = temp4;
                     datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[j + 1] = temp5;
                     datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[j + 1] = temp6;
                     datosDelHotel.todosLosHoteles.preciosParqueadero[j + 1] = temp7;
                     datosDelHotel.todosLosHoteles.preciosRestaurante[j + 1] = temp8;
                     datosDelHotel.todosLosHoteles.preciosPiscina[j + 1] = temp9;
                     datosDelHotel.todosLosHoteles.preciosSauna[j + 1] = temp10;
                     datosDelHotel.todosLosHoteles.preciosGimnasio[j + 1] = temp11;
                     datosDelHotel.todosLosHoteles.preciosSpa[j + 1] = temp12;
                     datosDelHotel.todosLosHoteles.preciosInternet[j + 1] = temp13;
               } 
          }
     }
     
     for(int i = 0; i < datosDelHotel.cantHoteles; i++){
           MuestraInfoHotel(datosDelHotel, i);
           cout<<endl;
     }
}

void MuestraInfoHotel(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls");
     cout<<"Nombre del hotel= "<<datosDelHotel.todosLosHoteles.nombresDeHoteles[posHotelAReservar]<<endl;
     cout<<"Ubicacion del hotel= "<<datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[posHotelAReservar]<<endl;
     cout<<"Estrellas del hotel= "<<datosDelHotel.todosLosHoteles.estrellasDeHoteles[posHotelAReservar]<<endl;
     cout<<"Habitaciones individuales disponibles del hotel= "<<datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[posHotelAReservar]<<endl;
     cout<<"Habitaciones dobles disponibles del hotel= "<<datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[posHotelAReservar]<<endl;
     cout<<"Habitaciones familiares disponibles del hotel= "<<datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[posHotelAReservar]<<endl;
     cout<<"Puntuacion del hotel= "<<datosDelHotel.comentariosHoteles.puntuacionHoteles[posHotelAReservar]<<endl;
     cout<<"Comentarios del hotel= "<<datosDelHotel.comentariosHoteles.comentariosDeHoteles[posHotelAReservar]<<endl;
     system("pause");
}

string getDate()
{
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);

    stringstream ss_year;
    ss_year << timePtr->tm_year+1900;
    string Year = ss_year.str();

    stringstream ss_month;
    ss_month << timePtr->tm_mon+1;
    string Month = ss_month.str();
    if(atoi(Month.c_str()) < 10)
        Month = "0"+Month;

    stringstream ss_day;
    ss_day << timePtr->tm_mday;
    string Day = ss_day.str();
    if(atoi(Day.c_str()) < 10)
        Day = "0"+Day;
    
    string Fecha = Day+"/"+Month+"/"+Year;
    //string Fecha = Year+Month+Day+"_"+Hour+Min+Sec;

    return Fecha;
}

string GetDay(){
     time_t t = time(NULL);
	 tm* timePtr = localtime(&t);
     
     stringstream ss_day;
     ss_day << timePtr->tm_mday;
     string Day = ss_day.str();
     if(atoi(Day.c_str()) < 10)
         Day = "0"+Day;
         
     return Day; 
}

string GetMonth(){
     time_t t = time(NULL);
	 tm* timePtr = localtime(&t);
	 
	 stringstream ss_month;
     ss_month << timePtr->tm_mon+1;
     string Month = ss_month.str();
     if(atoi(Month.c_str()) < 10)
         Month = "0"+Month;
         
     return Month;
}

string GetYear(){
     time_t t = time(NULL);
	 tm* timePtr = localtime(&t);
     
     stringstream ss_year;
     ss_year << timePtr->tm_year+1900;
     string Year = ss_year.str(); 
     
     return Year; 
}

string getHour(){
       
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);   
       
    stringstream ss_hour;
    ss_hour << timePtr->tm_hour;
    string Hour = ss_hour.str();
    if(atoi(Hour.c_str()) < 10)
        Hour = "0"+Hour;

    stringstream ss_min;
    ss_min << timePtr->tm_min;
    string Min = ss_min.str();
    if(atoi(Min.c_str()) < 10)
        Min = "0"+Min;

    stringstream ss_sec;
    ss_sec << timePtr->tm_sec;
    string Sec = ss_sec.str();
    if(atoi(Sec.c_str()) < 10)
        Sec = "0"+Sec;
        
    string Hora = Hour+":"+Min+":"+Sec;
    
    return Hora;
}

void FechaAQuedarse(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls"); 
     int dia, mes, anio;
     
     cout<<"Ingrese el dia, mes y año en el que llegará al hotel simultaneamente: \n"<<endl;
     cout<<"Dia= ";
     cin>>dia;
     cout<<"\nMes= ";
     cin>>mes;
     cout<<"\nAnio= ";
     cin>>anio;
     
     if(mes < (atoi(GetMonth().c_str()))){  //Aqui va el mes actual
         cout<<"\nFecha no disponible: "<<endl;
         FechaAQuedarse(datosDelHotel, posHotelAReservar);
     }
     
     if((atoi(GetMonth().c_str())) == mes){    //Aqui va el mes actual
          if(dia < (atoi(GetDay().c_str()))){      //Aqui va el dia actual
               cout<<"\nFecha no disponible: "<<endl;
               FechaAQuedarse(datosDelHotel, posHotelAReservar);
          }
     }
     
     if(dia > 31 || dia < 1 || mes > 12 || mes < 1 || anio < 2019){
            cout<<"\nFecha no disponible: "<<endl;
            FechaAQuedarse(datosDelHotel, posHotelAReservar);
     }
     
     int diasAQuedarse = 0;
     cout<<"Ingrese los dias que se quedará= ";
     cin>>diasAQuedarse;
     int mesActual = mes;
     int diasRestantes = diasAQuedarse + dia;
     int anioActual = anio;
     
     while((dia + diasAQuedarse) > 31){
          diasRestantes = (dia + diasAQuedarse) - 31;
          mesActual++;
          if(mesActual == 12){
              mesActual = 1;
              anioActual++;
          }
          diasAQuedarse = diasRestantes;
     }
     
     datosDelHotel.precioTotal += datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[posHotelAReservar] * diasAQuedarse;
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] = datosDelHotel.precioTotal;
     
     cout<<"Fecha en la que saldrá del hotel es= ";
     cout<<diasRestantes<<"/"<<mesActual<<"/"<<anioActual<<endl;
     system("pause");
}

void Comentar(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls"); 
     cout<<"Ingrese comentario: "<<endl;
     fflush(stdin);
     gets(datosDelHotel.comentariosHoteles.comentario);
     
     datosDelHotel.comentariosHoteles.comentariosDeHoteles[posHotelAReservar] = datosDelHotel.comentariosHoteles.comentario;
}

void Puntuar(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls"); 
     int puntuacion;
     cout<<"Ingrese la puntuacion que le da a nuestro hotel del 1 al 10"<<endl;
     cin>>puntuacion;
     
     if(puntuacion > 10){
          cout<<"Puntuacion no disponible"<<endl;
          Puntuar(datosDelHotel, posHotelAReservar);               
     }else{
          if(puntuacion < 1){
                cout<<"Puntuacion no disponible"<<endl;
                Puntuar(datosDelHotel, posHotelAReservar);             
          } else{
                datosDelHotel.comentariosHoteles.puntuacionHoteles[posHotelAReservar] = puntuacion;
          }
     }
}

void Opiniones(DatosHotel &datosDelHotel, int &posHotelAReservar){
     int op = 1;
     
     while(op != 0){
           system("cls"); 
           cout<<"Ingrese 1 si desea agregar un comentario sobre el hotel."<<endl;
           cout<<"Ingrese 2 si desea puntuar el hotel."<<endl;
           
           cin>>op;
           
           switch(op){
                   case 1:
                        Comentar(datosDelHotel, posHotelAReservar);
                        break;
                   case 2:
                        Puntuar(datosDelHotel, posHotelAReservar);
                        break;           
           }       
     }     
}

void Parqueadero(DatosHotel &datosDelHotel, int &posHotelAReservar){
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] += datosDelHotel.todosLosHoteles.preciosParqueadero[posHotelAReservar];
     datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]++;
}

void Restaurante(DatosHotel &datosDelHotel, int &posHotelAReservar){
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] += datosDelHotel.todosLosHoteles.preciosRestaurante[posHotelAReservar];
     datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]++;
}

void Piscina(DatosHotel &datosDelHotel, int &posHotelAReservar){
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] += datosDelHotel.todosLosHoteles.preciosPiscina[posHotelAReservar];
     datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]++;
}

void Sauna(DatosHotel &datosDelHotel, int &posHotelAReservar){
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] += datosDelHotel.todosLosHoteles.preciosSauna[posHotelAReservar];
     datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]++;
}

void Gimnasio(DatosHotel &datosDelHotel, int &posHotelAReservar){
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] += datosDelHotel.todosLosHoteles.preciosGimnasio[posHotelAReservar];
     datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]++;
}

void Spa(DatosHotel &datosDelHotel, int &posHotelAReservar){
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] += datosDelHotel.todosLosHoteles.preciosSpa[posHotelAReservar];
     datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]++;
}

void Internet(DatosHotel &datosDelHotel, int &posHotelAReservar){
     datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar] += datosDelHotel.todosLosHoteles.preciosInternet[posHotelAReservar];
     datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]++;
}

void Filtros(DatosHotel &datosDelHotel, int &posHotelAReservar){
     int op = 1;
     system("cls"); 
     while(op != 0){
          system("cls"); 
          cout<<"Ingrese los filtros que desea: "<<endl;
          cout<<"Ingrese 1 para parqueadero: "<<endl;
          cout<<"Ingrese 2 para restaurante: "<<endl;
          cout<<"Ingrese 3 para piscina: "<<endl;
          cout<<"Ingrese 4 para sauna: "<<endl;
          cout<<"Ingrese 5 para gimnasio: "<<endl;
          cout<<"Ingrese 6 para spa: "<<endl;
          cout<<"Ingrese 7 para internet: "<<endl;
          cout<<"Ingrese 0 para salir."<<endl;
          cin>>op;
          
          switch(op){
                case 1:
                     Parqueadero(datosDelHotel, posHotelAReservar);
                     break;
                case 2:
                     Restaurante(datosDelHotel, posHotelAReservar);
                     break;
                case 3:
                     Piscina(datosDelHotel, posHotelAReservar);
                     break;
                case 4:
                     Sauna(datosDelHotel, posHotelAReservar);
                     break;
                case 5:
                     Gimnasio(datosDelHotel, posHotelAReservar);
                     break;
                case 6:
                     Spa(datosDelHotel, posHotelAReservar);
                     break;
                case 7:
                     Internet(datosDelHotel, posHotelAReservar);
                     break;         
          }
     }
}

void ReservaHabitacionIndividual(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls"); 
     if(datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[posHotelAReservar] >= 1){
          //cout<<"Funcion Fecha que se va a quedar"<<endl;
          getHour();
          Filtros(datosDelHotel, posHotelAReservar);
          Opiniones(datosDelHotel, posHotelAReservar);
          datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[posHotelAReservar]--;
          datosDelHotel.todosLosHoteles.cantHabitacionesReservadas[posHotelAReservar]++;
          FechaAQuedarse(datosDelHotel, posHotelAReservar);                                                                                     
     }else{
         cout<<"\nNo hay habitaciones individuales disponibles"<<endl;
         system("pause");      
     }
     
}

void ReservaHabitacionDoble(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls"); 
     if(datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[posHotelAReservar] >= 1){
          getHour();
          Filtros(datosDelHotel, posHotelAReservar);
          Opiniones(datosDelHotel, posHotelAReservar);
          datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[posHotelAReservar]--;
          datosDelHotel.todosLosHoteles.cantHabitacionesReservadas[posHotelAReservar]++;
          FechaAQuedarse(datosDelHotel, posHotelAReservar);
     }else{
          cout<<"\nNo hay habitaciones dobles disponibles"<<endl;
          system("pause");      
     }
     
}

void ReservaHabitacionFamiliar(DatosHotel &datosDelHotel, int &posHotelAReservar){
     system("cls"); 
     if(datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[posHotelAReservar] >= 1){
         getHour();
         Filtros(datosDelHotel, posHotelAReservar);
         Opiniones(datosDelHotel, posHotelAReservar);
         datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[posHotelAReservar]--;
         datosDelHotel.todosLosHoteles.cantHabitacionesReservadas[posHotelAReservar]++;
         FechaAQuedarse(datosDelHotel, posHotelAReservar);
     }else{
         cout<<"\nNo hay habitaciones familiares disponibles"<<endl;
         system("pause");  
     }
}

void BuscaHotelAReservar(DatosHotel &datosDelHotel){
     system("cls"); 
    char hotelABuscar[100];
    cout<<"Ingrese el nombre del hotel que desea reservar= ";
    fflush(stdin);
    gets(hotelABuscar);
     
    for(int i = 0; i < datosDelHotel.cantHoteles; i++){
        cout<<hotelABuscar<<"="<<datosDelHotel.todosLosHoteles.nombresDeHoteles[i]<<endl;
        system("pause");
        if(hotelABuscar == datosDelHotel.todosLosHoteles.nombresDeHoteles[i]){
        	ReservarHotel(datosDelHotel, i);         
        }
    }
}

void BuscaHotelesPorCiudad(DatosHotel &datosDelHotel){
    system("cls"); 
    char ciudadABuscar[100];
    cout<<"Ingrese la ciudad en la que desea ver hoteles";
    fflush(stdin);
    gets(ciudadABuscar);
     
    for(int i = 0; i < datosDelHotel.cantHoteles; i++){
        if(ciudadABuscar == datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[i]){
            cout<<"Hotel "<<datosDelHotel.todosLosHoteles.nombresDeHoteles[i]<<endl;                 
        }        
    }
    
    system("pause");
}

void OpcionesUsuario(DatosHotel &datosDelHotel){
    int op = 1;
     
    while(op != 0){
        system("cls");
    	cout<<"Ingrese 1 para reservar un hotel en especifico"<<endl;
        cout<<"Ingrese 2 para buscar hoteles por ciudad"<<endl;
        cout<<"Ingrese 3 para mostrar los hoteles disponibles"<<endl;
        cin>>op;
          
        switch(op){
        	case 1:{
        		BuscaHotelAReservar(datosDelHotel);
				break;
			}
			
			case 2:{
                BuscaHotelesPorCiudad(datosDelHotel);
				break;
			}
			
			case 3:{
				cout<<"\nMuestra todos los hoteles"<<endl;
				MuestraTodosLosHoteles(datosDelHotel);
				break;
			}
        }
    }     
}

void OpcionesAdministrador(DatosHotel &datosDelHotel){
    int op = 1;
    //datosDelHotel.cantHoteles = 0;
     
    while(op != 0){
        system("cls");   
        cout<<"Ingrese 1 para ingresar un hotel"<<endl;
        cout<<"Ingrese 2 para mostrar hoteles"<<endl;
        cout<<"Ingrese 0 para cerrar sesion"<<endl;
        cin>>op;
           
        switch(op){
            case 1:{
                IngresarHoteles(datosDelHotel);
                break;
            }
            case 2:{
                MuestraHoteles(datosDelHotel);
                break;
            }
        }     
    }     
}

//Pregunta si desea ingresar a la pagina como usuario o como administrador
void Loguearse(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador, DatosHotel &datosDelHotel){
    int op = 1;
    system("start Presentacion.html");
      
    while(op != 0){
        system("cls");
        cout<<"Ingrese 1 para loguearse como usuario"<<endl;
        cout<<"Ingrese 2 para loguearse como administrador"<<endl;
        cin>>op;
        
        switch(op){
        	case 1:{
        		LoguearseComoUsuario(datosDelUsuario, estaRegistrado, datosDelHotel);
				break;
			}
			
			case 2:{
                LoguearseComoAdministrador(datosDelAdministrador, estaRegistrado, datosDelHotel);
				break;
			}        
        }        
    }     
}

//Se ejecuta si se elige ingresar a la pagina como administrador
void LoguearseComoAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado, DatosHotel &datosDelHotel){
    system("cls");
	char NombreAdministrador[100];
    cout<<"Ingrese su usuario de administrador= ";
    fflush(stdin);
    gets(NombreAdministrador);
    cout<<endl;
    char ContraseniaAdministrador[100];
    cout<<"Ingrese su contraseña de administrador= ";
    fflush(stdin);
    gets(ContraseniaAdministrador);
    cout<<endl;
     
    int cantLogIn = 0;
     
    for(int i = 0; i < datosDelAdministrador.cantAdministradores; i++){
        if(NombreAdministrador == datosDelAdministrador.todosLosAdmin.UsersAdministradores[i]){
            if(ContraseniaAdministrador == datosDelAdministrador.todosLosAdmin.ContrasAdministradores[i]){
                cout<<"Te has logueado exitosamente como administrador!"<<endl;
                cantLogIn++;
                OpcionesAdministrador(datosDelHotel);           
            }                       
    	}
    }
     
    if(cantLogIn == 0){
        cout<<"El usuario o la contraseña no corresponde con una cuenta"<<endl;             
    }else{
        cantLogIn = 0;      
    }
}    

//Se ejecuta si se elije ingresar a la pagina como usuario corriente
void LoguearseComoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosHotel &datosDelHotel){
    system("cls");
    char NombreUsuario[100];
    cout<<"Ingrese su usuario= ";
    fflush(stdin);
    gets(NombreUsuario);
    cout<<endl;
    char ContraseniaUsuario[100];
    cout<<"Ingrese su contraseña= ";
    fflush(stdin);
    gets(ContraseniaUsuario);
    cout<<endl;
     
    int cantLogIn = 0;
     
    for(int i = 0; i < datosDelUsuario.cantUsuarios; i++){
    	if(NombreUsuario == datosDelUsuario.todosLosUsuarios.UsersUsuarios[i]){
            if(ContraseniaUsuario == datosDelUsuario.todosLosUsuarios.ContrasUsuarios[i]){
                cout<<"Te has logueado exitosamente!"<<endl;
                system("start Pagina_principal.html");
                cantLogIn++;
            	OpcionesUsuario(datosDelHotel);         
            }                 
        }
    }
     
    if(cantLogIn == 0){
        cout<<"El usuario o la contraseña no corresponde con una cuenta"<<endl;
    }else{
        cantLogIn = 0;      
    }
}

//Muestra todos los administradores de la pagina
void MuestraDatosAdmins(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado){
    for(int i = 0; i < datosDelAdministrador.cantAdministradores; i++){
        cout<<"ADMINISTRADOR "<<i+1<<endl;
        cout<<"CEDULA= "<<datosDelAdministrador.todosLosAdmin.CedulasAdministradores[i]<<endl;
        cout<<"CONTRASENA= "<<datosDelAdministrador.todosLosAdmin.ContrasAdministradores[i]<<endl;
        cout<<"NOMBRE= "<<datosDelAdministrador.todosLosAdmin.NombresAdministradores[i]<<endl;
        cout<<"USUARIO= "<<datosDelAdministrador.todosLosAdmin.UsersAdministradores[i]<<endl;
        cout<<endl;      
    }
}

//FUNCION TEMPORAL QUE MUESTRA TODOS LOS USUARIOS DE LA BASE DE DATOS

//Muestra todos los usuarios de la pagina
void MuestraDatosUsuarios(DatosUsuario &datosDelUsuario, bool &estaRegistrado){
     
     for(int i = 0; i < datosDelUsuario.cantUsuarios; i++){
        cout<<"USUARIO "<<i+1<<endl;
        cout<<"CEDULA= "<<datosDelUsuario.todosLosUsuarios.CedulasUsuarios[i]<<endl;
        cout<<"CONTRASENA= "<<datosDelUsuario.todosLosUsuarios.ContrasUsuarios[i]<<endl;
        cout<<"NOMBRE= "<<datosDelUsuario.todosLosUsuarios.NombresUsuarios[i]<<endl;
        cout<<"USUARIO= "<<datosDelUsuario.todosLosUsuarios.UsersUsuarios[i]<<endl;      
        cout<<endl; 
    }
}

//Define si se quiere registrar como administrador o como usuario corriente
void DefineTipoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
    system("cls");
    int op = 1;
    system("start Registro.html");        //Aqui va el inicio de la vista principal         
     
    while(op != 0){
        system("cls"); 
        cout<<"Desea registrarse como administrador o como usuario corriente?"<<endl;
        cout<<"Ingrese 1 si quiere registrarse como administrador"<<endl;
        cout<<"Ingrese 2 si quiere registrarse como usuario corriente"<<endl;
         
        cin>>op;
         
        switch(op){
            case 1:{
            	RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario);
				break;
			}
            case 2:{
            	RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);
				break;
			}
        }           
    }
}

//Se ejecuta si se elige registrar como administrador
void RegistroAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado, DatosUsuario &datosDelUsuario){
     system("cls"); 
    //Valida si el usuario está registrado
    if(!estaRegistrado){
        //ALMACENA TODOS LOS DATOS NECESARIOS PARA EL REGISTRO EN LA ESTRUCTURA DatosUsuario
        cout<<"Ingrese su nombre completo= ";
        fflush(stdin);
        gets(datosDelAdministrador.NameAdmin);
        cout<<"\n"<<endl;
        cout<<"Ingrese su numero de cedula= ";
        cin>>datosDelAdministrador.IDAdmin;
        cout<<"\n"<<endl;
        cout<<"Ingrese el usuario que desea= ";
        fflush(stdin);
        gets(datosDelAdministrador.UserAdmin);
        cout<<"\n"<<endl;
        cout<<"Ingrese la contraseña que desea= ";
        fflush(stdin);
        gets(datosDelAdministrador.passwordAdmin);
          
        int cantRepeticionesCedula = 0;
        int cantRepeticionesUser = 0;
          
        //Recorre todos los administradores y valida si puede crear la cuenta.
        for(int i = 0; i < datosDelAdministrador.cantAdministradores; i++){
            if(datosDelAdministrador.IDAdmin == datosDelAdministrador.todosLosAdmin.CedulasAdministradores[i]){
                cantRepeticionesCedula++;                        
            }
            if(datosDelAdministrador.UserAdmin == datosDelAdministrador.todosLosAdmin.UsersAdministradores[i]){
                cantRepeticionesUser++;                    
            }
            
			for(int j = 0; j < datosDelUsuario.cantUsuarios; j++){
                cout<<"Segundo for de administrador"<<endl;
                
				if(datosDelAdministrador.IDAdmin == datosDelUsuario.todosLosUsuarios.CedulasUsuarios[j]){
                	cantRepeticionesCedula++;                      
                }
                if(datosDelAdministrador.UserAdmin == datosDelUsuario.todosLosUsuarios.UsersUsuarios[j]){
                    cantRepeticionesUser++;                       
                }
            }
        }
          
        //Validaciones de entrada.
        if(cantRepeticionesCedula != 0){
            cantRepeticionesCedula = 0;
            cout<<"\nYa existe un usuario con esa cedula registrada\n"<<endl;
            RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario);               
        }else{
            if(datosDelAdministrador.IDAdmin < 10000000 || datosDelAdministrador.IDAdmin > 2222222222){
                cout<<"\nCedula no valida\n"<<endl;
                RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario); 
            }else{
                if(cantRepeticionesUser != 0){
                    cantRepeticionesUser = 0;
                    cout<<"\nYa existe un usuario con ese usuario registrado\n"<<endl;
                    RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario);   
                }else{
                    datosDelAdministrador.todosLosAdmin.CedulasAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.IDAdmin;
                    datosDelAdministrador.todosLosAdmin.ContrasAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.passwordAdmin;
                    datosDelAdministrador.todosLosAdmin.NombresAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.NameAdmin;
                    datosDelAdministrador.todosLosAdmin.UsersAdministradores[datosDelAdministrador.cantAdministradores] = datosDelAdministrador.UserAdmin;
                    datosDelAdministrador.cantAdministradores++; 
                }
            }
        }
        
        system("cls");
        //Con esta parte confirmamos siquedan guardados los datos.
        cout<<datosDelAdministrador.NameAdmin<<endl;
        cout<<datosDelAdministrador.IDAdmin<<endl;
        cout<<datosDelAdministrador.UserAdmin<<endl;
        cout<<datosDelAdministrador.passwordAdmin<<endl;
        //Quedan guardados.
          
        //estaRegistrado = true;
    }/*else{
        IngresarDatos(datosDelUsuario);         //INGRESA LOS DATOS SI YA ESTÁ REGISTRADO.
    }*/
}

//Registra al usuario si no lo está, si lo está, pide los datos para loguearse
//Se ejecuta si se desea registrar como usuario corriente.
void RegistroUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     system("cls"); 
    //Valida si el usuario está registrado
    if(!estaRegistrado){
        //ALMACENA TODOS LOS DATOS NECESARIOS PARA EL REGISTRO EN LA ESTRUCTURA DatosUsuario
        cout<<"Ingrese su nombre completo= ";
        fflush(stdin);
        gets(datosDelUsuario.Name);
        cout<<"\n"<<endl;
        cout<<"Ingrese su numero de cedula= ";
        cin>>datosDelUsuario.ID;
        cout<<"\n"<<endl;
        cout<<"Ingrese el usuario que desea= ";
        fflush(stdin);
        gets(datosDelUsuario.User);
        cout<<"\n"<<endl;
        cout<<"Ingrese la contraseña que desea= ";
        fflush(stdin);
        gets(datosDelUsuario.password);
          
        int cantRepeticionesCedula = 0;
        int cantRepeticionesUser = 0;
          
          //Recorre todos los usuarios y valida si se puede crear la cuenta.
        for(int i = 0; i < datosDelUsuario.cantUsuarios; i++){
            if(datosDelUsuario.ID == datosDelUsuario.todosLosUsuarios.CedulasUsuarios[i]){
                cantRepeticionesCedula++;
            }
            if(datosDelUsuario.User == datosDelUsuario.todosLosUsuarios.UsersUsuarios[i]){
                cantRepeticionesUser++;                    
            }
            
			for(int j = 0; j < datosDelAdministrador.cantAdministradores; j++){
                cout<<"Segundo for de usuario"<<endl;
                if(datosDelUsuario.ID == datosDelAdministrador.todosLosAdmin.CedulasAdministradores[j]){
                    cantRepeticionesCedula++;                      
                }
                if(datosDelUsuario.User == datosDelAdministrador.todosLosAdmin.UsersAdministradores[j]){
                    cantRepeticionesUser++;                       
                }
            }
        }
          
        //Validaciones de entrada
        if(cantRepeticionesCedula != 0){
        	cantRepeticionesCedula = 0;
            cout<<"\nYa existe un usuario con esa cedula registrada\n"<<endl;
            RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);                
        }else{
            if(datosDelUsuario.ID < 10000000 || datosDelUsuario.ID > 2222222222){
                cout<<"\nCedula no valida\n"<<endl;
                RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);
            }else{
                if(cantRepeticionesUser != 0){
                    cantRepeticionesUser = 0;
                    cout<<"\nYa existe un usuario con ese usuario registrado\n"<<endl;
                    RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);  
                }else{
                	datosDelUsuario.todosLosUsuarios.CedulasUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.ID;
                	datosDelUsuario.todosLosUsuarios.ContrasUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.password;
                    datosDelUsuario.todosLosUsuarios.NombresUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.Name;
                    datosDelUsuario.todosLosUsuarios.UsersUsuarios[datosDelUsuario.cantUsuarios] = datosDelUsuario.User;
                    datosDelUsuario.cantUsuarios++; 
                }
            }
        }
          
          
          
        system("cls");
        //Con esta parte confirmamos siquedan guardados los datos.
        cout<<datosDelUsuario.Name<<endl;
        cout<<datosDelUsuario.ID<<endl;
    	cout<<datosDelUsuario.User<<endl;
        cout<<datosDelUsuario.password<<endl;
        //Si pilla, si quedan guardados xD.
          
        //estaRegistrado = true;
    }/*else{
        IngresarDatos(datosDelUsuario);         //INGRESA LOS DATOS SI YA ESTÁ REGISTRADO.
    }*/
}

//Funcion que pide los datos de usuario para poder ingresar.
void IngresarDatos(DatosUsuario &datosDelUsuario){
     
    cout<<"Ya tienes un usuario registrado.\n\n"<<endl;
     
    //Ingresa el usuario
    cout<<"Ingrese su usuario= "<<endl;
    char usuario[100];
    fflush(stdin);
    gets(usuario);
    //Ingresa la contraseña
    cout<<"Ingrese su contraseña= "<<endl;
    char contrasenia[100];
    fflush(stdin);
    gets(contrasenia);
     
    /*
    for(int i = 0; i < strlen(usuario); i++){              
    }*/
    
    if(usuario == datosDelUsuario.User){
    	if(contrasenia == datosDelUsuario.password){
            cout<<"\n\nLogeado correctamente!"<<endl;               
        }           
    }
     
}

void Escribir_principal(DatosHotel &datosDelHotel){
    ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	
	archivo.open("Pagina_principal.html", ios::out);
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<html>";
	
	archivo<<"<head>";
	
	archivo<<"<title>Proyecto final programacion 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend para proyecto final del segundo semestre.css'>";
	archivo<<"<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.js' type='text/javascript'></script>";
	archivo<<"<script src='JavaScript/JS_main_pg.js'></script>";
	
	archivo<<"</head>";
	
	archivo<<"<body>";
	
	archivo<<"<header>";
	
	archivo<<"<div id='search_div'>";
	archivo<<"<input type='text' placeholder='Buscar' name='Buscar' id='search'>";
	archivo<<"<input type='button' value='Buscar' id='button_buscar' onclick='buscador()'>";
	archivo<<"</div>";
	
	archivo<<"<br>";
	
	archivo<<"<div id='dates'>";
	archivo<<"<input id='fecha' type='button' value='Tiempo de estancia'>";
	archivo<<"<div id='banner_fecha' class='banners'>";
	
	archivo<<"<div id='month'>";
	archivo<<"<h2>Eliga el mes: </h2>";
	archivo<<"<p>  <a href='#' onclick='enviar_mes(1)'>Enero</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(2)'>Febrero</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(3)'>Marzo</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(4)'>Abril</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(5)'>Mayo</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(6)'>Junio</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(7)'>Julio</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(8)'>Agosto</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(9)'>Septiembre</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(10)'>Octubre</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(11)'>Noviembre</a>  ";
	archivo<<"  <a href='#' onclick='enviar_mes(12)'>Diciembre</a>  </p>";
	archivo<<"</div>";
	
	archivo<<"<div id='day'>";
	archivo<<"<h2>Eliga el dia: </h2>";
	archivo<<"<p>  <a href='#' onclick='enviar_dia(1)'>1</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(2)'>2</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(3)'>3</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(4)'>4</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(5)'>5</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(6)'>6</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(7)'>7</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(8)'>8</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(9)'>9</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(10)'>10</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(11)'>11</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(12)'>12</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(13)'>13</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(14)'>14</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(15)'>15</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(16)'>16</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(17)'>17</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(18)'>18</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(19)'>19</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(20)'>20</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(21)'>21</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(22)'>22</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(23)'>23</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(24)'>24</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(25)'>25</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(26)'>26</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(27)'>27</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(28)'>28</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(29)'>29</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(30)'>30</a>  ";
	archivo<<"  <a href='#' onclick='enviar_dia(31)'>31</a>  </p>";
	archivo<<"</div>";
	
	archivo<<"<label for='tiempo_de_estancia'>Tiempo de hospedaje</label>";
	archivo<<"<input type='text' placeholder='Ingrese el numero de dias que desea hospedarse en el hotel' id='ingresa_dias'>";
	
	archivo<<"</div>";
	archivo<<"<input id='menu' type='button' value='Menu'>";
	archivo<<"<div id='banner_menu' class='banners'>";
	archivo<<"<h2>Filtros</h2>";
	archivo<<"<input type='text' placeholder='Ingresar el nombre que busca'>";
	
	archivo<<"<br><br>";
	
	archivo<<"<label for='tags'>Tags</label>";
	
	archivo<<"<br><br>";
	
	archivo<<"<script>var adicional=0</script>";
	archivo<<"<input type='button' value='Wifi' id='wifi' onclick='seleccionado(adicional=1)'>";
	archivo<<"<input type='button' value='Parqueadero' id='parqueadero'  onclick='seleccionado(adicional=2)'>";
	archivo<<"<input type='button' value='Gimnasio' id='gimnasio'  onclick='seleccionado(adicional=3)'>";
	archivo<<"<input type='button' value='Restaurante' id='restaurante'  onclick='seleccionado(adicional=4)'>";
	archivo<<"<input type='button' value='Piscina' id='piscina'  onclick='seleccionado(adicional=5)'>";
	archivo<<"<input type='button' value='Spa' id='spa'  onclick='seleccionado(adicional=6)'>";
	archivo<<"<input type='button' value='Sauna' id='sauna'  onclick='seleccionado(adicional=7)'>";
	
	archivo<<"<br><br>";
	
	archivo<<"<input type='button' value='Filtrar' id='filtrar' onclick='location.reload()'>";
	
	archivo<<"<br>";
	
	archivo<<"<input type='button' value='Mas opciones' id='more'>";
	
	archivo<<"<div id='more_options'>";
	
	archivo<<"<h2>Mas opciones</h2>";
	archivo<<"<label for='ubicacion'>Ubicacion</label>";
	
	archivo<<"<br>";
	
	archivo<<"<input type='text' placeholder='Ingresa la ubicacion que deseas'>";
	
	archivo<<"<br><br>";
	
	archivo<<"<div id='puntuacion'>";
	archivo<<"<label for='puntuacion'>Puntuacion</label>";
	archivo<<"<br>";
	
	archivo<<"<input type='radio' name='puntuacion'> 5 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 4 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 3 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 2 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 1 estrellas<br>";
	archivo<<"</div>";
	
	archivo<<"<div id='hospedaje'>";
	archivo<<"<label for='hospedaje'>Hospedaje</label>";
	archivo<<"<br>";
	archivo<<"<input type='checkbox' name='feedback'> 100 Excelente<br>";
	archivo<<"<input type='checkbox' name='feedback'> 80 Muy Bueno<br>";
	archivo<<"<input type='checkbox' name='feedback'> 60 Bueno<br>";
	archivo<<"<input type='checkbox' name='feedback'> 40 Razonable<br>";
	archivo<<"<input type='checkbox' name='feedback'> 20 Aceptable<br>";
	archivo<<"<input type='checkbox' name='feedback'> 0 Sin calificar<br>";
	archivo<<"</div>";
	
	archivo<<"<br><br>";
	
	archivo<<"<label for='precio_por_noche'>Precio por noche</label>";
	archivo<<"<input type='range' name='price_per_nigth' value='180000' min='180000' max='1800000' autocomplete='off'>";
	archivo<<"<br>";
	archivo<<"<input type='button' value='Filtrar'>";
	
	archivo<<"</div>";
	
	archivo<<"</div>";
	
	archivo<<"</header>";
	
	archivo<<"<section class='main'>";
	
	/*Esto muestra los datos de las estructuras*/
	
	archivo<<"<article class='galeria'>";
	archivo<<"<img src='Imagenes/cancun.jpg' alt='Imagen' class='preView'>";
	archivo<<"<div class='title'>";
	archivo<<"<h2 class='refence'><a href='https://goo.gl/maps/hxJcrHy1dYt' class='reference' target='_blank'>"<<datosDelHotel.todosLosHoteles.nombresDeHoteles[0]<<"</a></h2>";
	archivo<<"</div>";
	
	/*Acá va la función del numero de estrellas*/
	
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	
	/*Acá va la función del numero de estrellas*/
	
	archivo<<"<div class='prices'>";
	archivo<<"<h3>Precio por noche</h3>";
	archivo<<"<br>";
	string val_numerico;
	val_numerico='1800000';
	archivo<<"<p>"<<datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[0]<<"</p>";
	archivo<<"<input type='button' value='comprar' id='compra' onclick='enviar_compra(1800000)'>";
	archivo<<"</div>";
	string identificador_de_caja, indentificador_de_comentario;
	identificador_de_caja='#desplegar_1', indentificador_de_comentario='#1';
	archivo<<"<div class='desplegar' id='desplegar_1'>";
	archivo<<"<a href='#' onclick='mostrar("<<identificador_de_caja<<","<<indentificador_de_comentario<<")'><img src='Imagenes/desplegar.png' alt='Comentarios'></a>";
	archivo<<"</div>";
	archivo<<"</article>";
	
	/*Función para mostrar comentarios*/
	
	archivo<<"<article class='comments' id='1'>";
	archivo<<"<div>";
	
	archivo<<"<div class='user_info'>";
	
	archivo<<"<img src='Imagenes/no_register.png' alt='Regular_user'>";
	archivo<<"<h4>Regular_user</h4>";
	
	archivo<<"</div>";
	archivo<<"<div class='comment_text'>";
	
	/*Acá va eld dato de los comentarios de la estructura*/
	
	archivo<<"<p></p>";
	
	/*Acá va eld dato de los comentarios de la estructura*/
	
	archivo<<"</div>";
	
	archivo<<"</div>";
	archivo<<"<form action='new_comment' id='fomr_comments'>";
	archivo<<"<label for='new_comments'>Agrega un comentario</label>";
	
	archivo<<"<br><br>";
	
	archivo<<"<textarea name='new_comments' id='nuevo_comentario' cols='30' rows='10' minlength='50' placeholder='Aquí puedes añadir un comentario'></textarea>";
	archivo<<"<input type='button' name='send' value='Añadir' id='añadir_comentario'>";
	archivo<<"</form>";
	
	archivo<<"<br>";
	
	archivo<<"</article>";
	
	/*Función para mostrar comentarios*/
	
	/*Esto muestra los datos de las estructuras*/
	
	archivo<<"<section id='pagar'>";
	archivo<<"<form action='pay'>";
	
	/*Aca se reemplazan nomnbres de usuario*/
	
	archivo<<"<p>Apreciado <b>cliente</b> es un placer tenerle en nuestra aplicacion y nuestro portal web, estamos muy agradecidos de presentar la <u>factura</u> que debe redimir bajo nuestro habituales <b><a href='Terminos_y_condiciones.html' target='_blank'>terminos y condiciones</a></b> esperamos que disfrute su viaje</p>";
	archivo<<"<br>";
	
	archivo<<"<input type='button' value='Aceptar terminos y condiciones' id='tersm_y_conditions'>";
	archivo<<"<a href='#' target='' id='enviar_factura'><input type='button' value='Facturar' id='facturar'></a>";
	archivo<<"<cite id='message'>Debes aceptar terminos y condiciones</cite>";
	archivo<<"</form>";
	archivo<<"</section>";
	
	archivo<<"<br><br>";
	
	archivo<<"<footer>";
	archivo<<"<blockquote id='show_autors'>Coltravels sas</blockquote>";
	archivo<<"<cite id='autores'>Cristian Andrés Grajales Pérez & Andrés Manuel Prieto Álvarez</cite>";
	archivo<<"</footer>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";

    /*Se requiere un vector con las urls, nombres e imagenes
	
	Con este vector se han de llenar src='' href='' y el texto
	que continua depues de >
	
	Esto se debe hacer con un bucle for que tendra por condición de
	para vct.legth() (El largo del vector)*/
	
	/* 
    for(int i=0;i<5;i++){
		archivo<<"<div class='galeria'>";
		archivo<<"<img src='Imagenes/cancun.jpg' alt='imagen'>";
		archivo<<"<div>";
		archivo<<"<h2 class='refence'><a href='https://goo.gl/maps/hxJcrHy1dYt' class='reference' target='_blank'>Hotel Occidental Costa de Cancun</a></h2>";
		archivo<<"</div>";
		
		
		
		//Esto saca las estrellas pero no sé como pasarlo a archivo debe ser un proceso XD
		
		for(int i=0;i<5;i++){
			archivo<<"<img src='Imagenes/Stars.png' alt='Estrella'>";
		}
		
		
		
		archivo<<"</div>";
	}
	*/

	archivo.close();
}

void Escribir_principal_del_admi(DatosHotel &datosDelHotel){
    ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	
	archivo.open("Pagina_principal.html", ios::out);
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<html>";
	
	archivo<<"<head>";
	
	archivo<<"<title>Proyecto final programacion 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend_para_main_pg_del_user.css'>";
	archivo<<"<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.js' type='text/javascript'></script>";
	archivo<<"<script src='JavaScript/JS_main_pg.js'></script>";
	
	archivo<<"</head>";
	
	archivo<<"<body>";
	
	archivo<<"<header>";
	
	archivo<<"<div id='search_div'>";
	archivo<<"<input type='text' placeholder='Buscar' name='Buscar' id='search'>";
	archivo<<"<input type='button' value='Buscar' id='button_buscar' onclick='buscador()'>";
	archivo<<"<a href='Ingreso_de_datos_del_admi.html'><input type='button' value='Agregar' id='agregar'></a>";
	archivo<<"</div>";
	
	archivo<<"<br>";
	
	archivo<<"<div id='dates'>";
	archivo<<"<input id='fecha' type='button' value='Tiempo de estancia'>";
	archivo<<"<div id='banner_fecha' class='banners'>";
	
	archivo<<"<div id='month'>";
	archivo<<"<h2>Eliga el mes: </h2>";
	archivo<<"<a href='#' onclick='enviar_mes(1)'>Enero</a>";
	archivo<<"<a href='#' onclick='enviar_mes(2)'>Febrero</a>";
	archivo<<"<a href='#' onclick='enviar_mes(3)'>Marzo</a>";
	archivo<<"<a href='#' onclick='enviar_mes(4)'>Abril</a>";
	archivo<<"<a href='#' onclick='enviar_mes(5)'>Mayo</a>";
	archivo<<"<a href='#' onclick='enviar_mes(6)'>Junio</a>";
	archivo<<"<a href='#' onclick='enviar_mes(7)'>Julio</a>";
	archivo<<"<a href='#' onclick='enviar_mes(8)'>Agosto</a>";
	archivo<<"<a href='#' onclick='enviar_mes(9)'>Septiembre</a>";
	archivo<<"<a href='#' onclick='enviar_mes(10)'>Octubre</a>";
	archivo<<"<a href='#' onclick='enviar_mes(11)'>Noviembre</a>";
	archivo<<"<a href='#' onclick='enviar_mes(12)'>Diciembre</a>";
	archivo<<"</div>";
	
	archivo<<"<div id='day'>";
	archivo<<"<h2>Eliga el dia: </h2>";
	archivo<<"<a href='#' onclick='enviar_dia(1)'>1</a>";
	archivo<<"<a href='#' onclick='enviar_dia(2)'>2</a>";
	archivo<<"<a href='#' onclick='enviar_dia(3)'>3</a>";
	archivo<<"<a href='#' onclick='enviar_dia(4)'>4</a>";
	archivo<<"<a href='#' onclick='enviar_dia(5)'>5</a>";
	archivo<<"<a href='#' onclick='enviar_dia(6)'>6</a>";
	archivo<<"<a href='#' onclick='enviar_dia(7)'>7</a>";
	archivo<<"<a href='#' onclick='enviar_dia(8)'>8</a>";
	archivo<<"<a href='#' onclick='enviar_dia(9)'>9</a>";
	archivo<<"<a href='#' onclick='enviar_dia(10)'>10</a>";
	archivo<<"<a href='#' onclick='enviar_dia(11)'>11</a>";
	archivo<<"<a href='#' onclick='enviar_dia(12)'>12</a>";
	archivo<<"<a href='#' onclick='enviar_dia(13)'>13</a>";
	archivo<<"<a href='#' onclick='enviar_dia(14)'>14</a>";
	archivo<<"<a href='#' onclick='enviar_dia(15)'>15</a>";
	archivo<<"<a href='#' onclick='enviar_dia(16)'>16</a>";
	archivo<<"<a href='#' onclick='enviar_dia(17)'>17</a>";
	archivo<<"<a href='#' onclick='enviar_dia(18)'>18</a>";
	archivo<<"<a href='#' onclick='enviar_dia(19)'>19</a>";
	archivo<<"<a href='#' onclick='enviar_dia(20)'>20</a>";
	archivo<<"<a href='#' onclick='enviar_dia(21)'>21</a>";
	archivo<<"<a href='#' onclick='enviar_dia(22)'>22</a>";
	archivo<<"<a href='#' onclick='enviar_dia(23)'>23</a>";
	archivo<<"<a href='#' onclick='enviar_dia(24)'>24</a>";
	archivo<<"<a href='#' onclick='enviar_dia(25)'>25</a>";
	archivo<<"<a href='#' onclick='enviar_dia(26)'>26</a>";
	archivo<<"<a href='#' onclick='enviar_dia(27)'>27</a>";
	archivo<<"<a href='#' onclick='enviar_dia(28)'>28</a>";
	archivo<<"<a href='#' onclick='enviar_dia(29)'>29</a>";
	archivo<<"<a href='#' onclick='enviar_dia(30)'>30</a>";
	archivo<<"<a href='#' onclick='enviar_dia(31)'>31</a>";
	archivo<<"</div>";
	
	archivo<<"<label for='tiempo_de_estancia'>Tiempo de hospedaje</label>";
	archivo<<"<input type='text' placeholder='Ingrese el numero de dias que desea hospedarse en el hotel' id='ingresa_dias'>";
	
	archivo<<"</div>";
	archivo<<"<input id='menu' type='button' value='Menu'>";
	archivo<<"<div id='banner_menu' class='banners'>";
	archivo<<"<h2>Filtros</h2>";
	archivo<<"<input type='text' placeholder='Ingreser el nombre que busca'>";
	
	archivo<<"<br><br>";
	
	archivo<<"<label for='tags'>Tags</label>";
	
	archivo<<"<br><br>";
	
	archivo<<"<script>var adicional=0</script>";
	archivo<<"<input type='button' value='Wifi' id='wifi' onclick='seleccionado(adicional=1)'>";
	archivo<<"<input type='button' value='Parqueadero' id='parqueadero'  onclick='seleccionado(adicional=2)'>";
	archivo<<"<input type='button' value='Gimnasio' id='gimnasio'  onclick='seleccionado(adicional=3)'>";
	archivo<<"<input type='button' value='Restaurante' id='restaurante'  onclick='seleccionado(adicional=4)'>";
	archivo<<"<input type='button' value='Piscina' id='piscina'  onclick='seleccionado(adicional=5)'>";
	archivo<<"<input type='button' value='Spa' id='spa'  onclick='seleccionado(adicional=6)'>";
	archivo<<"<input type='button' value='Sauna' id='sauna'  onclick='seleccionado(adicional=7)'>";
	
	archivo<<"<br><br>";
	
	archivo<<"<input type='button' value='Filtrar' id='filtrar' onclick='location.reload()'>";
	
	archivo<<"<br>";
	
	archivo<<"<input type='button' value='Mas opciones' id='more'>";
	
	archivo<<"<div id='more_options'>";
	
	archivo<<"<h2>Mas opciones</h2>";
	archivo<<"<label for='ubicacion'>Ubicacion</label>";
	
	archivo<<"<br>";
	
	archivo<<"<input type='text' placeholder='Ingresa la ubicacion que deseas'>";
	
	archivo<<"<br><br>";
	
	archivo<<"<div id='puntuacion'>";
	archivo<<"<label for='puntuacion'>Puntuacion</label>";
	archivo<<"<br>";
	
	archivo<<"<input type='radio' name='puntuacion'> 5 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 4 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 3 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 2 estrellas<br>";
	archivo<<"<input type='radio' name='puntuacion'> 1 estrellas<br>";
	archivo<<"</div>";
	
	archivo<<"<div id='hospedaje'>";
	archivo<<"<label for='hospedaje'>Hospedaje</label>";
	archivo<<"<br>";
	archivo<<"<input type='checkbox' name='feedback'> 100 Excelente<br>";
	archivo<<"<input type='checkbox' name='feedback'> 80 Muy Bueno<br>";
	archivo<<"<input type='checkbox' name='feedback'> 60 Bueno<br>";
	archivo<<"<input type='checkbox' name='feedback'> 40 Razonable<br>";
	archivo<<"<input type='checkbox' name='feedback'> 20 Aceptable<br>";
	archivo<<"<input type='checkbox' name='feedback'> 0 Sin calificar<br>";
	archivo<<"</div>";
	
	archivo<<"<br><br>";
	
	archivo<<"<label for='precio_por_noche'>Precio por noche</label>";
	archivo<<"<input type='range' name='price_per_nigth' value='180000' min='180000' max='1800000' autocomplete='off'>";
	archivo<<"<br>";
	archivo<<"<input type='button' value='Filtrar'>";
	
	archivo<<"</div>";
	
	archivo<<"</div>";
	
	archivo<<"</header>";
	
	archivo<<"<section class='main'>";
	
	/*Esto muestra los datos de las estructuras*/
	
	string pruebas;
	
	archivo<<"<article class='galeria'>";
	archivo<<"<img src='Imagenes/cancun.jpg' alt='Imagen' class='preView'>";
	archivo<<"<div class='title'>";
	archivo<<"<h2 class='refence'><a href='https://goo.gl/maps/hxJcrHy1dYt' class='reference' target='_blank'>Hotel Occidental Costa de Cancún</a></h2>";
	archivo<<"</div>";
	
	/*Acá va la función del numero de estrellas*/
	
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	archivo<<"<img src='Imagenes/Stars.png' alt='Estrella' class='stars'>";
	
	/*Acá va la función del numero de estrellas*/
	
	archivo<<"<div class='prices'>";
	archivo<<"<h3>Precio por noche</h3>";
	archivo<<"<br>";
	pruebas='1800000';
	archivo<<"<p>"<<pruebas<<"</p>";
	archivo<<"<input type='button' value='comprar' id='compra' onclick='enviar_compra(1800000)'>";
	archivo<<"</div>";
	string prueba_id, prueba_comentario;
	prueba_id='#desplegar_1', prueba_comentario='#1';
	archivo<<"<div class='desplegar' id='desplegar_1'>";
	archivo<<"<a href='#' onclick='mostrar("<<prueba_id<<","<<pruebas<<")'><img src='Imagenes/desplegar.png' alt='Comentarios'></a>";
	archivo<<"</div>";
	archivo<<"</article>";
	
	/*Función para mostrar comentarios*/
	
	archivo<<"<article class='comments' id='1'>";
	archivo<<"<div>";
	
	archivo<<"<div class='user_info'>";
	
	archivo<<"<img src='Imagenes/no_register.png' alt='Regular_user'>";
	archivo<<"<h4>Regular_user</h4>";
	
	archivo<<"</div>";
	archivo<<"<div class='comment_text'>";
	
	/*Acá va eld dato de los comentarios de la estructura*/
	
	archivo<<"<p></p>";
	
	/*Acá va eld dato de los comentarios de la estructura*/
	
	archivo<<"</div>";
	
	archivo<<"</div>";
	archivo<<"<form action='new_comment' id='fomr_comments'>";
	archivo<<"<label for='new_comments'>Agrega un comentario</label>";
	
	archivo<<"<br><br>";
	
	archivo<<"<textarea name='new_comments' id='nuevo_comentario' cols='30' rows='10' minlength='50' placeholder='Aquí puedes añadir un comentario'></textarea>";
	archivo<<"<input type='button' name='send' value='Añadir' id='añadir_comentario'>";
	archivo<<"</form>";
	
	archivo<<"<br>";
	
	archivo<<"</article>";
	
	/*Función para mostrar comentarios*/
	
	/*Esto muestra los datos de las estructuras*/
	
	archivo<<"<section id='pagar'>";
	archivo<<"<form action='pay'>";
	
	/*Aca se reemplazan nomnbres de usuario*/
	
	archivo<<"<p>Apreciado <b>cliente</b> es un placer tenerle en nuestra aplicacion y nuestro portal web, estamos muy agradecidos de presentar la <u>factura</u> que debe redimir bajo nuestro habituales <b><a href='Terminos_y_condiciones.html' target='_blank'>terminos y condiciones</a></b> esperamos que disfrute su viaje</p>";
	archivo<<"<br>";
	
	archivo<<"<input type='button' value='Aceptar terminos y condiciones' id='tersm_y_conditions'>";
	archivo<<"<a href='#' target='' id='enviar_factura'><input type='button' value='Facturar' id='facturar'></a>";
	archivo<<"<cite id='message'>Debes aceptar terminos y condiciones</cite>";
	archivo<<"</form>";
	archivo<<"</section>";
	
	archivo<<"<br><br>";
	
	archivo<<"<footer>";
	archivo<<"<blockquote id='show_autors'>Coltravels sas</blockquote>";
	archivo<<"<cite id='autores'>Cristian Andrés Grajales Pérez & Andrés Manuel Prieto Álvarez</cite>";
	archivo<<"</footer>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
	


    /*Se requiere un vector con las urls, nombres e imagenes
	
	Con este vector se han de llenar src='' href='' y el texto
	que continua depues de >
	
	Esto se debe hacer con un bucle for que tendra por condición de
	para vct.legth() (El largo del vector)*/
	
	/* 
    for(int i=0;i<5;i++){
		archivo<<"<div class='galeria'>";
		archivo<<"<img src='Imagenes/cancun.jpg' alt='imagen'>";
		archivo<<"<div>";
		archivo<<"<h2 class='refence'><a href='https://goo.gl/maps/hxJcrHy1dYt' class='reference' target='_blank'>Hotel Occidental Costa de Cancun</a></h2>";
		archivo<<"</div>";
		
		
		
		//Esto saca las estrellas pero no sé como pasarlo a archivo debe ser un proceso XD
		
		for(int i=0;i<5;i++){
			archivo<<"<img src='Imagenes/Stars.png' alt='Estrella'>";
		}
		
		
		
		archivo<<"</div>";
	}
	*/

	archivo.close();
}

/*
HTML de la presentacion de la pagina:

1) Validación de existencia del usuario que intenta loguearse
Nt:Si este no existe deberá resgistrase de lo contrario deberá
abrir la vista principal con todos los hoteles disponibles por
default

2)Vinculo a registro: En caso de no existir este tendrá la opcion
de registrarse o no hacerlo y permanecer en la vista de presentación
*/

void Escribir_presentacion(DatosHotel &datosDelHotel){
    ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
    
    //Establece un nombre al archivo html
        
    archivo.open("Presentacion.html", ios::out);  //Abre el archivo HTML
	if(archivo.fail()){
	cout<<"No se pudo leer el archivo, error fatal";
	exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<html>";
	
	archivo<<"<head>";
	
	archivo<<"<title>Proyecto final programación 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend_de_presentacion.css'>";
	archivo<<"<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.js' type='text/javascript'></script>";
	archivo<<"<script src='JavaScript/JS_presentacion.js'></script>";
	archivo<<"</head>";
	
	archivo<<"<body";
	
	archivo<<"<section class='main'>";
	
	archivo<<"<img src='Imagenes/presentacion.png' alt='avion' id='boton'>";
	
	archivo<<"<div id='banner'>";
	
	archivo<<"<form action='ingreso' id='ingreso'>";
	
	archivo<<"<label for='user'>Nombre de usuario</label>";
	archivo<<"<input type='text' placeholder='Ingrese su usuario' id='user'>";
	
	archivo<<"<br><br>";
	
	archivo<<"<label for='contrasena'>Ingrese su contrasena</label>";
	archivo<<"<input type='password' placeholder='Ingrese su contrasena' id='password'>";
	
	archivo<<"<br>";
	
	archivo<<"<cite><a href='Registro.html'>Registrarse</a></cite>";
	
	archivo<<"<br><br>";
	
	/*Aquí se valida si es administrador */
	
	/*
	Para abrir la vista normal se ponde 1 en esta linea onclick='abrir(1)' y en esta onclick='validar(1)'
	para abrir la de administrador se pone 2 en ambas
	*/
	
	archivo<<"<a href='#' id='validado' onclick='abrir(1)'><input type='button' value='Validar' onclick='validar(1)'></a>";
	archivo<<"</form>";
	
	archivo<<"<br><br><br><br><br>";
	archivo<<"<h2><a href='#'>Cootravels S.A.S</a></h2>";
	archivo<<"</div>";
	archivo<<"</section>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
	
	/*
	val_user()			//String
	val_password()		//String
	*/
	
	archivo.close();
}

void Escribir_registro(DatosHotel &datosDelHotel){
	ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
    
	archivo.open("Registro.html", ios::out);  //Abre el archivo HTML
	
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<html>";
	
	archivo<<"<head>";
	
	archivo<<"<title>Proyecto final programación 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend de registro.css'>";
	archivo<<"<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.js' type='text/javascript'></script>";
	archivo<<"<script src='JavaScript/JS_registro.js'></script>";
	
	archivo<<"</head>";
	
	archivo<<"<body>";
	
	archivo<<"<section>";
	
	archivo<<"<article>";
	archivo<<"<form action='registro'>";
	archivo<<"<br>";
	archivo<<"<h2>Registro de usuario</h2>";
	archivo<<"<br>";
	archivo<<"<label for='user'>User</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese su nombre de usuario' id='user'>";
	archivo<<"<br>";
	archivo<<"<label for='nombres'>Nombre</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese su nombre' id='names'>";
	archivo<<"<br>";
	archivo<<"<label for='cedula'>Cedula</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese su cedula' id='cddc'>";
	archivo<<"<br>";
	archivo<<"<label for='contrasena'>Contrasena</label>";
	archivo<<"<br>";
	archivo<<"<input type='password' placeholder='Ingrese su contrasena' id='password'>";
	archivo<<"<br><br><br>";
	archivo<<"<a href='Presentacion.html'><input type='button' value='Enviar' onclick='check()'></a>";
	archivo<<"</form>";
	archivo<<"</article>";
	
	archivo<<"</section>";
	archivo<<"</body>";
	archivo<<"</html>";
	
	/*
	nombre_de_usuario()			//String
	nombre_del_usuario()		//String
	cedula_del_usuario()		//Float
	contraseña_del_usuario()	//String
	*/
	
	
	archivo.close();
}

void Escribir_ingreso_de_datos_del_admin(DatosHotel &datosDelHotel){
	ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	archivo.open("Ingreso_de_datos.html", ios::out);  //Abre el archivo HTML
	
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<html>";
	
	archivo<<"<head>";
	
	archivo<<"<title>Proyecto final programación 2 Andrés Manuel Prieto Álvarez & Cristian Andrés Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend del admi.css'>";
	archivo<<"<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.js' type='text/javascript'></script>";
	archivo<<"<script src='JavaScript/JS_admi.js'></script>";
	archivo<<"</head>";
	
	archivo<<"<body>";
	
	archivo<<"<section class='main'>";
	
	archivo<<"<article>";
	archivo<<"<img src='Imagenes/presentacion.png' alt='Logo de la compania' id='avion'>";
	archivo<<"<form action='add_articles' id='form_add_dates'>";
	archivo<<"<h2>Registro de un nuevo hotel</h2>";
	archivo<<"<br>";
	archivo<<"<label for='hotels name'>Nombre del hotel</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Introduzca el nombre del nuevo hotel' id='name_hotel'>";
	archivo<<"<br>";
	archivo<<"<label for='URL'>URL</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Introduzca el URL del nuevo hotel' id='url'>";
	archivo<<"<br>";
	archivo<<"<label for='Ubi'>Ubicacion</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Introduzca la ubicacion del nuevo hotel' id='ubi'>";
	archivo<<"<br>";
	archivo<<"<label for='image_URL'>Imagen</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Introduzca el URL de la nueva imagen' id='url_img'>";
	archivo<<"<br>";
	archivo<<"<label for='precio'>Precio</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese el precio por noche' id='price'>";
	archivo<<"<br>";
	archivo<<"<label for='estrellas'>Estrellas</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese el numero de estrellas' id='stars'>";
	archivo<<"<br>";
	archivo<<"<label for='habitaciones_individuales'>Habitaciones individuales</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese el numero habitaciones individuales' id='individuals_rooms'>";
	archivo<<"<br>";
	archivo<<"<label for='habitaciones_doble'>Habitaciones dobles</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese el numero habitaciones dobles' id='doble_rooms'>";
	archivo<<"<br>";
	archivo<<"<label for='habitaciones_familiares'>Habitaciones familiares</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese el numero de habitaciones familiares' id='familiar_rooms'>";
	archivo<<"<br><br><br>";
	archivo<<"<input type='button' class='enviar' value='Anadir' onclick='take_dates()'>";
	archivo<<"</form>";
	archivo<<"</article>";
	
	archivo<<"<article id='aditamentos'>";
	archivo<<"<label for='aditamentos'>Aditamentos</label>";
	archivo<<"<br><br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='wifi'> Wifi <br>";
	archivo<<"<input type='text' class='aditamento' id='valor_wifi' placeholder='Ingresa el valor del aditamento'>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='parqueadero'> Parqueadero <br>";
	archivo<<"<input type='text' class='aditamento' id='valor_parqueadero' placeholder='Ingresa el valor del aditamento'>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='gimnasio'> Gimnasio <br>";
	archivo<<"<input type='text' class='aditamento' id='valor_gym' placeholder='Ingresa el valor del aditamento'>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='restaurante'> Restaurante <br>";
	archivo<<"<input type='text' class='aditamento' id='valor_restaurante' placeholder='Ingresa el valor del aditamento'>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='piscina'> Piscina <br>";
	archivo<<"<input type='text' class='aditamento' id='valor_piscina' placeholder='Ingresa el valor del aditamento'>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='spa'> Spa <br>";
	archivo<<"<input type='text' class='aditamento' id='valor_sap' placeholder='Ingresa el valor del aditamento'>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='sauna'> Sauna <br>";
	archivo<<"<input type='text' class='aditamento' id='valor_sauna' placeholder='Ingresa el valor del aditamento'>";
	archivo<<"<input type='button' class='enviar' name='send_extra' value='Agregar aditamentos' onclick='take_additions()'>";
	archivo<<"<input type='button' id='send_extra' class='enviar' name='add_extra' value='Anadir aditamentos' onclick='send_additions()'>";
	archivo<<"</article>";
	
	archivo<<"</section>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
	
	/*
	nombre_del_hotel() 						//String
	val_url() 								//String
	place() 								//String
	val_url_img()                   		//String
	precio()								//Float
	numero_de_estrellas()					//Short o Int
	numero_de_habitaciones_individuales() 	//Short o Int
	numero_de_habitaciones_dobles()			//Short o Int
	numero_de_habitaciones_familiares()		//Short o Int
	look_for_wifi()							//Bool
	look_for_parqueadero()					//Bool
	look_for_gimnasio()						//Bool
	look_for_restaurante()					//Bool
	look_for_piscina()						//Bool
	look_for_spa()							//Bool
	look_for_sauna()						//Bool
	*/
	archivo.close();
}

void Escribir_terminos_y_condiciones(DatosHotel &datosDelHotel){
	ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	archivo.open("terminos_y_condiciones.html", ios::out);  //Abre el archivo HTML
	
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<html>";
	
	archivo<<"<head>";
	archivo<<"<title>Proyecto final programacion 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/terminos_Y_codiciones.css'>";
	archivo<<"</head>";
	
	archivo<<"<body>";
	archivo<<"<div>";
	archivo<<"<p>";
	archivo<<"Terminos y Condiciones de Uso";
	archivo<<"<br><br>";
	archivo<<"INFORMACION RELEVANTE";
	archivo<<"<br><br>";
	archivo<<"Es requisito necesario para la adquisicion de los productos que se ofrecen en este sitio, que lea y acepte los siguientes Terminos y Condiciones que a continuacion se redactan. El uso de nuestros servicios asi como la compra de nuestros productos implicara que usted ha leido y aceptado los Terminos y Condiciones de Uso en el presente documento. Todas los productos que son ofrecidos por nuestro sitio web pudieran ser creadas, cobradas, enviadas o presentadas por una pagina web tercera y en tal caso estarian sujetas a sus propios Terminos y Condiciones. En algunos casos, para adquirir un producto, sera necesario el registro por parte del usuario, con ingreso de datos personales fidedignos y definicion de una contrasena.";
	archivo<<"<br><br>";
	archivo<<"El usuario puede elegir y cambiar la clave para su acceso de administracion de la cuenta en cualquier momento, en caso de que se haya registrado y que sea necesario para la compra de alguno de nuestros productos. 				no asume la responsabilidad en caso de que entregue dicha clave a terceros.";
	archivo<<"<br><br>";
	archivo<<"Todas las compras y transacciones que se lleven a cabo por medio de este sitio web, estan sujetas a un proceso de confirmacion y verificacion, el cual podria incluir la verificacion del stock y disponibilidad de producto, validacion de la forma de pago, validacion de la factura (en caso de existir) y el cumplimiento de las condiciones requeridas por el medio de pago seleccionado. En algunos casos puede que se requiera una verificacion por medio de correo electronico.";
	archivo<<"<br><br>";
	archivo<<"Los precios de los productos ofrecidos en esta Tienda Online es valido solamente en las compras realizadas en este sitio web.";
	archivo<<"<br><br>";
	archivo<<"LICENCIA";
	archivo<<"<br>				a traves de su sitio web concede una licencia para que los usuarios utilicen  los productos que son vendidos en este sitio web de acuerdo a los Terminos y Condiciones que se describen en este documento.";
	archivo<<"<br><br>";
	archivo<<"USO NO AUTORIZADO";
	archivo<<"<br><br>";
	archivo<<"En caso de que aplique (para venta de software, templetes, u otro producto de diseno y programacion) usted no puede colocar uno de nuestros productos, modificado o sin modificar, en un CD, sitio web o ningun otro medio y ofrecerlos para la redistribucion o la reventa de ningun tipo.";
	archivo<<"<br><br>";
	archivo<<"PROPIEDAD";
	archivo<<"<br><br>";
	archivo<<"Usted no puede declarar propiedad intelectual o exclusiva a ninguno de nuestros productos, modificado o sin modificar. Todos los productos son propiedad  de los proveedores del contenido. En caso de que no se especifique lo contrario, nuestros productos se proporcionan  sin ningun tipo de garantia, expresa o implicita. En ningun esta compania sera  responsables de ningun dano incluyendo, pero no limitado a, danos directos, indirectos, especiales, fortuitos o consecuentes u otras perdidas resultantes del uso o de la imposibilidad de utilizar nuestros productos.";
	archivo<<"<br><br>";
	archivo<<"POLITICA DE REEMBOLSO Y GARANTIA";
	archivo<<"<br><br>";
	archivo<<"En el caso de productos que sean  mercancias irrevocables no-tangibles, no realizamos reembolsos despues de que se envie el producto, usted tiene la responsabilidad de entender antes de comprarlo.  Le pedimos que lea cuidadosamente antes de comprarlo. Hacemos solamente excepciones con esta regla cuando la descripcion no se ajusta al producto. Hay algunos productos que pudieran tener garantia y posibilidad de reembolso pero este sera especificado al comprar el producto. En tales casos la garantia solo cubrira fallas de fabrica y solo se hara efectiva cuando el producto se haya usado correctamente. La garantia no cubre averias o danos ocasionados por uso indebido. Los terminos de la garantia estan asociados a fallas de fabricacion y funcionamiento en condiciones normales de los productos y solo se haran efectivos estos terminos si el equipo ha sido usado correctamente. Esto incluye:";
	archivo<<"<br><br>";
	archivo<<"– De acuerdo a las especificaciones tecnicas indicadas para cada producto.";
	archivo<<"<br>";
	archivo<<"– En condiciones ambientales acorde con las especificaciones indicadas por el fabricante.";
	archivo<<"<br>";
	archivo<<"– En uso especifico para la funcion con que fue disenado de fabrica.";
	archivo<<"<br>";
	archivo<<"– En condiciones de operacion electricas acorde con las especificaciones y tolerancias indicadas.";
	archivo<<"<br><br><br>";
	archivo<<"COMPROBACION ANTIFRAUDE";
	archivo<<"<br><br>";
	archivo<<"La compra del cliente puede ser aplazada para la comprobacion antifraude. Tambien puede ser suspendida por mas tiempo para una investigacion mas rigurosa, para evitar transacciones fraudulentas.";
	archivo<<"<br><br>";
	archivo<<"PRIVACIDAD";
	archivo<<"<br><br>";
	archivo<<"Este sitio web 								 garantiza que la informacion personal que usted envia cuenta con la seguridad necesaria. Los datos ingresados por usuario o en el caso de requerir una validacion de los pedidos no seran entregados a terceros, salvo que deba ser revelada en cumplimiento a una orden judicial o requerimientos legales.";
	archivo<<"<br><br>";
	archivo<<"La suscripcion a boletines de correos electronicos publicitarios es voluntaria y podria ser seleccionada al momento de crear su cuenta. 					reserva los derechos de cambiar o de modificar estos terminos sin previo aviso.";
	archivo<<"<br><br>";
	archivo<<"Estas terminos y condiciones se han generado en terminosycondicionesdeusoejemplo.com";
	archivo<<"</p>";
	archivo<<"</div>";
	archivo<<"</body>";
	archivo<<"</html>";
	
	archivo.close();
}

void Escribir_factura(DatosHotel &datosDelHotel, int posHotelAReservar){
	ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	archivo.open("Facturar.html", ios::out);  //Abre el archivo HTML
	
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<html>";
	
	archivo<<"<head>";
	
	archivo<<"<title>Proyecto final programación 2 Andrés Manuel Prieto Alvarez & Cristian Andrés Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/factura.css'>";
	archivo<<"<script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.js' type='text/javascript'></script>";
	archivo<<"<script src='JavaScript/JS_factura.js'></script>";
	
	archivo<<"</head>";
	
	archivo<<"<body>";
	
	archivo<<"<br>";
	
	archivo<<"<form action='facturar'>";
	archivo<<"<h2>Factura</h2>";
	archivo<<"<br>";
	archivo<<"<label for='Hotel'>Nombre del hotel: </label>";
	/*Aca va el nombre del hotel*/
	archivo<<"<p id='hotel_name'>"<<datosDelHotel.todosLosHoteles.nombresDeHoteles[posHotelAReservar]<<"</p><br>";
	archivo<<"<label for='Numero_de_habitaciones'>Numero de habitaciones: </label>";
	/*Acá va el numero de habitaciones*/
	archivo<<"<p id='num_room'>"<<datosDelHotel.todosLosHoteles.cantHabitacionesReservadas[posHotelAReservar]<<"</p><br>";
	archivo<<"<label for='Adicionales'>Elementos adicionales</label>";
	/*Numero de cosas adicionales*/
	archivo<<"<p id='add'>"<<datosDelHotel.todosLosHoteles.cantFiltrosReservados[posHotelAReservar]<<"</p><br>";
	archivo<<"<label for='Tiempo_de_estadia'>Tiempo de estadia</label>";
	/*Tiempo que se va a quedar*/
	archivo<<"<p id='stay'>n dias</p><br>";
	archivo<<"<label for='Precio_por_noche'>Precio por noche</label>";
	/*Precio por noche*/
	archivo<<"<p id='price_per_night'>"<<datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[posHotelAReservar]<<"</p><br>";
	archivo<<"<label for='Precio_a_pagar'>Precio a pagar</label>";
	archivo<<"<br><br>";
	/*onclick='obtener_costo()' ahi va el valor a pagar entre los parentesis de la funcion JS*/
	//archivo<<"<input type='button' value='Presiona para obtener costo' id=pay onclick='obtener_costo()'>";
	archivo<<"<input type='button' value='"<<datosDelHotel.todosLosHoteles.preciosTotales[posHotelAReservar]<<"'>";
	archivo<<"</form>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
	
	archivo.close();
}

int returnInt(){
    int num;
    return num;
}

string returnString(){
    string cadena;
    return cadena;    
}
