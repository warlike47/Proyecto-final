#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct ComentariosHoteles{
      char comentario[1000];
      string comentariosDeHoteles[100]; 
};

struct TodosHoteles{
    string nombresDeHoteles[100];          //Contiene el nombre de todos los hoteles
    string ubicacionesDeHoteles[100];          //Contiene la ubicacion de todos los hoteles
    int estrellasDeHoteles[100];           //Contiene las estrellas de todos los hoteles
    int preciosPorNocheDeHoteles[100];            //Contiene los precios por noche de todos los hoteles
    int cantHabitacionesIndividualesDeHoteles[100];           //Contiene la cantidad de habitaciones disponibles individuales de todos los hoteles
    int cantHabitacionesDoblesDeHoteles[100];          //Contiene la cantidad de habitaciones dobles disponibles de todos los hoteles
    int cantHabitacionesFamiliaresDeHoteles[100];            //Contiene la cantidad de habitaciones familiares disponibles de todos los hoteles
};

struct DatosHotel{
    struct TodosHoteles todosLosHoteles;         //Contiene todos los datos de todos los hoteles
    int cantHoteles;          //Contiene la cantidad de hoteles que hay en la pagina
	   
    char nombreHotel[100];           //Contiene el nombre del hotel
    char ubicacionHotel[100];           //Contiene la ubicacion del hotel
    int cantEstrellas;           //Contiene la cantidad de estrellas
	int precioPorNoche;           //Contiene el precio por noche
    int cantHabitacionesIndividuales;        //Contiene la cantidad de habitaciones individuales disponibles
    int cantHabitacionesDobles;           //Contiene la cantidad de habitaciones dobles disponibles
    int cantHabitacionesFamiliares;          //Contiene la cantidad de habitaciones familiares disponibles
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

void Escribir_ingreso_de_datos_del_admin();
void Escribir_presentacion();
void Escribir_principal();
void Escribir_registro();
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
void ReservaHabitacionIndividual(DatosHotel &datosDelHotel, int posHotelAReservar);
void ReservaHabitacionDoble(DatosHotel &datosDelHotel, int posHotelAReservar);
void ReservaHabitacionFamiliar(DatosHotel &datosDelHotel, int posHotelAReservar);
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
    
    //Realiza la maquetacion de la vista.
    Escribir_ingreso_de_datos_del_admin();
    Escribir_presentacion();
	Escribir_principal();
	Escribir_registro();
	
    MenuPrincipal(datosDelUsuario, estaRegistrado, datosDelAdministrador, datosDelHotel);
    //RegistroUsuario(datosDelUsuario, estaRegistrado);        //Registra al usuario si no lo está, si lo está, pide los datos para loguearse
    //RegistroUsuario(datosDelUsuario, estaRegistrado);
    
    //Lectura();
    system("PAUSE");
    return 0;
}

//El menu que se inicia al comienzo de el programa
void MenuPrincipal(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador, DatosHotel &datosDelHotel){ 
    int op = 1;       //Es la opcion que va a tomar el usuario
    datosDelUsuario.cantUsuarios = 0;       //Dice que al principio del programa hay 0 usuarios
    datosDelAdministrador.cantAdministradores = 0;        //Dice que al principio del programa hay 0 administradores
    datosDelHotel.cantHoteles = 0;
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
     
    datosDelHotel.todosLosHoteles.nombresDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.nombreHotel;
    datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.ubicacionHotel;
    datosDelHotel.todosLosHoteles.estrellasDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantEstrellas;
    datosDelHotel.todosLosHoteles.preciosPorNocheDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.precioPorNoche;
    datosDelHotel.todosLosHoteles.cantHabitacionesIndividualesDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantHabitacionesIndividuales;
    datosDelHotel.todosLosHoteles.cantHabitacionesDoblesDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantHabitacionesDobles;
    datosDelHotel.todosLosHoteles.cantHabitacionesFamiliaresDeHoteles[datosDelHotel.cantHoteles] = datosDelHotel.cantHabitacionesFamiliares;
    datosDelHotel.cantHoteles++;
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
     
    while(true){
        system("cls");
        cout<<"BIENVENIDO AL HOTEL "<<datosDelHotel.todosLosHoteles.nombresDeHoteles[posHotelAReservar]<<".\n"<<endl;      
                 
        cout<<"Que tipo de habitacion desea reservar?\n"<<endl;
           
        cout<<"Ingrese 1 para reservar una habitacion individual"<<endl;
        cout<<"Ingrese 2 para reservar una habitacion doble"<<endl;
        cout<<"Ingrese 3 para reservar una habitacion familiar"<<endl;
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
			
			case 0:{
				exit(0);
				break;
			}       
        }
    }
}

