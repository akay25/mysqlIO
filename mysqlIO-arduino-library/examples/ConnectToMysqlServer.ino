/* * ***************************************************************/
 * To run this code you have to follow the procedure :
 * Create database 'arduino'
 * Create table in arduino of name 'sensors' with fields:
 * 'id' of type INT with autoincrement
 * 'name' of type VARCHAR with size 100
 * 'value' of type integer
 *
 *
 * If you are using Wamp Server change the credentials according
 * to your MySQL configuration
 *
 *
 * Make sure your Wamp Server or anyother MySQL service as specified 
 * is running else it will generate error 
 */
#include <mysql.h>

char *host, *user, *pass, *db;
int isconnected = 0;

void setup()
{
	Serial.begin(9600);
	host = "localhost";
	user = "root";
	pass = "";
	db = "arduino";
	isconnected = mysql_connect(host,user,pass,db);
	if(isconnected){
		Serial.print("Connected to ");
                Serial.println(host);
	}
	else{
		Serial.println("Connection failed.");
	}
	mysql_close();
}

void loop(){}
