/*
 *  TOPPERS/HRP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      High Reliable system Profile Kernel
 *	
 *	Copyright (C) 2011-2012 by Embedded and Real-Time Systems Laboratory
 *				Graduate School of Information Science, Nagoya Univ., JAPAN
 *	
 *	�嵭����Ԥϡ��ʲ���(1)���(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *	�����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *	�ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *	(1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *		��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *		����������˴ޤޤ�Ƥ��뤳�ȡ�
 *	(2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *		�ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *		��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	(3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *		�ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *		�ȡ�
 *	  (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *		  �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *	  (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *		  ��𤹤뤳�ȡ�
 *	(4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *		������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *		�ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *		ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *		���դ��뤳�ȡ�
 *	
 *	�ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *	���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *	���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *	�������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *	����Ǥ�����ʤ���
 *	
 */


#ifndef TOPPERS_TARGET_SVC_H
#define TOPPERS_TARGET_SVC_H

#ifndef TOPPERS_MACRO_ONLY


/*
 *  �����ͥ�Υ����ӥ�������Υ��󥿥ե�����
 *
 *  ������å��쥸����
 *    r1 : �ؿ�������
 *    r4 - r7 : ������4�Ĥޤǡ�
 *    r2 : ��5����
 *  �ؿ��ƤӽФ�(jsr)�ǥ����ӥ��������ƤӽФ����ᡤPR����¸����
 */
extern char _kernel_svc_entry;

#define CAL_SVC_0(TYPE, FNCD) \
	return(0);

#define CAL_SVC_1(TYPE, FNCD, TYPE1, PAR1) \
	return(0);

#define CAL_SVC_2(TYPE, FNCD, TYPE1, PAR1, TYPE2, PAR2) \
	return(0);

#define CAL_SVC_3(TYPE, FNCD, TYPE1, PAR1, \
							TYPE2, PAR2, TYPE3, PAR3) \
	return(0);

#define CAL_SVC_4(TYPE, FNCD, TYPE1, PAR1, TYPE2, PAR2, \
								TYPE3, PAR3, TYPE4, PAR4) \
	return(0);

#define CAL_SVC_5(TYPE, FNCD, TYPE1, PAR1, TYPE2, PAR2, \
						TYPE3, PAR3, TYPE4, PAR4, TYPE5, PAR5) \
	return(0);

#define CAL_SVC_0M(TYPE, FNCD) \
	return(0);

#define CAL_SVC_1M(TYPE, FNCD, TYPE1, PAR1) \
	return(0);

#define CAL_SVC_2M(TYPE, FNCD, TYPE1, PAR1, TYPE2, PAR2) \
	return(0);

#define CAL_SVC_3M(TYPE, FNCD, TYPE1, PAR1, \
							TYPE2, PAR2, TYPE3, PAR3) \
	return(0);

#define CAL_SVC_4M(TYPE, FNCD, TYPE1, PAR1, TYPE2, PAR2, \
								TYPE3, PAR3, TYPE4, PAR4) \
	return(0);

#define CAL_SVC_5M(TYPE, FNCD, TYPE1, PAR1, TYPE2, PAR2, \
						TYPE3, PAR3, TYPE4, PAR4, TYPE5, PAR5) \
	return(0);

#ifndef TOPPERS_SVC_CALL
#include "gcc/tool_svc.h"
#endif /* TOPPERS_SVC_CALL */

Inline ER_UINT
cal_svc(FN fncd, intptr_t par1, intptr_t par2,
        intptr_t par3, intptr_t par4, intptr_t par5)
{
    if(fncd > 0){
        CAL_SVC_5M(FN, fncd, intptr_t, par1, intptr_t, par2, 
                intptr_t, par3, intptr_t, par4, intptr_t, par5);
    } else {
        return (E_RSFN);
    }
}

#endif /* TOPPERS_MACRO_ONLY */


#endif /* TOPPERS_TARGET_SVC_H */

