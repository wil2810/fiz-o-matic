#ifdef ALARM_OUT


void alarm_loop() {

  if ( alarm_counter > 0 ) {
    if ( alarm_on_timer > millis() ) {
      digitalWrite(ALARM_PORT, HIGH);
      if ( alarm_port != 0x00 ) {
        update_port_value(alarm_port, 1);
        read_ports();
      }
      /*if ( blink_bg_led ) {
        #ifdef DISPLAY_BG_LED
        analogWrite(DISPLAY_BG_LED, 255);
        #endif
      }*/
    }
    else if ( alarm_off_timer > millis() ) {
      digitalWrite(ALARM_PORT, LOW);
      if ( alarm_port != 0x00 ) {
        update_port_value(alarm_port, 0);
        read_ports();
      }
      /*if ( blink_bg_led ) {
        #ifdef DISPLAY_BG_LED
        analogWrite(DISPLAY_BG_LED, 0);
        #endif
      }*/
    }
    else {
      alarm_counter--;
      alarm_on_timer = millis() + alarm_on;
      alarm_off_timer = alarm_on_timer + alarm_pause;
    }
  }
}


void set_alarm(int on, int pause, int count, boolean blink) {
  alarm_counter = count;
  alarm_on = on;
  alarm_pause = pause;
  blink_bg_led = blink;
  alarm_counter++;
}

void set_alarm(int on, int pause, int count) {
  alarm_counter = count + 1;
  alarm_on = on;
  alarm_pause = pause;

}

#endif // ALARM_OUT
