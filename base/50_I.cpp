目录
1.	输入一个两位正整数，反向输出，比如输入19输出91；	2
2.	一个盒子最多装5个苹果，有n个苹果，最少要几个盒子才能装下；	2
3.	输入两个整数X和Y，然后交换他们的值（即X变成Y，Y变成X）	3
4.	输入一个数字X，判断它是不是两位数，是的话输出yes不是的话就输出no	3
5.	输入三个数x,y,z，按由大到小的顺序排出来；	4
6.	输入一个数字，判断它是否完全平方数；	5
7.	输入一个年份，判断它是否闰年；	5
8.	12345678910111213141516****，从左到右第N位是几？（0<N<1000）	6
9.	求s=1+3+5+7+**99	6
10.	求s=1+4+9+16+**100	7
11.	1!+2!+3!+***10!	7
12.	1+12+123+1234+***+123456789	8
13.	输入一个整数，反向输出	8
14.	输入一个大整数，判断它有多少位	8
15.	输入一个数判断是否质数	9
16.	输入一个数判断是否回文数	9
17.	求两个数的最大公约数和最小公倍数	10
18.	输入10个数，求其中最大的数和次大的数	10
19.	求Fibo数列第N项	11
20.	水仙花数	11
21.	百鸡问题	12
22.	100以内的勾股数有多少组	12
23.	A的B次方最末尾三位数是几	12
24.	被3除余1，被5除余3，被7除余2的最小数是几	13
25.	100！末尾有多少个连续的0，最右边第一个非零的数字是几	13
26.	1到N中所有的数字写成1排，其中8出现了多少次	14
27.	[l,r]中共有r-l+1个数，其中那个数的约数最多	15
28.	形如aabb的四位完全平方数有哪些	15
29.	5个数中选3个数字的排列有多少种情况	16
30.	数字菱形	16
31.	输入年月日，判断今天星期几	16
32.	筛法求质数	17
33.	约瑟夫问题	17
34.	10个数字由大到小排序（选择排序）	18
35.	杨辉三角	19
36.	螺旋方阵	20
37.	奇数阶幻方	21
38.	打印小九九乘法口诀表	22
39.	AHHAAH/JOKE=HA，不同的字母表示不同的数字	22
40.	355/113 小数点之后100位是几	23
41.	1234567891011***99除以997的余数	23
42.	100！的精确值	24
43.	高精度正整数加法字符串	24
44.	高精度正整数乘法	25
45.	求e=1+1/1!+1/2!+1/3!***，精确到小数点后100位	26
46.	进制转换	26
47.	分解质因数	28
48.	求cmn	28
49.	连续最长平台数	30
50.	快速幂	30

1.	输入一个两位正整数，反向输出，比如输入19输出91；
#include<iostream>
using namespace std;
int x,a,b;
int main()
{
    cin>>x;
    a=x/10;
    b=x%10;
    y=10*b+a;
    cout<<y;
    return 0;
}

2.	一个盒子最多装5个苹果，有n个苹果，最少要几个盒子才能装下；
#include<iostream>
#include<cmath>
using namespace std;
int x;
int main()
{
    cin>>x;
    cout<<(x-1)/5+1<<endl;
    cout<<(x+4)/5<<endl;
    cout<<ceil((float(x)/5))<<endl;
    return 0;
}
3.	输入两个整数X和Y，然后交换他们的值（即X变成Y，Y变成X）
#include<iostream>
using namespace std;
int x,y,z;
int main()
{

    cin>>x>>y;
    cout<<"\n=======way1=======\n";
    swap(x,y);
    cout<<x<<' '<<y;

    cout<<"\n=======way2=======\n";
    z=x;x=y;y=z;
    cout<<x<<' '<<y;

    cout<<"\n=======way3=======\n";
    x=x+y;y=x-y;x=x-y;
    cout<<x<<' '<<y;
    return 0;
}

