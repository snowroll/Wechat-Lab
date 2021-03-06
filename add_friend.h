#include <fstream>
#include <sstream>
#include <stdio.h>

int add_friend(char add_name[], char my_name[]){
	char suff[] = ".txt";
	char file_name[200];
	int count = 0;
	for(int i = 0; i < strlen(my_name); i++){
		file_name[count++] = my_name[i]; 
	}
	for(int i = 0; i < strlen(suff); i++){
		file_name[count++] = suff[i];
	}
	file_name[count] = '\0';
	
	std::ifstream fin;
    fin.open(file_name, std::ios_base::in);
	char line[1024] = {0};
    if(fin.fail())
    {
		printf("文件打开失败\n");
    }
	char cur_friend[200];
  	while(fin.getline(line, sizeof(line)))
    {	
		std::stringstream word(line);  //按空格切分读入的一行字符串
		word >> cur_friend;
        if(strcmp(cur_friend, add_name) == 0)
        {
  			printf("朋友已添加");
            return -1;
        }
    }
	fin.close();
	std::ofstream fout(file_name, std::ios::app);
	fout << add_name << "\n";
	return 0;
}

char* show_list(char name[]){
	char suff[] = ".txt";
	char file_name[200];
	int count = 0;
	for(int i = 0; i < strlen(name); i++){
		file_name[count++] = name[i]; 
	}
	for(int i = 0; i < strlen(suff); i++){
		file_name[count++] = suff[i];
	}
	file_name[count] = '\0';
	
	std::ifstream fin;
    fin.open(file_name, std::ios_base::in);
	char line[1024] = {0};
    if(fin.fail())
    {
		printf("文件打开失败\n");
    }
	char cur_friend[200];
	char seg[] = ",";
	count = 0;
	char *final_ans = new char[1000];
	char pre[] = "flist";
	for(int i = 0; i < strlen(pre); i++){
		final_ans[count++] = pre[i];
	}
  	while(fin.getline(line, sizeof(line)))
    {	
		std::stringstream word(line);  //按空格切分读入的一行字符串
		word >> cur_friend;
        for(int i = 0; i < strlen(cur_friend); i++){
			final_ans[count++] = cur_friend[i];
		}
		final_ans[count++] = seg[0];
    }
	final_ans[--count] = '\0';
	fin.close();
	return final_ans;
}