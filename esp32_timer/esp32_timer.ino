//  Calculation of settings for each frequency band
//  Resolution = log2(Clock(80MHz)/f) + 1   ex: 50.000 HZ = 80.0000/50.000 = 1.600 log2(1600) = 10 + 1 = 11
//  Duty 50%  = (2**Resolution)/2       ex: 2**11 = 2048   2048/2 = 1024

#include "driver/ledc.h"

#define LEDC_HS_CH0_GPIO      GPIO_NUM_25                                 // Ledc pulse output

#define LEDC_HS_CH0_CHANNEL   LEDC_CHANNEL_0                              // LEDC channel 0
#define LEDC_HS_MODE          LEDC_HIGH_SPEED_MODE                        // LEDC inhigh speed
#define LEDC_HS_TIMER         LEDC_TIMER_0                                // Use timer0 ledc

uint32_t        resolution    = 0;                                        // Resolution var
uint32_t        oscilator     = 4000000;                                  // Frequency  Hz
uint32_t        mDuty         = 0;                                        // Calc ledc duty var
//------------------------------------------------------------------------
void ledcInit ()
{
  resolution = log((80000000 / oscilator) + 1) / log(2);                  // Ledc resolution  calc
  if (resolution > 20) resolution = 20;                                   // Max resolution is 20
  mDuty = (pow(2, resolution)) / 2;                                       // Calc ledc duty
  //  Serial.println(mDuty);                                              // Print

  ledc_timer_config_t ledc_timer = {};                                    // Instantiate the ledc timer setting

  ledc_timer.duty_resolution = (ledc_timer_bit_t) + resolution;           // Config resolution
  ledc_timer.freq_hz    = oscilator;                                      // Frequency
  ledc_timer.speed_mode = LEDC_HIGH_SPEED_MODE;                           // Oper Mode high speed
  ledc_timer.timer_num = LEDC_TIMER_0;                                    // Use timer0
  ledc_timer_config(&ledc_timer);                                         // Config ledc timer

  ledc_channel_config_t ledc_channel = {};                                // Instantiates the ledc channel configuration

  ledc_channel.channel    = LEDC_HS_CH0_CHANNEL;                          // Config channel
  ledc_channel.duty       = mDuty;                                        // Calc duty  %
  ledc_channel.gpio_num   = LEDC_HS_CH0_GPIO;                             // Output GPIO
  ledc_channel.intr_type  = LEDC_INTR_DISABLE;                            // Disabledc interrupt de ledc
  ledc_channel.speed_mode = LEDC_HIGH_SPEED_MODE;                         // Oper high speed
  ledc_channel.timer_sel  = LEDC_TIMER_0;                                 // Use timer0

  ledc_channel_config(&ledc_channel);                                     // Config ledc channel
}
//------------------------------------------------------------------------
void setup() {
  ledcInit();
}
//------------------------------------------------------------------------
void loop() {}
