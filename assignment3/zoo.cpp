#include "zoo.h"



/*********************************************************************
 * ** Program: zoo.cpp
 * ** Description: Runs all of the main functions to run the zoo each week
 * ** Pre-Conditions:Needs to be called
 * ** Post-Conditions:Program will run and weeks will pass
 * *********************************************************************/ 

using namespace std;

Zoo::Zoo(){
	monkeys = new Monkey[10];
	seaotters = new Seaotter[10];
	meerkats = new Meerkat[10];
	num_monkeys = 0;
	num_seaotters = 0;
	num_meerkats = 0;
	mon_space = 10;
	sea_space = 10;
	meer_space = 10;
	food_cost = 40;
	num_weeks = 1;
	bank = 100000;
}

Zoo::~Zoo(){
	if(monkeys != NULL){
		delete [] monkeys;
	}	
	if(seaotters != NULL){
		delete [] seaotters;
	}	
	if(meerkats != NULL){
		delete [] meerkats;
	}	
}

void Zoo::week(){
	int play_again = 0;
	do{
		srand(time(NULL));
		cout << "\nBeggining of week, here are your stats: \n" << endl;
		display();
		increment_age();
		special_event();
		calculate_revenue();
		buy_animals();
		calculate_food_cost();	
		cout << "\nEnd of week, here are your stats:\n " << endl;
		display();
		
		play_again = int_check("Would you like to go another round? (1 = yes) (2 = no)", '1', '2');
		if(bank < 0){
			play_again = 1;
			cout << "GAME OVER" << endl;
		}

	}while(play_again != 2);

}

void Zoo::buy_animals(){
	int choice = 0;

	int number = int_check("You can buy up to 2 animals, would you like 0, 1 or 2 animals: \n", '0', '2');
	
	for(int i = 1; i <= number; i++){	
		choice = int_check("Would you like to buy a: \n (1) Monkey \n (2) Seaotter \n (3) Meerkat \n", '1', '3');
		switch(choice){
		case 1: add_monkey(); break;
		case 2: add_seaotter(0); break;
		case 3: add_meerkat(0); break;
		}
		cout << "Succesfully bought! You can buy " << number-i << " more." << endl;	
	}
	cout << "Monkeys: " << num_monkeys << " Seaotters: " << num_seaotters << " Meerkats: " << num_meerkats << endl;

	cout << "Buying time for this week is now over.\n" << endl;
	
}

void Zoo::add_monkey(){
		if(mon_space > num_monkeys+2){
			monkeys[num_monkeys].set_age(104);
			num_monkeys++;
		}
		else{
			
			Monkey *temp = new Monkey[mon_space * 2];
			for(int i = 0; i < num_monkeys; i++){
				temp[i] = monkeys[i];
			}
			delete [] monkeys;
			mon_space *= 2;
			monkeys = temp;
			monkeys[num_monkeys].set_age(104);
			num_monkeys++;
		}
}
void Zoo::add_seaotter(const int flag){
		if(flag == 1){
			for(int i = 0; i < 2; i++){ 
				seaotters[num_seaotters].set_age(0);
				num_seaotters++;
			}

		}
		else if(flag == 0 && sea_space > num_seaotters + 3){
			seaotters[num_seaotters].set_age(104);
			num_seaotters++;
		}
		else{
			
			Seaotter *temp = new Seaotter[sea_space * 2];
			for(int i = 0; i < num_seaotters; i++){
				temp[i] = seaotters[i];
			}
			delete [] seaotters;
			sea_space *= 2;
			seaotters = temp;
			seaotters[num_seaotters].set_age(104);
			num_seaotters++;
			
		}
	
}

void Zoo::add_meerkat(const int flag){
		if(flag == 1){
			for(int i = 0; i < 5; i++){
				meerkats[num_meerkats].set_age(0);
				num_meerkats++;
			}

		}
		else if(meer_space > num_meerkats+6){
			meerkats[num_meerkats].set_age(104);
			num_meerkats++;
		}
		else{
			
			Meerkat *temp = new Meerkat[meer_space * 2];
			for(int i = 0; i < num_meerkats; i++){
				temp[i] = meerkats[i];
			}

			delete [] meerkats;
			meer_space *= 2;
			meerkats = temp;
			meerkats[num_meerkats].set_age(104);
			num_meerkats++;
		}

}

