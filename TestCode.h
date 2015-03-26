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
	void TestCodeConv();//±àÂë×ª»»

public:
	static void TestMain();
};

