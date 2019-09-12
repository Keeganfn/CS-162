#include "event.h"

using namespace std;

Event::Event(){
	name = "none";
	symbol = " ";
}

Event::~Event(){

}

string Event::get_name() const{
	return name;
}

string Event::get_symbol() const{
	return symbol;
}