void ReservaHabitacionIndividual(DatosHotel &datosDelHotel, int posHotelAReservar){
     
     cout<<"Funcion Fecha que se va a quedar"<<endl;
     cout<<"Funcion Hora de llegada y hora salida"<<endl;
     cout<<"Funcion Comentar"<<endl;
     cout<<"Funcion Puntuar hotel"<<endl;
     cout<<"Funcion Filtros: Parqueaderos, restaurante y piscina"<<endl;
     
}

void ReservaHabitacionDoble(DatosHotel &datosDelHotel, int posHotelAReservar){
     
     cout<<"Funcion Fecha que se va a quedar"<<endl;
     cout<<"Funcion Hora de llegada y hora salida"<<endl;
     cout<<"Funcion Comentar"<<endl;
     cout<<"Funcion Puntuar hotel"<<endl;
     cout<<"Funcion Filtros: Parqueaderos, restaurante y piscina"<<endl;
     
}

void ReservaHabitacionFamiliar(DatosHotel &datosDelHotel, int posHotelAReservar){
     
     cout<<"Funcion Fecha que se va a quedar"<<endl;
     cout<<"Funcion Hora de llegada y hora salida"<<endl;
     cout<<"Funcion Comentar"<<endl;
     cout<<"Funcion Puntuar hotel"<<endl;
     cout<<"Funcion Filtros: Parqueaderos, restaurante y piscina"<<endl;
     
}

void BuscaHotelAReservar(DatosHotel &datosDelHotel){ 
    char hotelABuscar[100];
    cout<<"Ingrese el nombre del hotel que desea reservar= ";
    fflush(stdin);
    gets(hotelABuscar);
     
    for(int i = 0; i < datosDelHotel.cantHoteles; i++){
        if(hotelABuscar == datosDelHotel.todosLosHoteles.nombresDeHoteles[i]){
        	ReservarHotel(datosDelHotel, i);         
        }
    }
}

void BuscaHotelesPorCiudad(DatosHotel &datosDelHotel){
     
    char ciudadABuscar[100];
    cout<<"Ingrese la ciudad en la que desea ver hoteles";
    fflush(stdin);
    gets(ciudadABuscar);
     
    for(int i = 0; i < datosDelHotel.cantHoteles; i++){
        if(ciudadABuscar == datosDelHotel.todosLosHoteles.ubicacionesDeHoteles[i]){
            cout<<"Muestra hotel en la posicion i actual"<<endl;                 
        }        
    }
}

void OpcionesUsuario(DatosHotel &datosDelHotel){
    int op = 1;
     
    while(op != 0){
    	cout<<"Ingrese 1 para reservar un hotel en especifico"<<endl;
        cout<<"Ingrese 2 para buscar hoteles por ciudad"<<endl;
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
        }
    }     
}

