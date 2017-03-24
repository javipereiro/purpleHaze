/* Funciones con pines preasignados para la fácil lectura del programa*/
/* sharpMRead()*/
int sharpMRead(){
	return analogRead(2);
  }
/* sharpRRead()*/
int sharpRRead(){
	return analogRead(1);
  }
  /* sharpLRead()*/
int sharpLRead(){
	return analogRead(0);
  }