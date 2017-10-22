#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "wave_measure.h"
#include "Motor_Pwm.h"
#include "Move.h"
#include "sensor.h"
#include "search.h"


Distance distance={0,0,0},last_distance={0,0,0};
Angle angle={0,0};
Angle last_angle={0,0};

int main(void)
{ 
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
    delay_init();                                  // 延时函数初始化
    uart_init(9600);
    Wheel_Init();
    Wave_Init();
    parameter_init();
	  Sensor_Init();

    while(1)
    {
			if(distance.front<25)
				judge(0);
			else if(distance.front>70 && distance.front<75)
				judge(1);
			else judge(2);
			delay_ms(50);
    }
}
