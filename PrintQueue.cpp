/*   Alexander Lanthier Northern Michigan University CS222 Andy Poe
 *	 This program takes in a file input of printer queues and prints them to console in the order of completion
*/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"
#include "PrintQueue.h"
using namespace std;

int main (int argc, char **argv) {

	Queue *printqueue = new Queue(), *printingnow = new Queue();
	ifstream in("pg3cmds.txt");
	string info="-1", received="";
	bool printing = false;
	int printTime;

	for(int ii = 0; ii <= 720; ii++) { //Each loop is a minute
		if(!in.eof() && info=="-1") { //If there is no info and end of file has not been reached
			getline(in,info);
			for(int i=1; info.substr(i-1,1)!=" ";i++) received=info.substr(0,i);//When the print job was received

		}
		if(minutesPassed(received)==ii) {
			int pt;
			for(int i=1; info.substr(i-1,1)!=" ";i++) pt=toInt(info.substr(i+7)); //Convert the rest of the info string to the print time int
			cout << received << " received " << pt << "-minute print request." << endl;
			printqueue->ENQUEUE(info); //Send received message
			info="-1";
		}
		if (printing) {
			if(--printTime<=0) {
				printing = false; //Print out to console that it finished
				string done = printingnow->DEQUEUE(), rehist="";
				for(int i=1; done.substr(i-1,1)!=" ";i++) rehist=done.substr(0,i); //When this completed job was received
				cout << getTime(ii) << " completed print request submitted at " << rehist << endl;
			}
		}
		if(printing==false && !printqueue->ISEMPTY()) { //If not printing and there is still jobs left in queue
			string s = printqueue->DEQUEUE(), temp = "";
			for(int i=1; s.substr(i-1,1)!=" ";i++) temp=s.substr(i+7); //Setting print time
			printTime = toInt(temp); //Get how long the print time will be
			printing=true;
			printingnow->ENQUEUE(s);
		}
	}
	system("pause");
	return 0;
}
/*This method converts the clock time into minutes passed
  since 1:00 for up to a 12-hour period.
*/
int minutesPassed(string time) {
	int total=0,hour=0,minute=0;
	string hr = time.substr(1,1) == ":" ? time.substr(0,1) : time.substr(0,2); //Get chars before colon
	string min = time.substr(hr.length()+1); //Get chars after colon
	istringstream converthr(hr), convertmin(min);
	if ( !(converthr >> hour) ) hour = 0; //If either of these equals nothing, set to zero
	if ( !(convertmin >> minute) ) minute = 0;
	while(--hour != 0) total+=60; //Do operator first to make up for starting at "1" instead of zero on clock
	while(minute-- != 0) total++;
	return total;
}
/*This method converts the amount of minutes passed since 1:00
  for up to a 12-hour period into a string that gives the new
  clock time
*/
string getTime(int minutes) {
	if(minutes==720) return "1:00";
	stringstream convert;
	int firstNumber = 1, secondNumber = 0;
	while(minutes != 0) {
		if(minutes >= 60) { firstNumber++; minutes-=60; }//Get number of hours by subtracting by 60 min. at a time
		else {secondNumber++; minutes--;}//Get number of minutes by subtracting single min. down to zero after hours are done
	}
	convert << firstNumber << ":";

	if(secondNumber < 10){ //If this number is single digit, add a zero in front of it manually
		char a = (char)(((int)'0')+secondNumber);
		convert << "0" << a;
	}
	else convert << secondNumber;
	return convert.str();
}
//This method takes in a string, and returns the int version of it
int toInt(string a) {int b; istringstream c(a); if(!(c>>b)) b=0; return b; }
