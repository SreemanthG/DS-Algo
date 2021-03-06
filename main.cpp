#include<iostream>
#include<cstring>
#include<cmath>
#include<climits>
#include<string>
#include<algorithm>
#include<set>
#include<list>
#include<stack>
#define ll long long int
//#include<bits/stdc++.h> - includes every library

using namespace std;

bool p[1000001]={false};
char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
ll coins[40];
int ans=0;

class Student
{
public:
    string name;
    int marks;
};

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};

class Stack{
private:
    vector<int> v;
public:
    void push(int d)
    {
        v.push_back(d);
    }
    bool isEmpty()
    {
        return v.size()==0;
    }
    void pop()
    {
        if(!isEmpty())
            v.pop_back();
    }
    int top()
    {
        return v[v.size()-1];
    }
};

void input_array(int a[], int n)
{
    for(int i=0;i<n;i++)
        cin>>a[i];
}

void input_2d_array(int a[][100], int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }

}

void display_2d_array(int a[][100], int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void display_array(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int linear_searchit(int a[], int n, int k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
            return i+1;
    }
    return -1;
}

int binary_searchit(int a[], int n, int k)
{
    int m,s=0,e=n-1;
    while(s<=e)
    {
        m=(s+e)/2;
        if(a[m]==k)
            return m+1;
        else if(a[m]<k)
            s=m+1;
        else
            e=m-1;
    }
    return -1;
}

void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        for(int j=i; j<n; j++)
        {
            if(a[min_index]>a[j])
                min_index = j;
        }
        swap(a[i],a[min_index]);
    }
}

void bubble_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

void insertion_sort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        int e=a[i];

        while(j>=0 && e<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=e;
    }
}

void subarray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
                cout<<a[k]<<",";
            cout<<endl;
        }
    }
}

void subarray_max_sum1(int a[],int n)
{
    int max=INT_MIN,s=0,left=-1,right=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {   s=0;
            for(int k=i;k<=j;k++)
                s+=a[k];
            if(s>max)
                {
                    max=s;
                    left=i;
                    right=j;
                }
        }
    }
    for(int k=left;k<=right;k++)
        cout<<a[k]<<",";
    cout<<endl<<"max="<<max<<endl;
}

void subarray_max_sum2(int a[],int n)
{
    int b[n]={0},max=INT_MIN,s=0,left=-1,right=-1;
    b[0]=a[0];b[-1]=0;
    for(int i=1;i<n;i++)
        b[i]=b[i-1]+a[i];

    for(int i=0;i<n;i++)
        cout<<b[i]<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {   s=0;
            s=b[j]-b[i-1];
            if(s>max)
                {
                    max=s;
                    left=i;
                    right=j;
                }
        }
    }
    for(int k=left;k<=right;k++)
        cout<<a[k]<<",";
    cout<<endl<<"max="<<max<<endl;
}

void subarray_max_sum3(int a[],int n)
{
    int maxi=INT_MIN,s=0;
    for(int i=0;i<n;i++)
    {
        s=s+a[i];
        if(s<0) s=0;
    }
    maxi=max(maxi,s);
    cout<<"Maximum Sum = "<<maxi<<endl;
}

void two_pointer_approach(int a[],int n)
{
    int i=0,j=n-1,s=0;
    int f;
    cout<<"Enter the sum to be found : ";
    cin>>f;
    while(i<j)
    {   s=a[i]+a[j];
        if(s<f)
            i++;
        else if(s>f)
            j--;
        else
        {
            cout<<a[i]<<"+"<<a[j]<<"="<<f<<endl;
            i++;j--;
        }
    }
}

bool char_array_palindrome(char a[])
{
    int j=strlen(a)-1;
    int i=0;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

void remove_duplicate(char a[])
{
    int i=0,j=1;
    while(a[j]!='\0')
    {
        if(a[i]==a[j])
            j++;
        else
            a[++i]=a[j];
    }
    a[++i]='\0';
    cout<<a<<endl;
    return;
}

int kadenceAlgo(int a[],int n)
{
	int cs=0,ms=0;
	for(int i=0;i<n;i++)
	{
		cs += a[i];
		if(cs<0)cs=0;
		ms=max(cs,ms);
	}
	return ms;
}

int maxSum(int a[],int n)
{
	int totalSum=0;
	int max1=kadenceAlgo(a,n);

	for(int i=0;i<n;i++)
	{
		totalSum += a[i];
		a[i] = -a[i];
	}

	int max2=totalSum+kadenceAlgo(a,n);

	return max(max1,max2);
}

int bitonic(int arr[], int n)
{
    int inc[n],dec[n];
    int i, max;

    inc[0] = 1;
    dec[n-1] = 1;

    for (i = 1; i < n; i++)
        inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;

    for (i = n-2; i >= 0; i--)
        dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;

    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
       {
           if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;
       }
    return max;
}

bool comparator27(string a,string b)
{
	string p=a+b,q=b+a;
	if(p>q)
		return true;
	else
		return false;
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n)
{
    int res[1000];
    res[0] = 1;
    int res_size = 1;
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}

char* mystrtok(char* str)
{
    static char* input = NULL;
    if (str != NULL) {
        input = str;
    }

    // Base case
    if (input == NULL)
        return NULL;

    // Array for storing tokens
    // +1 is for '\0'
    char* output = new char[strlen(input + 1)];

    int i = 0;

    // Storing the upper case character
    output[i] = input[i];

    i++;

    // Generating Tokens
    for (; input[i] != '\0'; i++) {
        if (!isupper(input[i]))
            output[i] = input[i];
        else {
            output[i] = '\0';
            input = input + i;
            return output;
        }
    }

    output[i] = '\0';
    input = NULL;
    return output;
}

void extractWords(char* s)
{

    // Extract 1st word and print it
    char* ptr = mystrtok(s);
    cout << ptr << endl;

    // Extract the remaining words
    while (ptr != NULL) {
        ptr = mystrtok(NULL);
        cout << ptr << endl;
    }
}

bool pal(char ch[],int i, int j)
{
	if(i>=j)
		return true;
	if(ch[i]!=ch[j])
		return false;
	return pal(ch,i+1,j-1);
}

int cMax(string s, int l, int k, char ch)
{
	int i=0,j=0,c=0,ans=0;
	for(;j<l-1;j++)
	{
		if(s[j]!=ch)
			c++;
		if(c==k)
			break;
	}
	while(i<j)
	{
		while(j<l-1 && s[j+1]==ch)
			j++;
		int cs=j-i+1;
		ans=(cs>ans)?cs:ans;
		i++;
		if(j<l-1 && s[i-1]!=ch)
			j++;
	}
	return ans;
}

long stoint(string s)
{
    long i,j=0;
    i = 0;
    while(s[j] >= '0' && s[j] <= '9')
    {
        i = i * 10 + (s[j] - '0');
        j++;
    }
    return i;
}

bool is_cb_number(string s)
{
    long long num = stoint(s);
    if (num == 0 || num == 1) {
        return false;
    }
    int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num == arr[i]) {
                return true;
            }
        }
        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
            if (num % arr[i] == 0) {
                return false;
            }
        }
    return true;
}

bool is_valid(bool * visited, int l, int r)
{
    for(int i=l;i<r;i++)
    {
        if(visited[i])
        {
            return false;
        }
    }
    return true;
}

bool compare39(int a, int b)
{
    return a<=b;
}

bool sort_sec(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}

int square_root(int n)
{
    int s=0,e=n,ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        int m=mid*mid;
        if(m==n)
            return mid;
        else if(m<n)
        {
            ans = mid;
            s=mid+1;
        }
        else
            e=mid-1;
    }
    return ans;
}

bool canPlaceCows(int a[], int n, int c, int min_step)
{
    int last_cow = a[0];
    int cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(a[i]-last_cow >= min_step)
        {
            last_cow=a[i];
            if(++cnt>=c)            //It should be greater than equal to here
                return true;
        }
    }
    return false;
}

bool isPossible(int a[],int n, int m, int curr_min)
{
    int s=1;
    int read=0;
    for(int i=0;i<n;i++)
    {
        if(read+a[i]>curr_min)
        {
            s++;
            read=a[i];
            if(s>m)
                return false;
        }
        else
            read+=a[i];
    }
    return true;
}

int findPage(int a[], int n, int m)
{
    int ans=INT_MAX,e;
    for(int i=0;i<n;i++)
        e+=a[i];
    int s=a[n-1];
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(isPossible(a,n,m,mid))
        {
            e=mid-1;
            ans=min(ans,mid);
        }
        else
            s=mid+1;
    }
    return ans;
}

bool CanCookPrata(int cookRank[],int n,int time ,int P){

    int PrataMade=0;
    for(int i=0;i<n;i++){
        int t=0;//time
        int j=1;//multiplier
        int r=cookRank[i];
        while(t<time){
            t+=(r*j);
            if(t<=time)PrataMade++;
            if(PrataMade>=P)return true;
            j++;
        }
    }
    return false;

}

void solveThis()
{
    int p,c;
    cin>>p>>c;
    int r[c],ans=0;
    for(int i=0;i<c;i++)
        cin>>r[i];
    int s=1,e=((p*(p+1))/2)*8;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(CanCookPrata(r,c,mid,p))
        {
            ans = mid;
            e=mid-1;
        }
        else
            s=mid+1;
    }
    cout<<ans<<endl;
    return;
}

