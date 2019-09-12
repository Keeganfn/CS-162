#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct wizard {
  string name;
  int id;
  string password;
  string position_title; 
  float beard_length;
};

struct spellbook {
  string title;
  string author;
  int num_pages;
  int edition;
  int num_spells;
  float avg_success_rate;
  struct spell *s;
};

struct spell {
  string name;
  float success_rate;
  string effect; 
};

spellbook * create_spellbooks(int);
void get_spellbook_data(spellbook *, int, ifstream &); 
spell * create_spells(int);
void get_spell_data(spell *, int, ifstream &); 
int check_file(char **);
wizard * create_wizards(char **, int&);
int login(wizard *, int, int&);
int int_check(string, char, char);
void print_page_sort(int status, spellbook *spellbook_array, int spellbook_num, string, int);
void page_sort(int status, spellbook *spellbook_array, int spellbook_num);
void sort_options(int status, spellbook *spellbook_array, int spellbook_num );
void print_avg_sort(int status, spellbook *spellbook_array, int spellbook_num, string filename, int choice);
void avg_sort(int status, spellbook *spellbook_array, int spellbook_num);
void print_effect_sort(int status, spell *effect_array, int spell_num, string filename, int choice);
void effect_sort(int status, spellbook *spellbook_array, int spellbook_num);
void delete_info(wizard *wizard_array, spellbook *spellbook_array, int spellbook_num);

