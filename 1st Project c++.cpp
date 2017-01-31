#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
	struct student
	{
		int rollno;
		char name[80];
		int mark;
	};
	void AddData ()
	{
		student s;
		cin>>s.rollno>>s.name>>s.mark;
		ofstream ofs("student.bin",ios_base::app);
		ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
		ofs.close();
		cout<<"data succefully written"<<endl;
	}
	void DisplayData()
	{
		ifstream ifs("student.bin");
		student s;
	while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		cout<<"the student data"<<endl;
		cout<<s.rollno<<endl;
		cout<<s.name<<endl;
		cout<<s.mark<<endl;
	}
	ifs.close();
	}
	void ModifyData()
	{
		int r;
		cout<<"enter rollno whose record is to modified"<<endl;
		cin>>r;
		ifstream ifs ("student.bin");
		ofstream ofs ("temp.bin");
		student s;
		while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			if (s.rollno==r)
			{
				cout<<"enter new data"<<endl;
				cin>>s.rollno;
				cin>>s.name;
				cin>>s.mark;
			}
			ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs.close();
		ofs.close();
		ofstream ofs2("student.bin");
		ifstream ifs2("temp.bin");
		while(ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			ofs2.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs2.close();
		ofs2.close();
		cout<<"data succesfully written"<<endl;
	}
	void DeleteData ()
	{
		int r;
		cout<<"enter rolno whose data is deleted"<<endl;
		cin>>r;
		student s;
		ifstream ifs ("student.bin");
		ofstream ofs("temp.bin");
		while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			if(s.rollno!=r)
			{
				ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
			}
		}
		ifs.close();
		ofs.close();
			ofstream ofs2("student.bin");
		ifstream ifs2("temp.bin");
		while(ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			ofs2.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs2.close();
		ofs2.close();
		cout<<"data succesfully deleted"<<endl;
	}
	void DisplayHighest ()
	{
		ifstream ifs("student.bin");
		student s;
		int count=0;
		while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			count++;
		}
		ifs.close();
		student s2[count];
		ifstream ifs2("student.bin");
		int i=0;
		while(ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			s2[i]=s;
			i++;
		}
		ifs2.close();
		int large=s2[0].mark;
		int loc=0;
		for(i=1;i<count;i++)
		{
			if(s2[i].mark>large)
			{
				large =s2[i].mark;
				loc=i;
			}
		}
		cout<<"student with highest marks"<<endl;
		cout<<"rollno="<<s2[loc].rollno<<endl;
		cout<<"name="<<s2[loc].name<<endl;
		cout<<"marks="<<s2[loc].mark<<endl;
	}
	void PassData()
	{
	
		ifstream ifs("student.bin");
		ofstream ofs("temp.bin");
		cout<<"enter marks"<<endl;
		student s;
		while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			if(s.mark>=50)
			{
				cout<<"pass students"<<endl;
				cout<<s.rollno<<endl;
				cout<<s.name<<endl;
				cout<<s.mark<<endl;
			}
			ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs.close ();
		ofs.close();
		ofstream ofs2("student.bin");
		ifstream ifs2("temp.bin");
		while(ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			ofs2.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs2.close();
		ofs2.close();
	}
		void FailData()
	{
	
		ifstream ifs("student.bin");
		ofstream ofs("temp.bin");
		cout<<"enter marks"<<endl;
		student s;
		while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			if(s.mark<50)
			{
				cout<<"fail students"<<endl;
				cout<<s.rollno<<endl;
				cout<<s.name<<endl;
				cout<<s.mark<<endl;
			}
			ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs.close ();
		ofs.close();
		ofstream ofs2("student.bin");
		ifstream ifs2("temp.bin");
		while(ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			ofs2.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs2.close();
		ofs2.close();
	}
	void RecData ()
	{
		student s;
		cout<<"Enter a rollno"<<endl;
		int r;
		cin>>r;
	
		ifstream ifs("student.bin");
		ofstream ofs("temp.bin");
		while(ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			if(r==s.rollno)
			{
				cout<<"rollno="<<s.rollno<<endl;
				cout<<"name="<<s.name<<endl;
				cout<<"marks="<<s.mark<<endl;
			}
			ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
	   }
	   ifs.close();
	   ofs.close();
	   	ofstream ofs2("student.bin");
		ifstream ifs2("temp.bin");
		while(ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			ofs2.write(reinterpret_cast<char*>(&s),sizeof(s));
		}
		ifs2.close();
		ofs2.close();
	}
	int main ()
	{
		char ch;
		while (1)
		{
			cout<<"1.Add Student Data"<<endl;
			cout<<"2. Display student data"<<endl;
			cout<<"3. Modify data"<<endl;
			cout<<"4. Delete Data"<<endl;
			cout<<"5. Display hihgest data"<<endl;
			cout<<"6. Pass students"<<endl;
			cout<<"7. Fail students"<<endl;
			cout<<"8. Search a Student"<<endl;
			cout<<"9. Exit"<<endl;
			ch=getche();
			cout<<endl;
			if(ch=='1')
			AddData ();
			else if(ch=='2')
			DisplayData ();
			else if(ch=='3')
			ModifyData();
			else if(ch=='4')
			DeleteData();
			else if(ch=='5')
			DisplayHighest();
			else if(ch=='6')
			PassData ();
			else if (ch=='7')
			FailData ();
			else if (ch=='8')
			RecData() ;
			else if (ch=='9')
			break;
			else 
			cout<<"invalid character"<<endl;
		}
		getch();
		return 0;
	}

