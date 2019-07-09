#include<iostream>
#include<string>
using namespace std;

class lzy
{
public:
	char con;
	int grade;
	lzy(){ con = '.'; grade = 20; }
}; lzy a[15][15];

void Input(string code)
{
	//string code=mzw;
	int x = 0;
	x = code.length();
	if ((x / 2) % 2 == 0)
	for (int i = 0; i + 1< x; i = i + 2)
	{
		if ((i / 2) % 2 == 0)
			a[int(code[i]) - 97][int(code[i + 1]) - 97].con = 'M';
		else
			a[int(code[i]) - 97][int(code[i + 1]) - 97].con = 'O';
	}
	else
	for (int i = 0; i + 1< x; i = i + 2)
	{
		if ((i / 2) % 2 == 0)
			a[int(code[i]) - 97][int(code[i + 1]) - 97].con = 'O';
		else
			a[int(code[i]) - 97][int(code[i + 1]) - 97].con = 'M';
	}
}
string smx1(int x, int y)
{
	string s = "";
	int hy = y - 4;//起点
	int ey = y + 4;//终点
	for (int n = hy; n <= ey; n++)
	{
		if (n >= 0 && n <= 14)
		{
			if (n == y)
			{
				s += "C";
			}
			else
				s += a[x][n].con;
		}
	}
	return s;
}
string smx2(int x, int y)
{
	string s = "";
	int m, n;
	int hx = x - 4;//qi
	int ex = x + 4;//zhong
	int hy = y - 4;//起点
	int ey = y + 4;//终点
	for (m = hx, n = hy; m <= ex&&n <= ey; n++, m++)
	{
		if (m >= 0 && n >= 0 && m <= 14 && n <= 14)
		{
			if (m == x&&n == y)
			{
				s += "C";
			}
			else
				s += a[m][n].con;
		}
	}
	return s;
}
string smx3(int x, int y)
{
	string s = "";
	int hx = x - 4;//qi
	int ex = x + 4;//zhong

	for (int m = hx; m <= ex; m++)
	{
		if (m >= 0 && m <= 14)
		{
			if (m == x)
			{
				s += "C";
			}
			else
				s += a[m][y].con;
		}
	}
	return s;
}
string smx4(int x, int y)
{
	string s = "";
	int m, n;
	int hx = x - 4;//qi
	int ex = x + 4;//zhong
	int hy = y - 4;//起点
	int ey = y + 4;//终点
	for (m = hx, n = ey; m <= ex&&n >= hy; n--, m++)
	{
		if (m >= 0 && n >= 0 && m <= 14 && n <= 14)
		{
			if (m == x&&n == y)
			{
				s += "C";
			}
			else
				s += a[m][n].con;
		}
	}
	return s;
}
int win1(string str)
{
	int len, n = 0;
	string a = "CMMMM", b = "MCMMM", c = "MMCMM", d = "MMMCM", e = "MMMMC";
	string text;
	len = str.length();
	if (len<5)
		return 0;
	else
	{
		for (int i = 0; (i + 4)<len; i++)
		{
			text.assign(str, i, 5);
			if ((!text.compare(a)) || (!text.compare(b)) || (!text.compare(c)) || (!text.compare(d)) || (!text.compare(d)) || (!text.compare(e)))
				n = 10000;
		}
		return n;
	}
}
int win2(string str)
{
	int len, n = 0;
	string a = "COOOO", b = "OOOOC";
	string text;
	len = str.length();
	if (len<5)
		return 0;
	else
	{
		for (int i = 0; (i + 4)<len; i++)
		{
			text.assign(str, i, 5);
			if ((!text.compare(a)) || (!text.compare(b)))
				n = 6000;
		}
		return n;
	}
}
int win3(string str)
{
	int len, n = 0;
	string a = ".CMMM.", b = ".MCMM.", c = ".MMCM.", d = ".MMMC.";
	string text;
	len = str.length();
	if (len<6)
		return 0;
	else
	{
		for (int i = 0; (i + 5)<len; i++)
		{
			text.assign(str, i, 6);
			if ((!text.compare(a)) || (!text.compare(b)) || (!text.compare(c)) || (!text.compare(d)) || (!text.compare(d)))
				n = 5000;
		}
		return n;
	}
}
int win4(string smx)
{
	int g = 0;
	string str1 = "COOO.", str2 = ".OOOC", str3 = ".OOCO.", str4 = ".OCOO.";
	if (strstr(smx.c_str(), str1.c_str()))
		g += 2500;
	if (strstr(smx.c_str(), str2.c_str()))
		g += 2500;
	if (strstr(smx.c_str(), str3.c_str()))
		g += 2500;
	if (strstr(smx.c_str(), str4.c_str()))
		g += 2500;
	return g;
}
int win5(string str)
{
	int len, n = 0;
	string a = "OCMMM.", b = "OMCMM.", c = "OMMCM.", d = "OMMMC.", e = ".CMMMO", f = ".MCMMO", g = ".MMCMO", h = ".MMMCO";
	string text;
	len = str.length();
	if (len<6)
		return 0;
	else
	{
		for (int i = 0; (i + 5)<len; i++)
		{
			text.assign(str, i, 6);
			//cout<<"n "<<text<<endl;
			if ((!text.compare(a)) || (!text.compare(b)) || (!text.compare(c)) || (!text.compare(d)) || (!text.compare(d)) || (!text.compare(e)) || (!text.compare(f)) || (!text.compare(g)) || (!text.compare(h)))
				n = 2000;
		}
		return n;
	}
}
int win6(string str)
{
	int len, n = 0;
	string a = ".MMC.", b = ".MCM.", c = ".CMM.";
	string text;
	len = str.length();
	if (len<5)
		return 0;
	else
	{
		for (int i = 0; (i + 4)<len; i++)
		{
			text.assign(str, i, 5);
			if ((!text.compare(a)) || (!text.compare(b)) || (!text.compare(c)))
				n = 400;
		}
		return n;
	}
}
int win7(string smx)
{
	int g = 0;
	string str1 = ".OOC", str2 = "COO.", str3 = "MOOOC", str4 = "COOOM";
	if (strstr(smx.c_str(), str1.c_str()))
		g += 400;
	if (strstr(smx.c_str(), str2.c_str()))
		g += 400;
	if (strstr(smx.c_str(), str3.c_str()))
		g += 400;
	if (strstr(smx.c_str(), str4.c_str()))
		g += 400;
	return g;
}
int win8(string smx)
{
	int g = 0;
	string str1 = ".MMCO", str2 = ".MCMO", str3 = ".CMMO", str4 = "OMMC.", str5 = "OMCM.", str6 = "OCMM.", str7 = "MOOC", str8 = "COOM";
	if (strstr(smx.c_str(), str1.c_str()))
		g += 200;
	if (strstr(smx.c_str(), str2.c_str()))
		g += 200;
	if (strstr(smx.c_str(), str3.c_str()))
		g += 200;
	if (strstr(smx.c_str(), str4.c_str()))
		g += 200;
	if (strstr(smx.c_str(), str5.c_str()))
		g += 200;
	if (strstr(smx.c_str(), str6.c_str()))
		g += 200;
	if (strstr(smx.c_str(), str7.c_str()))
		g += 200;
	if (strstr(smx.c_str(), str8.c_str()))
		g += 200;
	return g;
}
int win9(string smx)
{
	int g = 0;
	string str1 = ".MC.", str2 = ".CM.", str3 = ".CO.", str4 = ".CO.";
	if (strstr(smx.c_str(), str1.c_str()))
		g += 50;
	if (strstr(smx.c_str(), str2.c_str()))
		g += 50;
	if (strstr(smx.c_str(), str3.c_str()))
		g += 1;
	if (strstr(smx.c_str(), str4.c_str()))
		g += 1;
	return g;
}
int GetGrade(string smx)
{
	int Gra = 0;
	Gra += win1(smx);
	Gra += win2(smx);
	Gra += win3(smx);
	Gra += win4(smx);
	Gra += win5(smx);
	Gra += win6(smx);
	Gra += win7(smx);
	Gra += win8(smx);
	Gra += win9(smx);
	return Gra;
}
void Sum()
{

	for (int i = 0; i<15; i++)
	{
		for (int j = 0; j<15; j++)
		{
			int Gra = 0;
			if (a[i][j].con == '.')
			{
				Gra += GetGrade(smx1(i, j));
				Gra += GetGrade(smx2(i, j));
				Gra += GetGrade(smx3(i, j));
				Gra += GetGrade(smx4(i, j));
				a[i][j].grade += Gra;
				//cout << i << " " << j << " " << a[i][j].grade << endl;
			}
		}
	}
}



extern "C"
{
	__declspec(dllexport) void reset()
	{
		for (int i = 0; i<15; i++)
		{
			for (int j = 0; j<15; j++)
			{
				a[i][j].grade = 20;
				a[i][j].con = '.';
			}
		}
	}
	__declspec(dllexport) char * Output(char * mzw)
	{

		Input(mzw);
		Sum();
		int x = 0, y = 0;
		for (int i = 0; i < 14; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (a[i][j].grade>a[x][y].grade)
				{
					x = i;
					y = j;
				}
			}
		}
		string re;
		re += char(x + 97);
		re += char(y + 97);
		char * strc = new char[strlen(re.c_str()) + 1];//string转char *
		strcpy_s(strc, strlen(strc), re.c_str());
		reset();
		return strc;
	}
}
