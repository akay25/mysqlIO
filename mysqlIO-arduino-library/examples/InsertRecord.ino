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
 * If you are using Wamp Server change the credentials according
 * to your MySQL configuration
 *
 *
 * Make sure your Wamp Server or anyother MySQL service as specified 
 * is running else it will generate error 
 */
 
#include <mysql.h>

char *host, *user, *pass, *db;

void setup()
{
	Serial.begin(9600);
	host = "localhost";
	user = "root";
	pass = "";
	db = "arduino";
	if(mysql_connect(host,user,pass,db)){
	 
		Serial.print("Connected to ");
		Serial.println(host);
		int result = mysql_query("INSERT INTO sensor(`name`, `value`) VALUES('IR', '0000')");
		if(result){
			Serial.println("Query exexcuted.");
		}else{
			Serial.println("Query exexcution failed.");
		}
	}else{
		Serial.println("Connection failed.");
	}
}

void loop(){}






