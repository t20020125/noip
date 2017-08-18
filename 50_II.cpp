
1.	S=1+2+4+7+***N	1
2.	验证哥德巴赫猜想	1
3.	随机产生100个互不相同的三位数	1
4.	模拟扑克发牌	1
5.	最大公约数	1
6.	扩展的欧几里得	1
7.	阶乘问题	1
8.	Fibo	1
9.	汉诺塔问题	1
10.	错排问题	1
11.	A^B的快速幂计算	1
12.	插入排序	1
13.	冒泡排序	1
14.	二分查找	1
15.	根号2	1
16.	求第K大元素	1
17.	快速排序	1
18.	有序表的合并	1
19.	归并排序	1
20.	PMN（超级注意）	1
21.	CMN	1
22.	8皇后问题	1
23.	间隔排列	1
24.	有重排列	1
25.	M个中选任意个	1
26.	0-9 全排列相邻的两个数之和为质数	1
27.	开心的金明（递归做法）	1
28.	1*2骨牌覆盖	1
29.	因式分解	1
30.	跳马问题	1
31.	2^100最少要算多少次（DFS）	1
32.	2的幂分解 NOIP1998	1
33.	老鼠迷宫	1
34.	砝码称重问题	1
35.	最大连续邮资	1
36.	100分成6个数字的和	1
37.	约数最多	1
38.	生日蛋糕NOI99	1
39.	奇怪的数列	1
40.	2^N最少多少次BFS	1
41.	贴邮票	1
42.	最长不下降序列	1
43.	最长公子序列	1
44.	经典背包	1
45.	连续最大和	1
46.	全排列的下一个	1
47.	全排列的第N个	1
48.	Dijistra最短路径	1
49.	SPFA最短路径	1
50.	FLOYD最短路径	1
1.	S=1+2+4+7+***N
int s,a,i;///i 第几项 a这一项的值 s总和
int main()
{
    cout<<"\n===N是第10项===\n";
    s=a=0;
    for(i=1; i<=10; i++)
    {
        a=a+i-1; ///注意体会ai与ai-1的关系
        s+=a;
    }
    cout<<s;

    cout<<"\n===N是大于100的最小整数===\n";
    s=a=1;
    for(i=2; a<=100; i++) ///看看判断条件 就是这样
    {
        a=a+i-1; ///注意体会ai与ai-1的关系
        s+=a;
    }
    cout<<s;

    cout<<"\n===N是小于100的最大整数===\n";
    s=a=1;
    for(i=2; a+i-1<=100; i++) ///看看判断条件 就是这样
    {
        a=a+i-1; s+=a;
    }
    cout<<s;

    cout<<"\n===N是小于100的最大整数===\n";
    s=0;
    a=1;///看看初值和循环里面两句话的位置和配合关系
    for(i=2; a<=100; i++) ///看看判断条件 就是这样
    {
        s+=a;
        a=a+i-1; ///注意体会ai与ai-1的关系
    }
    cout<<s;
}   
注意认真揣摩变量的变化情况，此题当然可以用while循环。
2.	验证哥德巴赫猜想
int x,x1,x2;
bool isprime(int x)  ///判断x是不是质数 注意1的隐患
{
    if(x<2) return 0;
    int i=2;bool b=true;
    while (b && (i*i<=x))
        if (x%i==0) b=false;
        else i++;
    return b;
}
int main()
{
    cin>>x; ///x>4,x1<=x/2,等条件保证了1不会出现
    for (x1=2;x1<=x/2;x1++)
    {
        x2=x-x1;
        if (isprime(x1)  && isprime(x2)) cout<<x<<'='<<x1<<'+'<<x2<<endl;
    }
}

3.	随机产生100个互不相同的三位数
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int i,j,x;
int a[100];
bool b;
int main()
{
    srand((int)time(NULL));   ///随机种子初始化
    i=0;while (i<=99)
    {
        b=1;///假设没有重复的
        x=100+rand()%900;  ///这样x就直接在100-999
        j=0;while (j<=i-1  && b)  ///在前面找看有没有相同的
            if  (a[j]==x) b=0;
            else j++;
        if (b) a[i++]=x;  ///没有重复就加进数组
    }
    for (i=0; i<=99; i++) cout<<a[i]<<' ';

    return 0;
}
 注意生成的技巧和判断重复的技术

4.	模拟扑克发牌
#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int n,r,i,j,k;
int a[100];
string MZ=" A 2 3 4 5 6 7 8 910 J Q K";
char HS[4]= {6,3,5,4};
int main()
{

    for (i=0; i<=51; i++) a[i]=i;
    srand((int)time(NULL));

    for (i=0; i<=51; i++)
    {
        j=rand()%52;
        swap(a[i],a[j]);
    }

    for (i=0; i<=51; i++)
    {
        cout<<HS[a[i]/13];
        cout<<MZ[2*(a[i]%13)];
        cout<<MZ[2*(a[i]%13)+1];
        cout<<' ';
        if (i%13==12) cout<<endl;

    }
    return 0;
}
注意花色和面值的对应技术，以及每发13张牌就换行的技术，但是此题在win10下好像不能正确显示花色，win7下可以。
5.	最大公约数
int gcd1(int m,int n)     递归做法
{
    if (n==0) return m;
    else return gcd1(n,m%n);
}
int gcd2(int m,int n)    递推做法
{
    int x=m%n;
    while (x!=0) {m=n;n=x;x=m%n;}
    return n;
}
更NB的 int gcd(int a,int b) {return b ? gcd(b,a%b) : a; }
6.	扩展的欧几里得
#include<iostream>
using namespace std;
int a,b,x,y;
int e_gcd(int  a,int  b,int  &x,int  &y)
{
    int ans;
    if(b==0)
    {x=1;y=0;ans=a;}
    else
    {
        ans=e_gcd(b,a%b,x,y);
        int t=x;x=y;y=t-a/b*y;
    }
    return ans;
}
int main()
{
    a=80;b=48;
    cout<<e_gcd(a,b,x,y)<<endl;
    cout<<x<<' '<<y<<' '<<endl;
    cout<<a*x+b*y;

}

7.	阶乘问题
int fac(int n)   递归做法
{
    if (n==0) return 1;
    else return fac(n-1)*n;
}

改进的记忆化递归
const int mm=20+1; ///最多算到20！
int a[mm],n;
long long  fac(int i)
{ long long x;
    if (a[i]!=0) return a[i];
    else {x=i*fac(i-1);a[i]=x;return x;}
}
int main()
{
    a[0]=1;cout<<fac(10); return 0;
}

8.	Fibo
int fibo(int n)
{
    if (n==1) return 1;
    else if (n==2) return 2;
    else return fibo(n-1)+fibo(n-2);
}
改进的记忆化的递归
const int mm=100; 
int a[mm];
long long  fac(int i)
{ long long x;
    if (a[i]!=0) return a[i];
    else {x=fac(i-1)+fac(i-2);a[i]=x;return x;}
}
int main()
{
    a[1]=a[2]=1;
    cout<<fac(10);
    return 0;
}
9.	汉诺塔问题
void ha(int n,char a,char b,char c)
{
    if (n==1) cout<<a<<"->"<<c<<endl;
    else
    {
        ha(n-1,a,c,b);  // n-1个盘子由A通过C挪到B上
        cout<<a<<"->"<<c<<endl;// 最后一个盘子直接由A到C
        ha(n-1,b,a,c);// n-1个盘子由B通过A挪到C
    }
}

