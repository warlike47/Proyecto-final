$(document).ready(function() {
	$('#banner').hide();
	$('#boton').click(function(){
	$('#banner').fadeIn(2000);
	$('#boton').addClass('whenClick');
		return false;
		})
	});

	var user_name, user_password;

	function validar() {
		user_name=document.getElementById('user').value;
		user_password=document.getElementById('password').value;
	}

	function val_user() {return user_name;}
	function val_password() {return user_password;}

	function abrir(existe){
		if(existe==1){
			$("#validado").attr('href','Pagina_principal.html');
		}else{
			if(existe==2){
				$("#validado").attr('href','Pagina_principal_para_admi.html');
			}
		}
	}