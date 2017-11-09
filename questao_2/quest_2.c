#include<at89x52.h>
#define esteira_caixa P0_0
#define esteira_produto P0_1
 
int cont0, cont1, quantidade = 0;
void nova_caixa(void) interrupt 3{
//TR0 = 0;
TR1 = 0; //Timer 1 Run Control  desativado
TH1 = 0x3C; //recarga
TL1 = 0xAF; 
TR1 = 1; //Timer 1 Run Control ativado
cont1++;
	if(cont1 == 12000){ 
		esteira_produto = 0;
		esteira_caixa = 1;
		cont1 = 0;
	}
}

void produto_caixa(void) interrupt 1{
TR0 = 0; 
TH0 = 0x3C;
TL0 = 0xAF; 
TR0 = 1; 
	cont0++;
	if(cont0==100){ 
		esteira_produto = 1;
	  esteira_caixa = 0;
		quantidade++;
		cont0=0;
	}
}
main(){
	P0 = 0;
	EA = 1; 
	ET0 = 1; 
	ET1 = 1; 
	TMOD = 1;
	TR0 = 1;

	while(1){
		if(quantidade != 10){
		TR1 = 1;
		quantidade = 0;
	}
}
}