int main()
{
    ha(3,'A','B','C');
    return 0;
}

10.	错排问题
///n个信封n封信本来是一一对应，但是现在所有的都装错了，问有多少种情况
int cp(int n)
{
    if (n==1) return 0;
    else if (n==2) return 1;
    else return (n-1)*(cp(n-1)+cp(n-2));
}

11.	A^B的快速幂计算
int a,b;
long long way1(int n)  ///这样写是不好的
{
   if (n==0) return 1;   //0次方等于1
   else if (n%2==1) return way1(n/2)*way1(n/2)*a; //奇数次
        else return way1(n/2)*way1(n/2);//偶数次
}
应该这样  否则有个编译器笨到二次递归
   if (n==0) return 1;   //0次方等于1
   else if (n%2==1) {x= way1(n/2);return x*x*a;} //奇数次
        else {x= way1(n/2);return x*x;}//偶数次

long long way2(int n)
{
	long long s=1,t=a;
	while (n>0)
	{
		if (n%2==1) s=(s*t);
		n=n/2;t=t*t;
	}
	return s;
}
12.	插入排序
#include <iostream>
using namespace std;
const int mm=20;
const int inf=9999999;
int i,j,x;
int a[mm];
void insert_sort()
{
    int b[mm+1];
    for (i=0; i<=mm-1; i++)
    {
        j=i-1;///从后往前凡是>a[i]的数都右挪一格
        while ((b[j]>=a[i]) && j>=0)
        { b[j+1]=b[j];j--;}

        j++; b[j]=a[i]; ///把a[i]插入到正确的地方
        ///输出检查
        for (int k=0; k<=i; k++) cout<<a[k]<<' ';
        cout<<endl;
        for (int k=0; k<=i; k++) cout<<b[k]<<' ';
        cout<<endl;
    }
    for(i=0; i<=mm-1; i++) a[i]=b[i];
}
void pp()
{
    for (int i=0; i<=mm-1; i++) cout<<a[i]<<' ';
    cout<<endl;
}
int main()
{
    ///顺序检查
    for (i=0; i<=19; i++) a[i]=i;
    insert_sort();
    pp();
    ///倒序检查
    for (i=0; i<=19; i++) a[i]=19-i;
    insert_sort();
    pp();
    ///相同的检查
    for (i=0; i<=19; i++) a[i]=5;
    insert_sort();
    pp();
    ///部分相同的乱序检查
    for (i=0; i<=19; i++) a[i]=19-i%4;
    insert_sort();
    pp();
    return 0;
}
13.	冒泡排序
#include<iostream>
using namespace std;
int a[10]= {1,3,7,5,9,8,2,4,6,0};
int i,j;bool b;
int main()
{
    for (i=9; (i>=1||b); i--) ///注意这个b的巧妙的位置 很多书上没有b变量
    {
        b=1;
        for (j=0; j<=i-1; j++)  ///前面的所有元素中找比后面大的
            if (a[j]>a[j+1])
            {
                swap(a[j],a[j+1]); ///若有则交换，置交换标记
                b=0;
            }
    }
    for (i=0;i<=9;i++) cout<<a[i]<<' ';
}
这种排序适合与数组小规模，基本有序的情况下，请用上面的方法检查

14.	二分查找
#include<iostream>
using namespace std;
const int mm=103;
int a[mm];
int ds(int x,int l,int r)
{
    int i=l;  ///从第一个数开始找起
    bool b=true; ///未找到标记
    while ((i<=r)  && b)  ///是不是很像判断质数
        if (a[i]==x) b=false;
        else i++;
    if(!b) return i;
    else return -1;
}
int bs(int x,int l,int r)
{
    if (r<l) return -1;
    else
    {
        int m=(l+r)/2;   ///m=l+(r-l)/2;
        if (a[m]==x) return m;
        else if (a[m]>x) return bs(x,l,m-1);  ///小了就找左边
        else if (a[m]<x) return bs(x,m+1,r);///大了就找右边
    }
}
int bs2(int x,int l,int r)
{
    int m;
    bool b=true;///未找到标记
    while (l<=r && b)
    {
        m=(l+r)/2;
        if (a[m]==x) b=false; ///找到了
        else if (a[m]>x) r=m-1;///小了就找左边
        else l=m+1;///大了就找右边
    }
    if (!b) return m;
    else return -1;
}
int main()
{
    for (int i=0; i<=102; i++) a[i]=2*i; ///都是有顺序的偶数
    
for (int i=0; i<=102; i++)   ///各种检查
{cout<<bs(i,0,100)<<endl;
    cout<<ds(i,0,100)<<endl;
    cout<<bs2(i,0,100)<<endl};

}
15.	根号2
   x=2;eps=0.0001 ///精度
   dl=0;dr=2;b=false;
   while (!b&& (dl<=dr))
   {
       dm=(dl+dr)/2.0;
       if ((dm*dm>=x-eps)&&(dm*dm<=x+eps)) b=true; ///实数一般不直接判断相等  abs(dm*dm-x)<=eps
       else if (dm*dm<x) dl=dm+eps;
       else dr=dm-eps;
   }
   cout<<dm<<endl;

16.	求第K大元素
#include <iostream>
using namespace std;
const int mm=10;
int a[mm];
int i;
int hf(int l,int r)
{
    int p=a[l];
    while (l<r)
    {
        while ((a[r]>=p) &&(l<r) ) r--;  ///一定是先从右边找小的
        a[l]=a[r];
        while ((a[l]<=p) &&(l<r) ) l++;  ///再从左边找大的
        a[r]=a[l];
    }
    a[l]=p;
    return l;
}

int get(int x,int l,int r)
{
    int p=hf(l,r);
    if (p==x) return a[x];
    else if (p>x) return  get(x,l,p-1);
    else return get(x,p+1,r);
}

int main()
{
    ///在很顺序的里面找
    for (i=0; i<=9; i++) a[i]=i;
    for (i=0; i<=9; i++) cout<<get(i,0,9)<<' ';

    cout<<endl;
    ///在倒序中找
    for (i=0; i<=9; i++) a[i]=9-i;
    for (i=0; i<=9; i++) cout<<get(i,0,9)<<' ';

    cout<<endl;
    ///在相同的中找
    for (i=0; i<=9; i++) a[i]=1;
    for (i=0; i<=9; i++) cout<<get(i,0,9)<<' ';

    ///在部分相同的中找
    cout<<endl;
    for (i=0; i<=9; i++) a[i]=10-i%2;
    for (i=0; i<=9; i++) cout<<get(i,0,9)<<' ';

    ///在乱序的中找
    cout<<endl;
    for (i=0; i<=9; i++) a[i]=i*i%10;
    for (i=0; i<=9; i++) cout<<get(i,0,9)<<' ';
    ///请体会此中的测试技巧
    return 0;
}

