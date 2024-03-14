#include <Firebase_ESP_Client.h>
#include <WiFi.h>
#include <addons/TokenHelper.h>
#include <ArduinoJson.h>
#define FIREBASE_USE_PSRAM

//Conectar a una red WiFi 
const char* WIFI_SSID = "ASTRONET_TENESACA_LOJANO";//el nombre de la red
const char* WIFI_PASSWORD = "joselin052003";//la contraseña de la red
//Recursos de Firebase
const char* API_KEY = "AIzaSyAf8ohmNDyWtf00Z_ABlEBxVLDybWz3bQk";
const char* FIREBASE_PROJECT_ID = "sumativaap4";
//CONFIGURAR UN EMAIL Y CONTRASEÑA EN AUTHENTICATION de Firebase
const char* USER_EMAIL = "naomit0222@ionic.cli.com";
const char* USER_PASSWORD = "Naomi0999462169";

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

//Funcion para configuara WiFi
void setupWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.token_status_callback = tokenStatusCallback;  // Ver addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void controlarLEDs(bool encender, int pin) {
  digitalWrite(pin, encender ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);//Verificamos la version
  setupWiFi();//Llamamos la funcion de configuración wifi
  setupFirebase();//Llamamos la funcion de configuración Firebase
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
}

void apagarLEDs() {
  // Apagar todos los LEDs
  for (int i = 4; i <= 23; ++i) { // Suponiendo que los pines de 4 a 23 están conectados a los LEDs
    controlarLEDs(false, i);
  }
}

void encenderLED(const char* pokemon_type) {
  apagarLEDs();

  // Mapear el tipo de Pokémon a los colores de los LEDs
  if (strcmp(pokemon_type, "steel") == 0) {
    controlarLEDs(true, 23); // Prender LED1 (Steel) en el pin 23
    Serial.println("LED1 On (Steel)");
  }
  else if (strcmp(pokemon_type, "water") == 0) {
    controlarLEDs(true, 22); // Prender LED2 (Water) en el pin 22
    Serial.println("LED2 On (Water)");
  }
  else if (strcmp(pokemon_type, "bug") == 0) {
    controlarLEDs(true, 21); // Prender LED3 (Bug) en el pin 21
    Serial.println("LED3 On (Bug)");
  }
  else if (strcmp(pokemon_type, "dragon") == 0) {
    controlarLEDs(true, 20); // Prender LED4 (Dragon) en el pin 20
    Serial.println("LED4 On (Dragon)");
  }
  else if (strcmp(pokemon_type, "electric") == 0) {
    controlarLEDs(true, 19); // Prender LED5 (Electric) en el pin 19
    Serial.println("LED5 On (Electric)");
  }
  else if (strcmp(pokemon_type, "ghost") == 0) {
    controlarLEDs(true, 18); // Prender LED6 (Ghost) en el pin 18
    Serial.println("LED6 On (Ghost)");
  }
  else if (strcmp(pokemon_type, "fire") == 0) {
    controlarLEDs(true, 4); // Prender LED7 (Fire) en el pin 17
    Serial.println("LED7 On (Fire)");
  }
  else if (strcmp(pokemon_type, "fairy") == 0) {
    controlarLEDs(true, 16); // Prender LED8 (Fairy) en el pin 16
    Serial.println("LED8 On (Fairy)");
  }
  else if (strcmp(pokemon_type, "ice") == 0) {
    controlarLEDs(true, 15); // Prender LED9 (Ice) en el pin 15
    Serial.println("LED9 On (Ice)");
  }
  else if (strcmp(pokemon_type, "fight") == 0) {
    controlarLEDs(true, 14); // Prender LED10 (Fight) en el pin 14
    Serial.println("LED10 On (Fight)");
  }
  else if (strcmp(pokemon_type, "normal") == 0) {
    controlarLEDs(true, 13); // Prender LED11 (Normal) en el pin 13
    Serial.println("LED11 On (Normal)");
  }
  else if (strcmp(pokemon_type, "grass") == 0) {
    controlarLEDs(true, 12); // Prender LED12 (Grass) en el pin 12
    Serial.println("LED12 On (Grass)");
  }
  else if (strcmp(pokemon_type, "psychic") == 0) {
    controlarLEDs(true, 11); // Prender LED13 (Psychic) en el pin 11
    Serial.println("LED13 On (Psychic)");
  }
  else if (strcmp(pokemon_type, "rock") == 0) {
    controlarLEDs(true, 10); // Prender LED14 (Rock) en el pin 10
    Serial.println("LED14 On (Rock)");
  }
  else if (strcmp(pokemon_type, "dark") == 0) {
    controlarLEDs(true, 9); // Prender LED15 (Dark) en el pin 9
    Serial.println("LED15 On (Dark)");
  }
  else if (strcmp(pokemon_type, "ground") == 0) {
    controlarLEDs(true, 8); // Prender LED16 (Ground) en el pin 8
    Serial.println("LED16 On (Ground)");
  }
  else if (strcmp(pokemon_type, "poison") == 0) {
    controlarLEDs(true, 7); // Prender LED17 (Poison) en el pin 7
    Serial.println("LED17 On (Poison)");
  }
  else if (strcmp(pokemon_type, "flying") == 0) {
    controlarLEDs(true, 5); // Prender LED18 (Flying) en el pin 6
    Serial.println("LED18 On (Flying)");
  }
  else {
    // Si el tipo de Pokémon no coincide con ninguno de los mapeos, no hacer nada
    Serial.println("No LED to turn on for this type of Pokémon.");
  }
}

void loop() {
  String path = "Pokedex";//RUTA DE COLECCION

  if (Firebase.Firestore.getDocument(&fbdo, FIREBASE_PROJECT_ID, "", path.c_str(), "")) {

    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, fbdo.payload().c_str());

     if (!error) {
      for (JsonObject document : doc["documents"].as<JsonArray>()) {
        const char* document_name = document["name"];
        const char* pokemon_type = document["fields"]["Tipo"]["stringValue"];
        // Encender el LED correspondiente al tipo de Pokémon
        encenderLED(pokemon_type);
      }
    }
  }
}