4.	输入一个数字X，判断它是不是两位数，是的话输出yes不是的话就输出no
#include<iostream>
#include<cmath>
using namespace std;
int x;
int main()
{
    cin>>x;
    if ((x>=10)&&(x<=99)) cout<<"Yes!";
    else cout<<"No!";
    return 0;
}
5.	输入三个数x,y,z，按由大到小的顺序排出来；
#include<iostream>
using namespace std;
int a,b,c;
int main()
{
    cin>>a>>b>>c;
    if ((a>=b)&&(b>=c)) cout<<a<<' '<<b<<' '<<c;
    if ((a>=c)&&(c>=b)) cout<<a<<' '<<c<<' '<<b;
    if ((b>=a)&&(a>=c)) cout<<b<<' '<<a<<' '<<c;
    if ((b>=c)&&(c>=a)) cout<<b<<' '<<c<<' '<<a;
    if ((c>=a)&&(a>=b)) cout<<c<<' '<<a<<' '<<b;
    if ((c>=b)&&(b>=a)) cout<<c<<' '<<b<<' '<<a;
    return 0;
}

#include<iostream>
using namespace std;
int a,b,c;
int _max,_mid,_min;
int main()
{
    cin>>a>>b>>c;
    if (a>b)
    {
        _max=a;
        _min=b;
    }
    else
    {
        _max=b;
        _min=a;
    }
    if (c>_max) _max=c;
    else if (c<_min) _min=c;
    _mid=a+b+c-_max-_min;
    cout<<_max<<' '<<_mid<<' '<<_min;
    return 0;
}

#include<iostream>
using namespace std;
int a,b,c;
int _max,_mid,_min;
int main()
{
    cin>>a>>b>>c;
    _max=max(a,max(b,c));
    _min=min(a,min(b,c));
    _mid=a+b+c-_max-_min;
    cout<<_max<<' '<<_mid<<' '<<_min;
    return 0;
}

6.	输入一个数字，判断它是否完全平方数；
   #include<iostream>
#include<cmath>
using namespace std;
int x;
float sqrtx;
int main()
{
    cin>>x;
    sqrtx=sqrt(x);
    if (sqrtx==int(sqrtx)) cout<<"Yes!";
    else cout<<"No!";
    return 0;
}
7.	输入一个年份，判断它是否闰年；
 #include<iostream>
using namespace std;
int y;
bool b1,b2;
int main()
{
    cin>>y;
    b1=(y%400==0);
    b2=(y%4==0)&&(y%100!=0);
    if (b1||b2)
        cout<<"Yes";
    else cout<<"No";
    return 0;
}
8.	12345678910111213141516****，从左到右第N位是几？（0<N<1000）
#include<iostream>
using namespace std;
int a,i,s,a1,a2,a3,ss;
int main()
{
    cin>>s;
    if(s<=9) i=s;
    else if (s<=189)
    {
        s=s-9;
        a=(s-1)/2+1;
        a=a+9;
        a1=a/10;
        a2=a%10;
        if (s%2==1) i=a1;
        else i=a2;
    }
    else if (s<=2889)
    {
        s=s-189;
        a=(s-1)/3+1;
        a=a+99;
        a1=a/100%10;
        a2=a/10%10;
        a3=a/1%10;
        if (s%3==1) i=a1;
        else if (s%3==2) i=a2;
        else  i=a3;
    }
    cout<<i;
    return 0;
}
9.	求s=1+3+5+7+**99
#include<iostream>
using namespace std;
int s,i;
int main()
{
    cout<<"\n=======way1=======\n";
    ///这里i表示每个单项
    s=0;for (i=1;i<=99;i+=2)s=s+i;
    cout<<s;

    cout<<"\n=======way2=======\n";
    ///这里i表示是第几项
    s=0;for (i=1;i<=50;i++)s=s+(2*i-1);
    cout<<s;

    cout<<"\n=======way3=======\n";
    s=0;i=1;
    while (i<=99) {s=s+i;i+=2;}
    cout<<s;
    return 0;
}

10.	求s=1+4+9+16+**100
S=0;for (i=1;i<=10;i++) s=s+i*I;
11.	1!+2!+3!+***10!
 #include<iostream>
using namespace std;
int s,a,i;
int main()
{
    cin>>n;
    a=1;
    for (i=1; i<=n; i++)
    {
        a=a*i;  //注意找后面项和前一项的关系
        s=s+a;
    }
    cout<<s;
    return 0;
}
12.	1+12+123+1234+***+123456789
s=i=0;for(i=1;i<=9;i++)
{
   a=a*10+i;   ///这里找的也是后项和前项的关系
   s=s+a;
}

13.	输入一个整数，反向输出
  #include<iostream>