17.	快速排序
#include <iostream>
using namespace std;
const int mm=10;
int a[mm];
int i;
void pp()
{
    for (int i=0; i<=9; i++) cout<<a[i]<<' ';cout<<endl;
}
void qs(int l,int r)
{
    if (l>=r) return;
    int p=a[l],ll=l,rr=r;
    while (l<r)
    {
        while ((a[r]>=p) &&(l<r) ) r--;
        a[l]=a[r];
        while ((a[l]<=p) &&(l<r) ) l++;
        a[r]=a[l];
    }
    a[l]=p;

    if (l>=ll)qs(ll,l);
    if (l+1<=rr)qs(l+1,rr);
}
int main()
{

    ///在顺序的里面找
    for (i=0; i<=9; i++) a[i]=i;
    qs(0,9);pp();

    cout<<endl;
    ///在倒序中排
    for (i=0; i<=9; i++) a[i]=9-i;
    qs(0,9);pp();

    cout<<endl;
    ///在相同的中排
    for (i=0; i<=9; i++) a[i]=1;
    qs(0,9);pp();

    ///在部分相同的中排
    cout<<endl;
    for (i=0; i<=9; i++) a[i]=10-i%3;
    qs(0,9);pp();

    ///在乱序的中排
    cout<<endl;
    for (i=0; i<=9; i++) a[i]=i*i%10;
    qs(0,9);pp();

    return 0;
}
18.	有序表的合并
///a数组里有la个元素有小到大，b数组中有lb个元素也是有小到大，合并到c数组
#include <iostream>
using namespace std;
const int mm=102;///最多100个元素
int a[mm]={1,3,5,7,8,9},la=6;  ///a有6个元素
int b[mm]={1,2,3,4,9,10,14,15},lb=8;///b有8个元素
int c[mm*2],lc;
int ia,ib,ic;
int main()
{
    ia=ib=ic=0;
    while ((ia<=la-1) && (ib<=lb-1))  ///一个数组还没有倒完
    if (a[ia]==b[ib]){ c[ic]=a[ia];ia++;ib++;ic++;}  ///重复的算一次
        else  if (a[ia]<b[ib]){ c[ic]=a[ia];ia++;ic++;}
        else { c[ic]=b[ib];ib++;ic++;}
    ///剩余的直接倒到c,显然这两个while只可能运行一个
    while (ia<=la-1) c[ic++]=a[ia++];
    while (ib<=lb-1) c[ic++]=b[ib++];
    lc=ic-1;///注意不计重复的时候lc=la+lb
    for(ic=0;ic<=lc;ic++) cout<<c[ic]<<' ';
    return 0;
}

19.	归并排序
const int mm=102;///最多100个元素
int a[mm],b[mm],i;
void m(int il,int im,int ir )
///原始数组，合并后的数组，起点，中点，终点
{
    int i=il,j=im+1,k=0;
    while (i<=im && j<=ir)
        if (a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++];
    while (i<=im) b[k++]=a[i++];
    while (j<=ir) b[k++]=a[j++];
    for (i=0; i<=k-1; i++) a[il+i]=b[i];
}
void ms(int il,int ir)
{
    if (il<ir)
    {
        int im=(il+ir)/2;
        ms(il,im);
        ms(im+1,ir);
        m(il,im,ir);
    }
}
void pp()
{
    for (int i=0; i<=9; i++) cout<<a[i]<<' ';
}
int main()
{
    ///在顺序的里面找
    for (i=0; i<=9; i++) a[i]=i;
    ms(0,9);pp();

    cout<<endl;
    ///在倒序中排
    for (i=0; i<=9; i++) a[i]=9-i;
    ms(0,9);pp();

    cout<<endl;
    ///在相同的中排
    for (i=0; i<=9; i++) a[i]=1;
    ms(0,9);pp();

    ///在部分相同的中排
    cout<<endl;
    for (i=0; i<=9; i++) a[i]=10-i%3;
    ms(0,9);pp();

    ///在乱序的中排
    cout<<endl;
    for (i=0; i<=9; i++) a[i]=i*i%10;
    ms(0,9);pp();
    return 0;
}
20.	PMN（超级注意）
#include <iostream>
using namespace std;
const int m=10;
const int n=5;//10个选5个
int a[n];
bool b[m];
void mysearch(int i)
{
    int j,k;
    if (i>=n) {for (j=0; j<=n-1; j++) cout<<a[j];cout<<endl;}
    else for (k=0; k<=m-1; k++)
            if (b[k])
            {
                a[i]=k;   ///填入
                b[k]=false;  ///这个数字再不能被用了
                mysearch(i+1);  ///继续搜索填下一个
                b[k]=true; /// 这个数字又可以被用了！！！
            }
}

int main()
{
    for (int i=0;i<=m-1;i++) b[i]=true;
    mysearch(0);
}
21.	CMN
int a[10];
void mysearch(int i)
{
    int j,k;
    if (i>=3) {for (j=0; j<=2; j++) cout<<a[j];cout<<endl;}
    else for (k=((i==0)?0:a[i-1]+1); k<=5; k++)
          { a[i]=k;  mysearch(i+1);  }
}

22.	8皇后问题
有一个难点是判断在同一列，同一对角线的情况，考虑他的斜率就很好理解了
#include <iostream>
using namespace std;
int a[8];
bool b1[8],b2[16],b3[16]; //分别表示列，左对角线，右对角线是否可以放

void mysearch1(int i)
{
    int j,k;
    if (i>=8)  {for (j=0; j<=7; j++) cout <<a[j]<<' '; cout<<endl; }
    else  for (k=0; k<=7; k++)
        { if (b1[k] && b2[i+k] && b3[i-k+8])
            {   a[i]=k;
                b1[k]=b2[i+k]=b3[i-k+8]=false; //体会这里的置位情况  斜率关系
                mysearch1(i+1);
                b1[k]=b2[i+k]=b3[i-k+8]=true;
            }
        }
}
bool canplace (int i ,int j)
{
    bool b=true;
    for (int k=0; k<=i-1; k++)
        if ((a[k]==j) ||(a[k]-k==i-j)||(a[k]+k==i+j)) b=false;
    return b;
}
void mysearch2(int i)
{
    int j,k;
    if (i>=8){for (j=0; j<=7; j++) cout <<a[j]<<' ';   cout<<endl;   }
    else  for (k=0; k<=7; k++)
            if (canplace(i,k))    {a[i]=k; mysearch2(i+1); }
}

int main()
    {   for (i=0; i<=7; i++) b1[i]=true;
        for (i=0; i<=15; i++) b2[i]=b3[i]=true;
        mysearch2(0);
}


23.	间隔排列
#include<iostream>
using namespace std;
int n=3;
int i,a[100],b[100];
void mysearch(int i)
{  int j,k;
   if (i>=2*n) {for(j=0;j<=2*n-1;j++) cout<<a[j]+1;cout<<endl;} //递归出口，当2*N的位子上都摆满了
   else  if (a[i]>-1) mysearch(i+1);  //若此位置已经有数字了，就直接搜索下一个
   else
     for (k=0;k<=n-1;k++)
        if ((a[i]==-1) && (i+k+2<=2*n-1) && (a[i+k+2]==-1) && b[k])
            //四个条件 1此位置没有数字，2此数字没有被占用 3间隔一定位置后面的那个数字不超范围4也没有数字
   {    a[i]=a[i+k+2]=k;b[k]=false;mysearch(i+1);
        a[i]=a[i+k+2]=-1;b[k]=true;
   }
}
int main()
{
    for (i=0;i<=2*n-1;i++) a[i]=-1;
    for (i=0;i<=n-1;i++) b[i]=true;
    mysearch(0);
    }
  注意这种把s带进去的技巧，免得每次置位复位
  注意这里和前面pmn不同的一个地方
     if (a[i]>-1) mysearch(i+1);  //若此位置已经有数字了，就直接搜索下一个