bool canGetScholarship(long int n, long int m, long int x, long int y, long int mid)
{
	if(mid*x<=m+(n-mid)*y)
		return true;
	return false;
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void bitOddOrEven(int n)
{
    if(n&1==1)//if n=5 then n=101 & 1 changes to 001
        cout<<"odd"<<endl;
    else
        cout<<"even"<<endl;
}

int getBit(int n, int i)
{
    int mask = (1<<i);
    int b = ((n&mask)>0)? 1 : 0;// n=5 and  i=1 then 101 & 010
    return b;
}

int setBit(int n, int i)
{
    int mask =(1<<i);
    int ans = (n|mask);
    return ans;
}

int clearBit(int n, int i)
{
    int mask = ~(1<<i);
    int ans = n&mask;
    return ans;
}

int updateBit(int n, int i, int m)
{
    int ans = clearBit(n,i);
    ans = ans|(m<<i);
    return ans;
}

int clearLastBits(int n, int i)
{
    int mask = (-1<<i);
    return (n&mask);
}

int clearRangeBits(int n, int i, int j)
{
    int ones=(~0);
    int a = ones<<(j+1);
    int b = ~(ones<<i);
    int mask = a|b;
    return (n&mask);
}

void subset(char c[],int n)
{
    int j=0;
    while(n>0)
    {
        int last_bit=(n&1);
        if(last_bit==1)
            cout<<c[j];
        j++;
        n=n>>1;
    }
    cout<<endl;
    return;
}

void primeSieve(int p[],int n)
{
    for(int i=3;i<=n;i+=2)
        p[i]=1;
    for(int i=3;i<=n;i+=2)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
                p[j]=0;
        }
    }
    p[2]=1;
    p[0]=p[1]=0;
    return;
}

int gcd(int a,int b)
{
	return (b==0)?a:gcd(b,a%b);
}

int pow_mod(int a,int b,int c)
{
	long long ans=1;
	while(b>0)
	{
		ans=ans*a;
		ans=ans%c;
		b--;
	}
	return ans;
}

long long int modpowIter(long long int a, long long int b, long long int c) {
        long long int ans=1;
        while(b != 0) {
                if(b%2 == 1)
                        ans=(ans*a)%c;

                a=(a*a)%c;
                b /= 2;
        }
        return ans;
}

void primeSieveNew(bool p[], int n)
{
	for(int i=3;i<=n;i=i+2)
		p[i]=true;
	for(int i=3;i*i<=1000000;i++){
		if(p[i]){
			for(int j=i;j*i<=1000000;j++) p[i*j]=false;
		}
	}
	return;
}

int countPrimes(int a, int b)
{
	int c=0;
	for(int i=a;i<=b;i++)
	{
		if(p[i])
			c++;
	}
	return c;
}

int recFact(int n)
{
    if(n==0)
        return 1;
    return n*recFact(n-1);
}

int recFib(int n)
{
    if(n==0 or n==1)
        return n;
    return recFib(n-2)+recFib(n-1);
}

void recInc(int n)
{
    if(n==0)
        return;
    recInc(n-1);
    cout<<n<<" ";
}

void recDec(int n)
{
    if(n==0)
        return;
    cout<<n<<" ";
    recDec(n-1);
}

bool recSort(int a[],int n)
{
    if(n==1)
        return true;
    if(a[0]<a[1] and recSort(a+1,n-1))
        return true;
    return false;
}

int recBinarySearch(int a[], int s,int e, int key)
{
    if(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
            return mid;
        if(a[mid]>key)
            return recBinarySearch(a,s,mid-1,key);
        else
            return recBinarySearch(a,mid+1,e,key);
    }
    return -1;
}

int recPower(int a, int n)
{
    if(n==1)
        return a;
    return a*recPower(a,n-1);
}

int recMul(int a, int n)
{
    if(n==1)
        return a;
    return a+recMul(a,n-1);
}

int linearSearch1(int a[],int n,int key)
{
    if(n==0)
        return 0;
    if(a[0]==key)
        return 0;
    int i = linearSearch1(a+1,n-1,key);
    if(i==-1)
        return -1;
    return i+1;
}

int linearSearch2(int a[],int i,int n,int key)
{
    if(i==n)
        return -1;
    if(a[i]==key)
        return i;
    return linearSearch2(a, i+1, n, key);
}

int lastOccurence(int a[],int n,int key)
{
    if(n==0)
        return -1;
    int i = lastOccurence(a+1,n-1,key);
    if(i==-1)
    {
        if(a[0]==key)
            return 0;
        else
            return -1;
    }
    return i+1;
}

void allOccurence(int a[],int i, int n,int key)
{
    if(n==0)
        return;
    if(a[0]==key)
        cout<<i<<",";
    allOccurence(a+1,i+1,n-1,key);
}

int allStoredOccurence(int a[],int i, int n,int key,int b[],int j)
{
    if(n==0)
        return j;
    if(a[i]==key)
        b[j++]=i;
    allStoredOccurence(a,i+1,n-1,key,b,j);
}

void recBubbleSort(int a[],int n,int j)
{
    if(n==1)
        return;
    if(j==n-1)
        return recBubbleSort(a,n-1,0);
    if(a[j]>a[j+1])
        swap(a[j],a[j+1]);
    recBubbleSort(a,n,j+1);
    return;
}

void mergeThem(int a[],int s,int e)
{
    int mid=(s+e)/2;
    int t[100],i=s,j=mid+1,k=s;
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
            t[k++]=a[i++];
        else
            t[k++]=a[j++];
    }
    while(i<=mid)
        t[k++]=a[i++];
    while(j<=e)
        t[k++]=a[j++];
    for(int i=s;i<=e;i++)
        a[i]=t[i];
}

void mergeSort(int a[],int s,int e)
{
    if(s>=e)
        return;
    int mid=(s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    mergeThem(a,s,e);
}

int inversionMerge(int a[], int s, int e)
{
    int mid=(s+e)/2;
    int c=0,i=s,k=s,j=mid+1,temp[100];
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;i++;
        }
        else
        {
            c+=mid-i+1;
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=e)
        temp[k++]=a[j++];
    for(int i=s;i<=e;i++)
        a[i]=temp[i];
    return c;
}

int inversionCount(int a[],int s,int e)
{
    if(s>=e)
        return 0;
    int mid=(s+e)/2;
    int x=inversionCount(a,s,mid);
    int y=inversionCount(a,mid+1,e);
    int z=inversionMerge(a,s,e);
    return x+y+z;
}

int part(int a[],int s,int e)
{
    int p = a[e],i=s-1;
    for(int j=s;j<=e-1;j++)
    {
        if(a[j]<=p)
            swap(a[++i],a[j]);
    }
    swap(a[i+1],a[e]);
    return (i+1);
}

void quickSort(int a[],int s,int e)
{
    if(s>=e)
        return;
    int p = part(a,s,e);

    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

void twoZeroFourEight(int n)
{
    if(n==0)
        return;
    twoZeroFourEight(n/10);
    cout<<words[n%10]<<" ";
    return;
}

int sti(char a[],int n)
{
    if(n==0)
        return 0;
    int last_digit = a[n-1]-'0';
    int small_Ans = sti(a,n-1);
    return small_Ans*10+last_digit;
}

void pi(char c[],int i)
{
    if(c[i]=='\0' || c[i+1]=='\0')
        return;
    if(c[i]=='p' && c[i+1]=='i')
    {
        int j=i+2;
        while(c[j]!='\0')
            j++;
        while(j>=i+2)
        {
            c[j+2]=c[j];
            j--;
        }
        c[i]='3';c[i+1]='.';c[i+2]='1';c[i+3]='4';
        pi(c,i+4);
    }
    else
        pi(c,i+1);
    return;
}

int tile(int n)
{
    if(n<=3)
        return 1;
    return tile(n-1)+tile(n-4);
}

int ladder(int n, int k)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=ladder(n-i,k);
    return ans;
}

void moveHanoi(int n,char src,char helper, char dest)
{
    if(n==0)
        return;
    moveHanoi(n-1,src,dest,helper);
    cout<<"Shift "<<n<<" from "<<src<<" to "<< dest<<endl;
    moveHanoi(n-1,helper,src,dest);
}

void generateSubsequence(char in[],char out[],int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=in[i];
    generateSubsequence(in,out,i+1,j+1);
    generateSubsequence(in,out,i+1,j);
}

void generateBrackets(char out[],int n, int idx, int open, int close)
{
    if(idx==2*n)
    {
        out[idx]='\0';
        cout<<out<<endl;
        return;
    }

    if(open<n)
    {
        out[idx]='(';
        generateBrackets(out,n,idx+1,open+1,close);
    }
    if(close<open)
    {
        out[idx]=')';
        generateBrackets(out,n,idx+1,open,close+1);
    }
}

int profit(int n, int c, int w[],int p[])
{
    if(n==0||c==0)
        return 0;
    int inc,exc,ans;
    inc=exc=ans=0;
    if(w[n-1]<=c)
        inc=p[n-1]+profit(n-1,c-w[n-1],w,p);
    exc=profit(n-1,c,w,p);
    return max(inc,exc);
}

void phone(char c[],char d[],int i,int j)
{
    if(c[i]=='\0')
    {
        d[j]='\0';
        cout<<d<<endl;
        return;
    }
    int digit = c[i]-'0';
    if(digit==1||digit==0)
        phone(c,d,i+1,j);
    for(int k=0; keypad[digit][k]!='\0';k++)
    {
        d[j]=keypad[digit][k];
        phone(c,d,i+1,j+1);
    }
    return;
}

void generateStrings(char in[], char out[], int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    int digit = in[i]-'0';
    if(digit==0)
        generateStrings(in,out,i+1,j);
    else
    {
        char ch = digit + 'A' - 1;
        out[j]=ch;
        generateStrings(in,out,i+1,j+1);
    }

    if(in[i+1]!='\0')
    {
        int second_digit = in[i+1]-'0';
        int new_digit = digit*10+second_digit;
        if(new_digit<=26)
        {
            char ch1 = new_digit + 'A' - 1;
            out[j]=ch1;
            generateStrings(in,out,i+2,j+1);
        }
    }
    return;
}

