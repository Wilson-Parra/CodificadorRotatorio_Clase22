

int A = 2; 			//variable A a pin digital 2 (DT en modulo)
int B = 4;  			//variable B a pin digital 4 (CLK en modulo)

int ANTERIOR = 50;		// almacena valor anterior de la variable POSICION

volatile int POSICION = 50;	// variable POSICION con valor inicial de 50 y definida
				// como global al ser usada en loop e ISR (encoder)
void setup() {
  pinMode(A, INPUT);		// A como entrada
  pinMode(B, INPUT);		// B como entrada

  Serial.begin(9600);		// incializacion de comunicacion serie a 9600 bps

  attachInterrupt(digitalPinToInterrupt(A), encoder, LOW);// interrupcion sobre pin A con
							  // funcion ISR encoder y modo LOW
  Serial.println("Listo");	// imprime en monitor serial Listo
}


void loop() {
  if (POSICION != ANTERIOR) {	
    Serial.println(POSICION);	
    ANTERIOR = POSICION ;	
  }
}

void encoder()  {
  static unsigned long ultimaInterrupcion = 0;	
					
  unsigned long tiempoInterrupcion = millis();	

  if (tiempoInterrupcion - ultimaInterrupcion > 5) {	
							
    if (digitalRead(B) == HIGH)		
    {
      POSICION++ ;			
    }
    else {					
      POSICION-- ;				
      
    }

    POSICION = min(100, max(0, POSICION));	
						
    ultimaInterrupcion = tiempoInterrupcion;	
  }						
}