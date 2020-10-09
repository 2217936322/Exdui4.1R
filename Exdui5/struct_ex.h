#pragma once
#include "help_ex.h"

typedef UINT32	ARGB, RGB0;	//ARGB��RGB
typedef UINT8	CHANNEL;	//ͨ��
typedef COLORREF EXARGB;		// ��ɫ
typedef UINT32 EXATOM;			// ԭ�Ӻ�
typedef HANDLE EXHANDLE;		// ���
typedef EXHANDLE HEXDUI;		// ������
typedef EXHANDLE HEXLAYOUT;		// ���־��
typedef EXHANDLE HEXTHEME;		// ������
typedef EXHANDLE HEXOBJ;		// �ؼ����
typedef EXHANDLE HEXCANVAS;		// �������
typedef EXHANDLE HEXBRUSH;		// ˢ�Ӿ��
typedef EXHANDLE HEXIMAGE;		// ͼƬ���
typedef EXHANDLE HEXFONT;		// ������
typedef EXHANDLE HEXEASING;		// �������/ָ��
typedef EXHANDLE HEXPATH;		// ·�����
typedef EXHANDLE HEXMATRIX;		// ������

struct EXDATA
{

	LPBYTE ptr;		// ����ָ��
	size_t len;		// ���ݳ���
};
struct EX_NMHDR
{
	HEXOBJ	hObjFrom;			// 0	������
	INT		idFrom;				// 4	���ID
	INT		nCode;				// 8	֪ͨ��Ϣ
	WPARAM	wParam;				// 12	�޷�������	::ͨ����һ������Ϣ�йصĳ���ֵ��Ҳ�����Ǵ��ڻ�ؼ��ľ��
	LPARAM	lParam;				// 16	������		::ͨ����һ��ָ���ڴ������ݵ�ָ��
};
struct RECTF
{
	FLOAT left;
	FLOAT top;
	FLOAT right;
	FLOAT bottom;
};
struct EX_CUSTOMDRAW {
	HEXCANVAS	hCanvas;
	HEXTHEME	hTheme;
	int		dwState;
	int		dwStyle;
	RECT		rcDraw;
	//int left;
	//int top;
	//int right;
	//int bottom;
	INT			iItem;
	INT			iItemParam;
};
struct EX_PAINTSTRUCT2
{
	HEXCANVAS hCanvas;		// 0	����
	HEXTHEME hTheme;		// 4	����
	int dwStyle;			// 8	���
	int dwStyleEx;		// 12	��չ���
	int dwTextFormat;		// 16	�ı���ʽ
	int dwState;			// 20	״̬
	INT dwOwnerData;		// 24	��������
	UINT uWidth;			// 28	���
	UINT uHeight;			// 32	�߶�
	RECT rcPaint;			// 36	���ƾ���
	//int pLeft;			// 36	���ƾ���::��
	//int pTop;				// 40	���ƾ���::��
	//int pRight;			// 44	���ƾ���::��
	//int pBottom;			// 48	���ƾ���::��
	RECT rcText;			// 52	�ı�����
	//int tLeft;			// 52	�ı�����::��
	//int tTop;				// 56	�ı�����::��
	//int tRight;			// 60	�ı�����::��
	//int tBottom;			// 64	�ı�����::��
	INT dwReserved;			// 68	����
};
struct EX_BITMAPDATA {
	UINT		Width;
	UINT		Height;
	INT			Stride;
	INT			PixelFormat;
	COLORREF* Scan0;
	INT			Reserved;
};
#pragma pack(1)
struct EX_EASINGINFO
{
	LPVOID		pEasing;			// 0  ����ָ��
	DOUBLE		nProgress;			// 4  ���� 0-1
	DOUBLE		nCurrent;			// 12 ��ǰֵ
	int_PTR	pEasingContext;		// 20 ��������
	UINT		nTimesSurplus;		// 24 ʣ����
	int		p1;					// 28 ����1
	int		p2;					// 32 ����2
	int		p3;					// 36 ����3
	int		p4;					// 40 ����4
};
#pragma pack()
struct EX_REPORTLIST_COLUMNINFO {
	LPCWSTR		wzText;				//��ͷ����
	UINT		nWidth;				//�п��
	int		dwStyle;			//��ͷ��� ERLV_CS_
	int		dwTextFormat;		//���ı���ʽ
	EXARGB		crText;				//���ı���ɫ
	UINT		nInsertIndex;		//����λ��,0Ϊ�����
};
struct EX_REPORTLIST_ITEMINFO {
	UINT		iRow;				//������[IN / OUT]
	UINT		iCol;				//������[IN / OUT]
	int		dwStyle;			//���з��(ͬ�й���)
	LPCWSTR		wzText;				//�����ı�
	UINT		nImageIndex;		//����ͼƬ(ͬ�й���)
	LPARAM		lParam;				//�������(ͬ�й���)
	int		dwState;			//����״̬(ͬ�й���)
};
struct EX_REPORTLIST_ROWINFO {
	UINT		nInsertIndex;		//����λ��,0Ϊ��� 
	int		dwStyle;			//���з�� ERLV_RS_ 
	LPARAM		lParam;				//���� 
	UINT		nImageIndex;		//ͼƬ������ 
};
struct EX_REPORTLIST_SORTINFO {
	UINT		iCol;				//0Ϊ��row.lParam���� 
	UINT		nType;				//0:�ı�,1:���� 
	INT			lpfnCmp;			//result cmp(hObj,nIndex1,pvData1,nIndex2,pvData2,nIndexCol,nType,lParam) 
	BOOL		fDesc;				// �Ƿ���
	LPARAM		lParam;				//
};
struct EX_TREEVIEW_INSERTINFO {
	INT itemParent;					// ��������0Ϊ���
	INT itemInsertAfter;			// �����ڴ���֮�󣨱�����ͬ�㣩
	INT nID;						// ID
	LPCWSTR tzText;					// �����ı�ansi / unicode
	LPARAM lParam;					// ����
	INT nImageIndex;				// ����ʱͼƬ����
	INT nImageIndexExpand;			// չ��ʱͼƬ����
	BOOL fExpand;					// �Ƿ�չ��
	int dwStyle;					// ���
	BOOL fUpdateLater;				// �Ƿ��ݲ�����(ͳһ��TVM_UPDATE����)
};
struct TREEVIEW_NODEITEM
{
	INT nID;						// ID
	LPCWSTR wzText;					// �ı�
	INT pvParam;					// 
	INT nImageIndex;				// ͼƬ����
	INT nImageIndexExpand;			// չ��ͼƬ����
	BOOL fExpand;					// �Ƿ�չ��
	int dwStyle;					// ״̬
	INT nDepth;						// ���
	INT pNodeParent;				// ���ڵ�
	INT pNodePrev;					// ��һ���ڵ�
	INT pNodeNext;					// ��һ���ڵ�
	INT pNodeChildFirst;			// ����Ŀ����
	INT nCountChild;				// ����Ŀ

};
struct EX_BACKGROUNDIMAGEINFO {
	int		dwFlags;				//��ʶ
	HEXIMAGE	hImage;				//ͼƬָ��
	INT		    x;			//
	INT		    y;		//
	int		dwRepeat;				//
	INT		    lpGrid;		//
	INT         lpDelay;
	int         curFrame;
	int         maxFrame;
	int       dwAlpha;
};
