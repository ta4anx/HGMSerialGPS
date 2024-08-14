//     _            _       _               _   _                   
//    / \   _ __ __| |_   _(_)_ __   ___   | \ | | __ _ _ __   ___  
//   / _ \ | '__/ _` | | | | | '_ \ / _ \  |  \| |/ _` | '_ \ / _ \ 
//  / ___ \| | | (_| | |_| | | | | | (_) | | |\  | (_| | | | | (_) |
// /_/   \_\_|  \__,_|\__,_|_|_| |_|\___/  |_| \_|\__,_|_| |_|\___/ 
//  _   _  ____ __  __   _  ___   _             ____ ____  ____     
// | | | |/ ___|  \/  | | |/ (_) (_)_ __ ___   / ___|  _ \/ ___|    
// | |_| | |  _| |\/| | | ' /| | | | '__/ _ \ | |  _| |_) \___ \    
// |  _  | |_| | |  | | | . \| |_| | | |  __/ | |_| |  __/ ___) |   
// |_| |_|\____|_|  |_| |_|\_\\__,_|_|  \___|  \____|_|   |____/    
//     _    _                                                       
//    / \  | |_  ___ _                                              
//   / _ \ | | |/ __| |                                             
//  / ___ \| | | (__| |                                             
// /_/   \_\_|_|\___|_|    

/*
Harita Genel Müdürlüğü - HGM Küre Windows Masaüstü uygulamasında GPS takibi kısmında yer alan GPS İzle NMEA formatı verisini sağlamak içim
Arduino Nano mikroişlemcisi ve gy neo6mv2 GPS Modülü ile NMEA formatında seri haberleşme kullanarak çıktı veren basit Arduino kodu
Bağlantıo şeması Modülü muhafaza edecek 3 Boyutlu model için GitHub reposunu ziyaret edin.

 github.com/ta4anx - Kaan Çakmak 2024
  _____ _  _ _   _   _  ___  __
 |_   _/_\| | | /_\ | \| \ \/ /
   | |/ _ \_  _/ _ \| .` |>  < 
   |_/_/ \_\|_/_/ \_\_|\_/_/\_\                           
*/


#include <SoftwareSerial.h>

SoftwareSerial gpsSerial(10, 11); // GPS modülünün RX TX pinleri

void setup() {
    Serial.begin(9600); // Seri bağlantı için hata ayıklamayı başlat
    gpsSerial.begin(9600); // GPS modülünün seri bağlantısını başlat
}

void loop() {
    if (gpsSerial.available()) {
        char c = gpsSerial.read();
        Serial.print(c); //  GPS verisini seri monitörde yeni satıra (newline) geçmeden çıktı ver
        if (c == '\n') { 
            Serial.println(); // Add newline after each NMEA sentence Her NMEA bağlantısından sonra yeni satır (newline) ekle
        }
    }
}