void Zoo::calculate_food_cost(){
	int percent = ((rand() % 51) + 75);
	food_cost = float(percent / 100.0) * float(food_cost);
	
	if(food_cost < 10){
		food_cost = 10;
	}	

	cout << "Your food cost is now $" << food_cost << endl; 
	int total = 0;

	for(int i = 0; i < num_monkeys; i++){
		total += food_cost;
	}
	for(int i = 0; i < num_seaotters; i++){
		total += food_cost;
	}
	for(int i = 0; i < num_meerkats; i++){
		total += food_cost;
	}
	bank -= total;
	cout << "To feed all the animals it cost $" << total << " You now have $" << bank << " left" << endl; 
}

void Zoo::display(){
	int baby = 0;
	int adult = 0;	


	for(int i = 0; i < num_monkeys; i++){
		if(monkeys[i].get_age() < 5){
			baby += 1;
		}
		if(monkeys[i].get_age() > 5){
			adult += 1;
		}
	}
	cout << "Monkeys: \n Adults: " << adult << "\n Babies: " << baby << endl;
	baby = 0;
	adult = 0;
	for(int i = 0; i < num_seaotters; i++){
		if(seaotters[i].get_age() < 5){
			baby += 1;
		}
		if(seaotters[i].get_age() > 5){
			adult += 1;
		}
	}
	cout << "Seaotters: \n Adults: " << adult << "\n Babies: " << baby << endl;
	baby = 0;
	adult = 0;
	for(int i = 0; i < num_meerkats; i++){
		if(meerkats[i].get_age() < 5){
			baby += 1;
		}
		if(meerkats[i].get_age() > 5){
			adult += 1;
		}
	}
	cout << "Meerkats: \n Adults: " << adult << "\n Babies: " << baby << endl;
	
	
	cout << "\nYou have $" << bank << " in the bank\n" << endl;
}

void Zoo::increment_age(){
	int temp;

	for(int i = 0; i < num_monkeys; i++){
		temp = monkeys[i].get_age();
		monkeys[i].set_age(temp+1);
	}
	for(int i = 0; i < num_seaotters; i++){
		temp = seaotters[i].get_age();
		seaotters[i].set_age(temp+1);
	}
	for(int i = 0; i < num_meerkats; i++){
		temp = meerkats[i].get_age();
		meerkats[i].set_age(temp+1);	
	}

}

void Zoo::calculate_revenue(){
	int total = 0;

	for(int i = 0; i < num_monkeys; i++){
		if(monkeys[i].get_age() < 5){
			total += (monkeys[i].get_revenue() * 2);
		}
		else{
			total += monkeys[i].get_revenue();
		}		
	}
	for(int i = 0; i < num_seaotters; i++){
		if(seaotters[i].get_age() < 5){
			total += (seaotters[i].get_revenue() * 2);
		}
		else{
			total += seaotters[i].get_revenue();
		}		
	}
	for(int i = 0; i < num_meerkats; i++){
		if(meerkats[i].get_age() < 5){
			total += (meerkats[i].get_revenue() * 2);
		}
		else{
			total += meerkats[i].get_revenue();
		}		
	}
	cout << "You earned a total of $" << total << " this week" <<  endl;
	bank += total;
		
	cout << "You now have $" << bank << endl;

}