using namespace std;
int x,y,k;
int main()
{
     x=653876;y=0;
     while (x>0)
     {
        k=x%10;x=x/10;
        y=10*y+k;
     }
     cout<<y;
}
14.	输入一个大整数，判断它有多少位
#include<iostream>
#include<cmath>
using namespace std;
int x,k;
int main()
{
    cin>>x;
       cout<<"\n=======way1=======\n";
k=floor(log10(x))+1;
    cout<<k;
        cout<<"\n=======way2=======\n";
     while (x>0)
     {
        x=x/10;  ///除以10后还>0说明至少还有一位
        k++;
     }
     cout<<k;

    return 0;
}
15.	输入一个数判断是否质数
#include<iostream>
#include<cmath>
using namespace std;
int x,i;
bool b;
int main()
{
    cin>>x;i=2;b=true;
    while ((i<=sqrt(x)&& b))
        if (x%i==0) b=false;
        else i++;
    if (b)  cout<<"Yes!"; //注意这里有个隐患，只能判断大于2 的整数
    else cout<<"No!";
    return 0;
}
16.	输入一个数判断是否回文数
  #include<iostream>
using namespace std;
int x,y,k;
int main()
{
     cin>>x;y=0;
     z=x; //
     while (x)
     {
        k=x%10;x=x/10;
        y=10*y+k;
     }
     if (y==z) cout<<'Y';else cout<<'N';
}
17.	求两个数的最大公约数和最小公倍数
  #include<iostream>
#include<cmath>
using namespace std;
int a,b,c,maxc,i;
int main()
{
    cin>>a>>b;
    cout<<"======way1========";
    maxc=0;
    for (i=1;i<=min(a,b);i++)
    {
        if ((a%i==0)&&(b%i==0))
            if (i>maxc) maxc=i;
    }
    cout<<maxc<<endl;
    cout<<"======way2========";
    c=a%b;
    while (c!=0)
    {
        a=b;b=c;c=a%b;
    }
    cout<<b;
    return 0;

}
18.	输入10个数，求其中最大的数和次大的数
#include<iostream>
using namespace std;
int i,x,y,max1,max2;
int main()
{
    cin>>x>>y;
    if (x>y) {max1=x;max2=y;}
    else {max1=y;max2=x;}
    for (i=3;i<=10;i++)
    {
        cin>>x;
        if (x>max1) {max2=max1;max1=x;}
        else if (x>max2) max2=x;  //注意顺序
    }
    cout<<max1<<' '<<max2;
    return 0;
}
19.	求Fibo数列第N项
#include<iostream>
using namespace std;
int a,b,c,i;
int main()
{
    a=b=1;
    cout<<a<<' '<<b<<' ';
    for (i=3;i<=10;i++)
    {
        c=a+b;
        cout<<c<<' ';
        a=b;b=c;  ///注意这种节省空间的迭代法a倒数第二个b倒数第一个
    }
    return 0;
}
20.	水仙花数
#include<iostream>
using namespace std;
int a ,b,c,abc;
int main()
{ 
cout<<"======way1========";
for (a=1; a<=9; a++)
   for (b=0; b<=9; b++)
    for (c=0; c<=9; c++)
     if (a*a*a+b*b*b+c*c*c==100*a+10*b+c)
        cout<<a<<b<<c<<endl;
cout<<"======way1========";
for(abc=100;abc<=999;abc++)
{    a=abc/100%10;b=abc/10%10;c=abc/1%10;  ///分离出单个的abc
     if (a*a*a+b*b*b+c*c*c==100*a+10*b+c)
        cout<<a<<b<<c<<endl;

}
    return 0;
}

