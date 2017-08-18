//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<map>
//#include<vector>
//#include<set>
//#include<sstream> 
//#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
struct point
{
	double math;
	double chinese;
};
struct node 
{
		string name;
		int    no;
		point  pt;
		set<int> hobby;
//		bool operator < (const node &x) const //重载结构体的<运算符，两个const都缺一不可 
//		{
//			return pt.math>x.pt.math; 
//		}
};
node myclass[100];

//也可以用如下两种方式定义 
//sort后不需要加比较函数  
bool operator <(node a,node b)
{
	return a.pt.math>b.pt.math;
} 

//sort后需要加比较函数 
bool comp_chinese(node a,node b)
{
	return a.pt.chinese>b.pt.chinese;
}

struct example
{
	int a;
	char s[11];
};

bool comp(string a,string b)//自定义比较函数定义a排在b前面的条件  
{
	 	return a>b;
}
bool comp_int(int a,int b)//自定义比较函数定义a排在b前面的条件  
{
	 	return a>b;
}

int main()
{
	///////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////IO//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////// 
	////输入输出流重定向到文件 
	freopen("diary.in","r",stdin);
	freopen("diary.out","w",stdout);
	string s1,s2,s3;int a;
	//输入变量之间可以用空格、回车或者文件结尾分割 
	cin>>s1>>s2>>s3>>a;
	cout<<s1<<" "<<s2<<" "<<s3<<" "<<a;
	 
	fclose(stdin);fclose(stdout);
	//关闭之后，stdin和stdou才能恢复正常，本程序中如果以后不用 cin（stdin）和cout（stdou）可以不关闭
	//关闭之后，还可以重定向到其他文件 
	//以下为恢复
	freopen("CON","r",stdin);//linux:freopen("/dev/tty","r",stdin);
	freopen("CON","w",stdout);//linux:freopen("/dev/tty","w",stdin); 

    ///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////STRING//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////// 
	////string流 
	stringstream ss;
	int aa=1024;float b=1.5;
	int c;float d;
	ss<<aa<<" "<<b;//空格很重要，否则ss中就是10241.5 
	ss>>c>>d;
	///string cc,dd;
	///ss<<aa;
	///ss>>cc;
	///cout<<cc<<endl;
	cout<<c<<" "<<d<<endl;
	
	////格式化输出
	//setf(ios::left) 左对齐
    //setf(ios::right) 右对齐
	//setf(ios::skipws) 忽略前导空白
	//setf(ios::uppercase) 16进制数大写输出
	//setf(ios::lowercase) 16进制小写输出
	//setf(ios::showpoint) 强制显示小数点后多余的0，凑齐精度 
	//setf(ios::showpos) 强制正数前显示+,
	//#include<iomanip>
	
	a=28;b=1.512345;d=1.51235;s1="hello";
	float e=0.51235;double f=1.51235678901;
	cout<<dec<<a<<" "<<hex<<a<<" "<<oct<<a<<endl; //28 1c 34
	cout<<dec<<a<<" "<<hex<<uppercase<<a<<" "<<oct<<a<<endl; //28 1C 34,16进制大写
	cout<<a<<" "<<hex<<a<<endl; //34 1C，dec,uppercase,等都会长期有效 
	cout.unsetf(ios::uppercase);
	cout<<dec<<a<<" "<<hex<<a<<" "<<oct<<a<<endl; //28 1c 34,恢复了 
	
	cout.fill('*'); cout.width(5);
	cout<<dec<<a<<endl;//***28
	cout<<a<<endl;//28 ,width只对下一个输出起作用
	
	cout.fill(' ');cout.width(5);//变回填充空格
	cout<<a<<endl;// ___28,缺省填充空格 
	 
	cout.precision(5);//精度为第一个非零数字后数字的个数，即有效数字位数 ，不会四舍五入 
	cout<<b<<" "<<d<<" "<<e<<" "<<f<<endl;//1.5123 1.5123 0.51235 1.5123
	cout.precision(6);//恢复成缺省的6
	cout<<scientific<<b+10<<" "<<b-1.5<<" "<<f<<endl;//1.151235e+001 1.234496e-002 1.512346e+000
	cout<<showpoint<<a<<" "<<f<<" "<<1.5<<endl; //28 1.512357e+000 1.500000e+000
	cout.unsetf(ios::scientific);
	cout<<a<<" "<<f<<" "<<1.5<<endl; //28 1.51236 1.50000
	cout.unsetf(ios::showpoint);
	cout<<a<<" "<<f<<" "<<1.5<<endl; //28 1.51236 1.5
	cout.precision(10);
    cout<<fixed<<b<<" "<<d<<" "<<e<<" "<<f<<endl;//1.5123449564 1.5123499632 0.5123500228 1.5123567890定点输出
	cout.unsetf(ios::fixed);
	
	///string的基本操作；
	//定义赋值 
	char ch[]="hello world!";
	string s4;
	string s5="abcdef";//abcdef
	string s6(6,'*');//******
	string s7(ch);//hello world!
	string s8(ch,5);//hello
	string s9(s8);//hello
	string s10(s7,6);//world!
	cout<<s5<<endl;	cout<<s6<<endl;	cout<<s7<<endl;	cout<<s8<<endl;	cout<<s9<<endl;	cout<<s10<<endl;
	//子串 
	cout<<s7.substr(0,5)<<endl;//hello
	cout<<s7.substr(6)<<endl;//world! 
	
	//获取长度
	cout<<s7.size()<<" "<<s7.length()<<endl;//6 6,都能取长度，等价 
	
	//获取字符
	char x=s7[1];//e
	char y=s7.at(1);//e
	const char *p=s7.c_str();//hello world!
	cout<<x<<' '<<y<<' '<<p<<endl;
	//+
	s4=s9+" "+s10;
	cout<<s4<<endl;//hello world!
	
	//erase 
	s4.erase(0,6);//world!,删除从位置0开始的6个字符 
	cout<<s4<<endl;
	
	//replace
	s4[0]=toupper(s4[0]);//World
	cout<<s4<<endl;
	s4[0]=tolower(s4[0]);//world
	s4.replace(0,3,"go");//gold，用go替换s4中的wor 
	cout<<s4<<endl; 
	
	//比较大小
	cout<<s9.compare(s10)<<endl;//1,0,-1
	cout<<(s9<s10)<<endl;//
	
	//字符排序
	cout<<s7<<endl;//hello world!
	sort(s7.begin(),s7.end());//_!dehllloorw,c++通用排序 调用std的sort模版函数，适合所有容器
	cout<<s7<<endl; 
	
	//查找字符，字符串，可以使 char，char*，string类型 
	int i =s7.find('l');//5
	cout<<i<<endl;
	i=s7.find("lll");//5
	cout<<i<<endl;
	s4=string("lll");
	i=s7.find(s4);//5
	cout<<i<<endl; 
	i=s7.find('l',3);//5
	cout<<i<<endl;
	i=s7.find("llloo",2,3); //5,从位置2开始，查找缓冲区 “llloo”的前三个字符 
	cout<<i<<endl;
	i=s7.find('a');
	cout<<i<<endl;//-1,即string::npos;
	
	//清空
	s7.clear();
	s4="";
	if(!s4.empty())//判断是否为空
	  cout<<s4;
	else
	  cout<<"NULL"; 
	 
	 ///////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////VECTOR//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////// 
	///定义、赋值
	vector<int> v1;
	vector<string> v2;
	
	///插入
	v1.push_back(1);//1
	v1.push_back(2);//1 2,从尾部插入
	v1.insert(v1.begin()+1,3);//1 3 2,将3插入v1的位置1 
	
	///访问类似数组
	cout<<v1[0]<<" "<<v1[1]<<" "<<v1[2]<<endl; //1 3 2
	for(int i=0;i<v1.size();i++)
	v1[i]+=1;
	cout<<v1[0]<<" "<<v1[1]<<" "<<v1[2]<<endl; //2 4 3
	
	///查找,没有专用find函数 
	vector<int>::iterator vit=find(v1.begin(),v1.end(),3);
	if(vit!=v1.end())cout<<*vit<<endl;//3
	vit=find(v1.begin(),v1.end(),5);///调用std的find模版函数，适合所有容器 
	if(vit!=v1.end())cout<<*vit<<endl;//空 
		
	///删除
	v1.push_back(6);v1.push_back(9);//2 4 3 6 9
	v1.erase(v1.begin()+2);//2 4 6 9
	v1.erase(v1.begin()+1,v1.end());//2，注意删除的区间为[1，end（）） ，end是不包含在v1中的尾部 
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<endl;
    v1.clear();	
	for(int i=0;i<10;i++)v1.push_back(i);//0 1 2 ... 9
	v1.erase(v1.begin(),v1.begin()+3);//3 4 5 ... 9,注意删除的区间为[0，3） 
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";cout<<endl;
	v1.erase(v1.begin(),v1.end()-1);//9,只剩最后一个元素 
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";cout<<endl;
	
	//循环删除 
	v1.clear(); 
	for(int i=0;i<10;i++)v1.push_back(i%3);//0 1 2 ... 0
	//删除所有0元素 
	///以下为错误写法 
	///for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
	///	if(*it==0)v1.erase(it);
	///正确写法
	for(vector<int>::iterator it=v1.begin();it!=v1.end();)
	  if(*it==0)v1.erase(it);
	  else it++; 
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";cout<<endl;
	 	 
	 //第一个元素和最后一个元素
	 v1.clear(); 
	 for(int i=0;i<10;i++)v1.push_back(i);//0 1 2 ... 9
	 cout<<*v1.begin()<<endl;//0，必须加*，将迭代器转化成元素 
	 cout<<v1.front()<<endl;//0,直接返回第一个元素 
	 cout<<v1.back()<<endl;//9，直接返回最后一个元素 
	 cout<<*(v1.end()-1)<<endl;//9
		
	///拷贝
	 v1.clear();
	 for(int i=0;i<10;i++)v1.push_back(i);//0 1 2 ... 9
	 vector<int> v4(v1);//0 1 2 ... 9
	 for(int i=0;i<v4.size();i++)cout<<v4[i]<<" ";cout<<endl;
	 vector<int> v3;
	 v3.assign(v1.begin(),v1.end());//0 1 2 ... 9
	 for(int i=0;i<v3.size();i++)cout<<v3[i]<<" ";cout<<endl;
	 v3.assign(v1.begin()+5,v1.begin()+8);//5 6 7
	 for(int i=0;i<v3.size();i++)cout<<v3[i]<<" ";cout<<endl;
	 vector<int>v5;
	 v5.swap(v1);//交换 
	 for(int i=0;i<v1.size();i++)cout<<v1[i]<<" ";cout<<endl;//空 
	 for(int i=0;i<v5.size();i++)cout<<v5[i]<<" ";cout<<endl;//0 1 2 ... 9 
	 
	 ///排序
	 v2.push_back("Smith");
	 v2.push_back("John");
	 v2.push_back("Tom");
	 v2.push_back("Tony");
	 sort(v2.begin(),v2.end());//调用std的find模版函数，适合所有容器
	 for(int i=0;i<v2.size();i++)cout<<v2[i]<<" ";cout<<endl;//John Smith Tom Tony,缺省升序排列
	 	 
	 sort(v2.begin(),v2.end(),comp);
	 for(int i=0;i<v2.size();i++)cout<<v2[i]<<" ";cout<<endl;//Tony Tom Smith John,按自定义比较函数排列
	 
	 ///比较
	 v1.clear();
	 v4.clear();
	 v3.clear();
	 v1.push_back(1); v1.push_back(2);v1.push_back(3);
	 v4.push_back(1); v4.push_back(2);v4.push_back(3);
	 v3.push_back(1); v3.push_back(3);v3.push_back(2);
	 if(v1==v4)cout<<"v1==v4"<<endl;//v1==v4
	 if(v1==v3)cout<<"v1==v3"<<endl;//v1!=v3 
	 
	  
	 ////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////SET//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////// 
	///定义、赋值
	set<int> set1;
	set<string> set2;
		
	///插入，不存在在什么位置插入什么值的函数 
	set1.insert(4);
	set1.insert(3);
	set1.insert(3);//3 4,set中相同的元素只算一个 ，元素自动按增序排列 
	set2.insert("Smith");
	set2.insert("Jony");//Jony Smith
	
	
	///访问：迭代器
	 for(set<int>::iterator it=set1.begin();it!=set1.end();it++)cout<<*it<<" ";cout<<endl;
	 for(set<string>::iterator it=set2.begin();it!=set2.end();it++)cout<<*it<<" ";cout<<endl;
	
	///第一个元素和最后一个元素 ,没有front和back，没有begin()+1,end（）-1 ,但是有++，-- 
	set1.insert(5);//3 4 5
	cout<<*set1.begin()<<endl;//3
	set<int>::iterator it2=set1.begin();
	it2++;
	cout<<*(it2)<<endl;//4
	cout<<*(set1.rbegin())<<endl;//5
	
	///查找 ，专用通用find函数都有 
	it2=set1.find(4);
	if(it2!=set1.end())cout<<"find1:"<<*it2<<endl;//find1 
	it2=set1.find(6);
	if(it2!=set1.end())cout<<"find2:"<<*it2<<endl;//空 
	it2=find(set1.begin(),set1.end(),3);//通用模版函数 
	if(it2!=set1.end())cout<<"find3:"<<*it2<<endl;//find3
		 
	///删除,可删除值，迭代器，区间 
	set1.erase(3);//4 5
	set1.erase(set1.begin());//5
	for(set<int>::iterator it=set1.begin();it!=set1.end();it++)cout<<*it<<" ";cout<<endl;
	set1.clear();
	for(int i=0;i<10;i++)set1.insert(i);
	it2=set1.find(5);
	set1.erase(it2,set1.end());//0 1 2 3 4
	for(set<int>::iterator it=set1.begin();it!=set1.end();it++)cout<<*it<<" ";cout<<endl;
	
	///循环删除
	///以下错误 
	///for(set<int>::iterator it=set1.begin();it!=set1.end();it++)
	///	if(*it%2==0)set1.erase(it);
	 ///以下正确 
	 for(set<int>::iterator it=set1.begin();it!=set1.end();)
		if(*it%2==0)set1.erase(it++);
		else it++; 
	for(set<int>::iterator it=set1.begin();it!=set1.end();it++)cout<<*it<<" ";cout<<endl;	//1 3
	
	///拷贝
	set1.clear();
	for(int i=0;i<10;i++)set1.insert(i);
	set<int>set3(set1);
	set<int>set4;
	set4.swap(set1);
	int array[10]={0,1,2,3,4,5,6,7,8,9};
	set<int>set5(array,array+5);//0,1,2,3,4，用数组初始化 
	for(set<int>::iterator it=set1.begin();it!=set1.end();it++)cout<<*it<<" ";cout<<endl;	//空 
	for(set<int>::iterator it=set3.begin();it!=set3.end();it++)cout<<*it<<" ";cout<<endl;	//0 1 2...9
	for(set<int>::iterator it=set4.begin();it!=set4.end();it++)cout<<*it<<" ";cout<<endl;	//0 1 2...9
	for(set<int>::iterator it=set5.begin();it!=set5.end();it++)cout<<*it<<" ";cout<<endl;	//0 1 2 3 4
		 
	///排序
	////set对于定义了“<”的对象，按照从小到大的顺序排列
		 
	
	///比较 
	if(set4==set3)cout<<"set4==set5"<<endl;//相等 
	if(set5<set3)cout<<"1.set5<set3"<<endl;//包含 
	set5.insert(11);
	if(set5<set3)cout<<"2.set5<set3"<<endl;//不包含 
	//集合的并交差 
    //set_union() 
    ////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////MAP//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////// 
	///定义
	map<string,double> m1; 
	 
	///赋值,数组形式赋值 
	m1["zhangsan"]=100;
	m1["lisi"]=105; 
	
	///查找
	map<string,double>::iterator mit=m1.find("lisi");
	if(mit!=m1.end())cout<<"map find "<<mit->second<<endl;//mit->first表示key,mit->second表示value;
	
	///删除
	cout<<m1.size()<<endl;//2
	m1.erase("lisi");
	cout<<m1.size()<<endl;//1

    ///循环删除 ,和set类似 
    m1["lisi"]=105;
    m1["wanglu"]=108;
    m1["guliu"]=100;
    for(mit=m1.begin();mit!=m1.end();)
	{
		if(mit->second==100)
		m1.erase(mit++);
		else mit++;
	 } 
    for(mit=m1.begin();mit!=m1.end();mit++)
    cout<<mit->first<<" "<<mit->second<<endl;//lisi 105  wanglu 108
    
    ////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////STRUCT//////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////// 
	//结构数组赋值 
	myclass[0].name="zhangsan";
	myclass[0].no=1;
	myclass[0].pt.math=95.5;
	myclass[0].pt.chinese=78;
	myclass[0].hobby.insert(1);
	myclass[0].hobby.insert(2);
	myclass[1].name="lisi";
	myclass[1].no=2;
	myclass[1].pt.math=98.5;
	myclass[1].pt.chinese=78;
	myclass[1].hobby.insert(2);
	myclass[1].hobby.insert(3);
	myclass[2].name="wangwu";
	myclass[2].no=3;
	myclass[2].pt.math=100;
	myclass[2].pt.chinese=67;
	myclass[2].hobby.insert(2);
	myclass[2].hobby.insert(3);
	//按数学成绩从高到低排序
	sort(myclass,myclass+3);
	
	for(int i=0;i<3;i++)
	{
	   cout<<myclass[i].name<<" "<<myclass[i].no<<" "<<myclass[i].pt.math<<" "<<myclass[i].pt.chinese<<endl;
	   cout<<"hobby: ";
	   for(set<int>::iterator it=myclass[i].hobby.begin();it!=myclass[i].hobby.end();it++)  
	   cout<<*it<<" ";cout<<endl;
	}
	vector<node> vn;
	vn.push_back(myclass[0]);vn.push_back(myclass[1]);vn.push_back(myclass[2]);
	///按语文成绩从高到底排序 
	sort(vn.begin(),vn.end(),comp_chinese);
	for(int i=0;i<vn.size();i++)
	{
	   cout<<vn[i].name<<" "<<vn[i].no<<" "<<vn[i].pt.math<<" "<<vn[i].pt.chinese<<endl;
	   cout<<"hobby: ";
	   for(set<int>::iterator it=vn[i].hobby.begin();it!=vn[i].hobby.end();it++)  
	   cout<<*it<<" ";cout<<endl;
		
	}
	///由于对结构体node的<进行了定义，所以set会自动按照数学分数从高到底排序 
	set<node> sn;
	sn.insert(myclass[2]);sn.insert(myclass[1]);sn.insert(myclass[0]);
	for(set<node>::iterator it=sn.begin();it!=sn.end();it++)
	{
	   cout<<it->name<<" "<<it->no<<" "<<it->pt.math<<" "<<it->pt.chinese<<endl;
	   cout<<"hobby: ";
	   for(set<int>::iterator it2=it->hobby.begin();it2!=it->hobby.end();it2++)  
	   cout<<*it2<<" ";cout<<endl;
	}
	///由于结构体是自定义的，运算符都没有定义，所以不能用==，！= 
	    //if(myclass[0]==myclass[1])	cout<<"myclass equal"<<endl;
	///上面定义了<,所以可以判断是否<
		if(myclass[0]<myclass[1])cout<<"myclass less than"<<endl;
	///大于仍然不可用，以下编译会发生错误 
		//if(myclass[0]>myclass[1])cout<<"myclass less than"<<endl;	
		
	///结构示例
	vector<example> ve;
	example ee;
	for(int i=0;i<3;i++)
	{
		ee.a=i;
		stringstream ss;
		ss<<i;
		sprintf(ee.s,"%010d",i); ///测试一下，下面ss>>ee.s会自动加0结尾，所以字符数组注意多留一个位置出来 
		ss>>ee.s;//变量转换到char数组中 
		ve.push_back(ee);
	}
	for(int i=0;i<ve.size();i++)
	{
		cout<<ve[i].a<<" "<<ve[i].s<<endl;
	}
	return 0;
}
