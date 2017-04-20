
//chân ST_CP của 74HC595
int latchPin1 = 8, latchPin2 = 7;
//chân SH_CP của 74HC595
int clockPin1 = 13, clockPin2 = 12;
//Chân DS của 74HC595
int dataPin1 = 11, dataPin2 = 10;

int ledStatus;


long pow(int a, int b)
{
  long kq = 1;
  for(int i = 1; i <= b; i++)
    kq *= a;
   return kq;
}

void setup() 
{
  Serial.begin(9600);
  pinMode(latchPin1, OUTPUT);
  pinMode(clockPin1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
   pinMode(latchPin2, OUTPUT);
  pinMode(clockPin2, OUTPUT);
  pinMode(dataPin2, OUTPUT);

}

void loop() 
{
  sang_traiphai(latchPin1, clockPin1, dataPin1);
  sang_traiphai(latchPin2, clockPin2, dataPin2);
  toi_traiphai(latchPin1, clockPin1, dataPin1);
  toi_traiphai(latchPin2, clockPin2, dataPin2);

  sang_phaitrai(latchPin2, clockPin2, dataPin2);
  sang_phaitrai(latchPin1, clockPin1, dataPin1);
  toi_phaitrai(latchPin2, clockPin2, dataPin2);
  toi_phaitrai(latchPin1, clockPin1, dataPin1);
}

void sang_traiphai(int latchPin, int clockPin, int dataPin)
{
  
  ledStatus = 0;
  for (int i = 0; i < 8; i++) {
    ledStatus = (ledStatus << 1) | 1; 
    
    
    
    digitalWrite(latchPin, LOW); //các đèn LED sẽ không sáng khi bạn digital LOW
 
    //ShiftOut ra IC
    shiftOut(dataPin, clockPin, MSBFIRST, ledStatus);  

    digitalWrite(latchPin, HIGH);//các đèn LED sẽ sáng với trạng thái vừa được cập nhập
   
    /**
      Kết thúc bắt buộc phải có
    **/
    
    delay(500); // Dừng chương trình khoảng 500 mili giây để thấy các hiệu ứng của đèn LED
  }
  
 
}

void toi_traiphai(int latchPin, int clockPin, int dataPin)
{
  ledStatus = pow(2,8)-1;
   for (int i = 0;i<8;i++) 
  {
    ledStatus <<= 1; //Đẩy tất cả các bit qua bên trái 1 bit
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ledStatus);  
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}

void sang_phaitrai(int latchPin, int clockPin, int dataPin)
{
  //Sáng tuần tự từ trái sang phải
  ledStatus = 0;
  int x1;
  
  for (int i = 7; i >=0; i--) 
  {
    x1 = pow(2,i);
    Serial.println(x1);
    ledStatus = ledStatus | x1;
    
    Serial.println(ledStatus);
    digitalWrite(latchPin, LOW);
    
    shiftOut(dataPin, clockPin, MSBFIRST, ledStatus);  
    
    digitalWrite(latchPin, HIGH);
    delay(500); 
  }
}

void toi_phaitrai(int latchPin, int clockPin, int dataPin)
{
  ledStatus = pow(2,8);
  int x1;
  //Tắt tuần tự
  for (int i = 7 ;i >= 0; i--)
  {
    x1 = pow(2,i)-1;
    digitalWrite(latchPin, LOW);
    
    shiftOut(dataPin, clockPin, MSBFIRST, x1);  
    
    digitalWrite(latchPin, HIGH);
    delay(500);
  }
}