bool maze(char maz[10][10], int output[10][10],int i, int j,int m, int n)
{
    if(i==m-1 && j==n-1)
    {
        output[i][j]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<output[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
        return true;
    }

    if(i>m-1||j>n-1)
        return false;
    if(maz[i][j]=='X')
        return false;

    output[i][j]=1;

    bool right_success = maze(maz,output,i,j+1,m,n);
    bool down_success = maze(maz,output,i+1,j,m,n);

    output[i][j]=0; //backtracking

    if(right_success||down_success)
        return true;
    return false;
}

void permute(char in[],int i,set<string> &s)
{
    if(in[i]=='\0')
    {
        s.insert(in);
        return;
    }

    for(int j=i;in[j]!='\0';j++)
    {
        swap(in[i],in[j]);
        permute(in,i+1,s);
        swap(in[i],in[j]);//backtracking
    }
}

bool isSafe(int chess[10][10],int n,int i,int j)
{
    for(int row=0;row<i;row++)
    {
        if(chess[row][j]==1)
            return false;
    }

    int x=i,y=j;
    while(x>=0 && y>=0)
    {
        if(chess[x][y]==1)
            return false;
        x--;y--;
    }

    x=i,y=j;
    while(x>=0 && y<n)
    {
        if(chess[x][y]==1)
            return false;
        x--;y++;
    }
    return true;
}

bool nqueen(int chess[10][10],int n,int i)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<chess[i][j]<<"_";
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    for(int j=0;j<n;j++)
    {
        if(isSafe(chess,n,i,j))
        {
            chess[i][j]=1;
            bool nextQueen = nqueen(chess,n,i+1);
            if(nextQueen)
                return true;
            chess[i][j]=0;
        }

    }
    return false;
}

bool canPlace(int sudoku[9][9],int n,int i,int j,int no)
{
    for(int x=0;x<n;x++)
    {
        if(sudoku[x][j]==no || sudoku[i][x]==no)
            return false;
    }
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++)
    {
        for(int y=sy;y<sy+rn;y++)
        {
            if(sudoku[x][y]==no)
                return false;
        }
    }
}

