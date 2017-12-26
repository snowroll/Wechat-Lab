#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

struct user{
	char name[50];
	char password[50];
};

/*void register(){
	string name;	
	ifstream fin;
	fin.open("user.txt", ios::in);
	cout << "请输入用户名" << endl;
	cin >> name;
	while(fin >> user.name >> user.password){  
		if(user.name == name){
			cout << "该用户名已被注册" << endl;
			register();
		}
	}
	char test; int i = 0;
	cout << "输入密码："；
	while(test = getch() != '\r'){
		if(test == 8){  //asci码为退格
			if(i > 0){
				cout << test << " " test ;
				password[i--] = '\0';
			}
		}
		else{
			if(i < 20){
				cout << "*";  //调试信息
				password[i] = test;
				i++;
			}
		}
	}
	password[i] = '\0';
	cout << "注册成功"；
	ofstream fout;
	fout.open('user.txt', ios_base::out|ios_base::app);
	fout << name << " " << password << endl;
	fout.close();
	cout << "三秒后返回登录界面"；
	nterface();  //界面  没有这部分
}*/

int login(char name[], char password[]){  //登录
    std::ifstream fin;
    fin.open("user.txt", std::ios_base::in);
	char line[1024] = {0};
    if(fin.fail())
    {
        std::cout << "文件打开失败";
		printf("文件打开失败\n");
    }
    int f1 = 0;
	user cur_user;
	int i = 0;
  	while(fin.getline(line, sizeof(line)))
    {	
		i++;
		printf("第%d次\n", i);
		//fin.getline(cur_user.name, 50);
		//fin.getline(cur_user.password, 50);
		std::stringstream word(line);
		word >> cur_user.name;
		word >> cur_user.password;
		printf("%s\n", cur_user.name);
		printf("%s\n", cur_user.password);
        if((strcmp(cur_user.name, name) == 0) && strcmp(cur_user.password, password) == 0)
        {
            std::cout << "登陆成功";
			printf("登录成功");
            f1=1;//登录成功标志
            return 0;
        }
    }
    if(f1 == 0)//f1==0登录失败
    {
		std::cout << "用户名或密码错误";
		printf("登录失败\n");
		return -1;
        
        
    }
}