21.	百鸡问题
#include<iostream>
using namespace std;
int g,m,x;
int main()
{
    for( g=0;g<=100/5;g++)
        for( m=0;m<=100/3;m++)
    {
        x=100-g-m;
        if (g*5+m*3+x/3.0==100) cout<<g<<' '<<m<<' '<<x<<endl;
    }
    return 0;
}
22.	100以内的勾股数有多少组
#include<iostream>
#include<cmath>
using namespace std;
int a,b;
double c;  //通过勾股定理求得C要开方是实数
int main()
{
    for (a=1; a<=100/sqrt(2); a++)  //假设a比较小，不会大于100/sqrt(2)
        for (b=a+1; b<100; b++)
        {
            c=sqrt(a*a+b*b);
            if ((int(c)==c)&& (c<=100)) cout<<a<<' '<<b<<' '<<int(c)<<endl;
        }
    return 0;
}
23.	A的B次方最末尾三位数是几
#include<iostream>
using namespace std;
long long s,a,b;
int main()
{
    cin>>a>>b;
    s=1;
    for (int i=1; i<=b; i++)
    {
        s=s*a;
        s=s%1000;   ///一般简写成一个s=s*a%1000
    }
    cout<<s;
    return 0;
}
24.	被3除余1，被5除余3，被7除余2的最小数是几
#include<iostream>
using namespace std;
int i;
int main()
{
    i=0;
    do
    {
        i++;
    }while (!((i%3==1)&&(i%5==3)&&(i%7==2)));
    cout<<i;
    return 0;
}
25.	100！末尾有多少个连续的0，最右边第一个非零的数字是几
#include<iostream>
#include<cmath>
using namespace std;
int s,i,j,n;
int main()
{
    cin>>n;
    //方法1
    for (i=1;i<=n;i++)
    {   //因为2的个数比5多，所以有多少个5就是多少个0
        j=i;while (j%5==0) {s++;j=j/5;} //注意，有的不止一个因子5
    }
    cout<<s<<endl;
    //方法2 注意如何巧妙的统计5的个数！
    i=n;s=0;while (i!=0){s=s+i/5;i=i/5;}
    cout<<s<<endl;

    //计算最后一个非零的数字
    s=1;
    for (i=1;i<=n;i++)
    {
        s=s*i%10000; //最多一次只能出现2个零，保守一点搞4个
        while (s%10==0) s=s/10; ///最后一位是0的话舍弃这些0.可能不止1个！
    }
    cout<<s%10<<endl; //为什么还要%10？
    return 0;
}
26.	1到N中所有的数字写成1排，其中8出现了多少次
#include<iostream>
using namespace std;
int s,i,x,n,t;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++)
    {
        x=i;
        while (x!=0)
        {
            t=x%10;x=x/10;  
            if (t==8) s++; ///  s+=(t==8)
        }
    }
    cout<<s;
    return 0;
}


27.	[l,r]中共有r-l+1个数，其中那个数的约数最多
#include<iostream>
using namespace std;
int l,r,s,i,j,maxy,maxi;
int main()
{
    cin>>l>>r;
    maxx=maxy=0;
    for (i=l; i<=r; i++)
    {
        s=0;
        for (j=1; j<=i; j++)
            if (i%j==0) s=s+1;
        if (s>maxy){maxy=s;maxi=i;}
    }
    cout<<maxy<<' '<<maxi;
    return 0;
}
28.	形如aabb的四位完全平方数有哪些
#include<iostream>
#include<cmath>
using namespace std;
int i,ii,x1,x2,x3,x4;
int main()
{
   for(i=ceil(sqrt(1000));i<=sqrt(9999);i++)
   {
       ii=i*i;
       x1=ii/1000%10;
       x2=ii/100%10;
       x3=ii/10%10;
       x4=ii/1%10;
       if ((x1==x2)&&(x3==x4)) cout<<ii<<endl;

   }
    return 0;
}
29.	5个数中选3个数字的排列有多少种情况
 #include<iostream>
