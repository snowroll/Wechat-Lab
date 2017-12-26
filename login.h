#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

struct user{
	char name[50];
	char password[50];
};

int regist(char name[], char password[]){	
	std::ifstream fin;
    fin.open("user.txt", std::ios_base::in);
	char line[1024] = {0};
    if(fin.fail())
    {
        std::cout << "文件打开失败";
		printf("文件打开失败\n");
    }
    int flag = 0;
	user cur_user;
  	while(fin.getline(line, sizeof(line)))
    {	
		std::stringstream word(line);  //按空格切分读入的一行字符串
		word >> cur_user.name;
		word >> cur_user.password;
		printf("%s\n", cur_user.name);
		printf("%s\n", cur_user.password);
        if(strcmp(cur_user.name, name) == 0)
        {
  			printf("用户名已存在");
            flag = 1;//登录成功标志
            return -1;
        }
    }
	fin.close();
	std::ofstream fout("user.txt", std::ios::app);
	if(flag == 0){
		fout << name << " " << password << "\n";
		return 0;
	}
}

int login(char name[], char password[]){  //登录
    std::ifstream fin;
    fin.open("user.txt", std::ios_base::in);
	char line[1024] = {0};
    if(fin.fail())
    {
        std::cout << "文件打开失败";
		printf("文件打开失败\n");
    }
    int flag = 0;
	user cur_user;
  	while(fin.getline(line, sizeof(line)))
    {	
		std::stringstream word(line);  //按空格切分读入的一行字符串
		word >> cur_user.name;
		word >> cur_user.password;
		printf("%s\n", cur_user.name);
		printf("%s\n", cur_user.password);
        if((strcmp(cur_user.name, name) == 0) && strcmp(cur_user.password, password) == 0)
        {
  			printf("登录成功");
            flag = 1;//登录成功标志
            return 0;
        }
		else if((strcmp(cur_user.name, name) == 0) && strcmp(cur_user.password, password) != 0){
			printf("密码错误");
			flag = 2;
			return -1;
		}
    }
    if(flag == 0)//f1==0登录失败
    {
		printf("用户不存在\n");
		return -2;   
    }
}