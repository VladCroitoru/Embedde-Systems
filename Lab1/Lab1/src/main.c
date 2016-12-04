#include "uart_stdio.h"
#include <util/delay.h>

int cnt = 0;
int i = 0;
int main(void) {
	
	uart_stdio_Init();
	printf("System is on");
	
	while(1){
		printf("\r System is on for %d s", cnt);
		_delay_ms(1000);
		cnt++;
	}
	
	return 0;
}
