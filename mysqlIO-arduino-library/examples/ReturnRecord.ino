/*
 * mysql
 * Version 1.0 22th of August, 2015
 * Author : Ajay Masi
 * Organisation : Shivy Inc.
 * ***********************************
 * To run this code you have to follow the procedure :
 * Create database 'arduino'
 * Create table in arduino of name 'sensors' with fields:
 * 'id' of type INT with autoincrement
 * 'name' of type VARCHAR with size 100
 * 'value' of type integer
 *
 *
 * You need to add a few records in the MySQL database manually or 
 * by using the example InsertRecord
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
String result;
void setup()
{
	Serial.begin(9600);
        while(!Serial){
          ;
        }
        pinMode(12,OUTPUT);
        host = "localhost";
	user = "root";
	pass = "";
	db = "arduino";
	mysql_connect(host,user,pass,db);
	 
	Serial.print("Connected to ");
	Serial.println(host);
	
        result = mysql_result_query("SELECT * FROM relays WHERE relay_name = 'light'", "state");
}

void loop(){
  result = mysql_result_query("SELECT * FROM relays WHERE relay_name = 'light'", "state");
  if(result){
                        Serial.print("Value is:");
                          Serial.println(result);	
                         if(result == "False"){
                          digitalWrite(12, LOW);
                        }else{
                          digitalWrite(12, HIGH);
                        }
		}else{
			Serial.println("Query exexcution failed or no record(s) found.");
		}
delay(500);
}






