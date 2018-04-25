#ifndef CIMAGE_INCLUDE_H
#define CIMAGE_INCLUDE_H
#include <windows.h>
#include <string>
using namespace std;
class CImage
{
public:
	CImage();
	virtual ~CImage();
	virtual int saveImage(HDC hdc,HBITMAP hbitMap,string fileName)=0;
protected:
	int  getBmpFromDc();
protected:
	HDC	m_hdc;
	char *m_buf;//�洢ѡ�����������rgb��ɫֵ��ÿ��������3�ֽڴ洢
	HBITMAP	m_hBitMap;
	BITMAP	m_bitMap;
};

//�ն���ģʽ�����ɵĿն������κβ���
class CNullImage:public CImage
{
public:
	CNullImage(){}
	~CNullImage(){}
	virtual int saveImage(HDC hdc,HBITMAP hbitMap,string fileName){return 0;}
};

class CBmpImage:public CImage
{
public:
	CBmpImage();
	virtual ~CBmpImage();
	virtual int saveImage(HDC hdc,HBITMAP hbitMap,string fileName);
};

class CPngImage:public CImage
{
public:
	CPngImage();
	virtual ~CPngImage();
	virtual int saveImage(HDC hdc,HBITMAP hbitMap,string fileName);
};

class CJpegImage:public CImage
{
public:
	CJpegImage();
	virtual	~CJpegImage();
	virtual  int saveImage(HDC hdc,HBITMAP hbitMap,string fileName);
};
#endif