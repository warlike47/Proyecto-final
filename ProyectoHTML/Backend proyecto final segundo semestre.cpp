#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct TodosUsuarios{
       string NombresUsuarios[100];
       long long int CedulasUsuarios[100];
       string UsersUsuarios[100];
       string ContrasUsuarios[100];       
};

struct TodosAdministradores{
      string NombresAdministradores[100];
      long long int CedulasAdministradores[100];
      string UsersAdministradores[100];
      string ContrasAdministradores[100]; 
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

void Escribir(short op);
void IngresarDatos(DatosUsuario &datosDelUsuario);
void RegistroUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void RegistroAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado, DatosUsuario &datosDelUsuario);
void MenuPrincipal(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void DefineTipoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void Loguearse(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador);
void LoguearseComoAdministrador(DatosAdministrador &datosDelAdministrador, bool &estaRegistrado);
void LoguearseComoUsuario(DatosUsuario &datosDelUsuario, bool &estaRegistrado);



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
    bool estaRegistrado = false;        //Contiene la verificacion si el usuario está registrado o no.
    system("color 4B");
    
    Escribir(1);      //Realiza la maquetacion de la vista.
    MenuPrincipal(datosDelUsuario, estaRegistrado, datosDelAdministrador);
    //RegistroUsuario(datosDelUsuario, estaRegistrado);        //Registra al usuario si no lo está, si lo está, pide los datos para loguearse
    //RegistroUsuario(datosDelUsuario, estaRegistrado);
    
    //Lectura();
    system("PAUSE");
    return 0;
}

//El menu que se inicia al comienzo de el programa
void MenuPrincipal(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     
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

//Pregunta si desea ingresar a la pagina como usuario o como administrador
void Loguearse(DatosUsuario &datosDelUsuario, bool &estaRegistrado, DatosAdministrador &datosDelAdministrador){
     int op = 1;
     system("start Frontend_proyecto_final_segundo_semestre_pagina_de_presentacion.html"); 
     
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
     
     int cantLogIn = 0;
     
     for(int i = 0; i < datosDelAdministrador.cantAdministradores; i++){
           if(NombreAdministrador == datosDelAdministrador.todosLosAdmin.UsersAdministradores[i]){
                if(ContraseniaAdministrador == datosDelAdministrador.todosLosAdmin.ContrasAdministradores[i]){
                      cout<<"Te has logueado exitosamente como administrador!"<<endl;
                      cantLogIn++;
                      system("start Frontend_proyecto_final_segundo_semestre_pagina_de_presentacion.html");        //Aqui va el inicio de la vista principal                    
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
                        cantLogIn++;
                        system("start Frontend_proyecto_final_segundo_semestre_pagina_de_presentacion.html");          //Aqui va el inicio de la vista principal           
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


//Funcion que realiza la maquetacion de la vista.     
void Escribir(short op){
    ofstream archivo;  //Contiene el archivo HTML de la vista
    ifstream file;
    
    if(op == 1){
    	archivo.open("Frontend_proyecto_final_segundo_semestre_pagina_de_presentacion.html", ios::out);  //Abre el archivo HTML
	    if(archivo.fail()){
	        cout<<"No se pudo leer el archivo, error fatal";
	        exit(1);
	    }
	    
	    archivo<<"<!doctype html>";
	    
	    archivo<<"<html lang='es'>";
	    
	    archivo<<"<head>";
	    archivo<<"<title>Proyecto final programacion 2 Andres Manuel Prieto Alvarez & Cristian Andres Grajales Perez</title>";
	    archivo<<"<meta charset='utf-8'>";
	    archivo<<"<link rel='shortcut icon type='/imagex-icon href='../Imagenes/icon.png'>";
	    archivo<<"<link rel='stylesheet' type='text/css' href='../CSS/frontend de presentacion.css'>";
	    archivo<<"<script src='../jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
	    archivo<<"<script>";
	    
	    archivo<<"$(document).ready(function(){$('#banner').hide();$('#boton').click(function(e){$('#banner').fadeIn(2000);$('#boton').addClass('whenClick');e.preventDefault();return false;})});";
	    
		archivo<<"var begin=0; function strart(op) {if (op){begin=1;}}function beginner(){return begin;}";
	    
		archivo<<"</script>";
		
		archivo<<"</head>";
		
		archivo<<"<body>";
		
		archivo<<"<section class='main'>";
		archivo<<"<img src='../Imagenes/presentacion.png' alt='avión' id='boton'>";
		archivo<<"<div id='banner'>";
		archivo<<"<form action='ingreso' id='ingreso'>";
		archivo<<"<label for='correo'>Nombre de usuario</label>";
		archivo<<"<input type='text' placeholder='Ingrese su usuario'>";
		archivo<<"<br><br>";
		archivo<<"<label for='contrasena'>Ingrese su contrasena</label>";
		archivo<<"<input type='text' placeholder='Ingrese su contrasena'>";
		archivo<<"</form>";
		archivo<<"<h2><a href='#' onclick='strart(1)'>Cootravels S.A.S</a></h2>";
		archivo<<"</div>";
		archivo<<"</section>";
		archivo<<"</body>";
		archivo<<"</html>";
	}else{
		if(op == 2){
			archivo.open("Frontend proyecto final segundo semestre pagina principal.html", ios::out);
		    if(archivo.fail()){
		        cout<<"No se pudo leer el archivo, error fatal";
		        exit(1);
		    }
		    
		    archivo<<"<!doctype html>";
		    
		    archivo<<"<html lang='es'>";
		    
		    archivo<<"<head>";
		    
			archivo<<"<title>Proyecto final programacion 2 Andrés Manuel Prieto Álvarez & Cristian Andrés Grajales Perez</title>";
		    archivo<<"<meta charset='utf-8''>";
		    archivo<<"<link rel='shortcut icon' type='/imagex-icon' href='../Imagenes/icon.png'>";
		    archivo<<"<link rel='stylesheet' type='text/css' href='../CSS/frontend para proyecto final del segundo semestre.css'>";
		    archivo<<"<script src='../jQuery/jquery-3.3.1.min.js' type='text/javascript'></script>";
		    
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
		    
		    for(int i=0;i<5;i++){
				archivo<<"<div class='galeria'>";
				archivo<<"<img src='../Imagenes/cancun.jpg' alt='imagen'>";
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
	}
}
