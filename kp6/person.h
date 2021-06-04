#ifndef PERSON_H
#define PERSON_H

typedef struct _Person
{
	char name[17];	// Фамилия
	char inits[9];	// Инициалы
	char gender;		// Пол
	int number_group;		// Группа
	int rating_math;  // Математика
	int rating_phisics;	// Физика
	int rating_russian;		// Русский язык
	int rating_english;		// Англ. язык
	int rating_society;   // Социология
} Person;

#endif
