#pragma once
class testEnDEcrypt
{
public:
	testEnDEcrypt(void);
	~testEnDEcrypt(void);

private:
	static testEnDEcrypt* instance;
	static testEnDEcrypt* GetInstance();

private:
	void TestDES();//DES���ܽ���
	void TestMD5();//MD5����

public:
	static void TestMain();
};