24.	有重排列
///2个A3个B2个C1个D中选3个字母的排列
#include <iostream>
using namespace std;
string ss=" ABCD";///第0位闲置
int a[10],c[10]= {0,2,3,2,1}; ///次数
void dfs(int i)
{
    int j,k;
    if (i>=4)
    {
        for (j=1; j<=3; j++) cout<<ss[a[j]];
        cout<<endl;
    }
    else for (k=1; k<=4; k++)
            if (c[k]>0)
            {
                a[i]=k;
                c[k]--;    ///和标准pmn的不同，这里是减1
                dfs(i+1);
                c[k]++;
            }
}

int main()
{
    dfs(1);
    return 0;
}

25.	M个中选任意个
void mysearch1(int i)
{    int j,k;
    if (i>=3) {for (j=0; j<=2; j++) cout<<a[j];cout<<endl;}
    else for (k=((i==0)?0:a[i-1]+1); k<=5; k++)
          { a[i]=k;  mysearch1(i+1);  }
}

void mysearch2(int i)
{    int j,k;
    for (j=0; j<=i-1; j++) cout<<a[j];cout<<endl;
    for (k=((i==0)?0:a[i-1]+1); k<=5; k++)
          { a[i]=k;  mysearch2(i+1);  }
}

比较下5选3 和5选任意个，
当然这里要是a[0]=0，做个假的虚拟岗哨更好
还有一个做法，枚举每个元素选还是不选
#include<iostream>
using namespace std;
const int mm=5; ///0-4中选任意个
int a[mm+1]; ///a[0]被浪费了
int b[mm+1];
void dfs1(int i)  ///这里的i表示第i个位置上该放什么
{
    int j,k;
    for (j=1; j<=i-1; j++) cout<<a[j];
    cout<<endl;
    for (k=a[i-1]+1; k<=mm; k++)
    {
        a[i]=k;
        dfs1(i+1);
    }
}

void dfs2(int i)  ///这里的i表示第i个元素是选还是不选
{
    if (i>=mm+1)
    {
        for(i=1; i<=mm; i++) ///选择了就输出 注意
            if (b[i]) cout<<i<<' ';
        cout<<endl;
    }
    else
    {
        b[i]=1;  ///选择了
        dfs2(i+1);
        b[i]=0;   ///不选择 因为只有两种情况就不循环了
        dfs2(i+1);
    }
}


int main()
{
    cout<<"\n======way1======\n";
    a[0]=0;
    dfs1(1);
    cout<<"\n======way2======\n";
    for (int i=1; i<=mm; i++) b[i]=0;
    dfs2(1);

    return 0;
}

26.	0-9 全排列相邻的两个数之和为质数
#include <iostream>
using namespace std;
int a[10];bool b[10];
const int bb[20]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1};
void mysearch(int i)
{
    int j,k;
    if (i>=5) {for (j=0; j<=4; j++) cout<<a[j];cout<<endl;}
    else for (k=0; k<=4; k++)
        if (b[k] && ((k>=1)?bb[k+a[i-1]]:true))   ///注意这个巧妙的写法，为1的特判
            {   a[i]=k; b[k]=false; mysearch(i+1);
                b[k]=true;
            }
}

27.	开心的金明（递归做法）
#include <iostream>
using namespace std;
int a[26],w[26],q[26];
int s,n,ss,qq,maxq;
void mysearch(int i)
{
    int j,k;
    if (i<=n)  //还有可以被选择的对象
        for (k=a[i-1]+1; k<=n; k++)
            if (ss+w[k]<=s)  //如果可以买
            {
                a[i]=k;
                ss=ss+w[k];   ///也可以把这个ss、qq当做参数带进函数中去，
                qq=qq+q[k];
                if (qq>maxq) maxq=qq; //比较最大值
                mysearch(i+1);
                ss=ss-w[k];
                qq=qq-q[k];

            }

}

int main()
{
    cin>>s>>n;
    for(int i=1; i<=n; i++)
    {   cin>>w[i]>>q[i]; q[i]=q[i]*w[i]; }
    a[0]=0;
    mysearch(1);
    cout<<maxq;
}
可不可以加一个剪枝：后面的所有都买齐还不到s就直接全买了？
28.	1*2骨牌覆盖
#include <iostream>
#include <iomanip>
using namespace std;
const int n=4;
int a[n*n];
int t=1;
void mysearch(int i,int s)
{
    if (i==n*n)
    {
        cout<<t++<<":"<<endl;
        for (int j=0; j<=n*n-1; j++)
        {
            cout<<setw(3)<<a[j];
            if (j%n==n-1) cout<<endl;
        }
        cout<<endl;
    }
    else if (a[i]>0)  mysearch(i+1,s);   ///注意和间隔排列的类似
    else
    {
        if ((i%n<=n-2) &&(a[i+1]==0))  //横着摆
        {
            a[i]=a[i+1]=s;
            mysearch(i+2,s+1); //a[i]和a[i+1]都放了骨牌，直接搜索i+2;
            a[i]=a[i+1]=0;
        }
        if ((i/n<=n-2)&&(a[i+n]==0))  //竖着摆
        {
            a[i]=a[i+n]=s;
            mysearch(i+1,s+1);
            a[i]=a[i+n]=0;
        }
    }
}
int main()
{
    mysearch(0,1);
    return 0;
}

29.	因式分解
输出一个数字的分解方法。

int a[10];
void mysearch(int s,int i)
{
    int j,k;
    if (s==1)  //最后一个因子等于1表示在无法分解了
    {
        for (j=1; j<=i-2; j++) cout<<a[j]<<'*';
        cout<<a[i-1]<<endl;
    }
    else
        for (k=a[i-1]; k<=s; k++)   //下一个因子的最小值是前面一个，最大不超过自己
            if (s%k==0)   //能被整除的话
            {
                a[i]=k;
                mysearch(s/k,i+1);   递归到下一个
            }
}
int main()
{
    a[0]=2; mysearch(100,1);
}

30.	跳马问题  
5*5的格子里面 马能否从（1，1）出发跳每个格子一次且仅一次
const int dr[9]= {0,+2,+1,-1,-2,-2,-1,+1,+2};   方向数组  （体会这种写法）
const int dc[9]= {0,+1,+2,+2,+1,-1,-2,-2,-1};
const int n=5;
int a[n+1][n+1];
bool can(int r,int c)   判断能否到达R C点
{
    bool b=true;
    if ((r<1)||(r>n)) b=false;   行超范围
    else if ((c<1)||(c>n)) b=false;  烈超范围
    else if (a[r][c]>0) b=false;     已经被经历过
    return b;
}
void pp()
{
    int ir,ic;
    cout<<s++<<"============"<<endl;
    for (int ir=1; ir<=n; ir++)
    {
        for (int ic=1; ic<=n; ic++)  cout<<setw(3)<<a[ir][ic];
        cout<<endl;
    }

}
void ms(int i,int r,int c)
{
    int d,tr,tc;
    if (i>=n*n) pp();
    else
        for( d=1; d<=8; d++)
        {
            tr=r+dr[d]; tc=c+dc[d];   计算下一个点的位置
            if (can(tr,tc))
            {
                a[tr][tc]=i+1;
                //pp();
                ms(i+1,tr,tc);
                a[tr][tc]=0;
            }
        }
}
int main()
{
a[1][1]=1; ms(1,1,1); //从1,1 这个点开始跳
}

