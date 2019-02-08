#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

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
void Loguearse(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void LoguearseComoAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado);
void LoguearseComoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado);
void OpcionesAdministrador(DatosHotel &datosDelHotel);
void OpcionesUsuario(DatosHotel &datosDelHotel);
void MuestraHoteles(DatosHotel &datosDelHotel);
void IngresarHoteles(DatosHotel &datosDelHotel);
void BuscaHotelAReservar(DatosHotel &datosDelHotel);
void BuscaHotelesPorCiudad(DatosHotel &datosDelHotel);
void ReservarHotel(string nombreDeHotelAReservar, int posHotelAReservar);
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
                    Loguearse(datosDelUsuario, estaRegistrado, datosDelAdministrador);
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
     system("start Pagina_de_ingreso_de_datos.html");
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


void ReservarHotel(string nombreDeHotelAReservar, int posHotelAReservar){
     
     system("cls");
     
     int op = 1;
     
     while(true){
           system("cls");
           cout<<"BIENVENIDO AL HOTEL "<<nombreDeHotelAReservar<<".\n"<<endl;      
                 
           cout<<"Que tipo de habitacion desea reservar?\n"<<endl;
           
           cout<<"Ingrese 1 para reservar una habitacion individual"<<endl;
           cout<<"Ingrese 2 para reservar una habitacion doble"<<endl;
           cout<<"Ingrese 3 para reservar una habitacion familiar"<<endl;
           cout<<"Ingrese 0 para cerrar el programa"<<endl;
           
           cin>>op;
           
           switch(op){
                 case 1:
                      cout<<"\nReserva habitacion individual"<<endl;
                      break;
                 case 2:
                      cout<<"\nReserva habitacion doble"<<endl;
                      break;
                 case 3:
                      cout<<"\nReserva habitacion familiar"<<endl;
                      break;
                 case 0:
                      exit(0);
                      break;           
           }
     }
}

void BuscaHotelAReservar(DatosHotel &datosDelHotel){
     
     char hotelABuscar[100];
     cout<<"Ingrese el nombre del hotel que desea reservar= ";
     fflush(stdin);
     gets(hotelABuscar);
     
     for(int i = 0; i < datosDelHotel.cantHoteles; i++){
          if(hotelABuscar == datosDelHotel.todosLosHoteles.nombresDeHoteles[i]){
                ReservarHotel(datosDelHotel.todosLosHoteles.nombresDeHoteles[i], i);         
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
                 case 1:
                      BuscaHotelAReservar(datosDelHotel);
                      break;
                 case 2:
                      BuscaHotelesPorCiudad(datosDelHotel);
                      break;
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
                  case 1:
                       IngresarHoteles(datosDelHotel);
                       break;
                  case 2:
                       MuestraHoteles(datosDelHotel);
                       break;           
           }         
     }     
}

//Pregunta si desea ingresar a la pagina como usuario o como administrador
void Loguearse(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     int op = 1;
     system("start Pagina_de_presentacion.html");
      
     
     while(op != 0){
          cout<<"Ingrese 1 para loguearse como usuario"<<endl;
          cout<<"Ingrese 2 para loguearse como administrador"<<endl;
          cin>>op; 
          
          switch(op){
                 case 1:
                      LoguearseComoUsuario(datosDelUsuario, estaRegistrado);
                      break;
                 case 2:
                      LoguearseComoAdministrador(datosDelAdministrador, estaRegistrado);
                      break;           
          }        
     }     
}

//Se ejecuta si se elige ingresar a la pagina como administrador
void LoguearseComoAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado){
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
     
     struct DatosHotel datosDelHotel;
     
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
void LoguearseComoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado){
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
          cout<<"CONTRASEÑA= "<<datosDelAdministrador.todosLosAdmin.ContrasAdministradores[i]<<endl;
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
          cout<<"CONTRASEÑA= "<<datosDelUsuario.todosLosUsuarios.ContrasUsuarios[i]<<endl;
          cout<<"NOMBRE= "<<datosDelUsuario.todosLosUsuarios.NombresUsuarios[i]<<endl;
          cout<<"USUARIO= "<<datosDelUsuario.todosLosUsuarios.UsersUsuarios[i]<<endl;      
          cout<<endl; 
     }
}

