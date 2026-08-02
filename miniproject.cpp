#include<iostream>
#include<cstring>
using namespace std;
class STRING
{

	char *p;
	public:
	STRING()
	{
		cout<<"constructor"<<endl;
		p=0;
	}
	STRING(const char *s)
	{
		p=new char[strlen(s)+1];
		strcpy(p,s);
	}
	STRING(STRING &s)
	{
		p=new char[strlen(s.p)+1];
		strcpy(p,s.p);
	}
	~STRING()
	{
		cout<<"destructor"<<endl;
		delete[] p;
	}
	void getstring()
	{
		cout<<p<<endl;
	}
	//////////////////////////////////////////////////
	//assigment operator overload 
	STRING &operator=(const STRING &s)
	{
		delete[] p;
		p=new char [strlen(s.p)+1];
		strcpy(p,s.p);
		return *this;
	}
	/////////////////////////////////////////////////////////////////////////////////////
	//[] operator
	char &operator[] (int i)
	{
		return p[i];
	}
	///////	////////////////////////////////////////////////
	//+ operator
	STRING operator+(const STRING &s)
	{
		STRING temp;
		delete[] temp.p;
		temp.p=new char[strlen(p)+strlen(s.p)+1];
		strcpy(temp.p,p);
		strcat(temp.p,s.p);
		return temp;
	}
	int operator<(const STRING &s)
	{
		return strcmp(p,s.p)<0;
	}

	int operator>(const STRING &s)
	{
		return strcmp(p,s.p)>0;
	}
	int operator ==(const STRING &s)
	{
		return strcmp(p,s.p)==0;

	}
	int operator<=(const STRING &s)
	{
		return strcmp(p,s.p)<=0;
	}

	int operator>=(const STRING &s)
	{
		return strcmp(p,s.p)>=0;
	}
	int operator!=(const STRING &s)
	{
		return strcmp(p,s.p)!=0;
	}
	////////////////////////////////////////////////////////////////////

	//insert and extract operators
	friend istream &operator >>(istream&,STRING &);
	friend ostream &operator <<(ostream&,STRING &);
	friend void my_strchr(const STRING &s,char p);
	friend void len(STRING &s);
	friend void str_reverse(STRING &s);
	friend void strstr(STRING &s);
	friend void str_upper(STRING &s);
	friend void str_lower(STRING &s);
	friend void strrchr(STRING &s,char a);
	friend void strcpy(STRING &s,STRING &d);
	friend void strncpy(STRING &s,STRING &d,int c);
	friend void strcmp(STRING &s,STRING &d);
	friend void strncmp(STRING &s,STRING &d,int c);
	friend void strcat(STRING &s,STRING &d);
	friend void strncat(STRING &s,STRING &d,int c);
};
///////////////////////////////////////////////////
//>> operator
istream &operator >>(istream &in,STRING &s)
{
	char temp[100];
	cout<<"operator >> "<<endl;
	in>>temp;
	delete []s.p;
	s.p=new char [strlen(temp)+1];
	strcpy(s.p,temp);
	return in;
}
///////////////////////////////////////////////////////
ostream &operator <<(ostream &out,STRING &s)
{
	cout<<"operator"<<endl;
	out<<s.p<<endl;
	return out;
}
////////////////////////////////////////////////////////////
void my_strchr(const STRING &s,char p )
{
	int i;
	cout<<"enter the character"<<endl;
	cin>>p;
	cout<<" "<<endl;
	for(i=0;s.p[i];i++)
	{
		if(s.p[i]==p)
		{
			cout<<"char found pos at "<<"yes"<<i<<endl;
			cout<<" "<<endl;
			return;
		}
	}
	cout<<"char not found"<<endl;
	cout<<" "<<endl;
}
////////////////////////////////////////////////////////
void len(STRING &s)
{
	int i;
	for(i=0;s.p[i];i++);
	cout<<"len"<<i<<endl;
}
////////////////////////////////////////////////////////
void str_reverse(STRING &s)
{
	char t;
	int i,j,len=0;
	for(len;s[len];len++);
	for(i=0,j=len-1;i<j;i++,j--)
	{
		t=s.p[i];
		s.p[i]=s.p[j];
		s.p[j]=t;
	}
	cout<<"string revrse:"<<s<<endl;

}
void strstr(STRING &s)
{
	char m[500];
	cout<<"enter sub:"<<endl;
	cin>>m;
	cout<<" "<<endl;
	int i,j,k,c=0;
	for(i=0;s.p[i]!='\0';i++)
	{
		for(j=0;m[j]!='\0';j++)
		{
			if(s.p[i+j]!=m[j])
				break;
		}
		if(m[j]=='\0')
			c++;
	}
	if(c>0)
		cout<<"substring found"<<endl;
	else
		cout<<"substring not found"<<endl;
	//cout<<"  "<<endl;
}

///////////////////////////////////////////////////////////////////////

void str_upper(STRING &s)
{
	int i;
	for(i=0;s.p[i]!='\0';i++)
	{
		if(s.p[i]>='a'&&s.p[i]<='z')
			s.p[i]=s.p[i]-32;
	}
	cout<<"uppercase is:"<<s.p<<endl;
	cout<< "  "<<endl;
}

/////////////////////////////////////////////////////////////////////////