31.	2^100最少要算多少次（DFS）
int a[200],x,y,n,iiii;
bool can(int i,int k) //判断前面i-1个数字中能有某两个数字之和为k
{
    bool bb=false;
    for (int ii=0; ii<=i; ii++)
        for (int jj=0; jj<=i; jj++)
            if (a[ii]+a[jj]==k) bb=true;  //很笨的做法没有优化
    return bb;
}
void dfs(int i)
{
    int j,k;
    if (i>=n) //达到预定的长度就不再往下找了
    {
        if (a[n-1]==x)  //符合要求的话
        {
            for (j=0; j<=n-1; j++) cout<<setw(3)<<a[j];
            cout<<endl;
            n--;  //下次就最大长度减一！！！
        }
    }
    else
        for (k=1+a[i-1]; k<=(2*a[i-1]); k++) // 下一个数字的范围若能由大到小更好
            if (can(i-1,k))
            {
                a[i]=k;
                dfs(i+1);
            }
}
int main()
{
    x=20;
    n=20;//假设最大值要算20次，这个是很保守的。
    a[0]=1; a[1]=2; //前面两个数字没有选择只能是1和2
    dfs(2);//从第三个数字开始搜索
}

32.	2的幂分解 NOIP1998
#include<iostream>
using namespace std;
int n;
void mysearch(int i)
{
    int r,s;
    if (i==1) cout<<"2(0)";///1和2的特殊判断
    else
    {
        s=2;r=0;
        ///找到前面的最大的一个2的幂次方
        while (i>=s)  {s=s*2;r++;}
        if (r==1) cout<<"2"; ///1次方的特殊判断
        else{cout<<"2(";mysearch(r);cout<<')';}
        s=i-s/2;///剩下的那一节再重复
        if (s>0){cout<<'+';mysearch(s);}
    }
}
int main()
{
    ///看看我是怎么样做测试的
    for(n=1; n<100; n++) {mysearch(n);cout<<endl;}
    return 0;
}
33.	老鼠迷宫
寻找从左上到右下的一条路
#include<iostream>
#include<iomanip>
using namespace std;
const int dx[5]={0,1,0,-1,0};
const int dy[5]={0,0,1,0,-1};
int map[9][9]={0,0,0,0,0,0,0,0,0,
               0,1,0,1,1,1,1,1,0,
               0,1,0,1,0,0,0,1,0,
               0,1,0,1,0,0,0,1,0,
               0,1,0,1,0,0,0,1,0,
               0,1,0,1,0,0,0,1,0,
               0,1,1,1,0,0,0,1,0,
               0,0,0,0,0,0,0,0,0,
               0,0,0,0,0,0,0,0,0};
int a[9][9];
void pp()
{   int i,j;
    cout<<"======\n";
    for (i=1;i<=7;i++)
    {
        for(j=1;j<=7;j++) cout <<setw(3)<<a[i][j];
        cout<<endl;
    }

}
//将迷宫的最外圈置为0表明不能走避免每次的比较
void ms(int i,int r,int c)
{   int k,tr,tc;
    if ((r==1)&& (c==7)) pp();
    else for (k=1;k<=4;k++)
    {
        tr=r+dx[k];tc=c+dy[k];
        if ((map[tr][tc]==1)&& (a[tr][tc]==0)){a[tr][tc]=a[r][c]+1;ms(i+1,tr,tc);a[tr][tc]=0;}
    }
}
int main()
{  ms(1,1,1);
}
34.	砝码称重问题
1 3 5 7 9的砝码各一个，称出X克有多少种方法
#include<iostream>
#include<iomanip>
using namespace std;
int a[6]={0,1,7,3,5,9};  //假设有5个砝码分别是1 3 5 7 9克加个假砝码0克
int f[30][6]; //f[x][y] 表示用不超过编号为Y的砝码拼出X克的重量有多少种可能
int g[30];
int i,j;
int main()
{
    for (i=0;i<=5;i++) f[0][i]=1;  //拼出0克显然有1种方法
    for (i=1;i<=5;i++)
        for (j=0;j<=29;j++)
           if (j>=a[i]) f[j][i]=f[j][i-1]+f[j-a[i]][i-1]; //若能用到这个砝码
           else f[j][i]=f[j][i-1];//若不能用到这个砝码

    for (i=1;i<=5;i++)
        {for (j=0;j<=29;j++) cout<<setw(2)<<f[j][i];
         cout<<endl;}

    g[0]=1;
    for (i=1;i<=5;i++)
        for (j=29;j>=a[i];j--) g[j]=g[j]+g[j-a[i]];
    for (i=0;i<=29;i++) cout<<setw(2)<<g[i];

    return 0;
}

35.	最大连续邮资
///有5种邮票面值1,3,5,7,4但是信封最多只能贴4张邮票，请问最小的不能贴出来的是几
#include <iostream>
using namespace std;
const int mm=100; ///显然贴不到100
int k=4,a[6]= {0,1,3,5,7,4};
int cnt[mm];///贴出mm面值最少需要几张邮票
int i,j,x;
int main()
{
    cnt[0]=0;for (i=1; i<=mm-1; i++) cnt[i]=99;  ///初始值
    for (i=1; i<=mm-1; i++)
    {
        for (j=1; j<=5; j++) /// 尝试5种面值
        {
            if(i>=a[j])
                x=cnt[i-a[j]]+1; ///由i-a[j]的方法加一个j得到

            if (x<cnt[i]) cnt[i]=x;
        }
        if (cnt[i]>4) break;///这就是贴出不出来
    }
    for (i=0; i<=mm-1; i++) cout<<cnt[i]<<' ';
    cout<<i;
    return  0;
}

注意和上面那个题的异同！做法原理基本是一样的。
36.	100分成6个数字的和
//100分成6个数字的和
#include <iostream>
#include <iomanip>
using namespace std;
const int maxm=20;  //100太大了 20 来验证
const int maxn=7;//0位作废
int ss;
int a[maxn];
int d[maxm+1][maxn];
int z[7]={0,maxn/6, maxn /5, maxn /4, maxn /3, maxn /2, maxn };  //每个数字的最大值  显然第一个数字不可能超过maxn /6
void mysearch(int i)  //递归的做法
{

    int j,k,s;
    if (i>=maxn-1)
    {
        s=a[1]+a[2]+a[3]+a[4]+a[5];
        a[6]=maxm-s;  //计算出A[6]而不是枚举出a[6]，减少一次递归，
        if (a[6]>=a[5])
        {cout<<setw(5)<<++ss<<':';for (j=1; j<=maxn-1; j++) cout<<a[j]<<' ';
        cout<<endl;}
    }
    else for (k=a[i-1]; k<=z[i]; k++)   {a[i]=k;mysearch(i+1);}

}
void pp()
{
    int i,j;
    cout<<"=====================\n";
    for (j=0;j<=6;j++)
    {for (i=0;i<=21;i++) cout<<setw(4)<<d[i][j];cout<<endl;}
}
int dp(int m,int n) //动态规划的做法
{   int i,j,k;
    for(i=1;i<=maxm;i++) {d[i][1]=1; //任何数字分成1个数字有一种做法；
    d[i][2]=i/2;}//任何数字分成2个数字有i/2种做法；
    for(i=2;i<=maxm;i++)
        for(j=2;j<=maxn-1;j++)
           if (i>=j) d[i][j]=d[i-1][j-1]+d[i-j][j];  //这个公式要认真思考！！！
    /*把100分成6份等价于两种分法的和
    1、99分成5份，最后加一份1
    2、95分成6份，每份加上1
    这两种分法之间没有重复，并且加起来覆盖了全部  */

    return d[m][n];
}
int main()
{
    a[0]=1;mysearch(1);
    cout<<dp(20,6);
    pp();
}
37.	约数最多
//求10^5内谁的约数最多
#include<iostream>
using namespace std;
int n;
int p[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}; //前7个质数的乘积已经大于10^5说明不可能有超过7个质因子
long long   maxs=1; //约数最多的那个数
int maxk=0;//最多的约数个数
void mysearch(int i,long  long s,long long  j,long long  k)
 //i表示深度（搜索到了第几个质因子）
 //s表示当前因子最多的那个数字
 //j表示最多含有多少个第i层的因子
 //k表示当前最多因子的个数
{
    int jj;
    if(i>=9) return;
    if (k>maxk){maxs=s;maxk=k; cout<<maxs<<' '<<maxk<<endl;}
    for (jj=1;jj<=j;jj++)
    {
        s=s*p[i];
        if (s<=n) mysearch(i+1,s,jj,k*(jj+1));
    }
}
int main()
{
   n=100000;
   mysearch(0,1,30,1);
   cout<<maxs<<' '<<maxk;
}
38.	生日蛋糕NOI99
做一个表面积nπ的m层的蛋糕，要求上面一层比下面一层底面半径小，高度矮。求最小的表面积。