//Define si se quiere registrar como administrador o como usuario corriente
void DefineTipoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     system("cls");
     int op = 1;
     system("start Pagina_de_registro.html");        //Aqui va el inicio de la vista principal         
     
     while(op != 0){
         cout<<"Desea registrarse como administrador o como usuario corriente?"<<endl;
         cout<<"Ingrese 1 si quiere registrarse como administrador"<<endl;
         cout<<"Ingrese 2 si quiere registrarse como usuario corriente"<<endl;
         
         cin>>op;
         
         switch(op){
                case 1:
                     RegistroAdministrador(datosDelAdministrador, estaRegistrado, datosDelUsuario);
                     break;
                case 2:
                     RegistroUsuario(datosDelUsuario, estaRegistrado, datosDelAdministrador);
                     break;           
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
          //Si pilla, si quedan guardados xD.
          
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

void Escribir_principal(){
    ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	
	archivo.open("Pagina_principal.html", ios::out);
	if(archivo.fail()){
	    cout<<"No se pudo leer el archivo, error fatal";
	    exit(1);
	}
		    
	archivo<<"<!doctype html>";
		    
	archivo<<"<html lang='es'>";
		    
	archivo<<"<head>";
		    
	archivo<<"<title>Proyecto final programacion 2 Andrés Manuel Prieto Álvarez & Cristian Andrés Grajales Perez</title>";
    archivo<<"<meta charset='utf-8''>";
    archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='Imagenes/icon.png'>";
    archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend para proyecto final del segundo semestre.css'>";
    archivo<<"<script src='jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
    
    archivo<<"<script>$(document).ready(function() {$('#banner').hide();$('#fecha_llegada').click(function(e){$('#banner').fadeIn(2000);e.preventDefault();return false;})});</script>";
			
	archivo<<"</head>";
		    
    archivo<<"<body>";
		    
	archivo<<"<header>";
		    
    archivo<<"<div id='search_div'>";
    archivo<<"<input type='text' placeholder='Buscar' name='Buscar' id='search'>";
    archivo<<"<input type='button' value='Buscar' id='button_buscar'>";
    archivo<<"</div>";
		    
	archivo<<"<div id='dates'>";
    archivo<<"<input type='button' value='Fecha de llegada'>";
    archivo<<"<input type='button' value='Fecha de salida'>";
    archivo<<"<input type='button' value='Menu'>";
    archivo<<"</div>";
		    
	archivo<<"</header>";
		    
    archivo<<"<section class='main'>";
    
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
		    
	archivo<<"</section>";
		    
	archivo<<"</body>";
	archivo<<"</html>";
	archivo.close();
}

void Escribir_presentacion(){
    ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
    
    archivo.open("Pagina_de_presentacion.html", ios::out);  //Abre el archivo HTML
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
	archivo<<"<link rel='stylesheet' type='text/css' href='CSS/frontend de presentacion.css'>";
	archivo<<"<script src='jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
	//Función de la etiqueta <img> con el avion
	archivo<<"<script>$(document).ready(function() {$('#banner').hide();$('#boton').click(function(e){$('#banner').fadeIn(2000);$('#boton').addClass('whenClick');e.preventDefault();return false;})});var user_name, user_password;function validar(){user_name=document.getElementById('user').value;user_password=document.getElementById('password').value;alert(user_name);alert(user_password);}</script>";
	
	archivo<<"</head>";
	
	archivo<<"<body>";
	
	archivo<<"<section class='main'>";
	
	archivo<<"<img src='Imagenes/presentacion.png' alt='avion' id='boton'>";
	
	archivo<<"<div id='banner'>";
	
	archivo<<"<form action='ingreso' id='ingreso'>";
	archivo<<"<label for='user'>Nombre de usuario</label>";
	archivo<<"<input type='text' placeholder='Ingrese su usuario' id='user'>";
	archivo<<"<br><br>";
	archivo<<"<label for='contrasena'>Ingrese su contrasena</label>";
	archivo<<"<input type='text' placeholder='Ingrese su contrasena' id='password'>";
	archivo<<"<br>";
	archivo<<"<cite><a href='Pagina_de_registro.html'>Registrarse</a></cite>";
	archivo<<"<br><br>";
	archivo<<"<a href='Pagina_principal.html'><input type='button' value='Validar' onclick='validar()'></a>";
	archivo<<"</form>";	
	archivo<<"<br><br><br><br><br>";
	archivo<<"<h2><a href='#'>Cootravels S.A.S</a></h2>";
	archivo<<"</div>";
	archivo<<"</section>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
}

void Escribir_registro(){
	ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
    
	archivo.open("Pagina_de_registro.html", ios::out);  //Abre el archivo HTML
	
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
	
	archivo<<"<script>function check() {var user_name, name_of_user, user_cddc, user_password, hotel_price;user_name=document.getElementById('user').value;name_of_user=document.getElementById('names').value;user_cddc=document.getElementById('cddc').value;user_password=document.getElementById('password').value;alert(user_name);alert(name_of_user);alert(user_cddc);alert(user_password);}</script>";
		
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
	archivo<<"<input type='text' placeholder='Ingrese su contrasena' id='password'>";
	archivo<<"<br><br><br>";
	archivo<<"<a href='Pagina de presentacion.html'><input type='button' value='Enviar' onclick='check()'></a>";
	archivo<<"</form>";
	archivo<<"</article>";
	archivo<<"</section>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
}

void Escribir_ingreso_de_datos_del_admin(){
	ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
	archivo.open("Pagina_de_ingreso_de_datos.html", ios::out);  //Abre el archivo HTML
	
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
	archivo<<"<script>var hotel, dirr, dirr_img;function take_dates() {hotel=document.getElementById('name_hotel').value;dirr=document.getElementById('url').value;dirr_img=document.getElementById('url_img').value;hotel_price=parseFloat(document.getElementById('price').value);alert(hotel);alert(dirr);alert(dirr_img);alert(hotel_price);}</script>";
	archivo<<"</head>";
	
	archivo<<"<body>";
	archivo<<"<section class='main'>";
	archivo<<"<article>";
	archivo<<"<img src='Imagenes/icon.png' alt='Logo de la compania'>";
	archivo<<"<form action='add_articles'>";
	archivo<<"<h2>Registro de un nuevo hotel</h2>";
	archivo<<"<br><br>";
	archivo<<"<label for='hotels name'>Nombre del hotel</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Introduzca el nombre del nuevo hotel' id='name_hotel'>";
	archivo<<"<br><br>";
	archivo<<"<label for='URL'>URL</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Introduzca el URL del nuevo hotel' id='url'>";
	archivo<<"<br><br>";
	archivo<<"<label for='image_URL'>Imagen</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Introduzca el URL de la nueva imagen' id='url_img'>";
	archivo<<"<br><br>";
	archivo<<"<label for='precio'>Precio</label>";
	archivo<<"<br>";
	archivo<<"<input type='text' placeholder='Ingrese el precio por noche' id='price'>";
	archivo<<"<br><br><br>";
	archivo<<"<input type='button' value='Anadir' onclick='take_dates()'>";
	archivo<<"</form>";
	archivo<<"</article>";
	archivo<<"</section>";
	
	archivo<<"</body>";
	
	archivo<<"</html>";
}

int returnInt(){
     int num;
     return num;
}

string returnString(){
     string cadena;
     return cadena;    
}