void Zoo::special_event(){
	int event = ((rand() % 3) + 1);
	
	switch(event){
		case 1: sick_animal(); break;
		case 2: animal_birth(); break;
		case 3: attendance_boom(); break;


	}


}
void Zoo::animal_birth(){
	int species = ((rand() % 3) + 1);
	int test = 0;
	if(species == 1 && num_monkeys > 0){
		add_monkey();
		test += 1;
		monkeys[num_monkeys-1].set_age(0);
		cout << "One of your monkeys had a baby this week! They will give bonus revenue for 5 weeks!" << endl; 
	}
	else if(species == 2 && num_seaotters > 0){
		add_seaotter(1);
		test += 1;
		cout << "One of your seaotters had babies this week! They will give bonus revenue for 5 weeks!" << endl; 
	}
	else if(species == 3 && num_meerkats > 0){
		add_meerkat(1);
		test += 1;
		cout << "One of your meerkats had babies this week! They will give bonus revenue for 5 weeks!" << endl; 
	}
	if(test == 0){
		if(num_monkeys > 0){
			add_monkey();
			monkeys[num_monkeys-1].set_age(0);
		cout << "One of your monkeys had a baby this week! They will give bonus revenue for 5 weeks!" << endl; 
		}	
		else if(num_seaotters > 0){
			add_seaotter(1);
		cout << "One of your seaotters had babies this week! They will give bonus revenue for 5 weeks!" << endl; 
		}
		else if(species == 3 && num_meerkats > 0){
			add_meerkat(1);
		cout << "One of your meerkats had babies this week! They will give bonus revenue for 5 weeks!" << endl; 
		}
	}
	cout << "\n You now have: " << endl;
	cout << "Monkeys: " << num_monkeys << " Seaotters: " << num_seaotters << " Meerkats: " << num_meerkats << endl;
}

void Zoo::attendance_boom(){
	cout << "The Zoo has increased attendace this week, if you have monkeys they will bring in extra revenue!" << endl;
	if(num_monkeys > 0){
		int total = 0;
		for(int i = 0; i < num_monkeys; i++){
			total += monkeys[i].bonus_revenue_event(); 	
		}
		bank += total;
		cout << " \n Because of your monkeys you gained " << total << " of bonus revenue! \n" << endl;
	}	
}

void Zoo::sick_animal(){
	int sick = ((rand() % 3) + 1);
	int treatment = 0;
	if(sick == 1 && num_monkeys > 0){
		treatment = monkeys[num_monkeys].get_cost();
		if(monkeys[num_monkeys].get_age() > 5 && bank > (treatment / 2)){
			bank -= treatment / 2;
			cout << "An adult monkey got sick this week so $7500 was deducted from your bank \n" << 
			"Your new balance is: " << bank << endl;
		}
 		else if(monkeys[num_monkeys].get_age() < 5 && bank > (treatment)){
			bank -= treatment;
			cout << "A baby monkey got sick this week so $15000 was deducted from your bank \n" << 
			"Your new balance is: " << bank << endl;
		}
 		else{
			cout << "A monkey got sick and since you were unable to pay for treatment, it died" << endl;
			num_monkeys--;	 
		}
	}
	else if(sick == 2 && num_seaotters > 0){
		treatment = seaotters[num_seaotters].get_cost();
		if(seaotters[num_seaotters].get_age() > 5 && bank > (treatment / 2)){
			bank -= treatment / 2;
			cout << "An adult Seaotter got sick this week so 2500 was deducted from your bank \n" << 
			"Your new balance is: " << bank << endl;
		}
 		else if(seaotters[num_seaotters].get_age() < 5 && bank > (treatment)){
			bank -= treatment;
			cout << "A baby Seaotter got sick this week so $5000 was deducted from your bank \n" << 
			"Your new balance is: " << bank << endl;
		}
 		else{
			cout << "A Seaotter got sick and since you were unable to pay for treatment, it died" << endl;
			num_seaotters--;	 
		}
	}
	else if(sick == 3 && num_meerkats > 0){
		treatment = meerkats[num_meerkats].get_cost();
		if(meerkats[num_meerkats].get_age() > 5 && bank > (treatment / 2)){
			bank -= treatment / 2;
			cout << "An adult Meerkat got sick this week so $250 was deducted from your bank \n" << 
			"Your new balance is: " << bank << endl;
		}
 		else if(meerkats[num_meerkats].get_age() < 5 && bank > (treatment)){
			bank -= treatment;
			cout << "A baby Meerkat got sick this week so $500 was deducted from your bank \n" << 
			"Your new balance is: " << bank << endl;
		}
 		else{
			cout << "A Meerkat got sick and since you were unable to pay for treatment it died" << endl;
			num_meerkats--;	 
		}
	}
	else{
		cout << "One of your exhibits was infected this week but because it was empty no animals were harmed" << 
		endl;
	}
}




