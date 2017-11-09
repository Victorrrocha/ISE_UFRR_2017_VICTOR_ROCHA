#include<at89x52.h>
#define Cha P2_0
#define Cafe P2_1
#define PresencaDeCopo P1_0
#define DeramandoLiquido P1_1


void delay(ms){
	int i;
		for (i=0;i<=4*ms;i++){
		;
		}
}

void acionarPedido()interrupt 0{
	
	if ((Cha == 1)&&(Cafe == 0)){
		PresencaDeCopo = 1;
		DeramandoLiquido = 1;
		delay(20000);
		DeramandoLiquido = 0;
		PresencaDeCopo = 0;
		Cha = 0;
	}else
	if ((Cha == 0)&&(Cafe == 1)){
		PresencaDeCopo = 1;
		DeramandoLiquido = 1;
		delay(20000);
		DeramandoLiquido = 0;
		PresencaDeCopo = 0;
		Cafe =0;
	}
}

void main (){
	P2=0;
	P1=0;
	EA=1;
	EX0=1;
	while (1){
	
	}

}