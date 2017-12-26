#include <string>
#include <string.h>
#include <cstdio>

#define Max 20
static int count = 0;
class Dict{
public:
	void put(char name[], int order){
		strcpy(names[count], name);
		orders[count] = order;
		count++;
	}
	int get(char name[]){
		for(int i = 0; i < count; i++){
			if(strcmp(name, names[i]) == 0)
				return orders[i];
		}
		printf("Not found \n");
	}
	void update(char name[], int order){
		for(int i = 0; i < count; i++){
			if(strcmp(name, names[i]) == 0){
				orders[i] =order;
				return ;
			}
		}
		strcpy(names[count], name);
		orders[count] = order;
		count++;
	}
	void show(){
		for(int i = 0; i < count; i++){
			printf("name %s  fd %d \n", names[i], orders[i]);
		}
	}
private:
	char names[Max][50];
	int orders[Max];
};