using namespace std;
int a,b,c;
int main()
{
    for(a=1; a<=5; a++)
        for(b=1; b<=5; b++)
            for(c=1; c<=5; c++)
                if ((a!=b)&&(b!=c)&&(c!=a)) cout<<a<<b<<c<<endl;
    return 0; 
}
30.	数字菱形
#include <iostream>
#include <cmath>
using namespace std;
int h,l,k;
int main()
{
    for (h=1; h<=18; h++)
    {
        for (k=1; k<=40.5+abs(9.5-h); k++) cout<<' ';
        for (l=1; l<=9.5-abs(9.5-h); l++) cout<<(h+1)/2<<' ';
        cout<<endl;
    }

}
31.	输入年月日，判断今天星期几
#include <iostream>
using namespace std;
int y,m,d,i;
int a[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
string ss="Sun.Mon.Tue.Wed.Thu.Fri.Sat.";
long long s;
int main()
{
    for (i=1; i<=y-1; i++)
        if ((i%400==0)||((i%4==0)&&(i%100!=0))) s=s+366;
        else s=s+365;
    if ((y%400==0)||((y%4==0)&&(y%100!=0))) a[2]=29; else a[2]=28;
    for (i=1; i<=m-1; i++) s=s+a[i];
    s=(s+d)%7;
    for (i=0;i<=3;i++)cout<<ss[4*s+i];
}
32.	筛法求质数
#include <iostream>
using namespace std;
bool a[201];
int i,j;
int main()
{
    for (i=2; i<=200; i++) a[i]=true;
    i=2;
    while (i<=200)
    {
        if (a[i])
        {
            j=i+i;
            while (j<=200)
            {
                a[j]=false;
                j=j+i;
            }
        }
        i++;
    }
    for (i=2; i<=200; i++) if (a[i]) cout<<i<<' ';
    return 0;
}
更好的写法：
    for (i=2; i<=m; i++) a[i]=1;
    for (i=2; i<=sqrt(m); i++)
        if (a[i])for (j=i*i; j<=m; j+=i) a[j]=0;

33.	约瑟夫问题
#include<iostream>
using namespace std;
int m,n;
int a[10],i,s,k;
int main()
{
    cin>>m>>n; //m个人围一圈，报到n就出去
    for (i=1; i<=m; i++) a[i]=1; // 在圈里面就是1否则0
    i=s=k=0;
    while (k<m)
    {
        i++;
        if(i>m) i=1; //报到m+1的时候重新回到1
        s=s+a[i];
        if (s==n)
        {
            k++; //出去的人加1
            cout<<i; //输出这个人的序号
            s=0; //下次重新从0开始报
            a[i]=0; //这个人不在参加报数
        }
    }
    return 0;
}

34.	10个数字由大到小排序（选择排序）
#include <iostream>
using namespace std;
int a[10];
int i,maxa,j,k;
int main()
{
    for (i=0;i<=9;i++) cin>>a[i];///读入10个数字
    for (i=0;i<=8;i++)
    {
        maxa=a[i];k=i;   ///假设第i个使最大的
        for (j=i+1;j<=9;j++)
          if (a[j]>maxa) {maxa=a[j];k=j;}  ///在后面找最大的数
        swap(a[i],a[k]);  ///和第i个交换
    }
    for (i=0;i<=9;i++) cout<<a[i]<<' ';
    return 0;
}

35.	杨辉三角 
#include <iostream>
#include <iomanip>
using namespace std;
int n;
void way1()
{
    int a[100][100];  //二维数组做法
    int i,j;
    a[1][1]=1;
    for (i=2; i<=n; i++)
    {
        a[i][1]=a[i][i]=1;
        for (j=2; j<=i-1; j++) a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n-i; j++) cout<<"  ";
        for (j=1; j<=i; j++) cout<<setw(4)<<a[i][j];
        cout<<endl;
    }
}
void way2()
{
    int b[2][100];//滚动数组做法
    int i,j;
    int p;//重要的滚动变量
    for (i=0; i<=n; i++)
    {
        p=i%2;    //也可以p=1-p
        b[p][1]=b[p][i]=1;   //首尾的特殊处理
        for (j=2; j<=i-1; j++) b[p][j]=b[1-p][j]+b[1-p][j-1];

        for (j=1; j<=n-i; j++) cout<<"  ";
        for (j=1; j<=i; j++) cout<<setw(4)<<b[p][j];
        cout<<endl;
    }
}
void way3()
{
    int c[100]; //一维数组做法
    int i,j;
    for (i=0; i<=n; i++)
    {
        c[0]=c[i]=1;
        for (j=i-1;j>=1;j--) c[j]=c[j]+c[j-1];  //回忆背包问题 为什么要从后往前推？

        for (j=0; j<=n-i; j++) cout<<"  ";
        for (j=0; j<=i; j++) cout<<setw(4)<<c[j];
        cout<<endl;
    }
}
int main()
{
    n=9;
    way2();
    return 0;
}

