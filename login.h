#include <string.h>
#include <fstream>

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
    if(fin.fail())
    {
        std::cout << "文件打开失败";
    }
    int f1;
	user cur_user;
  	while(fin >> cur_user.name >> cur_user.password)
    {
        if(cur_user.name == name && cur_user.password == password)
        {
            std::cout << "登陆成功";
            f1=1;//登录成功标志
            return 0;
        }
    }
    if(f1 == 0)//f1==0登录失败
    {
		return -1;
        std::cout << "用户名或密码错误";
        
    }
}