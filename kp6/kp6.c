#include <stdio.h>
#include "person.h"

void without_filename() //error 'without file name'
	{
		printf("Error.\nUsage: [-f][INT] FILE.\n");
	}

	void file_not_exist(char* file) //file not exist
	{
		printf("File \"%s\" not exist.\nUsage: [-f][INT] FILE.\n",file);
	}


void print_bottom_row()
	{
		printf("|");
		for(int i = 0; i < TABLE_NAME_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_INITS_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_GENDER_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_NUMBER_GROUP_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_RATING_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_RATING_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_RATING_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_RATING_WIDTH; ++i) {
			printf("_");
		}
		printf("|");
		for(int i = 0; i < TABLE_RATING_WIDTH; ++i) {
			printf("_");
		}
		printf("|\n");
}

void print_top_row()
	{
		for(int i = 0; i < TABLE_WIDTH; ++i) {
			printf("_");
		}
		printf("\n");

		printf("|Surname             ");
		printf("|Inits  ");
		printf("|Gender ");
		printf("|Number group ");
		printf("|Phisics");
		printf("|Math   ");
		printf("|Russian");
		printf("|English");
		printf("|Society|");

		printf("\n");
		print_bottom_row();
}

int readPerson(Person *p)
{
	int ret = scanf("%s %s %s %d %d %d %d %d %d",
		p->name,
		p->inits,
		&p->gender,
		&p->number_group,
		&p->rating_phisics,
		&p->rating_math,
		&p->rating_russian,
		&p->rating_english,
		&p->rating_society
	);
	
	return (ret == 9);
}


	void print_row(Person p)
	{
		if(p.name[0] == '\n') {
			p.name[0] = '|';
			printf("%-21s", p.name);
		}
		else {
			printf("|%-20s", p.name);
		}
		 
		
		printf("|%-7s", p.inits);
		printf("|%-7c", p.gender);
		printf("|%-13d", p.number_group);
		printf("|%-7d", p.rating_phisics);
		printf("|%-7d", p.rating_math);
		printf("|%-7d", p.rating_russian);
		printf("|%-7d", p.rating_english);
		printf("|%-7d|\n", p.rating_society);

		print_bottom_row();

	}

	void print_table(Person p,int count, FILE* f_in)
	{
		print_top_row();

		fseek(f_in,0,SEEK_SET);
		while(fread(&p,sizeof(p),1,f_in) == 1){
			print_row(p);
		}
		printf("\n");
	}
