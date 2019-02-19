var user_name, name_of_user, user_cddc, user_password, hotel_price;
	function check() {
		user_name=document.getElementById('user').value;
		name_of_user=document.getElementById('names').value;
		user_cddc=document.getElementById('cddc').value;
		user_password=document.getElementById('password').value;
	}

	function nombre_de_usuario() {return user_name;}
	function nombre_del_usuario() {return name_of_user;}
	function cedula_del_usuario() {return user_cddc;}
	function contraseña_del_usuario() {return user_password;}