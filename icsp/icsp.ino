  /* Arudino - PIC Programmer v1.0 */
  
  /* those are the pins configuration out of Arduino */
  const int MCLR_PIN  = 1;
  const int PGD_PIN   = 2;
  const int PGC_PIN   = 3;
  
  void setup() {
  // initialize serial:
    Serial.begin(9600);
    pinMode(MCLR_PIN, OUTPUT);  
    pinMode(PGD_PIN, OUTPUT);
    pinMode(PGC_PIN, OUTPUT);
  }
  void ICSPClock() {
    digitalWrite(PGC_PIN, 1);
    digitalWrite(PGC_PIN, 0);
  }
  void ICSPSendBitsClock(byte b, int nBits) {
    while(nBits--) {
      digitalWrite(PGD_PIN, b & 1);
      ICSPClock();
      b >> =1;
    }
  }
  
  void ICSPSendByteClock(byte b) {
    ICSPSendBitsClock(b);
  }
  
  void ICSPEnter() {
    // set MCLR_PIN
    digitalWrite(MCLR_PIN, HIGH);
    // wait 10ms
    delay(10);
    // clean MCLR PIN
    digitalWrite(MCLR_PIN, LOW);
    // Now #4D434851h should be sent to the board starting from MSB
    // in other words: #B2C2128A should be sent
    ICSPSendByteClock(0xB2);
    delay(10);
    ICSPSendByteClock(0xC2);
    delay(10);
    ICSPSendByteClock(0x12);
    delay(10);
    ICSPSendByteClock(0x8A);
    delay(10);
    // set MCLR PIN
    digitalWrite(MCLR_PIN, HIGH);
    
  }
