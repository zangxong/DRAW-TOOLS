// Circle.h: interface for the CCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLE_H__EE438C04_0AA8_41CF_AA03_87F95CA0725C__INCLUDED_)
#define AFX_CIRCLE_H__EE438C04_0AA8_41CF_AA03_87F95CA0725C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Draw.h"

class CCircle : public CDraw  
{
public:
	DECLARE_SERIAL(CCircle)
	void CCircle::Serialize(CArchive& ar);
	void GetRect(float * minX,float * minY,float * maxX,float * maxY);
	void Draw(CDC *pDC);
	CCircle(COLORREF ColorPen,COLORREF ColorBrush,int LineWidth,int LineType,int ID_Elementry,bool Delete,
			  float CircleX,float CircleY,float CircleR,BOOL Fill);
	CCircle();
	virtual ~CCircle();


protected:
	float m_fCircleX;
	float m_fCircleY;
	float m_fCircleR;   //°ë¾¶
	BOOL m_bFill;		//ÊÇ·ñÌî³ä
};

#endif // !defined(AFX_CIRCLE_H__EE438C04_0AA8_41CF_AA03_87F95CA0725C__INCLUDED_)
