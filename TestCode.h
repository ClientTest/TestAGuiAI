#pragma once
class TestCode
{
public:
	TestCode(void);
	~TestCode(void);

private:
	static TestCode* instance;
	static TestCode* GetInstance();

private:
	void TestCodeConv();//����ת��

public:
	static void TestMain();
};