void OpcionesAdministrador(DatosHotel &datosDelHotel){
    int op = 1;
    //datosDelHotel.cantHoteles = 0;
     
    while(op != 0){   
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
                struct DatosHotel datosDelHotel;
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Escribir_principal(){
    ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	
	archivo.open("Pagina_principal.html", ios::out);
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
    
    /*Se requiere un vector con las urls, nombres e imagenes
	
	Con este vector se han de llenar src='' href='' y el texto
	que continua depues de >
	
	Esto se debe hacer con un bucle for que tendra por condición de
	para vct.legth() (El largo del vector)*/
    
    for(int i=0;i<5;i++){
		archivo<<"<div class='galeria'>";
		archivo<<"<img src='Imagenes/cancun.jpg' alt='imagen'>";
		archivo<<"<div>";
		archivo<<"<h2 class='refence'><a href='https://goo.gl/maps/hxJcrHy1dYt' class='reference' target='_blank'>Hotel Occidental Costa de Cancun</a></h2>";
		archivo<<"</div>";
		archivo<<"</div>";
	}

	archivo.close();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
HTML de la presentacion de la pagina:

1) Validación de existencia del usuario que intenta loguearse
Nt:Si este no existe deberá resgistrase de lo contrario deberá
abrir la vista principal con todos los hoteles disponibles por
default

2)Vinculo a registro: En caso de no existir este tendrá la opcion
de registrarse o no hacerlo y permanecer en la vista de presentación
*/

void Escribir_presentacion(){
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
	
	archivo<<"<head>"; //Aca empieza la etiqueta <head> de la vista de presentación
	
	archivo<<"<title>Proyecto final programacion 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend de presentacion.css'>";
	archivo<<"<script src='jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
	
	//Funciones jQuery & recopilaciones de datos desde JavaScript
	archivo<<"<script>$(document).ready(function() {$('#banner').hide();$('#boton').click(function(e){$('#banner').fadeIn(2000);$('#boton').addClass('whenClick');e.preventDefault();return false;})});var user_name, user_password;function validar() {user_name=document.getElementById('user').value;user_password=document.getElementById('password').value;}function val_user() {return user_name;}function val_password() {return user_password;}</script>";
	
	archivo<<"</head>"; //Aca termina la etiqueta </head> de la vista de presentación
	
	archivo<<"<body>"; //Aca empieza la etiqueta <body> de la vista de presentación
	
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
	archivo<<"<input type='button' value='Validar' onclick='validar()'>";
	archivo<<"</form>";
	archivo<<"<br><br><br><br><br>";
	archivo<<"<h2><a href='#'>Cootravels S.A.S</a></h2>";	
	archivo<<"</div>";		
	archivo<<"</section>";
	
	archivo<<"</body>"; //Aca termina la etiqueta </body> de la vista de presentación
	
	archivo<<"</html>";
	
	/*
	val_user()
	val_password()
	*/
	
	archivo.close();
}

void Escribir_registro(){
	ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
    
	archivo.open("Registro.html", ios::out);  //Abre el archivo HTML
	
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
	
	archivo<<"<!doctype html>";
	
	archivo<<"<html lang='es'>";
	
	archivo<<"<head>";
	
	archivo<<"<title>Proyecto final programacion 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/Frontend de registro.css'>";
	archivo<<"<script>var user_name, name_of_user, user_cddc, user_password, hotel_price;function check() {user_name=document.getElementById('user').value;name_of_user=document.getElementById('names').value;user_cddc=document.getElementById('cddc').value;user_password=document.getElementById('password').value;}function nombre_de_usuario() {return user_name;}function nombre_del_usuario() {return name_of_user;}function cedula_del_usuario() {return user_cddc;}function contrasena_del_usuario() {return user_password;}</script>";
	
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
	archivo<<"<br>"	;
	archivo<<"<input type='text' placeholder='Ingrese su nombre' id='names'>";	
	archivo<<"<br>";
	archivo<<"<label for='cedula'>Cedula</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese su cédula' id='cddc'>";
	archivo<<"<br>";
	archivo<<"<label for='contrasena'>Contrasena</label>";
	archivo<<"<br>";
	archivo<<"<input type='password' placeholder='Ingrese su contraseña' id='password'>";
	archivo<<"<br><br><br>";
	archivo<<"<a href='Presentación.html'><input type='button' value='Enviar' onclick='check()'></a>";
	archivo<<"</form>";
	archivo<<"</article>";
	archivo<<"</section>";
	archivo<<"</body>";
	archivo<<"</html>";
	
	/*
	nombre_de_usuario()
	nombre_del_usuario()
	cedula_del_usuario()
	contraseña_del_usuario()
	*/
	
	
	archivo.close();
}

void Escribir_ingreso_de_datos_del_admin(){
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
	
	archivo<<"<title>Proyecto final programacion 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	archivo<<"<meta charset='utf-8'>";
	archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend del admi.css'>";
	archivo<<"<script src='jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
	archivo<<"<script>var hotel, dirr, ubication, dirr_img, hotel_price, num_star, room_type_1, room_type_2, room_type_3;var a_wf=0, a_rfrgrcn=0, a_prqdr=0, a_gmns=0, a_rstrnt=0, a_pscn=0, a_sp=0, a_sn=0, a_24hrs=0, a_ps_cs=0;function take_dates() {hotel=document.getElementById('name_hotel').value;dirr=document.getElementById('url').value;ubication=document.getElementById('ubi').value;dirr_img=document.getElementById('url_img').value;hotel_price=parseFloat(document.getElementById('price').value);num_star=parseFloat(document.getElementById('stars').value);room_type_1=parseFloat(document.getElementById('individuals_rooms').value);room_type_2=parseFloat(document.getElementById('doble_rooms').value);room_type_3=parseFloat(document.getElementById('familiar_rooms').value);if($(wifi).prop('checked')){a_wf=1;}else{a_wf=0}if($(refrigeracion).prop('checked')){a_rfrgrcn=1;}else{a_rfrgrcn=0}if($(parqueadero).prop('checked')){a_prqdr=1;}else{a_prqdr=0}if($(gimnasio).prop('checked')){a_gmns=1;}else{a_gmns=0}if($(restaurante).prop('checked')){a_rstrnt=1;}else{a_rstrnt=0}if($(piscina).prop('checked')){a_pscn=1;}else{a_pscn=0}if($(spa).prop('checked')){a_sp=1;}else{a_sp=0}if($(sauna).prop('checked')){a_sn=1;}else{a_sn=0}if($(recepcion_24_hrs).prop('checked')){a_24hrs=1;}else{a_24hrs=0}if($(piso_casa).prop('checked')){a_ps_cs=1;}else{a_ps_cs=0}}function nombre_del_hotel() {return hotel;}function val_url() {return dirr;}function place() {return ubication;}function val_url_img() {return dirr_img;}function precio() {return hotel_price;}function numero_de_estrellas() {return num_star;}function numero_de_habitaciones_individuales() {return room_type_1;}function numero_de_habitaciones_dobles() {return room_type_2;}function numero_de_habitaciones_familiares() {return room_type_3;}function look_for_wifi() {return a_wf;}function look_for_refrigeracion() {return a_rfrgrcn;}function look_for_parqueadero() {return a_prqdr;}function look_for_gimnasio() {return a_gmns;}function look_for_restaurante() {return a_rstrnt;}function look_for_piscina() {return a_pscn;}function look_for_spa() {return a_sp;}function look_for_sauna() {return a_sn;}function look_for_24_hrs() {return a_24hrs;}function look_for_piso_casa() {return a_ps_cs;}</script>";
	
	archivo<<"</head>";
	
	archivo<<"<body>";
	
	archivo<<"<section class='main'>";
	
	archivo<<"<article>";
	archivo<<"<img src='Imagenes/presentacion.png' alt='Logo de la compania'>";
	archivo<<"<form action='add_articles'>";
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
	archivo<<"<input type='text' placeholder='Introduzca la ubicación del nuevo hotel' id='ubi'>";
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
	archivo<<"<input type='button' value='Añadir' onclick='take_dates()'>";
	archivo<<"</form>";
	archivo<<"</article>";
	
	archivo<<"<article id='aditamentos'>";
	archivo<<"<label for='aditamentos'>Aditamentos</label>";
	archivo<<"<br><br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='wifi'> Wifi <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='refrigeracion'> Refrigeracion <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='parqueadero'> Parqueadero <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='gimnasio'> Gimnasio <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='restaurante'> Restaurante <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='piscina'> Piscina <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='spa'> Spa <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='sauna'> Sauna <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='recepcion_24_hrs'> Recepcion 24hrs <br>";
	archivo<<"<input type='checkbox' name='extra' value='0' id='piso_casa'> Piso/Casa <br>";
	archivo<<"</article>";
	
	archivo<<"</section>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
	
	
	/*
	nombre_del_hotel()
	val_url()
	place()
	val_url_img()
	precio()
	numero_de_estrellas()
	numero_de_habitaciones_individuales()
	numero_de_habitaciones_dobles()
	numero_de_habitaciones_familiares()
	look_for_wifi()
	look_for_refrigeracion()
	look_for_parqueadero()
	look_for_gimnasio()
	look_for_restaurante()
	look_for_piscina()
	look_for_spa()
	look_for_sauna()
	look_for_24_hrs()
	look_for_piso_casa()
	*/

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