36.	螺旋方阵
#include <iostream>
#include <iomanip>
using namespace std;
int a[100][100],n;
int u,d,l,r;  //u,d,l,r分别表示上下左右边界
int i,j,k;
void pp()
{
    int r,c;///平面图形输出千万不要用x和y
    for (r=1; r<=n; r++)
    {
        for (c=1; c<=n; c++)  cout<<setw(3)<<a[r][c];
        cout<<endl;
    }
}
int main()
{
    cin>>n;
    u=l=1;
    d=r=n;
    k=1;
    while (k<=n*n)
    {
        for (i=l; i<=r; i++) a[u][i]=k++; //沿着最上面从左到右；
        u++; //上界变化
        for (i=u; i<=d; i++) a[i][r]=k++; //沿着最右边从上到下；
        r--; //右界变化
        for (i=r; i>=l; i--) a[d][i]=k++; //沿着最下边从右到左；
        d--; //上界变化
        for (i=d; i>=u; i--) a[i][l]=k++; //沿着最上面从左到右；
        l++; //上界变化
    }
    pp();
    return 0;
}

37.	奇数阶幻方
#include <iostream>
using namespace std;
int a[39][39],n;
int r,c,tr,tc,i,j,k; //r和c表示当前的行和列  tr tc表示下一个位置的行和列
int main()
{
    cin>>n;   r=0;    c=n/2;  //首行正中间
    k=1;   a[r][c]=k;
    while (k<n*n)
    {
        tr=(r-1+n)%n;
        tc=(c+1+n)%n;  //仔细体会这种技巧
        if (a[tr][tc]>0)
        {
            tr=(r+1)%n;
            tc=c;
        }
        k++;r=tr;c=tc;a[r][c]=k;
    }
    for (r=0; r<=n-1; r++)
    {
        for (c=0; c<=n-1; c++) cout<<a[r][c]<<' ';
        cout<<endl;
    }
    return 0;
}
体会：1、空间折叠的技术2、临时判断的技术3、变量命名的技术
38.	打印小九九乘法口诀表
#include<iostream>
#include<iomanip>
using namespace std;
int r,c;  ///行和列
int main()
{
    for (r=1; r<=9; r++)
    {
        for (c=1; c<=r; c++)
            cout<<c<<'*'<<r<<'='<<setw(2)<<r*c<<' ';
        cout<<endl;
    }
    return 0;
}
39.	AHHAAH/JOKE=HA，不同的字母表示不同的数字
#include<iostream>
using namespace std;
int joke,ha,ahhaah;  //三个主输入变量
int j,o,k,e,h,a; //单个分解后的变量
int aa[10],i;
bool b;//判断是否符合条件的变量
int main()
{
    for (joke=1234; joke<=9876; joke++)  //joke的范围
        for (ha=12; ha<=98; ha++) //ha的范围
        {
            h=ha/10;
            a=ha%10; //分解数字
            ahhaah=h*11001+a*100110;
            if (ahhaah==joke*ha)   //第一个限制条件
            {
                j=joke/1000%10;
                o=joke/100%10;
                k=joke/10%10;
                e=joke/1%10;   //体会这里的无聊
                b=true; //开始数字判重
                for (i=0; i<=9; i++) aa[i]=1; //最大可以使用一次
                aa[j]--;aa[o]-- ;aa[k]--;aa[e]--;aa[h]--;aa[a]--;
                for (i=0; i<=9; i++) if (aa[i]<0)b=false; 
//倘若那个可用次数少于0，意味着被用过两次
                if (b) cout<<ahhaah<<'/'<<joke<<'='<<ha<<endl;
            }
        }

    return 0;
}
40.	355/113 小数点之后100位是几
#include<iostream>
using namespace std;
int a,b,c,x,i;
int main()
{
    a=355;b=113;
    x=a/b; cout<<x<<'.' ;   ///整数部分先输出
    c=a%b;
    for (i=1; i<=100; i++)
    {
        a=10*c; x=a/b;
        cout<<x;
        c=a%b;  ///余数将成为下一次的被除数
    }
    return 0;
}
41.	1234567891011***99除以997的余数
#include <iostream>
using namespace std;
int i,x,a;
int main()
{
    x=0;
    for (i=1;i<=100;i++)
    {
        if (i<=9) a=10;else a=100;
        x=x*a+i;///当前的被除数
        x=x%997;///余数
    }
    cout<<x;
    return 0;
}

