
/**********************************************************************
參考資源:https://www.itread01.com/content/1547094635.html
----C++檔案讀寫操作（三）如何統計文字的行數及如何讀取檔案某一行內容
**********************************************************************/ 




#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int CountLines(char *filename)
{
    ifstream ReadFile;
    int n=0;
    string tmp;
    ReadFile.open(filename,ios::in);//ios::in 表示以只讀的方式讀取檔案
    if(ReadFile.fail())//檔案開啟失敗:返回0
    {
        return 0;
    }
    else//檔案存在
    {
        while(getline(ReadFile,tmp,'\n'))
        {
            n++;
        }
        ReadFile.close();
        return n;
    }
}
string ReadLine(char *filename,int line)
{
    int lines=0;
    int i=0;
    string temp;
    fstream file;
    file.open(filename,ios::in);
    lines=CountLines(filename);

    
    while(getline(file,temp)&&i<line-1)
    {
        i++;
    }
    file.close();
    return temp;
}

int main()
{
    string myans;
    int line;
    char filename[]="D:/4c8aH23D/23478/video2.txt";
    int wordnum=CountLines(filename)/2;
    char wrong[1000];
    int a;
    int result[wordnum];
    cout<<"總共有: "<<wordnum<<"個單字"<<endl;
    cout<<"開始考試吧"<<endl;
    cout<<"________________________________________"<<endl;
    for(a=1;a<=wordnum;a++){
    	
    	cout<<"________________________________________"<<endl;
    	cout<<ReadLine(filename,a*2-1)<<endl;
    	cout<<"答案:";
    	myans="";
    	cin>>myans;
    	if(myans==ReadLine(filename,a*2)){
    		result[a-1]=1;
    	}else{
    		result[a-1]=0;
    		cout<<"答案錯誤"<<endl;
    		cout<<"正確答案為:"<<ReadLine(filename,a*2)<<endl;
    		
    	}
    	
    }
    int wrongnum=0;
    for(a=0;a<=wordnum-1;a++){
    	if(result[a]==0){
    		wrongnum++;
    	}
    	
    }
    cout<<"________________________________________"<<endl;
    cout<<"________________________________________"<<endl;
    cout<<"這次的錯誤題數: "<<wrongnum<<"題"<<endl;
    if(wrongnum!=0){
    	cout<<"錯物的題目:";
    	cout<<"第";
    	for(int c=1;c<=wordnum;c++){
    		if(result[c-1]==0){
    			cout<<c<<",";
    		}
    	}
    	cout<<"題"<<endl;
    }
    if(wrongnum!=0){
    	
    	
    	cout<<"要進行錯誤題目回收練習嗎？"<<"(yes or no)";
    	string feedback1;
    	cin>>feedback1;
    	if(feedback1=="yes"){
			string myans2;
			int result2[wrongnum];
			for(int d=1;d<=wordnum;d++){
			 	if(result[d-1]==0){
			 		cout<<ReadLine(filename,d*2-1)<<endl;
			 		cin>>myans2;
			 		if(myans2==ReadLine(filename,d*2)){
			    		result2[d-1]=1;
			    	}else{
			    		result2[d-1]=0;
			    		cout<<"答案錯誤"<<endl;
			    		cout<<"正確答案為:"<<ReadLine(filename,d*2)<<endl;
			    	}
			 	}else{
			 		result2[d-1]=1;
			 	}
			}
			int wrongnum2=0;
		    for(int f=0;f<=wordnum-1;f++){
		    	if(result2[f]==0){
		    		wrongnum2=wrongnum2+1;
		    	}
		    }
		    cout<<"這次的錯誤題數: "<<wrongnum2<<"題"<<endl;
		    if(wrongnum2!=0){
		    	cout<<"錯物的題目:";
		    	cout<<"第";
		    	for(int e=1;e<=wordnum;e++){
		    		if(result2[e-1]==0){
		    			cout<<e<<",";
		    		}
		    	}
		    	cout<<"題"<<endl;
		    	cout<<"再加油喔~"<<endl;
		    }
    	}
    }else{
    	cout<<"做的很棒!!!"<<endl;
    }
	system("pause");
    	
    
}