void str_lower(STRING &s)
{
	int i;
	for(i=0;s.p[i]!='\0';i++)
	{
		if(s.p[i]>='A'&&s.p[i]<='Z')
			s.p[i]=s.p[i]+32;
	}
	cout<<"lowercase is:"<<s.p<<endl;
	cout<< "  "<<endl;
}

//////////////////////////////////////////////////////////////////////

void strrchr(STRING &s,char a)
{
	int i;
	cout<<"enter the character"<<endl;
	cin>>a;
	cout<<  " "<<endl;
	for(i=strlen(s.p)-1;i>=0;i--)
	{
		if(s.p[i]==a)
		{
			cout<<"char found position at "<<i<<endl;
			cout<< "  "<<endl;
			return;
		}
	}
	cout<<"char not found"<<endl;
	cout<< "  "<<endl;
}
///////////////////////////////////////////////////////////////////////////////

void strcpy(STRING &s,STRING &d)
{
	int i;
	delete[] d.p;
	d.p=new char[strlen(s.p)+1];
	for(i=0;s.p[i];i++)
		d.p[i]=s.p[i];
	d.p[i]='\0';
	//cout<<"given string is: "<<s.p<<endl;
	cout<<"copy string is: "<<d.p<<endl;
	cout<< "  "<<endl;
}

/////////////////////////////////////////////////////////////////////

void strncpy(STRING &s,STRING &d,int c)
{
	//	cout<<"enter the num from where to copy:"<<endl;
	//	cin>>c;
	cout<<" "<<endl;
	delete[] d.p;
	d.p=new char[c+1];
	cout<<" "<<endl;
	int i;
	for(i=0;i<c&&s.p[i]!='\0';i++)
		d.p[i]=s.p[i];
	d.p[i]='\0';
	//cout<<"given string is: "<<s.p<<endl;
	cout<<"copy string is: "<<d.p<<endl;
	cout<<" "<<endl;
} 
///////////////////////////////////////////////////////////////////// 

void strcmp(STRING &s ,STRING &d)
{
	int i;
	for(i=0;s.p[i]!='\0'&&d.p[i]!='\0';i++)
	{
		if(s.p[i]!=d.p[i])
			break;
	}
	if(s.p[i]=='\0'&&d.p[i]=='\0')
		cout<<"strings are equal"<<endl;
	else
		cout<<"strings are unequal"<<endl;
	cout<<" "<<endl;
}

/////////////////////////////////////////////////////////////////////

void strncmp(STRING &s,STRING &d,int c)
{
	//	cout<<"enter the num from where to cmp:"<<endl;
	//	cin>>c;
	cout<<" "<<endl;
	int i;
	for(i=0;i<c&&s.p[i]!='\0'&&d.p[i]!='\0';i++)
	{
		if(s.p[i]!=d.p[i])
			break;
	}
	if(i==c||(s.p[i]=='\0'&&d.p[i]=='\0'))
		cout<<"strings are equal"<<endl;
	else
		cout<<"strings are unequal"<<endl;
	cout<<"  "<<endl;
}

/////////////////////////////////////////////////////////////////////

void strcat(STRING &s,STRING &d)
{
	int i,j;
	for(i=0;d.p[i]!='\0';i++);
	for(j=0;s.p[j]!='\0';j++)
		d.p[i++]=s.p[j];
	d.p[i]='\0';
	cout<<"after cancatenate:"<<d.p<<endl;
	cout<< "  "<<endl;
}

////////////////////////////////////////////////////////////////////
void strncat(STRING &s,STRING &d,int c)
{
	
	int i,j;
	for(i=0;d.p[i];i++);
	for(j=0;j<c&&s.p[j];j++)
		d.p[i++]=s.p[j];
	d.p[i]='\0';
	cout<<"after cancatenate:"<<d.p<<endl;
	cout<< "  "<<endl;
}



////////////////////////////////////////////////////////////////
int main()
{

	STRING s1,s2,s3,s4,s5;
	char p;
	int c;
	cout<<"enter c"<<endl;
	cin>>c;
	cout<<"enter first string:"<<endl;
	cin>>s1;
	cout<<"enter second string"<<endl;
	cin>>s2;

	s1.getstring();
	s2.getstring();            
	cout<<"assignment overload"<<endl;
	s1=s2;

	s1.getstring();

	//cin>>s3>>s4;
	//cout<<s3<<s4;
	cout<<"***************************"<<endl;

	cout<<"subscript"<<endl;
	s1[0]='K';                                   
	s1.getstring();


	cout<<"+ope overload"<<endl;
	s1=s1+s2;                             
	s1.getstring();

	if(s1<s2)
		cout<<"s2 is smaller"<<endl;
	else
		cout<<"s2 is not smalller"<<endl;
	if(s1>s2)
		cout<<"s1 is greater"<<endl;
	else
		cout<<"s1 is not greater"<<endl;
	if(s1==s2)
		cout<<"equal"<<endl;
	else
		cout<<"not equal"<<endl;
	if(s1<=s2)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	if(s1>=s2)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	if(s1!=s2)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;


	cout<<"*********************************"<<endl;
//friend functions
	my_strchr(s1,p);
	len(s1);
	str_reverse(s1);
	strstr(s1);
	str_upper(s1);
	str_lower(s1);
	strrchr(s1,p);
	strcpy(s1,s2);
	strncpy(s1,s2,c);
	strcmp(s1,s2);
	strncmp(s1,s2,c);
	strcat(s1,s2);
	strncat(s1,s2,c);
}