42.	100！的精确值
#include<iostream>
const int maxn=200;
int a[maxn];
int i,j,k,x;
using namespace std;
int main()
{
    for (i=1;i<=maxn-1;i++)a[i]=0;a[0]=1;
    for (j=2;j<=100;j++) //j表示乘数，连乘99次
    {
         for (i=0;i<=maxn-1;i++)a[i]=a[i]*j; //每一位都乘一下
         for (i=0;i<=maxn-2;i++)
         {x=a[i];a[i]=x%10;a[i+1]=a[i+1]+x/10;}  进位处理
    }
    j=maxn-1;while ((a[j]==0) && (j>=1)) j--;    去掉前面不要的0
    for (i=j;i>=0;i--) cout<<a[i];
    return 0;
}

43.	高精度正整数加法字符串
#include<iostream>
using namespace std;
string s1,s2,s3;
int l1,l2,x1,x2,x3,j;
int main()
{
    cin>>s1>>s2;
    s3="";   ///s3的初始为空
    if (s1.size()<s2.size()) swap(s1,s2);
    l1=s1.size();l2=s2.size();
    for (i=1; i<=l1-l2; i++)  s2="0"+s2;
    j=0;
    for (i=s1.size()-1; i>=0; i--)   ///低位往高位加
    {
        x1=s1[i]-'0';  ///字符变数字！
        x2=s2[i]-'0';
        x3=x1+x2+j;
        if  (x3>=10)
        {
            x3=x3-10;
            j=1;
        }
        else
            j=0;

        s3=char(x3+'0')+s3;   ///加到s3的前面
    }
    if (j==1) s3="1"+s3; ///最高位的处理
    cout<<s3;
    return 0;
}
44.	高精度正整数乘法
#include<iostream>
using namespace std;
string s1,s2,s3;
int l1,l2,l,x1,x2,x,i,j;
int a[201],b[201],c[201];  ///这里有个隐患 200位乘200位可能要400位！
int main()
{
    cin>>s1;l1=s1.size();
    for (i=0;i<=l1-1;i++) a[i]=s1[l1-1-i]-'0';  ///字符串变数组
    cin>>s2;l2=s2.size();
    for (i=0;i<=l2-1;i++) b[i]=s2[l2-1-i]-'0';///字符串变数组
    //for (i=0;i<=l2-1;i++) cout<<b[i];
    for (i=0;i<=l1-1;i++)
        for (j=0;j<=l2-1;j++)
             c[i+j]+=a[i]*b[j];

    for (i=0;i<=l1+l2-1;i++)   ///进位处理
    {
        x=c[i];c[i]=x%10;c[i+1]+=x/10;
    }

    if (c[l1+l2-1]!=0) cout<<c[l1+l2-1];   ///最高位判断
    for (i=l1+l2-2;i>=0;i--) cout<<c[i];

    return 0;
}

45.	求e=1+1/1!+1/2!+1/3!***，精确到小数点后100位
#include <iostream>
using namespace std;
const int maxl=105;//最大算到小数限制后104位
const int n=100;//最大算到100！其实没有必要
int a[maxl],s[maxl]; //a表示单项，s表示总和
int il,in;//分别对应着maxl和n的循环变量
int x;
int main()
{
   s[0]=a[0]=1;
   for (in=1;in<=n;in++)
   {
       x=0;for(il=0;il<=maxl-1;il++){x=10*x+a[il];a[il]=x/in;x=x%in;}  //每位的除法
       for(il=0;il<=maxl-1;il++) s[il]=s[il]+a[il];  //加进总和
       for(il=maxl-1;il>=1;il--) {x=s[il];s[il]=x%10;s[il-1]=s[il-1]+x/10;}  //进位处理
   }
   if s[101]>=5 //第101位四舍五入
   {
       s[100]++;il=100;
       while ((s[il]>=10) &&(il>0))   //顺次往前进位
       {
           x=s[il];s[il]=x%10;s[il-1]=s[il-1]+x/10;
       }
   }

    cout<<s[0]<<'.';for (il=1;il<=maxl;il++) cout<<s[il];
    return 0;
}

