	#include <stdio.h>
	#include <string.h>
	#include "person.h"
	#include <stdlib.h> 

	#define TABLE_WIDTH 92
	#define TABLE_NAME_WIDTH 20
	#define TABLE_INITS_WIDTH 7
	#define TABLE_GENDER_WIDTH 7
	#define TABLE_NUMBER_GROUP_WIDTH 13
	#define TABLE_RATING_WIDTH 7

	int main(int argc, char* argv[])
	{
		if(argc<1) { //if even 1 key name and filename exist
			without_filename();
			return 1;
		}

		int check_f=0;
		
		FILE* f_in;
		f_in = 0;
		for(int i=1; i<argc; ++i) { //choose arguments and filename

			if (!strcmp(argv[i],"-f")) {
				check_f = 1;
			}
		else {
			f_in  = fopen(argv[i],"r");
			if(!f_in) {
				file_not_exist(argv[i]);
				return 2;
			}
		}
	
	}

	
	if(!f_in) { //if keys wrong or file not exist
		without_filename();
		return 2;
	}

	fseek(f_in,0,SEEK_END); 
	int fsize = ftell(f_in); //file size
	fseek(f_in,0,SEEK_SET);

	Person tmp_p; 
	int psize = sizeof(tmp_p); //person struct size
	int count_of_recs = fsize/psize; //count of records of table
	
	Person p;
	int k = 0, f = 0;
	fflush(stdout);
	int *a = (int*)malloc(sizeof(int));
	
	while(fread(&p,sizeof(p),1,f_in) == 1) {
		if(p.gender == 'w'){
			f = 0;
			for(int i = 0; i < k; i++){
				if(p.number_group == a[i]){
					f = 1;
					break;
				}
			}
			if(f == 0){	
				a = (int*)realloc(a, (k+1) * sizeof(int));
				a[k] = p.number_group;
				k++;
			} 
		}
	}
	
	if(k == 0) {
		printf("Studentok ne bilo\n");
		if(check_f)
			print_table(p,count_of_recs, f_in);
		return 0;
	}
	
	fseek(f_in,0,SEEK_SET);
	int *b = (int*)calloc(k, sizeof(int));
	int *c = (int*)calloc(k, sizeof(int));
	double *sr = (double*)calloc(k, sizeof(double));
	double max = 0, srarf = 0, sum = 0;
	int maxgroup = 0;
	while(fread(&p,sizeof(p),1,f_in) == 1) {
		if(p.gender == 'w'){
			for(int i = 0; i < k; i++){
				if(p.number_group == a[i]){
					b[i] += p.rating_phisics + p.rating_math + p.rating_russian + p.rating_english + p.rating_society;
					c[i] += 5;	
				}
			}
		}		
	}
	for(int i = 0; i < k; i++){
		sr[i] = (double)b[i]/c[i];
	}		
	for(int i = 0; i < k; i++){
		if(sr[i] > max){
			maxgroup = i;
			max = (double)b[i]/c[i];
		}
	}
	for(int i = 0; i < k; i++){
		printf("Group %d have sredniy ball: %lf\n", a[i], sr[i]);
	}
	printf("Group with max sredniy ball: %d\n", a[maxgroup]);
	if(check_f)
		print_table(p,count_of_recs, f_in);
					
	free(a);
	fclose(f_in);
	return 0;
}