#include "version_info.h"

#include <stdio.h>
#include "pico/stdlib.h"

#define MAJOR_VERSION   0x01
#define MINOR_VERSION   0x01

static const uint LED_PIN = PICO_DEFAULT_LED_PIN;
static bool led_state = false;

static repeating_timer_t led_timer, print_timer;

bool timer_callback( repeating_timer_t *rt )
{   
    if(rt->alarm_id == 1)
    {
        //Blinks the LED
        led_state = !led_state;
        gpio_put(LED_PIN, led_state);
        printf("[alarm %d] [delay  %d]Current LED state is %s\n", rt->alarm_id, rt->delay_us, led_state?"On":"Off");
    }
    else if(rt->alarm_id == 2)
    {
        printf("[alarm %d] [delay  %d] dummy text\n", rt->alarm_id, rt->delay_us);
    }

    return (true);
}

static void led_init()
{    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

static void print_version_details()
{
    printf("Current version is %d.%d", MAJOR_VERSION, MINOR_VERSION);
}

void initial_configuraion()
{
    stdio_init_all();
    led_init();
    print_version_details();
    add_repeating_timer_ms( 1000, &timer_callback, NULL, &led_timer);
    add_repeating_timer_ms( 1500, &timer_callback, NULL, &print_timer);
}