46.	进制转换
#include<iostream>
using namespace std;
long long x;
int i,t;
char c;
string s;
int main()
{
    //=====10ת2======

    cin>>x;i=0;
     while (x>0)
     {
         if (x%2==0) c='0';else c='1';
         s=c+s;x=x/2;
     }
    cout<<s<<endl;

    //=====2ת10======
    cin>>s;x=0;
    for (i=0;i<=s.size()-1;i++)
    {
        if (s[i]=='1') c=1;else c=0;
        x=x*2+c;
     }
    cout<<x;

    //=====10ת16======
    cin>>x;s="";
     while (x>0)
     {
         t=x%16;
         if (t>=10) c='A'+t-10;else c='0'+t;
         s=c+s;x=x/16;
     }
    cout<<s<<endl;

    //=====16ת10======
    cin>>s;x=0;
    for (i=0;i<=s.size()-1;i++)
    {
        if (s[i]>='A') c=s[i]-'A'+10;else c=s[i]-'0';
        x=x*16+c;
     }
    cout<<x;

    return 0;
}
47.	分解质因数
#include <iostream>
using namespace std;
long x,a;
int main()
{
    cin>>x;
    a=2;while (x%a!=0) a++;   //找到第一个因子
    cout<<x<<'='<<a;x=x/a;
    while (x>1)   // x>1表示可能还有因子
    {
        if (x%a==0)   可以除尽的话就除 否则换下一个
        {x=x/a;cout<<'*'<<a;}
        else a++;
    }
    return 0;
}

48.	求cmn
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const  int  mm=1010; ///m的最大值
const int mn=100;///最后答案的位数
int p[mm],c[mm]; ///p是质数表，c是指数，将数字表示为p^c的乘积形式
int maxp;///质数的个数
int m,n,i,j,k,x;
int a[mn];
void creatprime(int m)  ///m以内的质数表
{
    bool a[mm];
    int i,j;
    for (i=2; i<=m; i++) a[i]=1;
    ///另外一种写法的筛法
    for (i=2; i<=sqrt(m); i++)
        if (a[i])
            for (j=i*i; j<=m; j+=i) a[j]=0;
    for (i=2,j=0; i<=m; i++) if (a[i]) p[j++]=i;
    maxp=j-1;
}
int main()
{
    cin>>m>>n;if (n>m/2) n=m-n;
    creatprime(m);
    for (i=0; i<=maxp; i++) cout<<setw(5)<<p[i];cout<<endl;
    for (i=m; i>=m-n+1; i--)
    {
        x=i,j=0;
        while (x>1) //体会这里与分解质因数那个题的相似
            if (x%p[j]==0) {x=x/p[j];c[j]++; }
            else j++;
    }
    for (i=1; i<=n; i++)
    {
        x=i,j=0;
        while (x>1)
            if (x%p[j]==0) {x=x/p[j];c[j]--; }
            else j++;
    }

    for (i=0;i<=maxp;i++) cout<<setw(4)<<p[i];cout<<endl;
    for (i=0;i<=maxp;i++) cout<<setw(4)<<c[i];cout<<endl;
    ///单精度乘法
    a[0]=1;
    for (i=0; i<=maxp; i++)   ///循环底数
        for (j=1; j<=c[i]; j++)  ///循环指数
        {
            for (k=0; k<=mn-1; k++) a[k]*=p[i];
            for (k=0; k<=mn-2; k++)
            {
                x=a[k];
                a[k]=x%10;
                a[k+1]+=x/10;
            }
        }

    i=mn-1;
    while (a[i]==0 && i>0) i--;
    for (; i>=0; i--) cout<<a[i];
    return 0;
}
当然还有个做法，杨辉三角里面嵌入高精度字符串加法。
49.	连续最长平台数
/// 1 1 2 2 2 2 2 3 3 4 4 那个数字连续出现的次数最多
#include <iostream>
using namespace std;
const int mm=105; ///假设最多只有100个数，都是正整数
int a[mm],n;
int i,k,mi,mk;
int main()
{
    cin>>n;
    for (i=1; i<=n; i++) cin>>a[i]; ///读入数字
    a[n+1]=0;///绝对不会出现的数字作为虚拟岗哨避免最后一次
    mk=0;
    for  (i=2; i<=n+1; i++)
    {
        if (a[i]==a[i-1])k++;
        else
        {
            if (k>mk)
            {
                mk=k;
                mi=a[i-1];  ///记录最长的数字和长度
            }
            k=1;            ///重新开始统计
        }
    }
    cout<<mi<<' '<<mk;
    return 0;
}
50.	快速幂
cin>>a>>n; ///计算a^n
long long s=1,t=a;
	while (n>0)
	{
		if (n%2==1) s=(s*t);
		n=n/2;t=t*t;
	}
    cout<<s;
