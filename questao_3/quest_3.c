#include<at89x52.h>
#define Cameras P2
#define Camera0 P2_0
#define Camera1 P2_1
#define Camera2 P2_2
#define Camera3 P2_3

#define Sensors P1
#define Sensor0 P1_0
#define Sensor1 P1_1
#define Sensor2 P1_2
#define Sensor3 P1_3


int count0,count1,count2,count3;

void sensor_verification ()interrupt 1{
TR0 = 0; 
TH0 = 0x3C;
TL0 = 0xAF; 
TR0 = 1; 
	count0++;

	if(Sensor0==1){
				Camera0=1;
				Camera1=0;
				Camera2=0;
				Camera3=0;
			}
	if(Sensor1==1){
				Camera1=1;
				Camera0=0;
				Camera2=0;
				Camera3=0;
			}
	if(Sensor2==1){
				Camera2=1;
				Camera1=0;
				Camera0=0;
				Camera3=0;
			}
	if(Sensor3==1){
				Camera3=1;
				Camera1=0;
				Camera2=0;
				Camera0=0;
			}	
	
	if((count0<60)){
		Camera0=1;
	}
	if((count0>=60)&&(count0<120)){
				Camera3=0;
			
	}
	if((count0>=120)&&(count0<180)){
				Camera1=1;
				Camera0=0;
			
	}
	
	if((count0>=180)&&(count0<240)){
				Camera2=1;
				Camera1=0;
			
	}
	
	if((count0>=240)&&(count0<300)){
				Camera3=1;
				Camera2=0;
					
	}
	if (count0==300){
		Camera3=0;
		count0=0;
	}
}



void main (){
	P0=0;
	Cameras = 0;
	Sensors = 0;
	EA=1;
	EX0=1;
	ET0 = 1; 
	TMOD = 1;

	while (1){
			TR0 = 1;
	}
	
}