bool solvesudoku(int sudoku[9][9],int n,int i, int j)
{
    if(i==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<sudoku[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(j==n)
        return solvesudoku(sudoku,n,i+1,0);
    if(sudoku[i][j]!=0)
        return solvesudoku(sudoku,n,i,j+1);
    for(int no=1;no<=n;no++)
    {
        if(canPlace(sudoku,n,i,j,no))
        {
            sudoku[i][j]=no;
            bool canSolve = solvesudoku(sudoku,n,i,j+1);
            if(canSolve)
                return true;
        }
    }
    sudoku[i][j]=0;
    return false;
}

void bucketSort(Student s[100],int n)
{
    vector<Student> v[101];
    for(int i=0;i<n;i++)
    {
        int m=s[i].marks;
        v[m].push_back(s[i]);
    }
    for(int i=100;i>=0;i--)
    {
        for(vector<Student>::iterator it = v[i].begin();it!=v[i].end();it++)
          cout<<(*it).name<<" "<<(*it).marks<<endl;
    }
    return;
}

void dnfSort(int a[],int n)
{
    int l=0,m=0,hi=n-1;
    while(m<hi)
    {
        if(a[m]==0)
        {
            swap(a[l],a[m]);
            l++;
            m++;
        }
        else if(a[m]==1)
            m++;
        else
        {
            swap(a[hi],a[m]);
            hi--;
        }
    }
    return;
}

void waveSort(int a[],int n)
{
    for(int i=0;i<n;i=i+2)
    {
        if(i!=0 and a[i]<a[i-1])
            swap(a[i],a[i-1]);
        else if(i!=n-1 and a[i]<a[i+1])
            swap(a[i],a[i+1]);
    }
}

ll optimalGame(ll i,ll j){
    if(i > j)
        return 0;
    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;
    return max(pickFirst,pickLast);
}

void sumitup(int a[],int arr[],int t,int arri,int e,int s){
	if(t==0){
		for(int i=0;i<arri;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	if(t<0){
		return;
	}
	if(s>e){
		return;
	}
	int prev=-1;
	for(int i=s;i<=e;i++){
		if(a[i]!=prev){
			arr[arri]=a[i];
			prev=a[i];
			sumitup(a,arr,t-a[i],arri+1,e,i+1);
		}
	}
}

void funkyboard(int board[100][100],int r,int c,int n,int count)
{
    if(r>=n || c>=n || r<0 || c<0 || board[r][c]==0)
        return;

     ans = max(ans,count+1);
     board[r][c] = 0;

     funkyboard(board,r+1,c+2,n,count+1);
     funkyboard(board,r+1,c-2,n,count+1);
     funkyboard(board,r-1,c+2,n,count+1);
     funkyboard(board,r-1,c-2,n,count+1);
     funkyboard(board,r+2,c+1,n,count+1);
     funkyboard(board,r+2,c-1,n,count+1);
     funkyboard(board,r-2,c+1,n,count+1);
     funkyboard(board,r-2,c-1,n,count+1);

     board[r][c]=1;
}

int countLength(Node* head)
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }
    return c;
}

void insertAtHead(Node* &head,int d)
{
    if(head==NULL)
    {
        head=new Node(d);
        return;
    }

    Node *n = new Node(d);
    n->next=head;
    head=n;
    return;
}

void insertAtTail(Node* &head,int d)
{
    if(head==NULL)
        insertAtHead(head,d);
    Node *tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    Node *n= new Node(d);
    tail->next=n;
    return;
}

void insertAtMiddle(Node* &head,int d,int p)
{
    if(head==NULL or p==0)
        insertAtHead(head,d);
    else if(p>countLength(head))
        insertAtTail(head,d);
    else
    {
        Node *t = head;
        while(--p)
            t=t->next;
        Node *n = new Node(d);
        n->next=t->next;
        t->next=n;
    }
}

void printLL(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void deleteHead(Node* &head)
{
    if(head==NULL)
        return;
    Node *t=head->next;
    delete head;
    head=t;
}

void deleteTail(Node* &head)
{
    if(head==NULL)
        return;
    Node *t = head,*prev=NULL;
    while(t->next!=NULL)
    {
        prev=t;
        t=t->next;
    }
    delete t;
    prev->next=NULL;
}

void deleteFromMiddle(Node* &head,int p)
{
    if(p==0)
        deleteHead(head);
    else if(p>=countLength(head)-1)
        deleteTail(head);
    else
    {
        Node *t=head,*prev=NULL;
    while(p--)
    {
        prev=t;
        t=t->next;
    }
    prev->next=t->next;
    delete t;
    }
}

bool searchKey(Node* &head,int key)
{
    Node* t= head;
    while(t!=NULL)
    {
        if(t->data==key)
            return true;
        t=t->next;
    }
    return false;
}

Node* takeInput()
{
    Node* head=NULL;
    int d;
    cin>>d;
    while(d!=-1)
    {
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

istream& operator>>(istream&is, Node* &head)
{
    head=takeInput();
    return is;
}

ostream& operator<<(ostream&os,Node* head)
{
    printLL(head);
    return os;
}

void reverseLL(Node* &head)
{
    Node *t=head;
    Node *prev = NULL;
    Node *n;
    while(t!=NULL)
    {
        n=t->next;
        t->next=prev;
        prev=t;
        t=n;
    }
    head=prev;
}

Node* recReverseLL(Node* &head)
{
    if(head->next==NULL)
        return head;
    Node *small_head  = recReverseLL(head->next);
    Node* t = head->next;
    t->next=head;
    head->next=NULL;
    return small_head;
}

Node* findMiddle(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node* slow=head;
    Node* fast=head->next;
    //and because if or is taken then fast can't take
    //2 jumps if its next pointer is NULL and hence will lead to segmentation fault
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}



int kthNodeFromEnd(Node* head,int k)
{
    Node* slow =head;
    Node* fast=head;
    while(k--)
        fast=fast->next;
    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
}

Node* mergeLL(Node* a,Node* b)
{
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    Node* c = NULL;
    if(a->data<b->data)
    {
        c=a;
        c->next=mergeLL(a->next,b);
    }
    else
    {
        c=b;
        c->next=mergeLL(a,b->next);
    }
    return c;
}

//takes same time as an array which is O(nlogn)
Node* mergeSortLL(Node* &head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* mid=findMiddle(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next=NULL;
    a=mergeSortLL(a);
    b=mergeSortLL(b);
    Node* c = mergeLL(a,b);
    return c;
}

bool detectCycle(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
            return true;
    }
    return false;
}

void removeCycle(Node* &head)
{
    int c=0;
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            c=1;
            break;
        }
    }
    if(c==1)
    {
        slow=head;
        while(fast->next==slow)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=NULL;
    }
    else
        return;
}

void insertCLL(Node* &head,int d)
{
    Node* n=new Node(d);
    Node* t=head;
    n->next=head;
    if(t!=NULL)
    {
        while(t->next!=head)
            t=t->next;
        t->next=n;
    }
    else
        n->next=n;
    head=n;
    return;
}

void printCLL(Node* head)
{
    Node* t=head;
    while(t->next!=head)
    {
        cout<<t->data<<"->";
        t=t->next;
    }
    cout<<t->data<<"->"<<"HEAD"<<endl;
    return;
}

Node* getNodeCLL(Node* head,int d)
{
    Node* t=head;
    while(t->next!=head)
    {
        if(t->data==d)
            return t;
        t=t->next;
    }
    if(t->data==d)
        return t;
    return NULL;
}

void deleteNodeCLL(Node* head,int d)
{
    Node* t=head;
    Node* del = getNodeCLL(head,d);
    if(t==del)
        head=head->next;
    while(t->next!=del)
        t=t->next;
    t->next=del->next;
    delete del;
}

void insertNodeBack(Node* &head, int d)
{
	if(head==NULL)
	{
		head=new Node(d);
		return;
	}
	Node *t=head;
	while(t->next!=NULL)
		t=t->next;
	t->next=new Node(d);
	return;
}

Node* kReverse(Node * &head,int k)
{
	Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
    head->next = kReverse(next, k);

    return prev;
}

Node* arrange_LinkedList(Node* head)
{
   Node *oh=NULL,*ot=NULL,*eh=NULL,*et=NULL;
    Node * current=head;
    while(current!=NULL)
    {
        if((current->data)%2!=0)
        {
            if(oh==NULL)
            {
                oh=current;
                ot=current;
            }
            else{
                ot->next=current;
                ot=ot->next;
            }
            current=current->next;
        }
        else
        {
            if(eh==NULL)
            {
                eh=current;
                et=current;
            }
            else{
                et->next=current;
                et=et->next;
            }
            current=current->next;
        }
     }
     if(eh==NULL || oh==NULL)
        return head;
    if(et!=NULL)
    	et->next=NULL;
    if(ot!=NULL)
        ot->next=NULL;
    if(eh!=NULL && ot!=NULL)
        ot->next=eh;
  	head=oh;
    return head;
}

void arrange_LinkedListreverse(Node* &head_ref)
{
    Node *endi = head_ref;
    Node *prev = NULL;
    Node *curr = head_ref;

    while (endi->next != NULL)
        endi = endi->next;

    Node *new_end = endi;

    while (curr->data % 2 != 0 && curr != endi)
    {
        new_end->next = curr;
        curr = curr->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }

    if (curr->data%2 == 0)
    {
        head_ref = curr;
        while (curr != endi)
        {
            if ( (curr->data) % 2 == 0 )
            {
                prev = curr;
                curr = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                new_end->next = curr;
                new_end = curr;
                curr = prev->next;
            }
        }
    }
    else prev = curr;
    if (new_end != endi && (endi->data) % 2 != 0)
    {
        prev->next = endi->next;
        endi->next = NULL;
        new_end->next = endi;
    }
    return;
}

void insertionSortitLL(Node* &sorted,Node* t)
{
	if(sorted==NULL || sorted->data >= t->data)
	{
		t->next=sorted;
		sorted=t;
	}
	else
	{
		Node* current = sorted;
		while(current->next!=NULL && current->next->data<t->data)
			current=current->next;
		t->next=current->next;
		current->next=t;
	}
}

void insertionSortLL(Node* &head)
{
	Node *t=head;
	Node *sorted = NULL;
	while(t!=NULL)
	{
		Node* next = t->next;
		insertionSortitLL(sorted,t);
		t=next;
	}
	head=sorted;
}

void transfer(stack<int> &s1,stack<int> &s2,int n)
{
    for(int i=0;i<n;i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1)
{
    stack<int> s2;
    int n=s1.size();
    for(int i=0;i<n;i++)
    {
        int d=s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(d);
        transfer(s2,s1,n-i-1);
    }
}

void insertAtBottom(stack<int> &s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int d=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(d);
}

void reverseStackRec(stack<int> &s)
{
    if(s.empty())
        return;
    int x=s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s,x);
}

bool balancedParenthesis(char c[])
{
    stack<char> s;
    for(int i=0;c[i]!='\0';i++)
    {
        char d=c[i];
        if(d=='(')
            s.push(d);
        else if(d==')')
        {
            if(s.empty() || s.top()!='(')
                return false;
            s.pop();
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}

void stockSpan(int prices[], int n, int span[])
{
    stack<int> s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<=n-1;i++)
    {
        int curr_price = prices[i];
        while(!s.empty() and prices[s.top()]<=curr_price)
            s.pop();
        if(!s.empty())
        {
            int prev_highest = s.top();
            span[i]=i-prev_highest;
        }
        else
            span[i]=i+1;
        s.push(i);
    }
}

int main()
{
    int ch;
    do{
    cout<<endl<<"*****MENU*****"<<endl;
    cout<<endl<<"*****Arrays*****"<<endl;
    cout<<"1. Linear Search"<<endl;
    cout<<"2. Binary Search"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cout<<"4. Bubble Sort"<<endl;
    cout<<"5. Insertion Sort"<<endl;
    cout<<"6. STL Sort"<<endl;
    cout<<"7. Subarrays"<<endl;
    cout<<"8. Max Subarray Sum O(n^3)"<<endl;
    cout<<"9. Max Subarray Sum O(n^2)"<<endl;
    cout<<"10. Max Subarray Sum O(n) - Kadane's Algorithm"<<endl;
    cout<<"11. Two Pointer Approach"<<endl;
    cout<<endl<<"*****2D Arrays*****"<<endl;
    cout<<"12. 2D Array Wave Print "<<endl;
    cout<<"13. 2D Array Spiral Print"<<endl;
    cout<<"14. Piyush and Magical Park - O(n^2) calculation part"<<endl;
    cout<<"15. Rotating Image"<<endl;
    cout<<"16. Staircase Search"<<endl;
    cout<<endl<<"*****Character Arrays*****"<<endl;
    cout<<"17. Check Palindrome using Character array"<<endl;
    cout<<"18. Remove consecutive duplicates"<<endl;
    cout<<"19. Largest Character Array"<<endl;
    cout<<endl<<"*****Strings*****"<<endl;
    cout<<"20. Sorting Strings"<<endl;
    cout<<endl<<"*****Problem Solving On 2D Arrays*****"<<endl;
    cout<<"21. Sum of all Submatrices O(n^6)"<<endl;
    cout<<"22. Sum of all Submatrices O(n^4)"<<endl;
    cout<<"23. Sum of all Submatrices O(n^2)"<<endl;
    cout<<endl<<"*****Arrays-Challenges*****"<<endl;
    cout<<"24. Maximum circular Subarray Sum"<<endl;
    cout<<"25. Maximum length of Bitonic Subarray"<<endl;
    cout<<"26. Rain Water Harvesting"<<endl;
    cout<<"27. Form Biggest Number"<<endl;
    cout<<"28. Broken Calculator - Factorial of Large Numbers"<<endl;
    cout<<"29. Sum of two arrays"<<endl;
    cout<<endl<<"*****Strings-Challenges*****"<<endl;
    cout<<"30. Extract CamelCase Strings-1"<<endl;
    cout<<"31. Extract CamelCase Strings-2"<<endl;
    cout<<"32. Palindrome string using recurssion"<<endl;
    cout<<"33. Strings-Max Frequency Character"<<endl;
    cout<<"34. Piyush and Magical Park - O(n) calculation part"<<endl;
    cout<<"35. String compression"<<endl;
    cout<<"36. Sanket and Strings"<<endl;
    cout<<"37. Coding Blocks Numbers"<<endl;
    cout<<endl<<"*****STL*****"<<endl;
    cout<<"38. Find STL"<<endl;
    cout<<"39. Money Change Problem"<<endl;
    cout<<"40. Next Permutation"<<endl;
    cout<<"41. Activity Selection Problem"<<endl;
    cout<<endl<<"*****Binary Search*****"<<endl;
    cout<<"42. Binary Search in a Sorted Rotated Array"<<endl;
    cout<<"43. Binary Search in Monotonic Spaces"<<endl;
    cout<<"44. Aggressive Cows (SPOJ)"<<endl;
    cout<<"45. Book Allocation"<<endl;
    cout<<"46. Parata (SPOJ)"<<endl;
    cout<<"47. Winning CodeBlocks Scholarship"<<endl;
    cout<<endl<<"*****Searching and Sorting-Challenges*****"<<endl;
    cout<<"48. Sting Sort Nishant"<<endl;
    cout<<"49. Count Sort-1"<<endl;
    cout<<"50. Count Sort-2"<<endl;
    cout<<"51. Upper Bound and Lower Bound"<<endl;
    cout<<endl<<"*****Base Conversions*****"<<endl;
    cout<<"52. Any Base to Decimal"<<endl;
    cout<<"53. Decimal to any Base"<<endl;
    cout<<endl<<"*****Bitmanipulation*****"<<endl;
    cout<<"54. Bit Manipulations"<<endl;
    cout<<"55. Unique Number - I"<<endl;
    cout<<"56. Unique Number - II"<<endl;
    cout<<"57. Unique Number - III"<<endl;
    cout<<"58. Exponent Optimised"<<endl;
    cout<<"59. Generate subsets using Bitmasking"<<endl;
    cout<<"60. The Incredible Hulk"<<endl;
    cout<<endl<<"*****Number Theory*****"<<endl;
    cout<<"61. Prime Numbers"<<endl;
    cout<<"62. Prime Factorization O(n)"<<endl;
    cout<<"63. Prime Factorization O(n^1/2)"<<endl;
    cout<<"64. Divisible Subarrays"<<endl;
    cout<<"65. GCD and LCM"<<endl;
    cout<<"66. Modular Exponentiation - O(b)"<<endl;
    cout<<"67. Modular Exponentiation - O(log(base-2)b)"<<endl;
    cout<<"68. Prime Visits (Sieve New)"<<endl;
    cout<<endl<<"*****Recurion*****"<<endl;
    cout<<"69. Recursive Factorial"<<endl;
    cout<<"70. Recursive Fibonacci"<<endl;
    cout<<"71. Recursive Increasing Decreasing"<<endl;
    cout<<"72. Recursive Sorted"<<endl;
    cout<<"73. Recursive Binary Search"<<endl;
    cout<<"74. Recursive Power"<<endl;
    cout<<"75. Recursive Multiplication"<<endl;
    cout<<"76. Recursive Linear Search First Ocurrence (2 methods)"<<endl;
    cout<<"77. Recursive Linear Search Last Ocurrence"<<endl;
    cout<<"78. Recursive All Occurrences"<<endl;
    cout<<"79. Recursive All Sorted Occurrences"<<endl;
    cout<<"80. Recursive Bubble Sort"<<endl;
    cout<<"81. Merge Sort"<<endl;
    cout<<"82. Inversion Count"<<endl;
    cout<<"83. Quick Sort"<<endl;
    cout<<"84. 2048 Problem"<<endl;
    cout<<"85. String to Int Recursion"<<endl;
    cout<<"86. Pi Recursion"<<endl;
    cout<<"87. Tiling Problem Recursion"<<endl;
    cout<<"88. Ladder Problem Recursion"<<endl;
    cout<<"89. Tower of Hanoi Problem"<<endl;
    cout<<"90. Generate Subset Recursion"<<endl;
    cout<<"91. Generate Brackets"<<endl;
    cout<<"92. 0-1 Knapsack Recursion"<<endl;
    cout<<"93. Phone Keypad Problem"<<endl;
    cout<<"94. Generate Acode Strings"<<endl;
    cout<<endl<<"*****Recurion-Backtracking*****"<<endl;
    cout<<"95. Rat in a maze Recursion"<<endl;
    cout<<"96. Permutation of strings"<<endl;
    cout<<"97. N-queen Backtracking"<<endl;
    cout<<"98. Sudoku Solver"<<endl;
    cout<<endl<<"*****Sorting Techniques*****"<<endl;
    cout<<"99. Bucket Sort"<<endl;
    cout<<"100. DNF Sort"<<endl;
    cout<<"101. Wave Sort"<<endl;
    cout<<endl<<"*****Recurion-Challenges*****"<<endl;
    cout<<"102. Optimal Game"<<endl;
    cout<<"103. Sum it Up"<<endl;
    cout<<"104. Funky Chess Board"<<endl;
    cout<<endl<<"******Linked List******"<<endl;
    cout<<"105. Insert"<<endl;
    cout<<"106. Delete"<<endl;
    cout<<"107. Search"<<endl;
    cout<<"108. Take input"<<endl;
    cout<<"109. Operator Overload"<<endl;
    cout<<"110. Reverse Linked List"<<endl;
    cout<<"111. Find the middle node"<<endl;
    cout<<"112. Find the kth node from last"<<endl;
    cout<<"113. Merge 2 Sorted Linked List"<<endl;
    cout<<"114. Merge Sort in Linked List"<<endl;
    cout<<"115. Linked List Floyd's Cycle Detection and Removal"<<endl;
    cout<<endl<<"******Circular Linked List"<<endl;
    cout<<"116. Insertion CLL"<<endl;
    cout<<"117. Deletion CLL"<<endl;
    cout<<"118. List STL - Adjacency List for Weighted Graph"<<endl;
    cout<<endl<<"******Linked List-Challenges******"<<endl;
    cout<<"119. K-Reverse"<<endl;
    cout<<"120. Even after odd LL"<<endl;
    cout<<"121. Odd after even LL"<<endl;
    cout<<"122. Insertion sort in LL"<<endl;
    cout<<endl<<"******Stack******"<<endl;
    cout<<"123. Stack using Vector"<<endl;
    cout<<"124. Stack STL"<<endl;
    cout<<"125. Reverse stack using only one extra stack"<<endl;
    cout<<"126. Reverse a stack recursively"<<endl;
    cout<<"127. Balanced Paranthesis"<<endl;
    cout<<"128. Stock Span Stack"<<endl;
    cout<<"129. "<<endl;
    cout<<"130. "<<endl;
    cout<<"200. Exit"<<endl;
    cout<<endl<<"Enter your choice : ";
    cin>>ch;

    switch(ch)
        {
        case 1 :    {
                        int n,k;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        cout<<"Enter the key : ";
                        cin>>k;
                        int p = linear_searchit(a,n,k);
                        cout<<"The key is present at "<<p<<" position"<<endl;
                        break;
                    }
        case 2 :    {
                        int n,k;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        cout<<"Enter the key : ";
                        cin>>k;
                        int p = binary_searchit(a,n,k);
                        cout<<"The key is present at "<<p<<" position"<<endl;
                        break;
                    }
        case 3 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        selection_sort(a,n);
                        display_array(a,n);
                        break;
                    }
        case 4 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        bubble_sort(a,n);
                        display_array(a,n);
                        break;
                    }
        case 5 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        insertion_sort(a,n);
                        display_array(a,n);
                        break;
                    }
        case 6 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        sort(a,a+n);
                        display_array(a,n);
                        break;
                    }
        case 7 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray(a,n);
                        break;
                    }
        case 8 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray_max_sum1(a,n);
                        break;
                    }
        case 9 :    {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray_max_sum2(a,n);
                        break;
                    }
        case 10 :   {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        subarray_max_sum3(a,n);
                        break;
                    }
        case 11 :   {
                        int n;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the sorted array : ";
                        input_array(a,n);
                        two_pointer_approach(a,n);
                        break;
                    }
        case 12 :   {
                        int n,m;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<n;i++)
                        {
                            if(i%2==0)
                            {
                             for(int j=0;j<m;j++)
                                cout<<a[j][i]<<" ";
                            }
                            else
                            {
                                for(int j=m-1;j>=0;j--)
                                cout<<a[j][i]<<" ";
                            }
                        }
                        break;
                    }
        case 13 :   {
                        int m,n;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        //sr-start row ; sc- start column
                        int sr=0,sc=0,er=m-1,ec=n-1;
                        while(sc<=ec && sr<=er)
                        {
                            for(int i=sc;i<=ec;i++)
                                cout<<a[sr][i]<<" ";
                            sr++;
                            for(int i=sr;i<=er;i++)
                                cout<<a[i][ec]<<" ";
                            ec--;
                            if(er>sr)
                            {
                                 for(int i=ec;i>=sc;i--)
                                    cout<<a[er][i]<<" ";
                                 er--;
                            }
                            if(ec>sc)
                            {
                                for(int i=er;i>=sr;i--)
                                    cout<<a[i][sc]<<" ";
                                sc++;
                            }
                        }
                        break;
                    }
        case 14 :   {
                        int n,m,s,k;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        char a[m][n];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                                cin>>a[i][j];
                        }
                        cout<<"Enter the Strength : ";
                        cin>>s;
                        cout<<"Enter min weight : ";
                        cin>>k;
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                char c=a[i][j];
                                if(s<k)
                                {
                                    cout<<"No";
                                    return 0;
                                }
                                if(c=='.')
                                    s-=2;
                                else if(c=='*')
                                    s+=5;
                                else
                                    break;
                                if(j!=n-1)
                                    s--;
                            }
                        }
                        cout<<"Yes"<<endl<<s<<endl;
                        break;
                    }
        case 15 :   {
                        int m,n;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<m;i++)
                            reverse(a[i],a[i]+n);

                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<i;j++)
                                swap(a[i][j],a[j][i]);
                        }
                        display_2d_array(a,m,n);
                        break;
                    }
        case 16 :   {
                        int m,n,k,i;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        cout<<"Enter the key to Search : ";
                        cin>>k;i=0;
                        int j=n-1;
                        while(j>=0)
                        {
                            if(k==a[i][j])
                                {
                                    cout<<"Found at a["<<i+1<<"]["<<j+1<<"]"<<endl;
                                    break;
                                }
                            else if(k>a[i][j])
                                i++;
                            else
                                j--;
                        }
                        break;
                    }
        case 17 :   {
                        char a[100];
                        cout<<"Enter the string : ";
                        cin.get();
                        cin.getline(a,100);
                        if(char_array_palindrome(a))
                            cout<<"Palindrome"<<endl;
                        else
                            cout<<"Not Palindrome"<<endl;
                        break;
                    }
        case 18 :   {
                        char a[100];
                        cout<<"Enter the string : ";
                        cin.get();
                        cin.getline(a,100);
                        remove_duplicate(a);
                        break;
                    }
        case 19 :   {
                        int current_str_len=0,max_str_len=0,n;
                        char current_str[100],max_str[100];
                        cout<<"Enter the numebr of Strings : ";
                        cin>>n;
                        cin.get();
                        for(int i=0;i<n;i++)
                        {
                            cin.getline(current_str,100);
                            current_str_len=strlen(current_str);
                            if(current_str_len>max_str_len)
                                {
                                    strcpy(max_str,current_str);
                                    max_str_len=current_str_len;
                                }
                        }
                        cout<<max_str<<" "<<max_str_len<<endl;
                        break;
                    }
        case 20 :   {
                        int n;
                        cout<<"Enter the number of strings : ";
                        cin>>n;
                        string s[n];
                        cin.get();
                        for(int i=0;i<n;i++)
                            getline(cin,s[i]);
                        sort(s,s+n);
                        for(int i=0;i<n;i++)
                            cout<<s[i]<<endl;
                        break;
                    }
        case 21 :   {
                        int n,m,s=0,t=0;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                            {
                                for(int k=i;k<m;k++)
                                {
                                    for(int l=j;l<n;l++)
                                    {   s=0;
                                        for(int p=i;p<=k;p++)
                                        {
                                            for(int q=j;q<=l;q++)
                                                {
                                                    s += a[p][q];
                                                    t += a[p][q];
                                                }
                                        }
                                        cout<<s<<endl;
                                    }
                                }
                            }
                        }
                        cout<<"Sum of all Submatrices = "<<t<<endl;
                        break;
                    }
        case 22 :   {
                        int n,m,s=0,t=0;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        int b[100][100]={0};
                        for(int i=0;i<m;i++)
                        {   s=0;
                            for(int j=0;j<n;j++)
                            {
                                s += a[i][j];
                                b[i][j]=s;
                            }
                        }
                        for(int j=0;j<n;j++)
                        {   s=0;
                            for(int i=0;i<m;i++)
                            {
                                s += b[i][j];
                                b[i][j]=s;
                            }
                        }
                        s=0;
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<n;j++)
                            {   s=0;
                                for(int k=i;k<m;k++)
                                {
                                    for(int l=j;l<n;l++)
                                    {
                                        s=b[k][l]-b[i-1][l]-b[k][j-1]+b[i-1][j-1];
                                        cout<<s<<endl;
                                        t+=s;
                                    }
                                }
                            }
                        }
                        cout<<"Sum of all Submatrices = "<<t<<endl;
                        break;
                    }
        case 23 :   {
                        int n,m,s=0;
                        cout<<"Enter 2D array size : ";
                        cin>>m>>n;
                        int a[100][100];
                        cout<<"Enter the elements of the 2D array : "<<endl;
                        input_2d_array(a,m,n);
                        for(int i=0;i<m;i++)
                        {
                            for(int j=0;j<m;j++)
                                s += a[i][j]*(i+1)*(j+1)*(n-i)*(m-j);
                        }
                        cout<<"Total Sum = "<<s<<endl;
                        break;
                    }
        case 24 :   {
                        int m;
                        cin>>m;
                        while(m>0)
                        {
                            int n;
                            cin>>n;
                            int a[n];
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            cout<<maxSum(a,n)<<endl;
                            m--;
                        }
                        break;
                    }
        case 25 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cout<<bitonic(a,n)<<endl;
                        break;
                    }
        case 26 :   {
                        int a[100], l[100], r[100];
                        int n, i, j;
                        cin >> n;
                        for (i = 0; i < n; i++)
                            cin >> a[i];
                        l[0] = a[0];
                        r[n - 1] = a[n - 1];
                        int leftmax = 0, rightmax = 0;
                        for (i = 1; i < n; i++)
                            l[i] = max(l[i - 1], a[i]);
                        for (i = n - 2; i >= 0; i--)
                            r[i] = max(r[i + 1], a[i]);
                        int water = 0;
                        for (i = 0; i < n; i++)
                            water += (min(l[i], r[i]) - a[i]);
                        cout << water;
                        break;
                    }
        case 27 :   {
                        int n;
                        cin>>n;
                        string a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        sort(a,a+n,comparator27);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 28 :   {
                        int n;
                        cin>>n;
                        factorial(n);
                        break;
                    }
        case 29 :   {
                        int n,m;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>m;
                        int b[m];
                        for(int i=0;i<m;i++)
                            cin>>b[i];
                        string a1="",b1="";
                        for(int i=0;i<n;i++)
                            a1=a1+to_string(a[i]);
                        for(int i=0;i<m;i++)
                            b1=b1+to_string(b[i]);
                        string d=to_string(stoi(a1)+stoi(b1));
                        for(int i=0;i<d.length();i++)
                            cout<<d[i]<<", ";
                        cout<<"END";
                        break;
                    }
        case 30 :   {
                        string ch;
                        cin>>ch;
                        for(int i=0;i<ch.length();i++)
                        {
                            int j=i+1;
                            if((ch[i]>='A' && ch[i]<='Z') && (ch[j]>='A' && ch[j]<='Z'))
                                cout<<ch[i]<<endl;
                            else  if((ch[i]>='a' && ch[i]<='z') && (ch[j]>='A' && ch[j]<='Z'))
                                cout<<ch[i]<<endl;
                            else if((ch[i]>='A' && ch[i]<='Z') && (ch[j]>='a' && ch[j]<='z'))
                                cout<<ch[i];
                            else
                                cout<<ch[i];
                        }
                        break;
                    }
        case 31 :   {
                        string s;
                        cin>>s;
                        char ch[s.length()+1];
                        strcpy(ch,s.c_str());
                        extractWords(ch);
                        break;
                    }
        case 32 :   {
                        int n;
                        cin>>n;
                        char ch[n];
                        cin.get();
                        for(int i=0;i<n;i++)
                            cin>>ch[i];
                        if(n==1 || n==0)
                        {
                            cout<<"true";
                            return 0;
                        }
                        if(pal(ch,0,n-1))
                            cout<<"true";
                        else
                            cout<<"false";
                        break;
                    }
        case 33 :   {
                        string s,ms;
                        cin>>s;
                        int max=0;
                        for(int i=0;i<s.length();i++)
                        {
                            int d=count(s.begin(),s.end(),s[i]);
                            if(d>max)
                            {
                                max=d;
                                ms=s[i];
                            }
                        }
                        cout<<ms;
                        break;
                    }
        case 34 :   {
                        int n,m,k,s;
                        cin>>n>>m>>k>>s;
                        char ch[n][m];
                        cin.get();
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<m;j++)
                                cin>>ch[i][j];
                        }
                        int i=0,j=0;
                        while(i<n)
                        {
                            if(s<k)
                            {
                                cout<<"No";
                                return 0;
                            }
                            if(j==m-1)
                            {
                                i++;
                                j=0;
                            }
                            else if(ch[i][j]=='.')
                            {
                                s = s-2-1;
                                j++;
                            }
                            else if(ch[i][j]=='*')
                            {
                                s = s+5-1;
                                j++;
                            }
                            else if(ch[i][j]=='#')
                            {
                                i++;
                                j=0;
                            }
                        }
                        if(s>=k)
                            cout<<"Yes"<<endl<<s;
                        else
                            cout<<"No";
                        break;
                    }
        case 35 :   {
                        string s;
                        getline(cin,s);
                        int cs=1;
                        for(int i=0;i<s.length();i++)
                        {
                            if(s[i]==s[i+1])
                                cs++;
                            else
                            {
                                cout<<s[i]<<cs;
                                cs=1;
                            }
                        }
                        break;
                    }
        case 36 :   {
                        int k;
                        cin>>k;
                        string s;
                        cin.get();
                        cin>>s;
                        int l=s.length();
                        int a=cMax(s,l,k,'a');
                        int b=cMax(s,l,k,'b');
                        cout<<max(a,b);
                        break;
                    }
        case 37 :   {
                        int n;
                        cin>>n;
                        string s;
                        cin>>s;
                        long count = 0;
                        bool* visited = new bool[n];
                        for(int i=0; i<s.length(); i++)
                        {
                            visited[i]=false;
                        }
                        for(int i=1; i <= s.length(); i++)
                        {
                            for(int j=0; j<=s.length()-i; j++)
                            {   int e = j+i;
                                string sub = s.substr(j, e-j);
                                if(is_cb_number(sub) && is_valid(visited,j,e))
                                {
                                    count++;
                                    for(int k=j;k<e;k++)
                                    {
                                        visited[k]=true;
                                    }
                                }
                            }
                        }
                        cout<<count<<endl;
                        break;
                    }
        case 38 :   {
                        int n,k;
                        cout<<"Enter array size : ";
                        cin>>n;
                        int a[n];
                        cout<<"Enter the elements of the array : ";
                        input_array(a,n);
                        cout<<"Enter the key : ";
                        cin>>k;
                        int *it = find(a,a+n,k);
                        int index= it-a;
                        if(index==n)
                            cout<<"Not present"<<endl;
                        else
                            cout<<"Present at "<<index+1<<endl;
                        break;
                    }
        case 39 :   {
                        int coins[]={1,2,5,10,20,50,100,500,1000};
                        int money;
                        cout<<"Enter the amount : ";
                        cin>>money;
                        int n=9;
                        while(money>0)
                        {
                            int lb = lower_bound(coins,coins+n,money,compare39)-coins-1;
                            int m=coins[lb];
                            cout<<m<<",";
                            money=money-m;
                        }
                        break;
                    }
        case 40 :   {
                        int m;
                        cin>>m;
                        int a[m];
                        for(int i=0;i<m;i++)
                            cin>>a[i];
                        next_permutation(a,a+m);
                        for(int i=0;i<m;i++)
                            cout<<a[i]<<" ";
                        cout<<endl;
                        break;
                    }
        case 41 :   {
                        int n,c=1;
                        cin>>n;
                        pair<int,int> p[n];
                        for(int i=0;i<n;i++)
                            cin>>p[i].first>>p[i].second;
                        sort(p,p+n,sort_sec);
                        int j=0;
                        for(int i=1;i<n;i++)
                        {
                            if(p[i].first >= p[j].second){
                                j=i;
                                c++;
                            }
                        }
                        cout<<c<<endl;
                        break;
                    }
        case 42 :   {
                        int n,k;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int s=0,e=n-1;
                        cin>>k;
                        while(s<=e)
                        {
                            int m=(s+e)/2;
                            if(a[m]==k)
                                {
                                    cout<<m;
                                    break;
                                }
                            else if(a[s]<=a[m])
                            {
                                if(k>=a[s] && k<=a[m])
                                    e=m-1;
                                else
                                    s=m+1;
                            }
                            else
                            {
                                if(k>=a[m] and k<=a[e])
                                    s=m+1;
                                else
                                    e=m-1;
                            }
                        }
                        break;
                    }
        case 43 :   {
                        int n;
                        cin>>n;
                        cout<<square_root(n);
                        break;
                    }
        case 44 :   {
                        int n,c;
                        cin>>n>>c;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        sort(a,a+n);
                        int s=0,e=a[n-1];
                        int ans;
                        while(s<=e)
                        {
                            int mid = (s+e)/2;

                            bool c = canPlaceCows(a,n,c,mid);
                            if(c)
                            {
                                ans=mid;
                                s=mid+1;
                            }
                            else
                                e=mid-1;
                        }
                        cout<<ans<<endl;
                        break;
                    }
        case 45 :   {
                        int b,s;
                        cin>>b>>s;
                        int a[b];
                        for(int i=0;i<b;i++)
                            cin>>a[i];
                        cout<<findPage(a,b,s)<<endl;
                        break;
                    }
        case 46 :   {
                        int m;
                        cin>>m;
                        while(m--)
                            solveThis();
                        break;
                    }
        case 47 :   {
                        long int n,m,x,y;
                        cin>>n>>m>>x>>y;
                        long int s=0,e=n,ans=0;
                        while(s<=e)
                        {
                            long int mid=(s+e)/2;
                            if(canGetScholarship(n,m,x,y,mid))
                            {
                                ans=mid;
                                s=mid+1;
                            }
                            else
                                e=mid-1;
                        }
                        cout<<ans;
                        break;
                    }
        case 48 :   {
                        int n;
                        cin>>n;
                        cin.get();
                        string s[n];
                        for(int i=0;i<n;i++)
                            getline(cin,s[i]);
                        sort(s,s+n);
                        for(int i=0;i<n-1;i++)
                        {
                            if(s[i+1].find(s[i])==0)
                                swap(s[i],s[i+1]);
                        }
                        for(int i=0;i<n;i++)
                            cout<<s[i]<<endl;
                        break;
                    }
        case 49 :   {
                        long long int n;
                        cin>>n;
                        long long int a[n];
                        for(long long int i=0;i<n;i++)
                            cin>>a[i];
                        long long int max = *max_element(a,a+n);
                        long long int min = *min_element(a,a+n);
                        long long int range = max-min+1;

                        long long int count[range]={0},output[n];

                        for(long long int i=0;i<n;i++)
                            count[a[i]-min]++;
                        for(long long int i=1;i<range;i++)
                            count[i]+=count[i-1];
                        for(long long int i=n-1;i>=0;i--)
                        {
                            output[count[a[i] - min] - 1] = a[i];
                            count[a[i] - min]--;
                        }
                        for(long long int i=0;i<n;i++)
                            cout<<output[i]<<" ";
                        break;
                    }
        case 50 :   {
                        int n;
                        cin >> n;
                        int a[n];
                        int maxNum=0;
                        for (int i = 0; i < n; i++) {
                            cin >> a[i];
                            if(a[i]>maxNum){
                                maxNum=a[i];
                            }
                        }
                        int freq[maxNum+1] = {0};
                        for (int i = 0; i < n; i++) {
                            freq[a[i]]++;
                        }
                        int sortedA[n];
                        for (int i = 0; i < maxNum+1; i++) {
                            if(freq[i]!=0){
                                while(freq[i]--){
                                    cout << i<<" ";
                                }
                            }
                        }
                        break;
                    }
        case 51 :   {
                        int n,q;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                            int m;
                            cin>>m;
                            if(binary_search(a,a+n,m))
                                    cout<<lower_bound(a,a+n,m)-a<<" "<<(upper_bound(a,a+n,m)-1)-a<<endl;
                            else
                                cout<<"-1"<<" "<<"-1"<<endl;
                        break;
                    }
        case 52 :   {
                        char a[10];
                        cin>>a;
                        int base;
                        cin>>base;
                        int l=strlen(a), power=1, num=0;
                        for(int i=l-1;i>=0;i--)
                        {
                            if(val(a[i])>=base)
                                cout<<"Invalid number";
                            num+=val(a[i])*power;
                            power*=base;
                        }
                        cout<<num;
                        break;
                    }
        case 53 :   {
                        int n,base,index=0;
                        cin>>n>>base;
                        char a[100];
                        while(n>0)
                        {
                            a[index++]=reVal(n%base);
                            n/=base;
                        }
                        a[index]='\0';
                        reverse(a,a+index);
                        string s(a);
                        cout<<s;
                        break;
                    }
        case 54 :   {
                        int n,i,m;
                        cin>>n;
                        bitOddOrEven(n);
                        cout<<"Get Bit : ";
                        cin>>i;
                        cout<<getBit(n,i)<<endl;
                        cout<<"Set Bit : ";
                        cin>>i;
                        cout<<setBit(n,i)<<endl;
                        cout<<"Clear Bit : ";
                        cin>>i;
                        cout<<clearBit(n,i)<<endl;
                        cout<<"Update Bit"<<endl;
                        cout<<"Position number : ";
                        cin>>i;
                        cout<<"Updated to : ";
                        cin>>m;
                        cout<<updateBit(n,i,m)<<endl;
                        cout<<"Clear Last Bits"<<endl;
                        cout<<"No. of bits to be cleared from last : ";
                        cin>>i;
                        cout<<clearLastBits(n,i)<<endl;
                        cout<<"Clear Range Bits"<<endl;
                        cout<<"Enter the range : ";
                        cin>>i>>m;
                        cout<<clearRangeBits(n,i,m)<<endl;
                        cout<<"Total Bits : "<<__builtin_popcount(n);
                        break;
                    }
        case 55 :   {
                        int n,d,ans=0;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            cin>>d;
                            ans = ans^d;
                        }
                        cout<<ans;
                        break;
                    }
        case 56 :   {
                        int n,res=0,pos=0,ans1=0,ans2=0;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                        {
                            cin>>a[i];
                            res = res^a[i];
                        }
                        int res1=res;
                        while(pos=0)
                        {
                            if(res1&1==1)
                                pos++;
                            res>>1;
                        }
                        for(int i=0;i<n;i++)
                        {
                            if((a[i]&(1<<pos))!=0)
                                ans1 = ans1^a[i];
                        }
                        cout<<ans1<<" "<<(ans1^res)<<endl;
                        break;
                    }
        case 57 :   {
                        int n;
                        cin>>n;
                        int a[n],c[64]={0};
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        for(int i=0;i<n;i++)
                        {
                            int j=0;
                            int d=a[i];
                            while(d>0)
                            {
                                c[j]+=(d&1);
                                d=d>>1;
                                j++;
                            }
                        }
                        int p=1,ans=0;
                        for(int i=0;i<64;i++)
                        {
                            c[i]%=3;
                            ans = ans+c[i]*p;
                            p=p<<1;
                        }
                        cout<<ans;
                        break;
                    }
        case 58 :   {
                        int n,power;
                        cin>>n>>power;
                        int ans=1;
                        while(power>0)
                        {
                            int last_bit=(power&1);
                            if(last_bit==1)
                                ans*=n;
                            n*=n;
                            power=power>>1;
                        }
                        cout<<ans;
                        break;
                    }
        case 59 :   {
                        char c[10];
                        cin>>c;
                        int l=strlen(c);
                        for(int i=0;i<(1<<l);i++)
                            subset(c,i);
                        break;
                    }
        case 60 :   {
                        int n,ans=0,k;
                        cin>>n;
                        while(n>0)
                        {
                            int i=0;
                            while(i<n)
                            {
                                if(pow(2,i)<=n)
                                    k=i;
                                else
                                    break;
                                i++;
                            }
                            ans++;
                            n=n-pow(2,k);
                        }
                        cout<<ans<<endl;
                        break;
                    }
        case 61 :   {
                        int n;
                        cin>>n;
                        int p[n]={0};
                        primeSieve(p,n);
                        for(int i=0;i<=n;i++)
                        {
                            if(p[i]==1)
                                cout<<i<<" ";
                        }
                        break;
                    }
        case 62 :   {
                        int n,c=0;
                        vector<pair<int,int>> v;
                        cin>>n;
                        for(int i=2;i<=n;i++)
                        {
                            if(n%i==0)
                            {
                                while(n%i==0)
                                {
                                    n=n/i;
                                    c++;
                                }
                                v.push_back(make_pair(i,c));
                                c=0;
                            }
                        }
                        for(auto it : v)
                            cout<<it.first<<"^"<<it.second<<endl;
                        break;
                    }
        case 63 :   {
                        int n,c=0;
                        vector<pair<int,int>> v;
                        cin>>n;
                        for(int i=2;i*i<=n;i++)
                        {
                            if(n%i==0)
                            {
                                while(n%i==0)
                                {
                                    n=n/i;
                                    c++;
                                }
                                v.push_back(make_pair(i,c));
                                c=0;
                            }
                        }
                        if(n!=1)
                            v.push_back(make_pair(n,1));
                        for(auto it : v)
                            cout<<it.first<<"^"<<it.second<<endl;
                        break;
                    }
        case 64 :   {
                        int pre[1000]={0}; //to store count of each index(number)
                        int n,sum=0,ans=0;
                        cin>>n;
                        int a[n];
                        pre[0]=1;
                        for(int i=0;i<n;i++)
                        {
                            cin>>a[i];
                            sum+=a[i];
                            sum %= n;
                            sum = (sum+n)%n;    //if sum becomes negative
                            pre[sum]++;
                        }
                        for(int i=0;i<n;i++)
                        {
                            int m=pre[i];
                            ans += m*(m-1)/2;
                        }
                        cout<<ans;
                        break;
                    }
        case 65 :   {
                        int a,b;
                        cin>>a>>b;
                        int g=gcd(a,b);
                        cout<<"GCD = "<<g<<endl;
                        cout<<"LCM = "<<(a*b)/g;
                        break;
                    }
        case 66 :   {
                        int a,b,c;
                        cin>>a>>b>>c;
                        cout<<pow_mod(a,b,c);
                        break;
                    }
        case 67 :   {
                        long long int a,b,c;
                        cin>>a>>b>>c;
                        cout<<modpowIter(a,b,c);
                        break;
                    }
        case 68 :   {
                        p[0]=p[1]=false;p[2]=true;
                        primeSieveNew(p,1000001);
                        int t;
                        cin>>t;
                        while(t--)
                        {
                            int a,b;
                            cin>>a>>b;
                            cout<<countPrimes(a,b)<<endl;
                        }
                        break;
                    }
        case 69 :   {
                        int n;
                        cin>>n;
                        cout<<recFact(n)<<endl;
                        break;
                    }
        case 70 :   {
                        int n;
                        cin>>n;
                        cout<<recFib(n)<<endl;
                        break;
                    }
        case 71 :   {
                        int n;
                        cin>>n;
                        recDec(n);
                        cout<<endl;
                        recInc(n);
                        break;
                    }
        case 72 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cout<<recSort(a,n);
                        break;
                    }
        case 73 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        cout<<recBinarySearch(a,0,n-1,key)<<endl;
                        break;
                    }
        case 74 :   {
                        int a,n;
                        cin>>a>>n;
                        cout<<recPower(a,n)<<endl;
                        break;
                    }
        case 75 :   {
                        int a,n;
                        cin>>a>>n;
                        cout<<recMul(a,n)<<endl;
                        break;
                    }
        case 76 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        cout<<linearSearch1(a,n,key)<<endl;
                        cout<<linearSearch2(a,0,n,key)<<endl;
                        break;
                    }
        case 77 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        cout<<lastOccurence(a,n,key);
                        break;
                    }
        case 78 :   {
                        int n,key;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                            cin>>key;
                        allOccurence(a,0,n,key);
                        break;
                    }
        case 79 :   {
                        int n,key;
                        cin>>n;
                        int a[n],b[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>key;
                        int k = allStoredOccurence(a,0,n,key,b,0);
                        cout<<"Count = "<<k<<endl;
                        for(int i=0;i<k;i++)
                            cout<<b[i]<<",";
                        break;
                    }
        case 80 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        recBubbleSort(a,n,0);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 81 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        mergeSort(a,0,n-1);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 82 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cout<<inversionCount(a,0,n-1);
                        break;
                    }
        case 83 :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        quickSort(a,0,n-1);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 84 :   {
                        int n;
                        cin>>n;
                        twoZeroFourEight(n);
                        break;
                    }
        case 85 :   {
                        char c[100];
                        cin>>c;
                        cout<<sti(c,strlen(c));
                        break;
                    }
        case 86 :   {
                        char c[100];
                        cin>>c;
                        pi(c,0);
                        cout<<c;
                        break;
                    }
        case 87 :   {
                        int n;
                        cin>>n;
                        cout<<tile(n);
                        break;
                    }
        case 88 :   {
                        int n,k;
                        cin>>n>>k;
                        cout<<ladder(n,k);
                        break;
                    }
        case 89 :   {
                        int n;
                        cin>>n;
                        moveHanoi(n,'A','B','C');
                        break;
                    }
        case 90 :   {
                        char in[]="abc";
                        char out[100];
                        generateSubsequence(in,out,0,0);
                        break;
                    }
        case 91 :   {
                        int n;
                        cin>>n;
                        char out[100];
                        generateBrackets(out, n,0,0,0);
                        break;
                    }
        case 92 :   {
                        int prices[]={40,20,30,100};
                        int weight[]={1,2,3,5};
                        int n=4,c=7;
                        cout<<profit(n,c,weight,prices);
                        break;
                    }
        case 93 :   {
                        char c[100];
                        cin>>c;
                        char d[100];
                        phone(c,d,0,0);
                        break;
                    }
        case 94 :   {
                        char in[100];
                        cin>>in;
                        char out[100];
                        generateStrings(in,out,0,0);
                        break;
                    }
        case 95 :   {
                        char maz[10][10]={"0000","00X0","000X","0X00"};
                        int out[10][10]={0};
                        bool ans = maze(maz,out,0,0,4,4);
                        if(ans==false)
                            cout<<"Path doesn't exist!"<<endl;
                        break;
                    }
        case 96 :   {
                        char in[100];
                        cin>>in;
                        set<string> s;
                        permute(in,0,s);
                        for(auto it:s)
                            cout<<it<<",";
                        break;
                    }
        case 97 :   {
                        int chess[10][10]={0},n;
                        cin>>n;
                        if(!nqueen(chess,n,0))
                            cout<<"Queens can't be placed"<<endl;
                        break;
                    }
        case 98 :   {
                        int sudoku[9][9]={
                             {3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0} };
                        int n=9;
                        solvesudoku(sudoku,n,0,0);
                        break;
                    }
        case 99 :   {
                        Student s[100];
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                            cin>>s[i].name>>s[i].marks;
                        bucketSort(s,n);
                        break;
                    }
        case 100 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        dnfSort(a,n);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 101 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        waveSort(a,n);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 102 :  {
                        int n;
                        cin >> n;
                        for(int i=0;i<n;i++)
                            cin >> coins[i];
                        cout << optimalGame(0,n-1);
                        break;
                    }
        case 103 :  {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++){
                            cin>>a[i];
                        }
                        int t ;
                        cin>>t;
                        int arr[n];
                        sort(a,a+n);
                        sumitup(a,arr,t,0,n-1,0);
                        break;
                    }
        case 104 :  {
                        int n;
                        cin>>n;
                        int board[100][100]={0};
                        int count=0;
                        for(int i=0;i<n;i++)
                        {
                            for(int j=0;j<n;j++)
                                {
                                    cin>>board[i][j];
                                    if(board[i][j]==1)
                                        count++;
                                }
                        }
                        funkyboard(board,0,0,n,0);
                        cout<<count-ans;
                        break;
                    }
        case 105 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        printLL(head);
                        insertAtMiddle(head,0,3);
                        printLL(head);
                        insertAtTail(head,8);
                        printLL(head);
                        break;
                    }
        case 106 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        printLL(head);
                        insertAtMiddle(head,0,3);
                        printLL(head);
                        insertAtTail(head,8);
                        printLL(head);
                        deleteHead(head);
                        printLL(head);
                        deleteTail(head);
                        printLL(head);
                        deleteFromMiddle(head,3);
                        printLL(head);
                        break;
                    }
        case 107 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        if(searchKey(head,99))
                            cout<<"Found"<<endl;
                        else
                            cout<<"Not Found"<<endl;
                        break;
                    }
        case 108 :  {
                        Node* head=takeInput();
                        printLL(head);
                        break;
                    }
        case 109 :  {
                        Node* head1=NULL;
                        Node* head2=NULL;
                        cin>>head1>>head2;
                        cout<<head1<<head2;
                        break;
                    }
        case 110 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        head = recReverseLL(head);
                        printLL(head);
                        break;
                    }
        case 111 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        Node* middle = findMiddle(head);
                        cout<<middle->data<<endl;
                        break;
                    }
        case 112 :  {
                        Node *head = NULL;
                        insertAtHead(head,3);
                        printLL(head);
                        insertAtHead(head,5);
                        insertAtHead(head,6);
                        insertAtHead(head,7);
                        insertAtHead(head,1);
                        insertAtHead(head,9);
                        cout<<kthNodeFromEnd(head, 3);
                        break;
                    }
        case 113 :  {
                        Node* head1=NULL;
                        Node* head2=NULL;
                        cin>>head1>>head2;
                        cout<<head1<<head2;
                        Node* m=mergeLL(head1,head2);
                        printLL(m);
                        break;
                    }
        case 114 :  {
                        Node* head=NULL;
                        cin>>head;
                        head=mergeSortLL(head);
                        printLL(head);
                        break;
                    }
        case 115 :  {
                        Node* head=NULL;
                        cin>>head;
                        if(detectCycle(head))
                            cout<<"Cycle is present"<<endl;
                        else
                            cout<<"Cycle is absent"<<endl;
                        removeCycle(head);
                        printLL(head);
                        break;
                    }
        case 116 :  {
                        Node* head=NULL;
                        insertCLL(head,20);
                        insertCLL(head,30);
                        insertCLL(head,40);
                        insertCLL(head,10);
                        printCLL(head);
                        break;
                    }
        case 117 :  {
                        Node* head=NULL;
                        insertCLL(head,20);
                        insertCLL(head,30);
                        insertCLL(head,40);
                        insertCLL(head,10);
                        printCLL(head);
                        deleteNodeCLL(head,30);
                        printCLL(head);
                        deleteNodeCLL(head,20);
                        printCLL(head);
                        break;
                    }
        case 118 :  {
                        list<pair<int,int>> *l;
                        l = new list<pair<int,int>>[3];
                        for(int i=0;i<3;i++)
                        {
                            int x,y,wt;
                            cin>>x>>y>>wt;
                            l[x].push_back(make_pair(y,wt));
                            l[y].push_back(make_pair(x,wt));
                        }
                        for(int i=0;i<3;i++)
                        {
                            cout<<"["<<i<<"]"<<" -> ";
                            for(auto xp:l[i])
                                cout<<"("<<xp.first<<","<<xp.second<<")"<<" ; "<<endl;
                        }
                        break;
                    }
        case 119 :  {
                        Node *head=NULL;
                        int n,m;
                        cin>>n>>m;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        Node *t=kReverse(head,m);;
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 120 :  {
                        Node *head=NULL;
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        Node *t = arrange_LinkedList(head);
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 121 :  {
                        Node *head=NULL;
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        arrange_LinkedListreverse(head);
                        Node* t=head;
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 122 :  {
                        Node *head=NULL;
                        int n;
                        cin>>n;
                        for(int i=0;i<n;i++)
                        {
                            int d;
                            cin>>d;
                            insertNodeBack(head,d);
                        }
                        insertionSortLL(head);
                        Node* t=head;
                        while(t!=NULL)
                        {
                            cout<<t->data<<" ";
                            t=t->next;
                        }
                        break;
                    }
        case 123 :  {
                        Stack s;
                        for(int i=0;i<5;i++)
                            s.push(i);
                        while(!s.isEmpty())
                        {
                            cout<<s.top()<<" ";
                            s.pop();
                        }
                        break;
                    }
        case 124 :  {
                        stack<int> s;
                        for(int i=0;i<5;i++)
                            s.push(i);
                        while(!s.empty())
                        {
                            cout<<s.top()<<" ";
                            s.pop();
                        }
                        break;
                    }
        case 125 :  {
                        stack<int> s;
                        for(int i=1;i<=5;i++)
                            s.push(i);
                        reverseStack(s);
                        while(!s.empty())
                        {
                            cout<<s.top()<<endl;
                            s.pop();
                        }
                        break;
                    }
        case 126 :  {
                        stack<int> s;
                        for(int i=1;i<=5;i++)
                            s.push(i);
                        reverseStackRec(s);
                        while(!s.empty())
                        {
                            cout<<s.top()<<endl;
                            s.pop();
                        }
                        break;
                    }
        case 127 :  {
                        char c[100]="()(()";
                        if(balancedParenthesis(c))
                            cout<<"Yes";
                        else
                            cout<<"No";
                        break;
                    }
        case 128 :  {
                        int prices[]={100,80,60,70,60,75,85};
                        int n=sizeof(prices)/sizeof(int);
                        int span[100]={0};
                        stockSpan(prices,n,span);
                        for(int i=0;i<n;i++)
                            cout<<span[i]<<" ";
                        break;
                    }
        case 129 :  {

                        break;
                    }
        case 130 :  {

                        break;
                    }
        case 200 :      break;
        default: cout<<"Try Again";
                    break;
        }
    }while(ch!=200);
	return 0;
}
