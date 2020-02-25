// Circle.cpp: implementation of the CCircle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "D040144.h"
#include "Circle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern void DPtoVP(float x,float y,int *X,int *Y);
extern float DLtoVL(float l);
IMPLEMENT_SERIAL(CCircle,CObject,1)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCircle::CCircle()
{

}

CCircle::~CCircle()
{

}

CCircle::CCircle(COLORREF ColorPen,COLORREF ColorBrush,int LineWidth,int LineType,int ID_Elementry,bool Delete,
			  float CircleX,float CircleY,float CircleR,BOOL Fill)
			  :CDraw(ColorPen,ColorBrush,LineWidth,LineType,ID_Elementry,Delete)
{
		m_fCircleX=CircleX;
		m_fCircleY=CircleY;
		m_fCircleR=CircleR;
		m_bFill=Fill;

}

void CCircle::Draw(CDC *pDC)
{
 	int x,y;
	float r;
	x=m_fCircleX;
	y=m_fCircleY;
	r=m_fCircleR;
	
	if(m_bDelete)	//����Ѿ�����ɾ��״̬
	{	return;}

	CBrush brush(3,m_ColorBrush);
	pDC->SelectObject(brush);

	if(!m_bFill)	//�����Բ
		pDC->SelectStockObject(NULL_BRUSH); //�������ͨԲ�����ò����״̬
	CPen pen(m_nLineType,m_nLineWidth,m_ColorPen);
	pDC->SelectObject(&pen);
//AfxMessageBox("zca ");
	pDC->SetROP2(R2_COPYPEN);//�趨���ǵĻ���ģʽ
	pDC->SetBkMode(TRANSPARENT);
	DPtoVP(m_fCircleX,m_fCircleY,&x,&y);//5.17
	r=DLtoVL(m_fCircleR);//5.17
	pDC->Ellipse(x-r,y-r,x+r,y+r); //����Բ


}

void CCircle::GetRect(float *minX, float *minY, float *maxX, float *maxY)//5.24
{
	*minX=m_fCircleX-m_fCircleR;
	*minY=m_fCircleY-m_fCircleR;  //�õ����������xֵ
	*maxX=m_fCircleX+m_fCircleR;  //�õ���������Сyֵ
	*maxY=m_fCircleY+m_fCircleR;  //�õ����������yֵ
}
void CCircle::Serialize(CArchive& ar)
{
	CDraw::Serialize(ar);
	if(ar.IsStoring())
	{
		ar<<m_bFill<<m_fCircleX<<m_fCircleY<<m_fCircleR;
	}
	else
	{
		ar>>m_bFill>>m_fCircleX>>m_fCircleY>>m_fCircleR;
	}
}