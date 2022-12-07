#include <WiFi.h>

const char* ssid     = "Inteli-COLLEGE";
const char* password = "QazWsx@123";

WiFiServer server(80);

const int azul = 45;    
const int vermelho = 37;  

const int ganhaAzul = 0;
const int empateVermelho = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(azul, OUTPUT);      // set the LED pin mode
    pinMode(vermelho, OUTPUT);

    delay(10);

    digitalWrite(azul, LOW);
    digitalWrite(vermelho, LOW);
    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<html lang=\"en\">");
            client.print("<head>");
            client.print("<meta charset=\"UTF-8\">");
            client.print("<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">");
            client.print("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
            client.print("<title>Jogo da velha da Vi</title>");
            client.print("<style>.game button {width: 100px;height: 100px;margin: 5px;cursor: pointer;font-size: 50px;background: #f7f7f7;}</style>");
            client.print("</head>");
            client.print("<body style=\" height: 100vh; display: flex; align-items: center; justify-content: center; background: #8e6893;\">");
            client.print("<main style=\" display: flex;flex-direction: column;gap: 2px;\">");
            client.print("<h1 style=\"color: rgb(0, 0, 0);\">JOGO DA VELHA DA Vi</h1>");
            client.print("<div>Jogador 1: X<br>Jogador 2: O</div>");
            client.print("<div class=\"game\" style=\"display: grid; grid-template-columns: 1fr 1fr 1fr;\">");
            client.print("<button data-i=\"1\"></button>");
            client.print("<button data-i=\"2\"></button>");
            client.print("<button data-i=\"3\"></button>");
            client.print("<button data-i=\"4\"></button>");
            client.print("<button data-i=\"5\"></button>");
            client.print("<button data-i=\"6\"></button>");
            client.print("<button data-i=\"7\"></button>");
            client.print("<button data-i=\"8\"></button>");
            client.print("<button data-i=\"9\"></button></div>");
            client.print("<h2 class=\"currentPlayer\"></h2>");
            client.print("</main>");
            client.print("<script>");
            client.print("const currentPlayer = document.querySelector(\".currentPlayer\");");
            client.print("let selected;");
            client.print("let player = \"X\";");
            client.print("let positions = [[1, 2, 3],[4, 5, 6],[7, 8, 9],[1, 4, 7],[2, 5, 8],[3, 6, 9],[1, 5, 9],[3, 5, 7],];");
            client.print("function init() {");
            client.print("selected = [];");
            client.print("document.querySelectorAll(\".game button\").forEach((item) => {");
            client.print("item.innerHTML = \"\";");
            client.print("item.addEventListener(\"click\", newMove);});}");
            client.print("init();");
            client.print("function newMove(e) {");
            client.print("const index = e.target.getAttribute(\"data-i\");");
            client.print("e.target.innerHTML = player;");
            client.print("e.target.removeEventListener(\"click\", newMove);");
            client.print("selected[index] = player;");
            client.print("setTimeout(() => {check();}, [100]);");
            client.print("player = player === \"X\" ? \"O\" : \"X\";}");
            client.print("function check() {let playerLastMove = player === \"X\" ? \"O\" : \"X\"; var wpta = new XMLHttpRequest();var wptb = new XMLHttpRequest();");
            client.print("const items = selected");
            client.print(".map((item, i) => [item, i])");
            client.print(".filter((item) => item[0] === playerLastMove)");
            client.print(".map((item) => item[1]);");
            client.print("for (pos of positions) {");
            client.print("if (pos.every((item) => items.includes(item))) {");
            client.print("alert(\"O JOGADOR '\" + playerLastMove + \"' GANHOU!\");init();wpta.open(\"GET\", \"/winone\", true); wpta.send();return;}}");
            client.print("if (selected.filter((item) => item).length === 9) {");
            client.print("alert(\"EMPATE!\");init();wptb.open(\"GET\", \"/wintwo\", true); wptb.send();return;}}</script></body>");
            client.print("</html>");
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }


        if (currentLine.endsWith("GET /winone")) {
          digitalWrite(azul, HIGH);
          delay(2000);
          digitalWrite(azul, LOW);
        }
        if (currentLine.endsWith("GET /wintwo")) {
          digitalWrite(vermelho, HIGH);
          delay(2000);
          digitalWrite(vermelho, LOW);
        }   
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