int n,m;
int res=99999999;

bool check(int dep,int r,int h,int v,int s)
{
    int maxv=0,mins=0,minv=0;
    for(int i=1; i<=dep; i++)
    {
        maxv+=(r-i)*(r-i)*(h-i); ///最大体积 做一个大柱子
        mins+=2*i*i;  ///最小表面积
        minv+=i*i*i;///最小体积 做一个小柱子
    }
    bool b1,b2,b3;
    b1=(v+minv<=n);
    b2=(v+maxv>=n);
    b3=(s+mins<=res);
    return (b1&&b2&&b3);
    ///return 1;
}

void dfs(int dep,int r,int h,int v,int s)
///dep现在是第几层 r,h这层的半径和高度 v s到现在为止的体积和表面积
{
    ///cout<<dep<<' '<<r<<' '<<h<<' '<<v<<' '<<s<<endl;
    if(dep==0)
    {
        ///cout<<v<<' '<<s<<endl;
        if(v==n) if (s<res) res=s;
    }
    else if( check(dep,r,h,v,s) )
        for(int ih=h-1; ih>=dep; ih--)   ///枚举高度
            for(int ir=r-1; ir>=dep; ir--)  ///枚举底面半径
                dfs(dep-1,ir,ih,v+ir*ir*ih,s+2*ir*ih);
}

int main()
{
    cin>>n>>m;
    for(int h=m; h<=n; h++)
        for(int r=m; h*r*r<=n; r++)
            dfs(m-1,r,h,r*r*h,2*r*h+r*r);
    if(res==99999999) res=0;
    cout<<res;
    return 0;
}

39.	奇怪的数列
递增序列，第一个元素是1，后面的每个数都是前面某个数的2X+1或者3X+2，求第100个数
#include<iostream>
using namespace std;
const int mm=10000;
int a[mm];
int head,tail;
bool b;
int x,x1,x2,i,j;
int main()
{
    a[0]=1;
    head=tail=0;
    b=true;
    while (b && (head<=tail) && (tail<=mm-100))
    {
        x=a[head];
        x1=2*x+1;
        ///找head和tail之间那个数字>=x1
        ///=就不管了 >就将此数字以及后面的数字挪一位，腾个空间给ｘ１
        i=tail;
        while (a[i]>x1) i--;  ///隐含一个条件a[head]<x
        if (a[i]<x1)
        {
            for (j=tail; j>=i+1; j--) a[j+1]=a[j];  ///挪出空间
            a[i+1]=x1;tail++; ///进队列
        }
        x2=3*x+2;
        i=tail;
        while (a[i]>x2) i--;
        if (a[i]<x2)
        {
            for (j=tail; j>=i+1; j--) a[j+1]=a[j];
            a[i+1]=x2;tail++;
        }
        head++;
        if (head>=100) b=false;    ///只要找到前100项
    }
    if (!b) for (i=0; i<=99; i++ ) cout<<a[i]<<' ';
}
40.	2^N最少多少次BFS
#include<iostream>
using namespace std;
const int mm=10010; // 最多搜索多少个节点
int a[10][mm],l[mm];
int  head,tail;
int aa[10],la;
bool b;
int i,k,kk;
void printout(int i)
{
    int j;
    cout<<i<<':';
    for (j=0; j<=9; j++) cout<<a[j][i]<<' ';
    cout<<' '<<l[i];
    cout<<endl;
}
bool can(int i,int j)   ///i 能不能出现在第j位
{
    int  i1,i2;
    bool b=false;
    for (i1=0; i1<=j-1; i1++)
        for (i2=0; i2<=j-1; i2++)
            if (aa[i1]+aa[i2]==i) b=true;
    return b;
}
int main()
{
    head=tail=0;
    a[0][head]=1;
    a[1][head]=2;
    l[0]=1;  ///首元素显然是[1,2]
    b=false; /// 表示没有找到
    while ((!b) && (tail>=head) && (tail<=mm-100))
    {
        for (i=0; i<=9; i++) aa[i]=a[i][head];
        la=l[head];///取出头元素
        kk=a[la][head];
        ///printout(head);
        for (k=kk+1; k<=kk*2; k++)  ///按规则生儿子
            if (can(k,la+1))  ///符合条件进队列
            {
                tail++;/// 写进去
                for (i=0; i<=9; i++) a[i][tail]=aa[i];
                a[la+1][tail]=k;
                l[tail]=la+1;
                ///printout(tail);  一般在这里加调试
                if (a[la+1][tail]==10)
                {
                    b=true;
                    break;
                }
            }
        head++;
    }
    if (b) for (i=0; i<=la+1; i++) cout<<a[i][tail];
    else if (tail<head) cout<<"No Answer!";
    else if (tail>mm-100) cout<<"cannot found!";
    return 0;
}
41.	贴邮票
给定一个信封，最多只允许粘贴N张邮票，计算在给定K（N+K≤15）种邮票的情况下（假定所有的邮票数量都足够），如何设计邮票的面值，能得到最大值MAX，使在1～MAX之间的每一个邮资值都能得到。

