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
	void TestDES();//DESº”√‹Ω‚√‹
	void TestMD5();//MD5º”√‹

public:
	static void TestMain();
};

