#include "devices/random.h"
#include "devices/uart.h"
#include "devices/timer.h"

#include <register_access.h>
#include <stdbool.h>


static void timerTest( void );

int main( void )
{
  uart_init();
  uart_writeLine( "Hello World!\n" );

  timerTest();
}

static void timerTest( void )
{
  //timer_init( TIMER0 );
  timer_init_detailed( TIMER0, 15, TIMER_MODE_TIMER, TIMER_BIT_MODE_32);
  timer_captureCompareSet( TIMER0, CC0, 2000, true );
  timer_start( TIMER0 );

}