例如，N=3，K=2，如果面值分别为1分、4分，则在1分～6分之间的每一个邮资值都能得到（当然还有8分、9分和12分）；如果面值分别为1分、3分，则在1分～7分之间的每一个邮资值都能得到。可以验证当N=3，K=2时，7分就是可以得到的连续的邮资最大值，所以MAX=7，面值分别为1分、3分。
【思路】没有别的好方法，只能用搜索，那么回忆一下搜索设计框架：
void dfs(int i)  典型的m个中选k个的搜索框架
{
    int  j,temp=getmax(i-1);
    if (i>k)
    {
        if (temp>maxs)  {maxs=temp;    for (int ii=0; ii<=9; ii++) b[ii]=a[ii];}
    }
    Else for (j=a[i-1]+1; j<=temp+1; j++) {a[i]=j;dfs(i+1);}
}
但是这里加了一点剪枝，temp=getmax(i-1)求出前面i-1张邮票能贴出的最大值，最后一张邮票的面值显然在a[i-1]+1和temp+1之间，每次还更新temp
getmax执行的次数很多，这里要高效地设计，否则程序会超时，我也多次说过，目前考试中搜索最重要的都是剪枝，我们用类似背包的递推方式来求getmax
int getmax(int l)
{
    int i,j,p,q,r  ;
    for (i=2; i<=999; i++)
    {
        r=s[i-1]+1;//任何一种面值均可以由前面一个加上一张一分的
        j=2;  //从第二个邮票面值开始试
        p=i-a[j];  //假定由i-a[j]+当前的面值贴出
        while ((p>=0)&&(j<=l))
        {
            q=s[p]+1;  //如此贴出
            if (r>q) r=q;//检测最小
            j++; p=i-a[j];
        }
        s[i]=r; if (s[i]>n)  break;
    }
    return i-1;
}
两个一结合，程序就完美解决了。


42.	最长不下降序列

#include<iostream>
#include<iomanip>
using namespace std;
int a[11]= {0,1,7,3,5,9,2,8,6,4,99}; //假设有9个数字分别是1,7,3,5,9,2,8,6,4，第一个位子空着，最后一个是假标记
int l[11]; //到当前为止的最长不下降序列的长度
int f[11]; //当前最优决策时的前驱的编号
int p[11];//输出路径时用的数组
int i,j;
int main()
{
    for (i=0; i<=10; i++)
    {
        l[i]=1;  //至少的长度是1
        f[i]=-1; //不需要前驱
    }

    for(i=2; i<=10; i++) ///枚举当前位置
        for (j=1; j<i; j++) ///枚举当前位置前面的所有可能
            if (a[j]<=a[i])  ///不下降
                if (l[j]+1>=l[i])        ///最长
                {
                    l[i]=l[j]+1;  ///决策
                    f[i]=j;       ///记录前驱
                }

    for (i=0; i<=10; i++)
        cout<<setw(4)<<a[i];
    cout<<endl;
    for (i=0; i<=10; i++)
        cout<<setw(4)<<l[i];
    cout<<endl;
    for (i=0; i<=10; i++)
        cout<<setw(4)<<f[i];
    cout<<endl;
    i=0;
    p[i]=10; ///最后一个绝对是最长的
    while (f[p[i]]!=-1)  ///还有前驱
    {
        i++;
        p[i]=f[p[i-1]];
    }

    for (j=i; j!=-1; j--) cout<<a[p[j]]<<' '; ///输出最后的路径
    return 0;
}

43.	最长公子序列
#include<iostream>
#include<iomanip>
using namespace std;
char a[12]="0ABCDEFGHIJ";  ///字符串的第一个位子被废掉了
char b[12]="0ACEGIBDFHJ";
int f[11][11];
char c[11];
int i,ia,ib;
int main()
{
    for (ia=1; ia<=10; ia++)
        for (ib=1; ib<=10; ib++)
            if (a[ia]==b[ib])   //两个字符相同的话都加1
            {
                f[ia][ib]=f[ia-1][ib-1]+1;
                c[f[ia][ib]]=a[ia];
            }
            else if (f[ia-1][ib]>f[ia][ib-1])  //不相同的话都找最大的那个
                f[ia][ib]=f[ia-1][ib];
            else
                f[ia][ib]=f[ia][ib-1];

    cout<<f[10][10]<<':';
    for (i=1; i<=f[10][10]; i++) cout<<c[i];

}

44.	经典背包
#include<iostream>
#include<iomanip>
using namespace std;
int w[5]= {0,1,3,5,8}; //假设有5个砝码重量分别是1 3 5 7 9克加个假砝码0克
int v[5]= {0,10,20,155,100}; //假设有5个砝码价值
int f[105][5]; //f[x][y] 表示重量不超过x时最大的价值
int g[105];
int i,j;
int t1,t2,t;
int main()
{
    cout<<"\n========way1=========\n";

    for(i=1; i<=4; i++)
        for (j=0; j<=100; j++)
        {
            if (j>=w[i])  ///这样写很清晰吧！虽然效率低了点
            {
                t1=f[j-w[i]][i-1]+v[i];
                t2=f[j][i-1];
                t=max(t1,t2);
            }
            else t=f[j][i-1];
            f[j][i]=t;
        }

    for (i=1; i<=4; i++)
    {

        for (j=0; j<=15; j++) cout<<setw(4)<<f[j][i];
        cout<<'\n';
    }


    cout<<"\n========way2=========\n";
    g[0]=0;
    for (i=1; i<=4; i++)
        for (j=100; j>=w[i]; j--)   ///注意方向
        {
            if (j>=w[i])
            {
                t1=g[j-w[i]]+v[i];
                t2=g[j];
                t=max(t1,t2);
            }
            g[j]=t;
        }
    for (j=0; j<=23; j++) cout<<setw(4)<<g[j];

    return 0;
}

45.	连续最大和
#include<iostream>
using namespace std;
const int mm=11;
int a[mm]= {0,1,2,3,-4,5,-6,7,9,-8,10};  ///第0位闲置
int way1()
{
    int i,j,k,s,m=0;
    for (i=1; i<=mm-1; i++)
        for (j=i; j<=mm-1; j++)
        {
            s=0;
            for (k=i; k<=j; k++)
                s+=a[k];
            if (s>m) m=s;
        }
    return m;
}
int way2()
{
    int sum[mm]= {0}; ///前缀和
    int i,j,x,m,ms;
    for (i=1; i<=mm-1; i++) sum[i]=sum[i-1]+a[i];
    for (i=0; i<=mm-1; i++)
    {
        ms=sum[i];
        for (j=i+1; j<=mm-1; j++)   ///后面找最大的
            if (sum[j]>ms) ms=sum[j];
        x=ms-sum[i];
        if (x>m)m=x;
    }
    return m;
}
int way4()
{
    int s=0,m=0;
    for (int i=1; i<=mm-1; i++)
    {
        s+=a[i];
        if (s<0) s=0;
        if (s>m) m=s;
    }
    return m;
}
int main()
{
    cout<<way1()<<endl;
    cout<<way2()<<endl;
///    cout<<way3()<<endl;
    cout<<way4()<<endl;
}
46.	全排列的下一个
#include <iostream>
using namespace std;
const int mm=6+1;  ///6个数字
int a[mm]= {0,1,2,3,4,5,6};
int * nxt(int a[])
{
    int *temp=new int[mm];
    int i=mm-1,j;
    while (a[i]<a[i-1] && i>=1) i--;
     ///第一位永远是0， 所以i>=1也可以不要
    i--;
    ///cout<<'i'<<i<<' ';
    if (i==0)   ///到了首位，说明已经没有下一个
    {
        for ( j=1; j<=mm-1; j++) temp[j]=0;
    }
    else
    {
        int m=99,k=i;
        for (j=i+1;j<=mm-1;j++)  ///在后面找比他大的最小数字
          if ((a[j]>a[i])&&(a[j]<m)) {m=a[j];k=j;}
          ///cout<<k<<' '<<a[k]<<endl;
        swap(a[i],a[k]);  ///交换
        for ( j=i+1,k=mm-1;j<k;j++,k--) swap(a[j],a[k]);
        ///原地颠倒的技巧
        temp=a;
    }
    return temp;
}
int main()
{
    int *b;b=a;
    for (int i=1; i<=720; i++)
    {
        b=nxt(b);for (int j=1; j<=6; j++) cout<<b[j]<<' ';
        cout<<endl;
        delete []b;
    }
}

