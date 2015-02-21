void msgHandleZevaCoreStatus(byte rx_status, byte length, uint32_t frame_id, byte filter, byte buffer, byte *frame_data, byte ext) {
  
  int soc = frame_data[1];
  int voltage = (frame_data[2] + ((frame_data[3] & 0xF0) << 4));
  int current = ((frame_data[4] << 4) + (frame_data[3] & 0x0F)) - 2048;
  float aux_voltage = frame_data[5]/10;
  int temperature = frame_data[7];
  
  Serial.print("Error: ");
  Serial.println(frame_data[0]>>4);
  Serial.print("Status: ");
  Serial.println(frame_data[0]&15);
  Serial.print("State of Charge: ");
  Serial.println(soc);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.print("Current: ");
  Serial.println(current);
  Serial.print("Auxiliary Voltage: ");
  Serial.println(aux_voltage);
  Serial.print("Temperature: ");
  Serial.println(temperature);
}

void msgHandleZevaCoreConfigData1(byte rx_status, byte length, uint32_t frame_id, byte filter, byte buffer, byte *frame_data, byte ext) {
  Serial.print("Pack capacity [Ah]: ");
  Serial.println(frame_data[0]);
  
  Serial.print("SOC warning threshold [%]: ");
  Serial.println(frame_data[1]);
  
  Serial.print("Full voltage [V]: ");
  Serial.println(2 * frame_data[2]);
  
  Serial.print("Current warning threshold [A]: ");
  Serial.println(10 * frame_data[3]);
  
  Serial.print("Overcurrent threshold [A]: ");
  Serial.println(10 * frame_data[4]);
  
  Serial.print("Over-temperature theshold [C]: ");
  Serial.println(frame_data[5]);
  
  Serial.print("Minimum auxiliary voltage [V]: ");
  Serial.println(frame_data[6]);
  
  Serial.print("Maximum leakage [%]: ");
  Serial.println(frame_data[7]);
}