/*
[1]从右往左寻找第一个小于右边的数，设其位置为j
[2]在j位置的右边寻找大于a[j]的最小数字a[k]，位置k
[3]将a[j]与a[k]的值进行交换
[4]将数列的j+1位到n位倒转。
原排列：a[1] a[2] a[3]…….a[j] a[j+1]……..a[k] a[k+1]…….....a[n-1] a[n]
新排列：a[1] a[2] a[3]…… a[k] a[n] a[n-1]..…a[k+1] a[j] a[k-1]…..a[j+1]
*/
47.	全排列的第N个
#include <iostream>
using namespace std;
const int mm=6+1;  ///9个数字
int  fac[mm];
int a[mm]; ///待求
int c[mm]; ///第i位记录着后面有几个比a[i]小的数
int i;
int getn(int a[])  ///求a是第几个
{
    int i,j,s=0;
    for(i=1; i<=mm-1; i++) c[i]=0;
    for(i=1; i<=mm-2; i++)  ///统计i后面有多少个比a[i]小的数
        for (j=i+1; j<=mm-1; j++)
            if (a[i]>a[j]) c[i]++;

    for(i=1; i<=mm-1; i++) s+=c[i]*fac[mm-1-i];
    return s;
}
int * geta(int n)  ///求n对应的排列是什么
{
    int *temp=new int[mm];
    int i,k;
///求出c数组
    n--;///和我们计数法统一
    for (i=1; i<=mm-1; i++)  ///求出c[i]，类似进制转换
    {
        c[i]=n/fac[mm-1-i];
        n%=fac[mm-1-i];
    }
    for (i=1; i<=mm-1; i++) cout<<c[i]<<' ';
    cout<<endl;
    k=1;
    while (k<=mm-1)
    {
        i=1;while (c[i]!=0) i++;///找到第一个为0的元素
        temp[i]=k++;///就是当前的数
        for (int j=0; j<=i; j++) c[j]--;  ///前面的所有都减1！！！
    }

    return temp;
}

int main()
{
    int *b;
    fac[0]=1;for (i=1; i<=9; i++) fac[i]=fac[i-1]*i;
    for (i=1; i<=720; i++)
    {
        cout<<i<<endl;
        b=geta(i);

        for(int j=1; j<=mm-1; j++) cout<<b[j]<<' ';
        cout<<getn(b)<<endl;  ///体会这种对拍的技术
    }
}
48.	Dijistra最短路径
#include<iostream>
using namespace std;
const int inf=2147483647;
const int mm=500050;  ///最多的边数
const int mn=10010; ///最多顶点
int n,m,s;
int nbs[mn],nxt[mm],ev[mm],ew[mm]; ///邻接表
int dist[mn];  ///src到每个点的最短路径长度
int vist[mn];  ///此点是否被标记
int p[mn];   ///最短路从何而来

int getmin()
{
    int m,k,i;
    m=inf;
    k=0;  ///起点，无路可找的时候就返回0
    ///for (i=1;i<=n;i++)  cout<<dist[i]<<' '; cout<<endl;
    for (i=1; i<=n; i++)
        if (!vist[i])
            if (dist[i]<m)
            {
                m=dist[i];
                k=i;
            }
    return k;
}

void dijkstra(int src)
{
    int i,j,u,v;
    for(i=1; i<=n; i++)
    {
        dist[i]=inf;
        vist[i]=0;
    };
    dist[src]=0;
    while(1)  ///因为是找所有的路，所以这个和标准写法有点不一样
    {
        u=getmin();
        if (u==0) return ;  ///靠这句话终结程序
        vist[u]=1;
        for(j=nbs[u]; j!=0; j=nxt[j])
        {
            v=ev[j];
            if(!vist[v]&&dist[u]+ew[j]<dist[v])  更新与v相连的边
            {
                dist[v]=dist[u]+ew[j];   
                p[v]=u;
            }
        }
    }
}
void printpath(int i)///反推路径找到S到I的路
{
    int path[mn]={i,}; ///初始终点
    int j=0,k=i;
    while (p[k]!=0)  ///完全类似导弹飞机的倒推
    {
        j++;
        path[j]=p[k];
        k=p[k];
    }
    cout<<s<<"-->"<<i<<':';
    for (; j>=0; j--) cout<<path[j];
    cout<<endl;
}
int main()
{
    int i,u,v,w;
    cin>>n>>m>>s;
    for(i=1; i<=n; i++)nbs[i]=0;
    for(i=1; i<=m; i++)
    {
        cin>>u>>v>>w;
        nxt[i]=nbs[u];
        nbs[u]=i;
        ev[i]=v;
        ew[i]=w;///无向图的话要做两次
    }
    dijkstra(s);
    for (i=1; i<=n; i++)  cout<<dist[i]<<' ';
    ///cout<<endl;
    ///for (i=1; i<=n; i++)  printpath(i);
    return 0;
}
49.	SPFA最短路径
USACO 热浪
const int inf=9999999;
int g[2600][2600];
int n;  //表示n个点，从1到n标号
int s,t;  //s为源点，t为终点
int d[2600];  //d[i]表示源点s到点i的最短路
int p[2600];  //记录路径（或者说记录前驱）
int c[2600];  //统计次数
int q[99999],head,tail;  //模拟队列一个队列
bool vis[2600];   //vis[i]=1表示点i在队列中 vis[i]=0表示不在队列中

int main()
{
    int T, C, Ts, Te, rs, re, ci;
    int i,j,k;
    cin >> T >> C >> Ts >> Te;

    for (i=1; i<=T; i++)
        for (j=i; j<=T; j++)
            g[i][j]=g[j][i]=inf;


    for (i = 1; i <= C; i++)
    {
        cin >> rs >> re >> ci;
        ///注意邻接矩阵做题时候的这个！！！
        if (ci<g[rs][re]) g[rs][re]= g[re][rs] = ci;
    }

    for (i=1; i<=T; i++)
    {d[i]=inf;c[i]=0;vis[i]=0; }
    d[Ts]=0;vis[Ts]=1;c[Ts]=1;   ///起点初始
    head=tail=1;q[head]=Ts;
    //顶点入队vis要做标记，另外要统计顶点的入队次数
    int OK=1;
    while((tail>=head) && (tail<=99990) && OK)
    {
        int x=q[head];
        head++;
        vis[x]=0;     //队头元素出队，并且消除标记
        for(int k=1; k<=T; k++) //遍历与顶点x的相连的点
        {
            int y=g[x][k];
            if( d[x]+y < d[k])
            {
                d[k]=d[x]+y;  //松弛
                if(!vis[k])  //顶点y不在队内
                {
                    vis[k]=1;    //标记
                    //cout<<k<<' ';
                    c[k]++;      //统计次数
                    tail++;q[tail]=k;   //入队
                    if(c[k]>T)  //超过入队次数上限，说明有负环
                        OK=0;
                }
            }
        }
    }
    if (OK) cout<<d[Te];return 0;
}
50.	FLOYD最短路径
for(k=1; k<=n; k++)
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if (a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j];
邻接表注意初值情况
